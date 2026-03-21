# 10062 - Tell me the frequencies!

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1003)

## 簡介:
計算一行字串中，各個 ASCII 字元出現的頻率，並依照特定規則進行排序輸出。
1. **輸入處理**：測資可能包含空白字元，必須使用 `getline()` 讀取整行。
2. **排序雙重條件**：
   - 第一優先：出現頻率**由小到大** (Ascending)。
   - 第二優先：若頻率相同，ASCII 碼**由大到小** (Descending)。
3. **格式陷阱**：每組測資輸出之間必須有一個空白行，但**最後一組測資後不能有空白行**。

<details>
<summary><head>點擊查看 struct 與 自訂排序 cmp 的用法</head></summary>

### 為什麼這題必須用 struct？
如果我們只用一個單純的陣列 `int count[128]` 記錄頻率，陣列的**「位置 (Index)」**就代表 ASCII 碼。
一旦我們對這個陣列進行排序，頻率的數字雖然排好了，但它們會全部移位，導致我們**完全不知道這個頻率原本屬於哪個 ASCII 字元**！

因此，我們必須使用 `struct` 把「頻率」和「ASCII 身分證」綁定成一個組合包：
```cpp
struct CharFrequence {
    int ASCIIchar = 0; // 記錄身分證 (ASCII 碼)
    int count = 0;     // 記錄出現次數
};
```

### 自訂裁判函式 (cmp)
C++ 內建的 `std::sort` 允許我們自訂排序規則。裁判函式必須回傳 `bool` 值，代表「參數 a 是否應該排在參數 b 的前面」。

這題的「雙重條件」寫法：
```cpp
bool mycmp(CharFrequence a, CharFrequence b) {
    // 規則 1：如果頻率不同，頻率小的排前面
    if(a.count != b.count) {
        return a.count < b.count; 
    }
    // 規則 2：如果頻率相同，ASCII 碼大的排前面
    else {
        return a.ASCIIchar > b.ASCIIchar; 
    }
}
```
*註：這是在邏輯上等價於 V1 程式碼的精簡寫法。*

</details>

<details>
<summary><head>點擊查看測資間空白行陷阱的解法</head></summary>

### UVa 經典的 PE (Presentation Error) 陷阱
很多題目要求「測資之間印出空白行」。如果我們在每筆測資最後直接 `cout << '\n';`，會導致最後一筆測資結尾也多出一個多餘的空白行，從而拿到 PE 甚至 WA。

### 完美解法：標記法 (Flag)
我們可以宣告一個變數 `T = 1` 當作第一筆測資的標記：
```cpp
int T = 1;
while(getline(cin, sentences)) {
    // 如果是第一筆測資，什麼都不印，並把標記改掉
    if(T == 1) {
        T++;
    } 
    // 從第二筆測資開始，每次處理前先印一個空白行，作為「上一筆」和「這一筆」的間隔
    else {
        cout << '\n';
    }
    
    // ... 下面繼續寫主要的處理邏輯 ...
}
```
利用「前置印出」的概念，就能完美避開結尾多餘空白行的問題。

</details>


## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `sentences` | The entire line of input text, read via `getline()` |
| `T` | A flag used to handle the blank line formatting between test cases |
| `data[129]` | An array of structs to track the ASCII value and count for all possible characters |
| `temp` | A temporary variable holding the ASCII integer value of the current character |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `sentences` | 透過 `getline()` 讀取的整行輸入字串 |
| `T` | 標記變數，用來控制測資之間的空白行格式 |
| `data[129]` | 結構體陣列，涵蓋 0~128，用來綁定並記錄每個 ASCII 字元及其出現次數 |
| `temp` | 暫存變數，記錄當前字元的 ASCII 整數值 |

</details>

### version 1 - 邏輯:
```text
1. Read input line by line using getline(cin, sentences)
2.      Handle the blank line formatting using the T flag
3.      Initialize an array of CharFrequence structs (size 129)
4.      For each character in sentences:
5.          temp = ASCII value of character
6.          data[temp].ASCIIchar = temp (Assign ID)
7.          data[temp].count++          (Increment frequency)
8.      Sort the data array using sort() and custom mycmp
9.      For i = 0 to 128:
10.         If count > 0, print the ASCIIchar and count
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 使用 getline(cin, sentences) 逐行讀取字串直到 EOF
2.      利用標記變數 T 處理測資之間的空白行格式
3.      初始化大小為 129 的 CharFrequence 結構體陣列
4.      走訪字串中的每一個字元：
5.          取得字元的 ASCII 整數值 (temp)
6.          發放身分證：將該格子的 ASCIIchar 設為 temp
7.          計數器 +1：將該格子的 count 增加 1
8.      使用 std::sort 搭配自訂裁判 mycmp 進行陣列排序
9.      走訪排完序的陣列 (0 到 128)：
10.         如果該字元的出現次數 > 0，則印出 ASCII 碼與次數
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 | $O(N + C \log C)$ per test case | $O(C)$ |

* 註：$N$ 為輸入字串的長度。$C$ 為 ASCII 字元集的大小（常數，本題陣列大小為 129）。由於陣列大小固定，排序的時間消耗幾乎是常數時間 $O(1)$，因此整體時間複雜度主要取決於讀取與走訪字串的 $O(N)$。空間複雜度僅需極小的常數級別陣列。

## 版本總結

| 特性 | V1 (Struct + 自訂 Sort 版) |
| :--- | :--- |
| 資料結構 | 結構體陣列 (`struct CharFrequence data[129]`) |
| 關聯綁定方式 | 利用 Struct 將 ASCII ID 與 Count 打包 |
| 排序方式 | `std::sort` 配合自訂的 `mycmp` 雙重條件判斷 |
| 記憶體使用 | 極低 (僅 129 個結構體) |
| 邏輯複雜度 | 直觀、易理解 |