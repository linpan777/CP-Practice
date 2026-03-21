# 11005 - Cheapest Base

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=22&page=show_problem&problem=1946)

## 簡介

想像你有一台印表機，列印不同的字元需要消耗不同量的墨水（成本不同）。
題目會給定印出 `0~9` 和 `A~Z`（共 36 個字元）各自的成本。
接著給你一個十進位數字，要求你計算：**將這個數字轉換成 2 進位到 36 進位後，哪一種進位制的總列印成本最低？**

1. **核心演算法**：使用「短除法（剝洋蔥）」將十進位數字轉換為 $N$ 進位，並在過程中同步查表累加成本。
2. **多重平手處理**：如果有多個進位制的最低成本相同，必須由小到大將它們全部印出。
3. 可將所有邏輯寫在主迴圈中（V1），或將「計算成本」的邏輯獨立成函式以增加可讀性並處理數字 `0` 的特例（V2）。

<details>
<summary><head>點擊查看「短除法算成本」的核心原理</head></summary>

### 短除法（剝洋蔥）轉換進位制

我們不需要真的把轉換後的字串（例如 `"1010"` 或 `"1A"`）拼湊出來，我們只需要在每次取餘數時，順便去「查價目表」把錢加上去就好。

以十進位數字 `10`，轉成 `2` 進位為例：

1. **取餘數（找最後一位）：** `10 % 2 = 0`
   - 代表 2 進位的最後一個字元是 `0`
   - 總成本加上 `price[0]`
2. **除以基數（剝掉最後一位）：** `10 / 2 = 5`
   - 數字變成 5，準備進入下一輪
3. **取餘數：** `5 % 2 = 1`
   - 代表倒數第二個字元是 `1`
   - 總成本加上 `price[1]`
4. **除以基數：** `5 / 2 = 2`
5. **...持續循環，直到數字變成 0 為止。**

**程式碼實作：**
```cpp
int totalCost = 0;
while(number != 0) 
{
    totalCost += price[number % base]; // 取餘數，查表加錢
    number /= base;                    // 除以基數，縮小數字
}
```

### 為什麼要宣告 `numberTemp`？
在迴圈中，因為短除法會一路把數字除到變成 0，如果直接拿原本的 `number` 去除，算完 2 進位後，`number` 就歸零了，後面的 3~36 進位就沒東西可以算。
所以必須宣告一個分身 `int numberTemp = number;`，拿分身去當炮灰除到 0。

</details>


## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | The number of test cases |
| `price[37]` | Array storing the printing cost for characters '0'-'9' and 'A'-'Z' |
| `numberCase` | The number of queries within a single test case |
| `number` | The decimal number to be evaluated |
| `cost[37]` | Array storing the total printing cost for each base (from base 2 to 36) |
| `less` | Stores the minimum printing cost found across all bases |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `T` | 測試用例的總數量 |
| `price[37]` | 儲存印出字元 '0'-'9' 與 'A'-'Z' 成本的價目表陣列 |
| `numberCase` | 單一測資內，需要查詢的數字數量 |
| `number` | 老闆要求查詢（要轉換）的十進位數字 |
| `cost[37]` | 記錄該數字轉換成各個進位制（2~36）後的總列印成本 |
| `less` | 記錄在所有進位制中，最低的列印成本金額 |

</details>

### version 1 - 邏輯:
```text
1. cin >> T
2. while(T--)
3.      Read 36 integers into the price array
4.      cin >> numberCase
5.      while(numberCase--)
6.          cin >> number
7.          For base = 2 to 36:
8.              Use a temporary copy of number
9.              While copy != 0:
10.                 cost[base] += price[copy % base]
11.                 copy /= base
12.             Update minimum cost (less)
13.         For base = 2 to 36:
14.             If cost[base] == less, print base
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀取測資數量 T
2. 當 T 不為 0 時循環：
3.      讀取 36 個數字存入 price 陣列（建立價目表）
4.      讀取查詢次數 numberCase
5.      當 numberCase 不為 0 時循環：
6.          讀取要查詢的數字 number
7.          利用 for 迴圈，讓 base 從 2 跑到 36：
8.              複製一份 number 的分身
9.              當分身不為 0 時循環（短除法）：
10.                 cost[base] 加上 price[分身 % base]
11.                 分身除以 base
12.             更新歷史最低成本變數 (less)
13.         再次用 for 迴圈從 2 跑到 36：
14.             如果該進位的成本等於 less，則印出該進位制
```
</details>

### version 2 (Refactored) - 邏輯:
```text
1. Define a helper function calculateCost(num, base, price[])
2.      If num == 0, return price[0] (Handle the edge case for 0)
3.      Perform the short division while loop and return total cost
4. In main(), read inputs same as V1
5. For each query number:
6.      For base = 2 to 36:
7.          cost[base] = calculateCost(number, base, price)
8.          Update minimum cost (less)
9.      Print all bases that match the minimum cost
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 定義一個輔助函式 calculateCost(數字, 進位制, 價目表陣列)
2.      如果數字是 0，直接回傳 price[0]（修復數字 0 的極端情況）
3.      執行短除法剝洋蔥迴圈，並回傳總成本
4. 在主程式中，讀取測資的方式與 V1 相同
5. 對於每一個查詢數字：
6.      利用 for 迴圈從 2 跑到 36：
7.          呼叫函式計算成本並存入 cost[base]
8.          更新最低成本變數
9.      印出所有成本等於最低成本的進位制
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 & V2 | $O(Q \times 35 \times \log N)$ | $O(1)$ |

* 註：$Q$ 為查詢次數，$N$ 為查詢的數字大小。由於基數固定從 2 到 36（共 35 次迴圈），且每次轉換的時間取決於短除法的次數 $\approx \log_{base}(N)$，而空間只需常數大小的陣列即可。

## 版本對比

| 特性 | V1 | V2 (重構版) |
| :--- | :--- | :--- |
| 架構設計 | 巢狀迴圈（全擠在 main） | 函式抽離 (Function Extraction) |
| 數字 0 的處理 | 剛好平手過關（存在潛在 Bug） | 完美攔截並處理 `0` 的特例 |
| `number` 暫存 | 需手動宣告 `numberTemp` | 傳值呼叫 (Pass by value)，自動保護 |
| 程式碼簡潔度 | 中 | 高 |
| 易讀性 | 中 | 極高 |
| 推薦指數 | ⭐⭐⭐ | ⭐⭐⭐⭐⭐ |