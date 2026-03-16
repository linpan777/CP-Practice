# UVa 10038 - Jolly Jumpers

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979)

## Introduction:
The core of this problem is to determine if the absolute differences between successive elements in a sequence of $n$ numbers take on all values from $1$ through $n-1$
1. Achieve this by calculating the differences and marking them in a boolean array. A critical trap in this problem is input stream management, specifically handling the edge case where $n = 1$.

<details>
<summary><head>點擊查看中文版</head></summary>

核心是判斷一個包含 $n$ 個數字的序列中，相鄰兩個元素的絕對差值是否剛好涵蓋了 $1$ 到 $n-1$ 的所有數字
1. 透過計算差值並記錄在bool array來解題
> [!NOTE]
> 陷阱： 輸入流的讀取節奏」，特別是在處理 $n = 1$ 的極端情況

<details>
<summary><head>點擊查看演算法與除錯詳情</head></summary>

## core logic：讀取節奏與避免越界 (Runtime Error)
這題的 V1 寫法會導致 Runtime Error (RE)，而 V2 則順利 Accepted (AC)，原因在於**應對極端值 $n = 1$ 的讀取方式**
如果沒有確保 $n \ge 2$ 就強行讀取兩個數字，會把下一筆測資的資料吸過來，導致輸入流徹底錯亂，進而產生極大的差值引發陣列越界

## 實際演練 (Dry Run) 致命錯誤分析：
假設有兩筆測資：
`1 5` (第一筆：n=1，陣列只有數字5)
`4 1 4 2 3` (第二筆：n=4)

**V1 (RE 寫法): 強制提前讀取**
1. 讀取 $n = 1$。
2. 執行 `cin >> first >> second`。`first` 拿到 `5`。
3. 因為第一筆測資結束了，`second` 會直接把第二筆測資的 `4` 吸走！
4. 測資錯位，下一輪讀取 $n$ 時會讀到 `1`，後續差值計算出錯，導致 `number[abs(first - second)]` 存取到超出 3000 的索引，發生 Runtime Error。

**V2 (AC 寫法): 依照 n 的大小精準讀取**
1. 讀取 $n = 1$。
2. 執行 `cin >> first`，只拿一個 `5`。
3. 迴圈 `for (int i{ 1 }; i < n; i++)` 因為 $i < 1$ 不成立，直接跳過。
4. 測資乾淨無錯位，順利輸出 Jolly，接著精準讀取下一筆的 $n = 4$。
</details>
</details>

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `n` | The length of the sequence |
| `first`, `second` | Consecutive elements used to calculate the absolute difference |
| `number` | The boolean array acting as a checklist for the differences (size 3000) |
| `jolly` | A boolean flag indicating whether the sequence meets the criteria |

<details>
<summary><head>點擊查看中文版</head></summary>

| variable | meaning |
| :--- | :--- |
| `n` | 序列的長度 |
| `first`, `second` | 用於計算絕對差值的相鄰元素 |
| `number` | 作為差值檢查表的布林陣列 (大小設定為 3000 涵蓋測資範圍) |
| `jolly` | 標記該序列是否為 Jolly Jumper 的布林變數 |
</details>

### version 1 - 邏輯 (Runtime Error - Input Misalignment):
> 1. Read the length n.
> 2. Force read first and second sequentially. // DANGER: Fails if n = 1.
> 3. Calculate difference and mark number[abs(first - second)] as true.
> 4. for i = 1 to n - 2
> 5.      first = second, read new second, mark difference.
> 6. Verify if all values from 1 to n - 1 are marked true.

<details>
<summary><head>點擊查看中文版</head></summary>

> 1. 讀取長度 n。
> 2. 強制讀取 first 和 second。 // 危險：當 n = 1 時會吃掉下一筆測資。
> 3. 計算差值並將 number[abs(first - second)] 設為 true。
> 4. 迴圈讀取剩下的元素 (i 從 1 到 n - 2)。
> 5.      將 second 給 first，讀取新的 second，並標記差值。
> 6. 檢查陣列中 1 到 n - 1 是否都被標記為 true。

</details>

### version 2 - 邏輯 (Accepted - Safe Reading):
> 1. Read the length n.
> 2. Read ONLY the first element. // SAFE
> 3. for i = 1 to n - 1
> 4.      Read second element.
> 5.      Mark number[abs(first - second)] as true.
> 6.      first = second // Move forward for the next iteration
> 7. Verify if all values from 1 to n - 1 are marked true.

<details>
<summary><head>點擊查看中文版</head></summary>

> 1. 讀取長度 n。
> 2. 僅讀取 first 元素。 // 安全寫法
> 3. 迴圈依照 n 的大小嚴格執行讀取次數 (i 從 1 到 n - 1)。
> 4.      讀取 second 元素。
> 5.      計算差值並將 number[abs(first - second)] 設為 true。
> 6.      將 second 賦值給 first，準備下一輪計算。
> 7. 檢查陣列中 1 到 n - 1 是否都被標記為 true。

</details>

## Complexity
### Time Complexity: 
* **Version 2:** $O(N)$ - We iterate through the $N$ numbers exactly once to read the input and calculate the differences, followed by another loop of size $N-1$ to verify the boolean array.
### Space Complexity: 
* **Version 2:** $O(1)$ - The problem specifies $n \le 3000$. We allocate a fixed-size boolean array of 3000, which takes constant space regardless of the actual sequence length $n$.

<details>
<summary><head>點擊查看中文版</head></summary>

### Time Complexity: 
* **Version 2:** $O(N)$ - 將 $N$ 個數字遍歷一次以讀取輸入並計算差值，接著再執行一次長度為 $N-1$ 的迴圈來檢查布林陣列。時間與 $N$ 成正比。
### Space Complexity: 
* **Version 2:** $O(1)$ - 題目限制 $n \le 3000$。我們宣告了一個固定大小為 3000 的布林陣列，無論輸入長度 $n$ 為何，記憶體消耗皆為常數級別。
</details>