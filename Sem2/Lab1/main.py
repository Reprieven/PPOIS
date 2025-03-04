from Interface import ParkingFSM
from Rate import Rate
from ParkingSpace import ParkingSpace

rate = Rate(5.50)
spaces_in_row = 10
spaces = []
for i in range(100):
    space = ParkingSpace()
    spaces.append(space)
fsm = ParkingFSM(rate,spaces,spaces_in_row)
fsm.run()
