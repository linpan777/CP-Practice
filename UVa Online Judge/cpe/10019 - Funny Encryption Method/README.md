# 10019 - Funny Encryption Method

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=960)

## 簡介:
給定一個十進位數字 $M$，我們需要計算兩種加密方法的結果：
1. **$b_1$**：將 $M$ 視為十進位，轉成二進位後，計算有幾個 `1`。
2. **$b_2$**：將 $M$ 的「字面數字」直接視為十六進位（例如輸入 265，視為 $265_{16}$），轉成二進位後，計算有幾個 `1`。

<details>
<summary><head>點擊查看 V1 的陷阱：為什麼 pow() 算整數很危險？</head></summary>

### 浮點數精度誤差
`<cmath>` 裡的 `pow()` 是設計給**浮點數 (double)** 用的。浮點數在電腦底層運算時會產生精度誤差（例如 `pow(10, 2)` 可能會被算出 99.99999）。當這個結果被強制轉型存入 `int` 時，小數點會被無條件捨去，變成 99，導致致命的計算錯誤。
**解法**：在純整數題型中，應使用迴圈自乘（如 `base *= 16`）來取代 `pow()`。

</details>

<details>
<summary><head>點擊查看 V2 的優化核心：十六進位轉換捷徑與 popcount</head></summary>

### 十六進位與二進位的直觀對應 (Hex to Binary)
因為 $16 = 2^4$，十六進位的一個位數（0~15）剛好完美對應二進位的 4 個 bits。
這意味著，我們完全**不需要**把十六進位轉回真實的十進位數字。只要把輸入數字 $M$ 的每一個位數（如 2、6、5）拆下來，**分別轉成二進位並計算 '1' 的數量加總**，結果就會等於整串數字的 '1' 數量！

### C++ 內建算 bit 神器：`__builtin_popcount()`
在計算二進位有幾個 `1` 時，除了慢慢 `% 2` 與 `/ 2`，C++ 提供了編譯器內建函式 `__builtin_popcount(x)`。它會直接呼叫 CPU 內部的硬體指令 (POPCNT)，瞬間算出答案，時間複雜度為常數級別的 $O(1)$！

</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | The number of test cases |
| `M` | The input integer to be processed |
| `b1` | Number of '1's when M is treated as decimal |
| `b2` | Number of '1's when M is treated as hexadecimal |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `T` | 測試資料的總筆數 |
| `M` | 輸入的目標數字 |
| `b1` | $M$ 轉二進位後 '1' 的數量 |
| `b2` | 把 $M$ 當作十六進位轉二進位後 '1' 的數量 |

</details>

### version 1 - 邏輯 (直觀暴力解):
```text
1. read T
2. while (T-- > 0):
3.     read M
4.     b1 ← binary(M)          // 計算 M 轉二進位的 1 數量
5.     b2 ← binary(hex(M))     // 先將 M 視為十六進位轉成十進位數值，再算二進位 1 數量
6.     output: b1 b2
7.
8. function binary(M):
9.     count ← 0
10.    while (M != 0):
11.        if M % 2 == 1: count++
12.        M /= 2
13.    return count
14.
15. function hex(M):
16.    dec ← 0, i ← 0
17.    while (M != 0):
18.        dec += (M % 10) * pow(16, i++)  // 危險：使用 pow 算整數
19.        M /= 10
20.    return dec
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀取測資筆數 T
2. 當 (T-- > 0):
3.     讀取數字 M
4.     b1 ← binary(M)          // 呼叫 binary 算出十進位 M 轉二進位有幾個 1
5.     b2 ← binary(hex(M))     // 呼叫 hex 先把 M 轉成真正的十進位值，再丟給 binary 算
6.     輸出: b1 b2
7.
8. 函式 binary(M):
9.     count ← 0
10.    當 (M != 0):
11.        如果 M 除以 2 餘數為 1: count++
12.        M 除以 2 (向右移位)
13.    回傳 count
14.
15. 函式 hex(M):
16.    dec ← 0, i ← 0
17.    當 (M != 0):
18.        取最後一位數字乘上 16 的 i 次方 (使用 pow)，加入 dec 中
19.        M 除以 10 (消去最後一位)
20.    回傳 dec (真實的數值)
```
</details>

### version 2 - 邏輯 (硬體指令與位數拆解優化解):
```text
1. read T
2. while (T-- > 0):
3.     read M
4.     b1 ← __builtin_popcount(M)   // O(1) 硬體指令直出
5.     b2 ← 0
6.     while (M != 0):              // 捷徑：獨立拆解每個位數
7.         b2 += __builtin_popcount(M % 10) 
8.         M /= 10
9.     output: b1 b2
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀取測資筆數 T
2. 當 (T-- > 0):
3.     讀取數字 M
4.     b1 ← __builtin_popcount(M)   // 直接利用內建函式算出 M 的 bit 1 數量
5.     b2 ← 0
6.     當 (M != 0):                 // 捷徑：將數字當作 Hex，一顆一顆拔下來算
7.         將 (M % 10) 丟入 __builtin_popcount() 算出該位數的 1 數量，加總進 b2
8.         M 除以 10 (消去最後一位)
9.     輸出: b1 b2
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 | $O(\log_{10} M + \log_2 M)$ per test case | $O(1)$ |
| V2 | $O(\log_{10} M)$ per test case | $O(1)$ |

* 註：$M$ 為輸入的數字。V1 需要先花時間轉成十進位，再花 $O(\log_2 M)$ 的時間不斷除以 2 來算二進位。V2 使用 `__builtin_popcount` 為 $O(1)$ 常數時間，迴圈只取決於數字有幾位（$\log_{10} M$），效能達到極致。

## 版本總結

| 特性 | V1 (暴力解) | V2 (最佳化) |
| :--- | :--- | :--- |
| `b1` 算法 | 手工寫迴圈 `% 2` 與 `/ 2` | `__builtin_popcount(M)` 內建神招 |
| `b2` 算法 | 先轉回真實十進位值，再轉二進位 | 將位數拆成個體，逐一算 popcount 累加 |
| 風險/效能 | 有 `pow()` 浮點誤差風險，迴圈次數多 | 全整數運算無誤差，極致精簡 |