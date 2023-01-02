# A magic wand control.
## **Version 1.32(2023/1/2 10:27)**
### 目前版本功能:
1. arduino讀取mpu6050數據並卡爾曼濾波取得yaw、pitch、roll三值
2. 可利用python讀取arduino數據並將位移數據圖像顯示出來
3. 延後讀取數據抵銷按按鈕時震動
4. 數據圖像點放大以利之後圖像辨識
### 修復: 
1. V1.0時python讀取序列阜數據卡在暫存區延遲過高問題(優化至10hz讀取率)
### 新增:
1. 數據圖像顯示
### 待實現:
1. 將python程式碼翻譯至arduino-c(因目前演算法測試階段使用python可免去編譯燒錄時間提高研發效率)
2. 實現魔仗軌跡圖像辨識，將於目前程式碼移植至esp32時再實現(因python序列阜更新率過低直接於esp32
上使用原始資料效果更佳)
3. 新增紅外線發射器
4. 新增震動引擎，強化使用體驗
### 目前成果展示(V1.32):
[![](https://img.onl/L12P2h)](https://photos.app.goo.gl/5FmcTnXPaZoideAj7)
# A RGB pwm LED cube.
### **測試中的digital模擬LEDpwm代碼**
### updat : 2022/12/26
[![](https://img.shields.io/badge/RGBLEDCube3-note-green)](https://github.com/samjocker/Magic_wondXLED_tube/tree/main/RGBLED-Cube%208%C2%B3)
[![](https://img.shields.io/badge/CubeDrive0.1.pt.01.ino-Debug-red)](https://github.com/samjocker/Magic_wondXLED_tube/blob/main/RGBLED-Cube%208%C2%B3/CubeDrive0.1.pt.1.ino)

### 版本紀錄:
    利用二進位減少LED每禎的寫入次數
    >>函式led_pwm()
### 預計效果:
    由原255次刷新改進為8次刷新，減少每禎消耗時間以提升整體刷新率。