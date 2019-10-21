import serial
import time
import sys

# Modify these at will
port = 'COM5'
baud = 115200
toCrack = 'e74aa0f06f344e47e97a975e22c51cef'

# File definitions
file = open("list.txt", "r")
if file.mode != "r":
    print("Unable to open list.txt in current directory!")
    sys.exit()
lines = file.readlines()

ser = serial.Serial(port, baud, timeout=1)
time.sleep(1)
ser.flushInput()

# Extra input Sanitation
for line in lines:
    line = line.strip()

# The main attraction
for line in lines:
    ser.write(line.encode())
    ser.flushOutput()
    while ser.inWaiting() < 32:
        continue
    hashVal = ser.read_until(size=32)
    if hashVal.decode('ascii') == toCrack:
        print("Found! -- " + line)
        ser.close()
        sys.exit()
    ser.flushInput()
ser.close()
sys.exit()
