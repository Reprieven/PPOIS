from User import User
from Parking import Parking
class ParkingManager():

    @staticmethod
    def choose_space(user: User, parking: Parking, space_num: int):
        if parking.spaces[space_num].park_car(user.car):
            user.taken_space = parking.spaces[space_num]
            return True
        else:
            return False
    
    @staticmethod
    def leave_space(user: User, parking: Parking, space_num: int):
        if parking.spaces[space_num].is_free:
            return False
        parking.spaces[space_num].remove_car()
        user.taken_space = None
        return True