# 105 - The Skyline Problem

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=41)

## 簡介:
給定多棟建築物的左邊界、高度與右邊界，要求計算並輸出整座城市重疊後的天際線 (Skyline) 輪廓轉折點。
1. **核心演算法 (空間換取時間)**：放棄處理複雜的二維矩形交集，直接開一個一維大陣列模擬「地平線」，將複雜度降維打擊。
2. **區間覆蓋與取最大值**：將每棟建築物的影響範圍 `[L, R)` 逐一填入陣列，並取最大值 `max(原本高度, 新大樓高度)`，完美解決大樓互相遮擋的問題。
3. **狀態追蹤 (掃描線)**：最後從左到右掃描陣列，利用「當前高度」與「下一格高度」的**差值 (變化點)** 來捕捉天際線的轉彎處。

<details>
<summary><head>點擊查看 為什麼不用標準「差分陣列」？</head></summary>

### 區間覆蓋 vs 標準差分
在標準的差分陣列 (Difference Array) 中，我們處理的是「數值的累加/抵銷」，因此只需要在起點 `+H`、終點 `-H`。
但在這題中，大樓的高度是**「遮擋 (取 Max)」**而非「疊加」。高度遮擋無法簡單地被抵銷 (你移除了最高的樓，無法輕易得知第二高的樓是多少)。

**暴力但最穩定的極致解法：**
因為本題的座標範圍極小 (最大只到 10,000)，直接使用 `for` 迴圈將區間內的地平線一格一格更新為最大值：
```cpp
for (int i{ L }; i < R; i++) builds[i] = max(builds[i], H);
```
這在時間複雜度上完全可以秒殺測資，且邏輯最不容易出錯！
</details>

<details>
<summary><head>點擊查看 EOF 讀取 與 致命的輸出格式 (PE/WA 防禦)</head></summary>

### EOF (End of File) 讀取技巧
這題沒有給定測資數量，也沒有結束條件標記 (如 `0 0 0`)。必須使用 `while` 迴圈包覆 `cin`：
```cpp
while (cin >> L >> H >> R) { ... }
```
當系統測資給完時，`cin` 會回傳 `false`，程式便會自動跳出迴圈進入最後的掃描結算階段。

### 完美防禦 Presentation Error (PE)
UVa 系統對空白與換行極度嚴格：
1. **行末多餘空白**：使用 `bool first = true` 旗標來控制，確保輸出格式嚴格遵守 `數字 空白 數字 空白 數字`，且結尾沒有多餘的 ` `。
2. **結尾換行**：程式結束前必須加上 `cout << '\n';`。
</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `L, H, R` | 讀入的單棟建築物：左座標 (Left)、高度 (Height)、右座標 (Right) |
| `maxR` | 紀錄所有大樓中最遠的右邊界，用以縮減最後掃描陣列的時間 |
| `builds[10001]` | 模擬地平線的陣列，`builds[i]` 儲存座標 `i` 到 `i+1` 之間的最高高度 |
| `currentHeigh` | 掃描線的狀態追蹤變數，紀錄「目前的天際線高度」，用來捕捉變化瞬間 |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `L, H, R` | 讀入的單棟建築物：左座標 (Left)、高度 (Height)、右座標 (Right) |
| `maxR` | 紀錄所有大樓中最遠的右邊界，用以縮減最後掃描陣列的時間 |
| `builds[10001]` | 模擬地平線的陣列，`builds[i]` 儲存座標 `i` 到 `i+1` 之間的最高高度 |
| `currentHeigh` | 掃描線的狀態追蹤變數，紀錄「目前的天際線高度」，用來捕捉變化瞬間 |

</details>

### 邏輯流程:
```text
1. 初始化地平線陣列 builds 為全 0，並宣告 maxR = 0 紀錄最右邊界。
2. While 不斷讀取 L, H, R 直到 EOF (End of File)：
3.      更新全域的最遠右邊界 maxR = max(maxR, R)。
4.      For i 從 L 走到 R-1 (半開區間)：
5.          更新該格高度 builds[i] = max(builds[i], H)。
6. 結束讀取，準備掃描輸出。初始化 currentHeigh = 0，first = true。
7. For i 從 0 走到 maxR：
8.      如果 builds[i] != currentHeigh (偵測到高度變化 / 天際線轉折)：
9.          控制空白格式後，輸出 座標 i 以及 新高度 builds[i]。
10.         更新狀態：currentHeigh = builds[i]。
11. 輸出結尾換行符號。
```

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| 掃描線陣列法 | $O(N \times W)$ | $O(W)$ |

* 註：$N$ 為測資的大樓數量，$W$ 為大樓的最大座標寬度 (常數 10000)。由於 $W$ 極小，此解法實際執行速度極快，且避免了複雜的樹狀結構實作。