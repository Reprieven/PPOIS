from ParkingSpace import ParkingSpace
from Human import Human
class Security(Human):
    def __init__(self, name: str, phone:str):
        super().__init__(name,phone)
    
    @staticmethod
    def security_check(parking_space: ParkingSpace):
        if not parking_space.is_free and parking_space.parked_car == None:
            return False
        else: 
            return True
            