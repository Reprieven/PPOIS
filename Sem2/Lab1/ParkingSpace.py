from Car import Car
class ParkingSpace():
    def __init__(self):
        self.__is_free = True
        self.__parked_car = None
    
    @property 
    def is_free(self)->bool:
        return self.__is_free
    
    @property 
    def parked_car(self)->Car:
        return self.__parked_car
    
    def park_car(self, car: Car)->bool:
        if not self.is_free:
            return False
        self.__is_free = False
        self.__parked_car = car 
        return True

    def remove_car(self)->bool:
        if self.is_free:
            return False
        self.__is_free = True
        self.__parked_car = None
        return True


        