import pickle
from ParkingUI import ParkingUI
class SerializationManager:
    @staticmethod
    def save(data, file_name: str):
        try:
            with open(file_name, "wb") as file:
                pickle.dump(data, file)
            ParkingUI.safe_state_ok(file_name)
        except Exception as e:
            ParkingUI.input_error(f"Ошибка при сохранении данных: {e}")
    
    @staticmethod
    def load(file_name: str):
        try:
            with open(file_name, "rb") as file:
                data = pickle.load(file)
            ParkingUI.load_state_ok(file_name)
            return data
        except FileNotFoundError:
            ParkingUI.load_state_no_file(file_name)
            return None
        except Exception as e:
            ParkingUI.input_error(f"Ошибка при загрузке данных: {e}")
            return None