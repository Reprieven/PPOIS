class Rate(): 
    def __init__(self,value: float):
        self.__value = value
    
    @property 
    def value(self)->float:
        return self.__value
    