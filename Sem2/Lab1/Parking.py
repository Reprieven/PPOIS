from ParkingSpace import ParkingSpace
from Rate import Rate
from typing import List, Tuple
class Parking():
    def __init__(self, rate: Rate, spaces:List[ParkingSpace], spaces_in_row: int):
        self.__rate = rate
        self.__spaces = spaces
        self.__spaces_in_row = spaces_in_row
    
    @property
    def rate(self)->Rate:
        return self.__rate
    
    @property
    def spaces(self)->List[ParkingSpace]:
        return self.__spaces
    
    @property
    def spaces_in_row(self)->int:
        return self.__spaces_in_row

