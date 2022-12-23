import serial
import keyboard
import math
from matplotlib import pyplot as plt
import asyncio

ser = serial.Serial("COM5", 115200)
plt.ion()
first = True
x,y = 0,0

Long = 6    #cm

async def draw():
    global x,y,Long,value
    x = float(value[2])
    y = float(value[1])
    # if first == True:
    #     x_raw = float(value[2])
    #     y_raw = float(value[1])
    #     first = False
    # x_value = float(value[2]) - x_raw
    # y_value = float(value[1]) - y_raw
    x = Long*(math.degrees(math.asin(math.radians(x))))
    y = Long*(math.degrees(math.asin(math.radians(y))))
    print(round(x,3),round(y,3))
    plt.clf()
    plt.plot(-300,300,"o")
    plt.plot(300,-300,"o")
    plt.plot(300,300,"o")
    plt.plot(-300,-300,"o")
    plt.plot(y,-1*x,"o")
    plt.pause(0.001)
    plt.ioff()

async def Serial_read():
    global ser,value
    data = ser.readline()
    value = str(data)
    if value[2:5] == "ypr":
        value = value.split("\\t")
    else:
        print(value)
        value = [0,0,0]
        
    task = asyncio.create_task(draw())
    await task

while 1:
    if keyboard.is_pressed("b"):
        break
    asyncio.run(Serial_read())
    # try:
        # data = ser.readline()
        # value = str(data)
        # value = value.split("\\t")
        #print(value[1], value[2], value[3])
        # if first == True:
        #     x_raw = float(value[2])
        #     y_raw = float(value[1])
        #     first = False
        # x_value = float(value[2]) - x_raw
        # y_value = float(value[1]) - y_raw
        # x = Long*(math.degrees(math.asin(math.radians(x_value))))
        # y = Long*(math.degrees(math.asin(math.radians(y_value))))
        # print(round(x,3),round(y,3))
        # plt.clf()
        # plt.plot(-300,300,"o")
        # plt.plot(300,-300,"o")
        # plt.plot(300,300,"o")
        # plt.plot(-300,-300,"o")
        # plt.plot(y,-1*x,"o")
        # plt.pause(0.001)
        # plt.ioff()
    # except:
    #     print("load", end="")
    #     data = ser.readline()
    #     print(data)

ser.close()
