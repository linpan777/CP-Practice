# 10056 - What is the Probability?

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=997)

## 簡介:
這是一個回合制的機率遊戲。有 $N$ 個玩家輪流擲骰子（或進行某項判定），每次成功的機率為 $p$。誰先成功，誰就獲勝並結束遊戲。
給定玩家總數 $N$、單次成功機率 $p$、以及我們想預測的玩家序號 $I$，求該玩家（第 $I$ 個玩家）獲勝的總機率。
最後輸出必須四捨五入到小數點後 4 位。

<details>
<summary><head>點擊查看核心數學公式推導：無窮等比級數</head></summary>

### 為什麼這是一個無窮等比級數？
因為遊戲可能會無限循環下去，玩家 $I$ 可以在第 1 輪贏，也可能在第 2 輪、第 3 輪... 甚至第無限輪贏。我們必須把所有他獲勝的機率加起來。

令成功的機率為 $p$，失敗的機率為 $q = 1 - p$。
* **第 1 輪獲勝的機率**：他前面的 $I - 1$ 個人都必須失敗，然後輪到他成功。
    機率為：$p \cdot q^{I-1}$
* **第 2 輪獲勝的機率**：第 1 輪所有人 ($N$ 個) 都失敗，接著第 2 輪前面的 $I - 1$ 個人也失敗，然後他成功。
    機率為：$p \cdot q^{I-1} \cdot q^N$
* **第 $k$ 輪獲勝的機率**：前面 $k-1$ 輪全滅，然後輪到他贏。
    機率為：$p \cdot q^{I-1} \cdot (q^N)^{k-1}$

### 總和公式
將所有輪次的機率相加，會形成一個首項為 $a = p \cdot q^{I-1}$，公比為 $r = q^N$ 的無窮等比級數：
$$S = a + ar + ar^2 + \dots$$
根據高中數學的無窮等比級數求和公式 $S = \frac{a}{1 - r}$，這題的終極核心公式為：
$$Probability = \frac{p \cdot q^{I-1}}{1 - q^N}$$

</details>

<details>
<summary><head>點擊查看除以零的致命陷阱 (p = 0)</head></summary>

### ⚠️ 極端測資陷阱：當機率為 0 時
在套用公式 $Probability = \frac{p \cdot q^{I-1}}{1 - q^N}$ 時，必須特別注意分母！
如果輸入的成功機率 $p = 0$，那麼失敗的機率 $q = 1 - 0 = 1$。
此時分母的 $1 - q^N$ 會變成 $1 - 1^N = 0$！
在 C++ 中，浮點數除以 0 會產生 `NaN` (Not a Number) 或造成程式崩潰。因此在程式碼中必須加入判斷式 `if (p != 0)` 來攔截這個情況，若 $p = 0$ 則直接輸出 $0.0000$。

</details>


## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | The number of test cases |
| `people` | Total number of players in the game (denoted as $N$ in the formula) |
| `p` | The probability of success in a single throw |
| `q` | The probability of failure ($1 - p$) |
| `x` | The serial number of the target player (denoted as $I$ in the formula) |
| `ans` | The calculated final winning probability for player $x$ |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `T` | 測試資料的總筆數 |
| `people` | 參與遊戲的總人數 (公式中的 $N$) |
| `p` | 單次擲骰子成功的機率 |
| `q` | 單次擲骰子失敗的機率 ($1 - p$) |
| `x` | 目標玩家的順序序號 (公式中的 $I$) |
| `ans` | 計算出該玩家最終獲勝的總機率 |

</details>

### version 1 - 邏輯:
```text
1. Read the number of test cases T
2. Loop T times:
3.      Read people, p, x
4.      Calculate q = 1 - p
5.      Initialize ans = 0
6.      If p is not equal to 0:
7.          ans = (pow(q, x - 1) * p) / (1 - pow(q, people))
8.      Print ans formatted to 4 decimal places using setprecision(4) and fixed
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀取測資筆數 T
2. 執行 T 次迴圈處理每組測資：
3.      讀入總人數 people、成功機率 p、目標玩家序號 x
4.      計算失敗機率 q = 1 - p
5.      初始化最終答案 ans 為 0
6.      如果 p 不等於 0 (避開除以零的陷阱):
7.          套用無窮等比級數公式：ans = (q 的 x-1 次方 * p) / (1 - q 的 people 次方)
8.      利用 setprecision(4) 與 fixed 將 ans 格式化為小數點後 4 位並輸出
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 | $O(1)$ per test case | $O(1)$ |

* 註：此題完全依賴數學公式推導，計算過程僅涉及常數次數的浮點數次方運算 `pow()`，因此時間複雜度與空間複雜度皆為 $O(1)$，效能極佳。

## 版本總結

| 特性 | V1 (無窮等比級數公式版) |
| :--- | :--- |
| 核心演算法 | 數學 (無窮等比級數求和) |
| 例外處理 | 使用 `if(p != 0)` 完美避開 $p=0$ 時分母為 0 的陷阱 |
| 格式化輸出 | 引入 `<iomanip>` 並使用 `fixed` 與 `setprecision(4)` 處理小數點位數 |
| 效能表現 | 最佳化常數時間 $O(1)$ |