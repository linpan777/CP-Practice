# 11417 - GCD

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=26&page=show_problem&problem=2412)

## 簡介:
給定一個整數 `N`，要求計算所有滿足 `1 <= i < j <= N` 的數對 `(i, j)` 的最大公因數 (GCD) 總和。
1. **核心演算法**：利用「輾轉相除法」快速求取 GCD，取代傳統的暴力迴圈找因數。
2. **極致效能優化 (建表法)**：觀察雙層迴圈的規律，預先算出所有 `N` 的答案存入陣列，將每次查詢的時間複雜度降至極致的 O(1)。
3. 提供直觀暴力的 V1 寫法，以及融合建表法與遞迴 GCD 的 V2 寫法供對照。

<details>
<summary><head>點擊查看 GCD (輾轉相除法) 與 自動交換特性</head></summary>

### 輾轉相除法 (Euclidean Algorithm)
求最大公因數的最佳解法。數學原理：兩個數字的最大公因數，等於「較小的數字」和「兩數相除的餘數」的最大公因數。

**傳統寫法 (V1)：**
使用迴圈從 1 慢慢測試到 `a`，運算次數可能高達 `a` 次。
```cpp
int gcd(int a, int b) {
    int gcd = 0;
    for(int i = 1; i <= a; i++)
        if(a % i == 0 && b % i == 0) gcd = i;
    return gcd;
}
```

**極致遞迴寫法 (V2)：**
利用三元運算子 `? :` 結合遞迴，只需短短一行。
```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

### 隱藏能力：自動交換大小
在呼叫 `gcd(a, b)` 時，如果發生 `a < b`（小數在前、大數在後）的情況，**不需要手動寫 `if` 去交換它們！**
因為 `a % b` 的結果會等於 `a` 本身。
- 範例：呼叫 `gcd(12, 18)`
- 第一回合：`b` (18) 不為 0，回傳 `gcd(18, 12 % 18)`
- 因為 `12 % 18 = 12`，所以下一回合自動變成 `gcd(18, 12)`
電腦利用取餘數 `%` 的特性，在第一回合就默默完成了大小交換，這就是數學與程式結合的極致優雅！

</details>

<details>
<summary><head>點擊查看 建表法 (Precomputation) 的推導邏輯</head></summary>

### 為什麼要建表？
題目有多筆測資，如果每次輸入 `N` 都重新跑一次雙層迴圈，會造成大量重複運算。
觀察題目的雙層迴圈規律：
- 當 `N = 3`：總和為 `gcd(1,2) + gcd(1,3) + gcd(2,3)`
- 當 `N = 4`：總和為 `(N=3 的結果) + gcd(1,4) + gcd(2,4) + gcd(3,4)`

**推導公式：**
`Answer[N] = Answer[N-1] + sum( gcd(j, N) )` (其中 j 從 1 走到 N-1)

### 建表法實作
在讀取任何測資前，先用一個迴圈把 `1` 到 `500` 的答案全部算好，並存進 `answer` 陣列中。
當系統輸入 `N` 時，我們只需要 `cout << answer[N]`，查詢時間直接變成 O(1)。

</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `N` | The input integer representing the upper limit for pairs |
| `G` | <sub>Used in `V1`</sub> The sum of GCDs for a specific testcase |
| `answer[502]` | <sub>Used in `V2`</sub> An array to precompute and store the sum of GCDs for all N up to 500 |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `N` | 輸入的整數，代表數對的上限值 |
| `G` | <sub>用於 `V1`</sub> 紀錄當前測資的 GCD 總和 |
| `answer[502]` | <sub>用於 `V2`</sub> 建表用陣列，預先儲存 1 到 500 所有的答案 |

</details>

### version 1 - 邏輯:
```text
1. Define a brute-force gcd(a, b) function
2. While reading N (and handling N == 0 break condition):
3.      Initialize G = 0
4.      For i from 1 to N-1:
5.          For j from i+1 to N:
6.              G += gcd(i, j)
7.      Print G
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 實作一個暴力解的 gcd(a, b) 函式 (使用 for 迴圈逐一測試)
2. 當成功讀取 N (並處理 N == 0 的結束條件) 時：
3.      初始化總和 G = 0
4.      外迴圈 i 從 1 跑到 N-1：
5.          內迴圈 j 從 i+1 跑到 N：
6.              G 加上 gcd(i, j) 的結果
7.      輸出 G
```
</details>

### version 2 - 邏輯:
```text
1. Define an optimized recursive gcd(a, b) using Euclidean algorithm
2. Precompute the answers:
3.      Initialize answer[502] array with 0
4.      For i from 2 to 501:
5.          answer[i] = answer[i - 1]
6.          For j from 1 to i-1:
7.              answer[i] += gcd(j, i)
8. While reading N (and N != 0):
9.      Print answer[N] directly in O(1) time
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 實作極致優化的 gcd(a, b) 函式 (使用輾轉相除法與三元運算子)
2. 執行建表 (Precomputation)：
3.      初始化 answer 陣列
4.      外迴圈 i 從 2 跑到 501：
5.          繼承前一個數字的答案：answer[i] = answer[i - 1]
6.          內迴圈 j 從 1 跑到 i-1：
7.              累加新產生的 GCD：answer[i] += gcd(j, i)
8. 當成功讀取 N (且 N != 0) 時：
9.      直接輸出陣列中對應的答案 answer[N]
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 | $O(T \times N^3)$ | $O(1)$ |
| V2 | Precomputation: $O(N^2 \log N)$<br>Per Query: $O(1)$ | $O(N)$ (Size 502 array) |

* 註：V1 的 GCD 函數使用暴力迴圈，時間為 $O(N)$，配合雙層迴圈導致單筆測資達到 $O(N^3)$。V2 使用輾轉相除法，GCD 耗時 $O(\log N)$，且採用建表法，所有測資查詢只需 $O(1)$。

## 版本對比

| 特性 | V1 (暴力法) | V2 (大師級最佳化) |
| :--- | :--- | :--- |
| GCD 實作 | 迴圈暴力測試因數 | 遞迴 + 輾轉相除法 |
| 處理多筆測資方式 | 每次重新跑雙層迴圈計算 | 查表法 (直接調用已算好的陣列) |
| 執行效率 | 極低 (可能導致 TLE) | 極高 |
| 程式碼簡潔度 | 普通 | 極高 |
| 推薦指數 | ⭐ | ⭐⭐⭐⭐⭐ |