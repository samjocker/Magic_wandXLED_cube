# A magic wond control.
## **Version 1.3**
### 目前版本功能:
1. arduino讀取mpu6050數據並卡爾曼濾波取得yaw、pitch、roll三值
2. 可利用python讀取arduino數據並將位移數據圖像顯示出來
### 修復: 
1. V1.0時python讀取序列阜數據卡在暫存區延遲過高問題(優化至10hz讀取率)
### 新增:
1. 數據圖像顯示
# A RGB pwm LED tube.
### **測試中的digital模擬LEDpwm代碼**
### 2022/12/26
[![](https://img.shields.io/badge/RGBLED Cube 8³-note-red)]([https://github.com/samjocker/Magic_wondXLED_tube/blob/main/RGBLED-Cube%208%C2%B3/CubeDrive0.1.pt.1.ino](https://github.com/samjocker/Magic_wondXLED_tube/tree/main/RGBLED-Cube%208%C2%B3)
[![](https://img.shields.io/badge/CubeDrive0.1.pt.01.ino-Debug-red)](https://github.com/samjocker/Magic_wondXLED_tube/blob/main/RGBLED-Cube%208%C2%B3/CubeDrive0.1.pt.1.ino)

### 版本紀錄:
    利用二進位減少LED每禎的寫入次數
    >>函式led_pwm()
### 預計效果:
    由原255次刷新改進為8次刷新，減少每禎消耗時間以提升整體刷新率。
