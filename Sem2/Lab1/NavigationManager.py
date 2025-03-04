from Parking import Parking
class NavigationManager():
    
    @staticmethod
    def ask_for_path(parking: Parking, space_num: int):
        if space_num < 0 or space_num >= len(parking.spaces):
            return -1 , -1 
        move_forward = space_num // parking.spaces_in_row
        move_side = space_num % parking.spaces_in_row
        return move_forward, move_side

