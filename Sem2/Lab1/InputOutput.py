class InputProvider:
    @staticmethod
    def get_string(prompt: str) -> str:
        return input(prompt)

    @staticmethod
    def get_int(prompt: str) -> int:
        while True:
            try:
                res = int(input(prompt))
                return res
            except ValueError:
                OutputProvider.show_message("Ошибка введите целое число!")

    @staticmethod
    def get_float(prompt: str) -> float:
        while True:
            try:
                res = float(input(prompt))
                return res
            except ValueError:
                OutputProvider.show_message("Ошибка введите число!")


class OutputProvider:
    @staticmethod
    def show_message(message: str):
        print(message)
