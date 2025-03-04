from Balance import Balance
from Rate import Rate
class BalanceManager():
    @staticmethod
    def pay_check(balance: Balance, rate: Rate):
        if balance.value < rate.value: 
            return False
        balance.value-=rate.value
        return True
    
    @staticmethod 
    def top_up(balance: Balance, top_up_value: float):
        if top_up_value < 1:
            return False
        balance.value+=top_up_value
        return True