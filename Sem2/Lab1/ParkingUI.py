from InputOutput import *
class ParkingUI():

    @staticmethod
    def safe_state_ok(file_name):
        OutputProvider.show_message(f"Данные успешно сохранены в файл: {file_name}")
    
    @staticmethod
    def load_state_ok(file_name):
        OutputProvider.show_message(f"Данные успешно загружены из файла: {file_name}")
    
    @staticmethod
    def load_state_no_file(file_name):
        OutputProvider.show_message(f"Файл {file_name} не найден. Начинаем с чистого состояния.")
    
    @staticmethod
    def create_user_get_info():
        name = InputProvider.get_string("Введите имя: ")
        phone = InputProvider.get_string("Введите номер телефона: ")
        return name , phone
    
    @staticmethod
    def create_user_ok(name: str):
        OutputProvider.show_message(f"Пользователь {name} успешно создан и выбран.")

    @staticmethod
    def add_car_get_info():
        sub_choice = InputProvider.get_string("Ваша машина - электромобиль?\n(1.Да, 2.Нет): ")
        model = InputProvider.get_string("Введите модель машины: ")
        year = InputProvider.get_int("Введите год выпуска: ")
        licence_plate =InputProvider.get_string("Введите номер машины: ")
        return sub_choice,model,year,licence_plate

    @staticmethod
    def add_car_ok(model, licence_plate):
        OutputProvider.show_message(f"Машина {model} ({licence_plate}) успешно добавлена.")
        
    @staticmethod
    def top_up_balance_get_info():
        value = InputProvider.get_float("Введите сумму пополнения: ")
        return value
    
    @staticmethod
    def top_up_balance_ok(value):
        OutputProvider.show_message(f"Счёт пополнен на {value} BYN.")

    @staticmethod
    def choose_parking_space():
        space = InputProvider.get_int("Введите номер места для парковки: ")
        return space
    
    @staticmethod
    def choose_parking_space_ok(space):
        OutputProvider.show_message(f"Место #{space} успешно выбрано.")
    
    
    @staticmethod
    def show_pass(move_forward: int, move_side: int):
        if not move_forward and not move_side:
            OutputProvider.show_message("Ваше место 0, ехать никуда не нужно")
        elif not move_forward:
            OutputProvider.show_message(f"Продолжайте движение в сторону на {move_side} метров")
        elif not move_side:
            OutputProvider.show_message(f"Двигайтесь вперед {move_forward} метров")
        else:
            OutputProvider.show_message(f"Двигайтесь вперед {move_forward} метров\
                                          и продолжайте движение в сторону на {move_side} метров")
    @staticmethod   
    def pay_check_ok(space):
        OutputProvider.show_message(f"Парковка на месте #{space} успешно оплачена.")

    @staticmethod
    def charger_ok():
        OutputProvider.show_message("Машина заряжена на 100%")

    @staticmethod
    def security_not_ok():
        OutputProvider.show_message("Машину украли")

    @staticmethod
    def security_ok():
        OutputProvider.show_message("Машина на месте")
    
    @staticmethod
    def balance(value: float):
        OutputProvider.show_message(f"Баланс-{value} BYN")
    
    @staticmethod
    def user_info(name: str, phone: str):
        OutputProvider.show_message(f"Имя пользователя:{name}")
        OutputProvider.show_message(f"Телефон:{phone}")
    
    @staticmethod
    def car_info(model: str, year: int, licence_plate: str):
        OutputProvider.show_message(f"Модель машины:{model}")
        OutputProvider.show_message(f"Год производства:{year}")
        OutputProvider.show_message(f"Номер:{licence_plate}")

    @staticmethod
    def change_user_get_info():
        name = InputProvider.get_string("Введите имя пользователя: ")
        phone = InputProvider.get_string("Введите номер телефона: ")
        return name,phone
    
    @staticmethod
    def change_user_ok():
         OutputProvider.show_message("Пользователь успешно выбран")
    
    @staticmethod
    def change_user_not_ok():
        OutputProvider.show_message("Пользователь не зарегистрирован")
    
    @staticmethod
    def input_error(message: str):
        OutputProvider.show_message(f"Ошибка ввода: {message}")

    @staticmethod
    def main_menu_choice():
        choice = InputProvider.get_string("1. Создать пользователя\n2. Выйти\n")
        return choice
    @staticmethod
    def user_exist():
        choice = InputProvider.get_string("Войти в профиль который вы использовали при последнем входе?\
                                          \n(1.Да, 2.Нет)\n")
        return choice
    @staticmethod
    def exit():
        OutputProvider.show_message("Выход из программы")
    
    @staticmethod
    def operation_choice():
        choice = InputProvider.get_int("""1.Добавить автомобиль\
                                           \n2.Пополнить баланс\
                                           \n3.Посмотреть баланс\
                                           \n4.Посмотреть информацию о пользователе\
                                           \n5.Посмотреть информацию об автомобиле\
                                           \n6.Изменить текущего пользователя\
                                           \n7.Выбрать место для парковки\
                                           \n8.Найти дорогу к парковочному месту\
                                           \n9.Оплатить парковку\
                                          \n10.Зарядить электромобиль\
                                          \n11.Проверить сохранность автомобиля\
                                          \n12.Выйти:\n""")   
        return choice
    
    @staticmethod
    def main_menu_back():
        OutputProvider.show_message("Возврат в главное меню")
    