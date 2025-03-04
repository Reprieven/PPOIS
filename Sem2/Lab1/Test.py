import unittest
from BalanceManager import BalanceManager
from Balance import Balance
from Rate import Rate
from ElectricCar import ElectricCar
from Charger import Charger
from User import User
from Parking import Parking
from ParkingSpace import ParkingSpace
from NavigationManager import NavigationManager

class TestBalance(unittest.TestCase):
    def test_pay_check(self):
        balance = Balance(10)
        rate = Rate(5)
        BalanceManager.pay_check(balance,rate)
        self.assertEqual(balance.value,5)

    def test_top_up(self):
        balance = Balance(10)
        BalanceManager.top_up(balance,3.2)
        self.assertEqual(balance.value,13.2)

class TestCharger(unittest.TestCase):
    def test_charge(self):
        model = "qwe"
        license_plate = "1234"
        year = "2025"
        car = ElectricCar(model,year,license_plate)
        name = "Qwerty"
        phone = "+123456"
        user = User(name,phone)
        user.car = car
        Charger.ask_for_charge(user)
        self.assertEqual(user.car.battery, 100)

class TestNavigation(unittest.TestCase):
    def test_navigation(self):
        rate = Rate(5.50)
        spaces_in_row = 10
        spaces = []
        for i in range(100):
            space = ParkingSpace()
            spaces.append(space)
        parking = Parking(rate,spaces,spaces_in_row)
        forward,side = NavigationManager.ask_for_path(parking,37)
        self.assertEqual(forward,3)
        self.assertEqual(side,7)


        