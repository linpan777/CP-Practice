# 10082 - WERTYU

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1023)

## 簡介:
這是一題經典的「鍵盤錯位」字串處理題。打字員不小心把手往右放偏了一格，導致打出來的字元全部向右錯位（例如想打 `Q` 卻打成 `W`）。
給定錯誤的字串，要求輸出原本正確的字串（相當於把每個字元在鍵盤上「往左平移一格」）。空白鍵不受影響，且測資保證不會出現需要換行或無法往左平移的邊界字元。

1. **核心技術**：字串查表與映射。利用 `std::string::find()` 找出字元在預設鍵盤字串中的位置，並轉換為對應的輸出。
2. **單一字串偏移 (V2)**：因為錯位規則具有高度的規律性（固定往左一格），所以不需要像一般字典對照一樣建立兩個字串，只需一個鍵盤序列，透過 `index - 1` 即可優雅解決。
3. **隱藏陷阱（跳脫字元）**：鍵盤符號中包含反斜線 `\`，在程式語言的字串中，反斜線是具有特殊作用的「跳脫字元」。如果沒有正確處理，會導致字串長度被吞噬，後續的查表 index 全部大亂。

<details>
<summary><head>點擊查看 C++ 的跳脫字元陷阱 (Escape Character)</head></summary>

### 為什麼字串裡的反斜線會消失？
在 C++ 字串中，反斜線 `\` 被設計為特殊指令的開頭（例如 `\n` 是換行，`\t` 是 Tab）。
如果你直接在字串中寫下 `...[]\ASDF...`，編譯器會試圖解析 `\A` 這個指令，而不是把它當成普通的斜線印出來。這會導致該字元憑空消失，字串長度變短。

**解法：使用雙反斜線 `\\`**
若要在字串中保留一個真實的反斜線，必須輸入兩次 `\\`。第一個 `\` 用來解除特殊指令的魔法，第二個 `\` 才是真正存進字串裡的符號。

</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `input` | A string to temporarily store the current test case read by `getline` |
| `origin` | The dictionary string containing the keyboard layout from left to right, top to bottom. Contains the `\\` escape character sequence. |
| `Switch` | (V1 only) The shifted dictionary string aligned with `origin`, representing the character one key to the left. |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `input` | 暫存每次用 `getline` 讀取進來的字串測資 |
| `origin` | 鍵盤字典字串，依照鍵盤由左至右、由上至下排列。需特別注意 `\\` 跳脫字元的處理 |
| `Switch` | (僅 V1) 與 `origin` 對齊的字典字串，代表每個按鍵「往左一格」的結果 |

</details>

### version 1 (雙字串映射版) - 邏輯:
```text
1. Fast I/O optimization
2. Define the keyboard dictionary string 'origin' and its left-shifted counterpart 'Switch'. (Be careful with '\\')
3. Read a line of text into 'input'.
4. Loop through each character 'c' in 'input':
5.      If 'c' is a space, print a space and continue to the next character.
6.      Otherwise, find the index of 'c' in 'origin', and print the character at the same index in 'Switch'.
7. Print a newline at the end.
```

<details>
<summary><head>點擊查看 V1 中文版</head></summary>

```text
1. 關閉 I/O 同步以加速讀取
2. 定義原鍵盤字串 origin 與平移一格後的字串 Switch (注意跳脫字元 \\ 的使用)
3. 讀取一行測資至 input
4. 走訪 input 中的每一個字元 c：
5.      如果是空白字元，直接輸出空白並跳過後續步驟
6.      如果不是空白，找出 c 在 origin 中的 index，並輸出 Switch 對應 index 的字元
7. 測資結束後輸出換行
```
</details>

### version 2 (單字串 index 偏移版) - 邏輯:
```text
1. Fast I/O optimization
2. Define a single keyboard dictionary string 'origin'.
3. While reading a line into 'input' (handles multiple test cases):
4.      Loop through each character 'c' in 'input':
5.          If 'c' is a space, print a space and continue.
6.          Otherwise, find the index of 'c' in 'origin', and print 'origin[index - 1]' (the key directly to its left).
7.      Print a newline after each testcase.
```

<details>
<summary><head>點擊查看 V2 中文版</head></summary>

```text
1. 關閉 I/O 同步以加速讀取
2. 定義單一鍵盤字串 origin
3. 使用 while(getline) 不斷讀取測資直到 EOF：
4.      走訪 input 中的每一個字元 c：
5.          如果是空白字元，直接輸出空白並跳過後續步驟
6.          如果不是空白，找出 c 在 origin 中的 index，直接印出 index - 1 (左邊一格) 的字元
7.      每筆測資處理完畢後輸出換行
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 (雙字串映射) | $O(N)$ | $O(1)$ |
| V2 (單字串偏移) | $O(N)$ | $O(1)$ |

* 註：$N$ 為單筆測資字串的長度。字串走訪的時間成本為 $O(N)$。`find()` 因鍵盤字典長度固定（常數大小 47），故視同 $O(1)$ 運作。空間上僅使用固定的常數字串，複雜度為 $O(1)$。

## 版本總結

| 特性 | V1 (雙字串映射法) | V2 (單字串 index 偏移法) |
| :--- | :--- | :--- |
| 核心思維 | 建立嚴格的 Key-Value 雙字串對照表 | 利用題目「左移一格」的規律性，透過 index 計算直接取值 |
| 程式碼結構 | 需維護兩個冗長的鍵盤字串，打錯字風險高 | 僅需維護單一字串，並加上 `while` 迴圈處理 UVa 的多筆測資標準格式 |
| 效能與可讀性 | 效能相同，邏輯直觀 | **更優**：減少多餘的字串宣告，更符合問題本質的位移邏輯 |