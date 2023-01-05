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
2023/1/5
# A RGB pwm LED cube.
### **測試中的digital模擬LEDpwm代碼**
### update : 2023/1/5

[![](https://img.shields.io/badge/CubeDrive0.2.st.ino-Debug-red)](https://github.com/samjocker/Magic_wandXLED_cube/blob/main/RGBLED-Cube%208%C2%B3/cubedrive1.5.1.one.ino)

### 目前功能:
    通過二維陣列設定led的顏色，並使用函式刷新。
### 已知問題:
    因LED刷新順序問題，順位靠後的LED工作時常過低，導致亮度不平均。

https://user-images.githubusercontent.com/34911327/210252287-098fcaef-6f39-4aea-9a2e-6753492e4f1d.mp4


### 待實現:
    1.通過序列埠通訊控制cube的顏色
    2.圖像化編輯器 方便測試、動畫製作
    3.新增對8x8的支持
    4.與magic wand建立連結
### 版本紀錄:
    增加控制單顆led顏色的函示。
