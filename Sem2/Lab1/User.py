from Human import Human
from Car import Car
from Balance import Balance
from ParkingSpace import ParkingSpace
class User(Human):

    def __init__(self, name: str, phone: str):
        super().__init__(name, phone)
        self.__balance = Balance(0)
        self.__car = None
        self.__taken_space = None

    @property
    def car(self)->Car:
        return self.__car
    
    @property
    def balance(self)->Balance:
        return self.__balance
    
    @property
    def taken_space(self)->ParkingSpace:
        return self.__taken_space
    
    @car.setter
    def car(self,car:Car):
        try:
            self.__car = car
        except Exception:
            raise("Должен быть объект класса Car")
        self.__car = car
    
    @taken_space.setter
    def taken_space(self,space: ParkingSpace):
        try:
            self.__taken_space = space
        except Exception:
            raise("Должен быть объект класса ParkingSpace")
        self.__taken_space = space


        

