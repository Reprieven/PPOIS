from Rate import Rate
class Balance():
    def __init__(self, value: int):
        self.__value = value
    
    @property
    def value(self)->int:
        return self.__value
    
    @value.setter
    def value(self, new_value: float):
        self.__value = new_value


    