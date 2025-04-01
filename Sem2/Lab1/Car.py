class Car():
    def __init__(self, model: str, year: int, licence_plate: str):
        self.__model = model
        self.__year = year
        self.__licence_plate = licence_plate
    
    @property 
    def model(self)->str: 
        return self.__model
    
    @property
    def year(self)->int:
        return self.__year
    
    @property
    def licence_plate(self)->str:
        return self.__licence_plate
    
    

