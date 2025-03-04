from ElectricCar import ElectricCar
from User import User
class Charger():
    @staticmethod
    def ask_for_charge(user: User):
        if isinstance(user.car, ElectricCar):
            user.car.battery = 100
            return True
        else: 
            return False