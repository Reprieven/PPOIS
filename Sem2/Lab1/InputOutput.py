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
        return float(input(prompt))


class OutputProvider:
    @staticmethod
    def show_message(message: str):
        print(message)
