from Car import Car 
class ElectricCar(Car):
    def __init__(self, model: str, year: int, licence_plate: str, battery = 50):
        super().__init__(model, year, licence_plate)
        self.__battery = battery
    
    @property
    def battery(self)->int:
        return self.__battery
    
    @battery.setter
    def battery(self,value: int):
        self.__battery = value

    