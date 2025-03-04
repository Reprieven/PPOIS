from Parking import Parking
from Rate import Rate
from ParkingSpace import ParkingSpace
from ElectricCar import ElectricCar
from User import User
from Car import Car
from ParkingManager import ParkingManager
from NavigationManager import NavigationManager
from BalanceManager import BalanceManager
from Charger import Charger
from Security import Security
from typing import List
from SerializationManager import SerializationManager
from ParkingUI import *

class ParkingFSM():
    def __init__(self, rate: Rate, spaces: List[ParkingSpace], spaces_in_row: int):
        self.users = []
        self.parking = Parking(rate, spaces, spaces_in_row)
        self.current_user = None
        self.state = "MAIN_MENU"

    def save_state(self, file_name: str = "parking_state.pkl"):
        data = {
            "users": self.users,
            "current_user": self.current_user,
            "parking": self.parking,
        }
        SerializationManager.save(data, file_name)
    
    def load_state(self, file_name: str = "parking_state.pkl"):
        state = SerializationManager.load(file_name)
        if state:
            self.users = state.get("users", [])
            self.current_user = state.get("current_user", None)
            self.parking = state.get("parking", None)
            print("Состояние программы успешно загружено.")
        else:
            print("Начинаем с чистого состояния программы.")
    
    def create_user(self):
        name, phone = ParkingUI.create_user_get_info()
        if not name.strip() or not phone.strip():
            ParkingUI.input_error("Имя и номер телефона не могут быть пустыми.")
            return False
        user = User(name, phone)
        self.users.append(user)
        self.current_user = user
        ParkingUI.create_user_ok(user.name)
        return True
    
    def add_car(self):
        sub_choice, model, year, licence_plate = ParkingUI.add_car_get_info()
        if not model.strip() or not licence_plate.strip():
            ParkingUI.input_error("Модель и номер машины не могут быть пустыми.")
            return
        if sub_choice not in ["1", "2"]:
            ParkingUI.input_error("Выберите правильный тип машины (1 или 2).")
            return
        try:
            if sub_choice == "1":
                car = ElectricCar(model, year, licence_plate)
            else:
                car = Car(model, year, licence_plate)
        except ValueError:
            ParkingUI.input_error("Некорректный ввод данных.")
            return
        self.current_user.car = car
        ParkingUI.add_car_ok(model, licence_plate)

    def top_up_balance(self):
        value = ParkingUI.top_up_balance_get_info()
        if not BalanceManager.top_up(self.current_user.balance, value):
            ParkingUI.input_error("Минимальная сумма пополнения 1 BYN")
        else:
            ParkingUI.top_up_balance_ok(value)

    def choose_parking_space(self):
        space = ParkingUI.choose_parking_space()
        if space<0 or space>=len(self.parking.spaces):
            ParkingUI.input_error("Такого места нет на парковке")
            return
        if not ParkingManager.choose_space(self.current_user, self.parking, space):
            ParkingUI.input_error("Это место занято")
        else:
            ParkingUI.choose_parking_space_ok(space)
    
    def find_parking_path(self):
        space = ParkingUI.choose_parking_space()
        move_forward, move_side = NavigationManager.ask_for_path(self.parking, space)
        if move_forward == -1 and move_side == -1:
            ParkingUI.input_error("Такого места нет на парковке")
        else:
            ParkingUI.show_pass(move_forward, move_side)
    
    def pay_parking(self):
        space = ParkingUI.choose_parking_space()
        if space<0 or space>=len(self.parking.spaces):
            ParkingUI.input_error("Такого места нет на парковке")
            return
        if BalanceManager.pay_check(self.current_user.balance,self.parking.rate):
            ParkingUI.pay_check_ok(space)
            if ParkingManager.leave_space(self.current_user, self.parking, space):
                ParkingUI.pay_check_ok(space)
            else: 
                ParkingUI.input_error(f"На месте #{space} нет машины")
                BalanceManager.top_up(self.current_user.balance,self.parking.rate.value)
        else:
            ParkingUI.input_error("На балансе недостаточно средств")
    
    def charge_electric_car(self):
        if Charger.ask_for_charge(self.current_user):
            ParkingUI.charger_ok()
        else:
            ParkingUI.input_error("Ваша машина, не является электромобилем")

    def check_car_security(self):
        try:
            if Security.security_check(self.current_user.taken_space):
               ParkingUI.security_ok()
            else:
               ParkingUI.security_not_ok() 
        except AttributeError:
            ParkingUI.input_error("Вы не парковали свою машину на парковку")
    
    def show_balance(self):
        ParkingUI.balance(self.current_user.balance.value)
        
    def show_user_info(self):
        ParkingUI.user_info(self.current_user.name,self.current_user.phone)
    
    def show_car_info(self):
        try:
            model = self.current_user.car.model
            year = self.current_user.car.year
            license_plate = self.current_user.car.licence_plate
            ParkingUI.car_info(model,year,license_plate)
        except AttributeError:
            ParkingUI.input_error("Сначала добавьте машину.")

    def change_current_user(self):
        name, phone  = ParkingUI.change_user_get_info()
        if not name.strip() or not phone.strip():
            ParkingUI.input_error("Имя и номер телефона не могут быть пустыми.")
            return
        for user in self.users:
            if name == user.name and phone == user.phone:
                self.current_user = user
                ParkingUI.change_user_ok()
                return
        ParkingUI.change_user_not_ok()


    def run(self):
        self.load_state()
        if self.current_user:
            choice = ParkingUI.user_exist()
            if choice == "1":
                self.state = "USER_MENU"
        while True:
            if self.state == "MAIN_MENU":
                choice = ParkingUI.main_menu_choice()
                if choice == "1":
                    if self.create_user():
                        self.state = "USER_MENU"
                elif choice == "2":
                    self.save_state()
                    ParkingUI.exit()
                    break
                else:
                    ParkingUI.input_error("Неправильный пункт меню")
            elif self.state == "USER_MENU":
                choice =  ParkingUI.operation_choice()
                match choice:
                    case 1:
                        self.add_car()
                    case 2:
                        self.top_up_balance()
                    case 3:
                        self.show_balance()
                    case 4:
                        self.show_user_info()
                    case 5:
                        self.show_car_info()
                    case 6:
                        self.change_current_user()
                    case 7:
                        self.choose_parking_space()
                    case 8:
                        self.find_parking_path()
                    case 9:
                        self.pay_parking()
                    case 10:
                        self.charge_electric_car()
                    case 11:
                        self.check_car_security()
                    case 12:
                        ParkingUI.main_menu_back()
                        self.state = "MAIN_MENU"
                    case _:
                        ParkingUI.input_error("Неправильный пункт меню")
    
