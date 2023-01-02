import time
import math
import numpy as np
import asyncio
import keyboard
import serial
from matplotlib import pyplot as plt
import cv2

ser = serial.Serial("COM5", 115200)
plt.ion()
first = True
x,y = 0,0
coordinate = [[(0,0)]]
button_state = True
button_time = 0

Long = 0.7 
sl = 32 #picture side length
point_size = 3  #px

x_max,x_min,y_max,y_min = 0,sl,0,sl
coordinate = []

async def show_picture(coordinate):
    global x_max,x_min,y_max,y_min
    picture = [255 for _ in range(sl*sl)]
    picture = np.resize(picture,(sl,sl,3))
    x_mid = (x_max+x_min)/2
    y_mid = (y_max+y_min)/2
    x_gap = 0-x_mid
    y_gap = 0-y_mid
    x_size = sl/(((x_max+x_gap)))
    y_size = sl/(((y_max+y_gap)))
    print(x_max,x_gap,x_size)
    for c in coordinate:
        if c[0] <= sl and c[1] <= sl and c[0] >= sl*-1 and c[1] >= sl*-1:
            cX = int(((c[0]+x_gap))*x_size/2+sl/2-point_size/2)
            cY = int(((c[1]+y_gap))*y_size/2+sl/2-point_size/2)
            x_num = range((point_size-int(point_size/2+0.5))*-1,int(point_size/2)+1)
            y_num = x_num
            for X in x_num:
                for Y in y_num:
                    if cX+X < sl and cX+X >= 0:
                        if cY+Y < sl and cY+Y >= 0:
                            picture[cX+X][cY+Y] = [0,0,0]
    coordinate = []
    print(picture)
    cv2.imwrite('picture.jpg',picture)
    s = cv2.imread('picture.jpg')
    s = cv2.resize(s,(500,500))
    cv2.imshow('img',s)
    cv2.waitKey(0)

async def draw():
    global x,y,Long,value,coordinate,button_state,picture,x_max,x_min,y_max,y_min,button_time
    x = float(value[2])
    y = float(value[1])
    x = Long*(math.degrees(math.asin(math.radians(x))))
    y = Long*(math.degrees(math.asin(math.radians(y))))
    if value[4][0] == "p" and button_state == True:
        button_time = time.time()
        start_draw = False
        button_state = False
        coordinate = []
    elif value[4][0] == "s" and button_state == False:
        start_draw = True
        button_state = True
    else:
        start_draw = False
    now_time = time.time()
    if now_time - button_time >= 0.2:
        coordinate.append((x,y))
        if x > x_max:
            x_max = x
        elif x < x_min:
            x_min = x
        else:
            x_max,x_min = x_max,x_min
        if y > y_max:
            y_max = y
        elif y < y_min:
            y_min = y
        else:
            y_max,y_min = y_max,y_min
    # coordinate.append((x,y))
    if start_draw == True:
        taskP = asyncio.create_task(show_picture(coordinate))
        await taskP
    print(round(x,3),round(y,3))
    plt.clf()
    plt.plot(sl*-1,sl,"o")
    plt.plot(sl,sl*-1,"o")
    plt.plot(sl,sl,"o")
    plt.plot(sl*-1,sl*-1,"o")
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
        value = [0,0,0,0,"aaa"]
        
    task = asyncio.create_task(draw())
    await task

while 1:
    if keyboard.is_pressed("b"):
        break
    asyncio.run(Serial_read())

ser.close()
