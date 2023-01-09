# A magic wand control.
## **Version 1.5(2023/1/9 19:27)**
## **宣告 V1 版本失敗開始研究 V2 版本**
### V2版本大方向
1. 拋棄數據圖片化影像辨識，V2版本將導入ai進行數據分類
### V1版本失敗原因
1. 因本次採買加速度計較便宜無法執行抵銷重力加速度之任務造成我只使用角度數據來三角函數算出移動軌跡，但此方法不能偵測平行移動，所以在目前方法中只要平行移動就會引巷道數據精確度
2. 雖然已經將數據處理的近乎可以抵消現實中揮棒力度差距(已有演算法將他們放大至固定大小，也有拉伸算法將數據填滿畫框好進行相似度計算)但實際運用效果還是差強人意(如影片所式所得相似度分數基本不可用)
### 目前版本功能:
1. arduino讀取mpu6050數據並卡爾曼濾波取得yaw、pitch、roll三值
2. ~~可利用python讀取arduino數據並將位移數據圖像顯示出來~~
3. 延後讀取數據抵銷按按鈕時震動
4. 數據圖像點放大以利之後圖像辨識
5. 得到數據後計算漢明距離來求出加速度圖像與範本圖像之相似度
### 新增:
1. 實現數據相似度計算演算法
### 待實現:
1. ~~將python程式碼翻譯至arduino-c(因目前演算法測試階段使用python可免去編譯燒錄時間提高研發效率)~~
2. ~~實現魔仗軌跡圖像辨識，將於目前程式碼移植至esp32時再實現(因python序列阜更新率過低直接於esp32上使用原始資料效果更佳)~~
3. 新增紅外線發射器
4. 新增震動引擎，強化使用體驗
<<<<<<< HEAD
### 目前成果展示(V1.5):
[![](https://img.onl/L12P2h)](https://photos.app.goo.gl/Ge4SD9J4hyFiKFeUA)
=======
### 目前成果展示(V1.32):
[![](https://img.onl/L12P2h)](https://photos.app.goo.gl/5FmcTnXPaZoideAj7)
>>>>>>> cbbd8736ef2e8c9f87c6462dc62b0c365c947ffe

![image](https://github.com/samjocker/Magic_wandXLED_cube/blob/main/InCollage_20230107_070140917_2-modified.png)
### **測試中的digital模擬LEDpwm代碼**

### update : 2023/1/5

[![](https://img.shields.io/badge/CubeDrive.ino-1.5.1.one-green)](https://github.com/samjocker/Magic_wandXLED_cube/blob/main/RGBLED-Cube%208%C2%B3/cubedrive1.5.1.d.ino)
[![](https://img.shields.io/badge/CubeDrive.ino-Debug-red)](https://github.com/samjocker/Magic_wandXLED_cube/blob/main/RGBLED-Cube%208%C2%B3/cubedrive0.2.st.ino)


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


### 待實現:
    1.通過序列埠通訊控制cube的顏色
    2.圖像化編輯器 方便測試、動畫製作
    3.新增對8x8的支持
    4.與magic wand建立連結
### 版本紀錄:
<<<<<<< HEAD
    增加控制單顆led顏色的函式。
=======
    增加控制單顆led顏色的函式。
>>>>>>> cbbd8736ef2e8c9f87c6462dc62b0c365c947ffe
