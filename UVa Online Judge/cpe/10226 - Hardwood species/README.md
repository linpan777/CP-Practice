# 10226 - Hardwood Species

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1167)

## 簡介:
給定多筆測資，每筆測資包含一系列的樹木品種名稱（每行一棵樹）。
要求統計每種樹木在該筆測資中佔的「百分比」，並將結果輸出到小數點後第 4 位。輸出必須按照樹木名稱的「字母順序」排列，且相鄰兩組測資的輸出之間必須有一個空白行。
1. **核心資料結構**：這題是 `std::map<string, double>` 的完美應用場景。利用 `map` 自動按 Key (樹名) 進行字母排序的特性，免去手動 `sort` 的麻煩。
2. **百分比與輸出格式化**：利用 `<iomanip>` 函式庫中的 `fixed` 與 `setprecision(4)`，精準控制浮點數的輸出格式。
3. **字串讀取陷阱**：測資之間以「空白行」分隔，必須善用 `getline` 配合字串是否為空 (`tree != ""`) 來判斷單筆測資的結束。

<details>
<summary><head>點擊查看 C++ 的輸出格式化魔法 (iomanip)</head></summary>

### 如何精準控制小數點位數？
在 C++ 中處理浮點數輸出時，預設的 `cout` 可能會用科學記號或省略尾數的 0。為了嚴格遵守題目「輸出到小數點後 4 位」的要求，我們需要 `#include <iomanip>`：
- **`fixed`**：告訴編譯器「請使用固定的小數點表示法」，不要給我轉成科學記號。
- **`setprecision(n)`**：告訴編譯器「請保留到小數點後第 n 位」，如果後面沒有數字會自動補 0。
這兩個常常綁定在一起使用：`cout << fixed << setprecision(4) << 數字;`

</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `Case` | The number of test cases |
| `treeAndSpecies` | A `std::map` to store the tree name (Key) and its occurrence count (Value) |
| `tree` | A string to temporarily store the tree name read by `getline` |
| `count` | The total number of trees in the current testcase |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `Case` | 測試資料的總筆數 |
| `treeAndSpecies` | 字典容器，Key 存樹木名稱，Value 存出現次數 (設為 `double` 方便後續計算) |
| `tree` | 暫存每次用 `getline` 讀取進來的樹木名稱字串 |
| `count` | 紀錄當前這組測資總共有幾棵樹 (作為計算百分比的分母) |

</details>

### version 1 - 邏輯:
```text
1. Read the number of test cases 'Case' and consume the trailing newlines
2. Loop 'Case' times:
3.      Create a map<string, double> 'treeAndSpecies' and initialize total 'count' = 0
4.      While reading a line into 'tree' and it is not an empty string:
5.          Increment total 'count'
6.          Increment the occurrence of the specific tree in the map
7.      Iterate through the map (which is automatically sorted):
8.          Print the tree name and its percentage (count / total * 100) formatted to 4 decimal places
9.      If it is not the last test case, print an extra blank line
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀取測資筆數 Case，並用兩次 cin.ignore() 吃掉後面的換行與空白行
2. 執行 Case 次迴圈：
3.      宣告 map 字典 treeAndSpecies 與樹木總數 count = 0
4.      使用 getline 讀取樹名，只要讀取成功且字串不為空 (代表尚未遇到空白行)：
5.          總數量 count + 1
6.          該樹種的計數器 + 1 (treeAndSpecies[tree]++)
7.      利用 for-each 走訪 map (已自動按字母排好序)：
8.          輸出 樹名 與 其所佔百分比 (次數 / 總數 * 100)，並強制顯示到小數點後 4 位
9.      如果這不是最後一筆測資，印出一個空白行隔開
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 | $O(N \log K)$ | $O(K)$ |

* 註：$N$ 為單筆測資中的樹木總數，$K$ 為相異的樹種數量。每次讀取樹名並存入 `map` 的時間成本為 $O(\log K)$，總共執行 $N$ 次。計算與輸出的時間為 $O(K)$。整體空間複雜度取決於樹種的數量 $O(K)$。

## 版本總結

| 特性 | V1 (std::map 計數法) |
| :--- | :--- |
| 核心思維 | 利用 `map` 的自動排序與動態計數特性 |
| 浮點運算防呆 | 直接將 `map` 的 Value 宣告為 `double`，避免整數相除導致小數點遺失 |
| 格式化輸出 | 完美應用 `<iomanip>` 處理題目要求的 4 位小數 |
| 空白行處理 | 迴圈結尾加上 `if(Case != 0)` 精準控制測資間的空白行 |