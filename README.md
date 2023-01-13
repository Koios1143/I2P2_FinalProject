# I2P2 Final Project
https://hackmd.io/5lWOrEonSnyMAwpxtqzn0Q?view

## 基本設定
Flappy Bird
會希望有不同的 stage，先設定兩個
1. 固定間距出現的水管，每次只會出現兩個水管，且空隙大小相等
2. 同一組水管會同時上下的移動

### 遊戲狀態
1. 主畫面(**MENU**)
2. 記分板(**SCOREBOARD**)
    - Optional
3. 遊戲開始(**IN_GAME**)
    1. Stage 1
    2. Stage 2
4. 遊戲結束(**GAME_OVER**)

### 控制方法
透過***空白鍵***或是***滑鼠左鍵***控制 Bird，每次會點擊會向上移動

### 失敗條件
碰到地板或是碰到水管

### 勝利條件
無，每經過一個水管就加上一分，分數越高越好

## 物件設定

### Game Title (Title)✔️
> 遊戲標題
:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    顯示在畫面正上方
2. 記分板(**SCOREBOARD**)
    隱藏
3. 遊戲開始(**IN_GAME**)
    隱藏
4. 遊戲結束(**GAME_OVER**)
    隱藏

### IN_GAME (Buttom)✔️
> 遊戲開始按鈕

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    顯示在畫面下方左側
    ***點擊：*** 觸發遊戲開始，切換遊戲狀態到
2. 記分板(**SCOREBOARD**)
     隱藏 
3. 遊戲開始(**IN_GAME**)
    隱藏
4. 遊戲結束(**GAME_OVER**)
    隱藏

### Score (Buttom)❌
> 遊戲記分板

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    顯示在畫面下方右側
    ***點擊：*** 切換遊戲狀態到記分板
2. 記分板(**SCOREBOARD**)
    隱藏
3. 遊戲開始(**IN_GAME**)
    隱藏
3. 遊戲結束(**GAME_OVER**)
    隱藏

### Back (Buttom)❌
> 返回按鈕

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    隱藏
2. 記分板(**SCOREBOARD**)
    顯示在畫面正下方
    ***點擊：*** 切換遊戲狀態到主畫面
3. 遊戲開始(**IN_GAME**)
    隱藏
3. 遊戲結束(**GAME_OVER**)
    隱藏

### SCOREBOARD Title (title)❌
> 記分板

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    隱藏
2. 記分板(**SCOREBOARD**)
    顯示在畫面正上方
3. 遊戲開始(**IN_GAME**)
    隱藏
3. 遊戲結束(**GAME_OVER**)
    隱藏

### SCOREBOARD Background❌
> 記分板背景

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    隱藏
2. 記分板(**SCOREBOARD**)
    顯示，會顯示在主背景上方
3. 遊戲開始(**IN_GAME**)
    隱藏
3. 遊戲結束(**GAME_OVER**)
    隱藏

### Background✔️
> 一般遊戲背景

:::success
<center>遊戲狀態</center>
:::

總是顯示在畫面最下方

### Floor❌
> 地板

:::success
<center>遊戲狀態</center>
:::

總是顯示，在畫面最下方，並且在主畫面之上

### Game over (Title)❌
> 遊戲結束標題

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    隱藏
2. 記分板(**SCOREBOARD**)
    隱藏
3. 遊戲開始(**IN_GAME**)
    隱藏
3. 遊戲結束(**GAME_OVER**)
    顯示於畫面正上方

### Personal Score❌
> 個人成績

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    隱藏
2. 記分板(**SCOREBOARD**)
    隱藏
3. 遊戲開始(**IN_GAME**)
    隱藏
3. 遊戲結束(**GAME_OVER**)
    顯示於畫面中間，包含這次的成績以及過去最佳成績

### OK (Buttom)✔️
> 遊戲結束確認按鈕

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    隱藏
2. 記分板(**SCOREBOARD**)
    隱藏
3. 遊戲開始(**IN_GAME**)
    隱藏
3. 遊戲結束(**GAME_OVER**)
    顯示在畫面正下方
    ***點擊：*** 切換畫面到主畫面

### Pause (Buttom)✔️
> 遊戲暫停按鈕

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    隱藏
2. 記分板(**SCOREBOARD**)
    隱藏
3. 遊戲開始(**IN_GAME**)
    顯示在畫面左上角
    ***點擊：*** 將遊戲時間暫停
3. 遊戲結束(**GAME_OVER**)
    隱藏

### Game Score❌
> 當前遊戲分數

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    隱藏
2. 記分板(**SCOREBOARD**)
    隱藏
3. 遊戲開始(**IN_GAME**)
    顯示在畫面正上方，表示當前的分數
3. 遊戲結束(**GAME_OVER**)
    隱藏

### Pipe✔️
> 管子

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    隱藏
2. 記分板(**SCOREBOARD**)
    隱藏
3. 遊戲開始(**IN_GAME**)
    依照不同的 stage 有不同的呈現方式
    1. Stage 1
        進入 Stage 1 過 3 秒之後，每次會決定出一組管子的位置，空格大小會相同，並且間隔相同的時間再顯示下一組
    2. Stage 2
        進入 Stage 2 過 3 秒之後，每次會決定出一組管子的初始位置，並且隨時間上下移動，移動到最上方後往下，移動到最下方後往上
        每組管子的間隔距離相同。
4. 遊戲結束(**GAME_OVER**)
    維持原樣

### Bird❌
> 主角 Bird

:::success
<center>遊戲狀態</center>
:::

1. 主畫面(**MENU**)
    顯示在標題的後方
2. 記分板(**SCOREBOARD**)
    隱藏
3. 遊戲開始(**IN_GAME**)
    永遠維持在 x = width / 4 的位置
    ***空白鍵/滑鼠左鍵：*** 讓 Bird 跳躍
3. 遊戲結束(**GAME_OVER**)
    維持原樣


###### tags: `清華大學`