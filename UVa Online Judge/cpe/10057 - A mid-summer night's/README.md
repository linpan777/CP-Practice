# 10057 - A mid-summer night's dream.

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=998)

## 簡介:
給定一個包含 $n$ 個整數的數列，找出一個整數 $A$，使得數列中所有數字與 $A$ 的絕對差值總和最小。
根據數學性質，這個點就是該數列的**中位數**。
針對每組測資，必須輸出三個數字，以空白隔開：
1. **最小的可能中位數**：若有兩個中位數，取較小的那一個（即「左中位數」）。
2. **原數列中，符合中位數條件的數字數量**：原數列中有多少個數字恰好等於可能的 $A$ 值。
3. **可能的整數 $A$ 有幾種**：在所有能讓絕對差值總和最小的範圍內，包含幾個相異的整數。

<details>
<summary><head>點擊查看數學原理：為什麼是中位數？</head></summary>

### 絕對值距離總和的極值
如果我們在數線上尋找一個點 $A$，讓所有給定點到 $A$ 的距離總和最小，直覺可能會想找「平均值」。但實際上，**中位數**才是正確答案。

想像數線上有最左邊的點 $L$ 和最右邊的點 $R$。只要點 $A$ 落在 $L$ 和 $R$ 之間，它到這兩個點的距離和永遠等於 $R - L$（固定常數）。如果 $A$ 跑到 $L$ 左邊或 $R$ 右邊，距離和就會變大。
透過不斷把最外圍的兩個點配對並向內縮，最後的交集就會落在正中間的數字（奇數個時）或正中間的區間（偶數個時），也就是**中位數**。

</details>

<details>
<summary><head>點擊查看奇偶數的處理差異</head></summary>

### 奇數個與偶數個的情況探討
因為陣列排序後，中位數的位置會根據 $n$ 是奇數還是偶數而有所不同：

1. **當 $n$ 是奇數時**：
   - 最中間的數字只有一個，這個數就是唯一的中位數。
   - 輸出 1：該中位數。
   - 輸出 2：陣列中與該中位數數值相同的元素個數。
   - 輸出 3：因為中位數只有一個，所以可能的整數 $A$ 只有 **1** 種。

2. **當 $n$ 是偶數時**：
   - 最中間的數字有兩個（我們稱之為 `mid_left` 和 `mid_right`）。只要 $A$ 落在 `[mid_left, mid_right]` 這個閉區間內的所有整數，都能讓距離總和最小。
   - 輸出 1：題目要求最小的，所以取左中位數 `mid_left`。
   - 輸出 2：陣列中等於 `mid_left` 或等於 `mid_right` 的元素個數（因為原本的整數只會出現在邊界上）。
   - 輸出 3：這個區間內包含的整數總數，計算公式為 `mid_right - mid_left + 1`。

</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `n` | The number of integers in the input sequence |
| `number` | An array used to store the sequence of input integers |
| `secondOutput` | A counter to track how many numbers in the input match the valid median values |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `n` | 該筆測資包含的數字總數 |
| `number` | 用來儲存輸入數字序列的陣列 |
| `secondOutput` | 計數器，用來統計原數列中有多少個數字恰好等於找出的中位數 |

</details>

### version 1 - 邏輯:
```text
1. while(cin >> n)
2.      number[n] ← 讀入 n 個整數
3.      sort(number, number + n)
4.      
5.      if n % 2 == 1:                    // n is odd
6.          cout median ← number[n/2 + 1]      // unique median (middle element)
7.          cnt ← count(secondoutput)           // occurrences of median in array
8.          output:  cnt 1          // 1 integer minimizes sum of differences
9.      else:                              // n is even
10.         cout mid_left ← number[n/2]        // left median
11.         mid_right ← number[n/2 + 1]   // right median
12.         cnt ← count(mid_left) + count(mid_right)  // boundary values occur times
13.         output: mid_left cnt (mid_right - mid_left + 1)  // all integers in range [mid_left, mid_right]
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. while(cin >> n)                           // 持續讀入測資
2.      number[n] ← 讀入 n 個整數
3.      sort(number, number + n)             // 由小到大排序
4.      
5.      if n % 2 == 1:                       // n 是奇數
6.          輸出median ← number[n/2 + 1]     // 唯一中位數（正中間元素）
7.          cnt ← 統計 median 的出現次數
8.          輸出: cnt 1               // 只有 1 個整數能使差值總和最小
9.      else:                                // n 是偶數
10.         輸出mid_left ← number[n/2]           // 左中位數
11.         mid_right ← number[n/2 + 1]      // 右中位數
12.         cnt ← mid_left 的出現次數 + mid_right 的出現次數
13.         輸出：mid_left cnt (mid_right - mid_left + 1)  // [mid_left, mid_right] 中所有整數
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 | $O(N \log N)$ per test case | $O(N)$ or $O(Max\_N)$ |

* 註：$N$ 為輸入序列的長度。時間複雜度的瓶頸在於 `std::sort` 排序陣列，需要 $O(N \log N)$。統計次數僅需走訪一次陣列為 $O(N)$。空間複雜度取決於儲存序列的陣列大小。

## 版本總結

| 特性 | V1 (排序 + 中位數分析) |
| :--- | :--- |
| 資料結構 | 一維陣列 (`int number[]`) |
| 核心演算法 | 數學 (絕對差總和與中位數定理) |
| 排序方式 | 內建的 `std::sort` |
| 記憶體使用 | 較高 (需儲存整組測資) |
| 邏輯複雜度 | 直觀，只需處理好奇偶數的區間判斷 |