# 401 - Palindromes

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6)

## 簡介:
給定多筆字串測資，要求判斷該字串屬於以下四種類型中的哪一種：
1. 不是回文也不是鏡像 (not a palindrome)
2. 是回文但不是鏡像 (a regular palindrome)
3. 不是回文但是鏡像 (a mirrored string)
4. 同時是回文與鏡像 (a mirrored palindrome)  
判斷完畢後，依照題目規定的格式與英文句型輸出結果。

1. **核心技術**：雙指標法 (Two Pointers)。從字串頭尾同時往中間走訪，並利用兩個布林值 (`is_palindromes`, `is_mirror`) 分別紀錄兩種狀態。
2. **字串映射 (V1)**：不使用冗長的 `switch-case`，而是建立 `mirror` 與 `mirror2` 兩個對齊的字串字典，配合 `string::find()` 來達成字元的鏡像比對。
3. **極致效能的陣列查表 (V2)**：捨棄耗時的字串搜尋，直接利用字元在底層即為整數的特性，建立大小為 256 的字元陣列 `mirror_map`，實現 $O(1)$ 的超高速查表。
4. **現代 STL 演算法混搭 (V3)**：在保留 V2 極致查表效能的同時，引入 `<algorithm>` 函式庫中的 `std::reverse` 來取代手動迴圈判斷回文，讓程式碼達到最高的可讀性。
5. **邊界陷阱**：
   * **奇數長度**：當字串長度為奇數時，最中間的字元必須是「鏡像為自己」的字元，否則不能算作鏡像字串。
   * **無效字元**：部分字元沒有對應的鏡像，必須確實處理找不到的情況，以免將無效字元誤判為鏡像。

<details>
<summary><head>點擊查看 C++ 的 string::find 與 string::npos (V1)</head></summary>

### 如何判斷字元是否存在於字典中？
在 C++ 中，`std::string::find(字元)` 會回傳該字元在字串中第一次出現的 **索引值 (index)**。如果該字元根本不在字串裡，它會回傳一個特殊的常數：`std::string::npos`。

我們可以用這個特性來擋下「無效字元」：
`if (mirror.find(c) == string::npos)` 就代表這個字元 `c` 根本沒有對應的鏡像，可以直接判定它不是鏡像字串！

</details>

<details>
<summary><head>點擊查看 C++ 的 ASCII 陣列查表 (V2, V3)</head></summary>

### 為什麼可以用字元當作陣列的 index？
在電腦底層，字元 (`char`) 其實就是 ASCII 碼的整數（例如 `'A'` 就是 `65`）。
宣告 `char mirror_map[256]` 後，我們可以直接寫 `mirror_map['A'] = 'A'`，電腦會自動理解為 `mirror_map[65] = 'A'`。這讓我們尋找鏡像字元的時間，從迴圈搜尋降到了絕對的 $O(1)$ 瞬間讀取！

</details>

<details>
<summary><head>點擊查看 C++ 的字串反轉與直接比較魔法 (V3)</head></summary>

### 為什麼可以直接用 != 比較字串？
在 C++ 中，`std::string` 已經幫我們處理好了底層的運算子多載。因此我們不需要像 C 語言一樣使用 `strcmp`，直接使用 `==` 或 `!=`，電腦就會自動幫我們逐字元比對內容。搭配 `<algorithm>` 裡的 `std::reverse(begin, end)` 將字串反轉後直接比較，即可用最語意化、最防呆的方式完成回文檢查。

</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `input` | A string to temporarily store the current test case read by `getline` |
| `mirror_map` | (V2, V3) A char array of size 256 acting as an $O(1)$ direct lookup table. |
| `re_input` | (V3) A copy of `input` used to reverse the string and check for palindromes using `<algorithm>`. |
| `mirror` | (V1) The dictionary string containing characters that have a valid mirror |
| `mirror2` | (V1) The dictionary string aligned with `mirror`, containing the mirrored result for each character |
| `mirror3` | (V1) The dictionary string containing characters that mirror to themselves (self-mirrored) |
| `is_palindromes` | A boolean flag indicating whether the string is a regular palindrome |
| `is_mirror` | A boolean flag indicating whether the string is a mirrored string |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `input` | 暫存每次用 `getline` 讀取進來的字串測資 |
| `mirror_map` | (V2, V3) 長度 256 的字元陣列，以字元 ASCII 碼為 index 的 $O(1)$ 查表陣列 |
| `re_input` | (V3) 複製自 `input` 的字串，用於透過 `std::reverse` 反轉後直接比對回文 |
| `mirror` | (V1) 字典字串 A，儲存所有「擁有鏡像對應」的字元 |
| `mirror2` | (V1) 字典字串 B，儲存與 A 對齊的「鏡像結果」字元 |
| `mirror3` | (V1) 字典字串 C，儲存「鏡像就是自己本身」的字元 (用於檢查奇數長度的正中間字元) |
| `is_palindromes` | 布林值旗標，紀錄該字串是否符合回文規則 |
| `is_mirror` | 布林值旗標，紀錄該字串是否符合鏡像規則 |

</details>

### version 1 (字串映射版) - 邏輯:
```text
1. Fast I/O optimization
2. Define the dictionary strings 'mirror', 'mirror2', and 'mirror3'
3. While reading a line into 'input':
4.      Initialize 'is_mirror' and 'is_palindromes' to true
5.      Loop through the first half of the string (i from 0 to input.size() / 2):
6.          Check mirror: If input[i] is not in 'mirror', OR its corresponding character in 'mirror2' does not equal the opposite character from the end, set 'is_mirror' to false and break
7.      If the string length is odd (input.size() % 2 == 1):
8.          Check the exact middle character. If it is not found in 'mirror3', set 'is_mirror' to false
9.      Loop through the first half of the string again:
10.         Check palindrome: If the left character does not equal the right character, set 'is_palindromes' to false and break
11.     Print the formatted result
```

<details>
<summary><head>點擊查看 V1 中文版</head></summary>

```text
1. 關閉 I/O 同步以加速讀取
2. 定義三個用於對應的字典字串 mirror, mirror2, mirror3
3. 使用 getline 不斷讀取字串直到 EOF：
4.      將 is_mirror 與 is_palindromes 初始化為 true
5.      走訪字串的前半部 (索引 i 到 input.size() / 2)：
6.          鏡像檢查：如果左邊的字元在 mirror 找不到，或者從 mirror2 映射出來的字元不等於右邊對稱的字元，則將 is_mirror 設為 false 並提早結束迴圈
7.      如果字串長度為奇數 (取餘數為 1)：
8.          檢查最中間的字元，如果它不在 mirror3 (自己映射自己) 裡面，將 is_mirror 設為 false
9.      再次走訪字串的前半部：
10.         回文檢查：如果左邊的字元不等於右邊對稱的字元，將 is_palindromes 設為 false 並提早結束迴圈
11.     根據兩個布林值旗標的結果，組合出對應的句子並輸出
```
</details>

### version 2 (O(1) 陣列查表版) - 邏輯:
```text
1. Fast I/O optimization
2. Initialize 'mirror_map' array of size 256 with '\0' and manually populate the valid mirror character pairs.
3. While reading a line into 'input':
4.      Initialize 'is_mirror' and 'is_palindromes' to true
5.      Loop through the first half of the string (i from 0 to input.size() / 2):
6.          Lookup the mirror of input[i] from 'mirror_map'.
7.          If the mirrored character is '\0' (invalid) OR does not match the symmetric character from the right, set 'is_mirror' to false and break.
8.      If the string length is odd (input.size() % 2 == 1):
9.          Lookup the exact middle character in 'mirror_map'. If it does not equal itself, set 'is_mirror' to false.
10.     Loop through the first half of the string again:
11.         If the left character does not equal the symmetric right character, set 'is_palindromes' to false and break.
12.     Print the formatted result.
```

<details>
<summary><head>點擊查看 V2 中文版</head></summary>

```text
1. 關閉 I/O 同步以加速讀取
2. 建立大小為 256 的 mirror_map 字元陣列，預設為 '\0'，並手動填入所有有效的鏡像對應字元
3. 使用 getline 不斷讀取字串直到 EOF：
4.      將 is_mirror 與 is_palindromes 初始化為 true
5.      走訪字串的前半部 (索引 i 到 input.size() / 2)：
6.          從 mirror_map 查出左邊字元的鏡像
7.          如果查無此鏡像 ('\0')，或者鏡像不等於右邊對稱的字元，則將 is_mirror 設為 false 並提早結束迴圈
8.      如果字串長度為奇數 (取餘數為 1)：
9.          從 mirror_map 查出最中間字元的鏡像，如果它不等於自己，將 is_mirror 設為 false
10.     再次走訪字串的前半部：
11.         回文檢查：如果左邊的字元不等於右邊對稱的字元，將 is_palindromes 設為 false 並提早結束迴圈
12.     根據兩個布林值旗標的結果，組合出對應的句子並輸出
```
</details>

### version 3 (STL 演算法混搭版) - 邏輯:
```text
1. Fast I/O optimization & Initialize 'mirror_map' array.
2. While reading a line into 'input':
3.      Initialize 'is_mirror' and 'is_palindromes' to true
4.      Check mirror using 'mirror_map' loop (same as V2).
5.      Check palindrome: Create 're_input' as a copy of 'input', reverse it using std::reverse(), and directly compare it with 'input'. If not equal, set 'is_palindromes' to false.
6.      Print the formatted result.
```

<details>
<summary><head>點擊查看 V3 中文版</head></summary>

```text
1. 關閉 I/O 同步以加速讀取，並手動建立 mirror_map 鏡像查表陣列
2. 使用 getline 不斷讀取字串直到 EOF：
3.      將 is_mirror 與 is_palindromes 初始化為 true
4.      鏡像檢查：使用與 V2 相同的陣列查表法，走訪字串前半段與最中間的字元
5.      回文檢查：複製一份 input 命名為 re_input，使用 std::reverse() 將其反轉，並直接以 != 運算子比對兩者。若不相等則 is_palindromes 設為 false。
6.      根據兩個布林值旗標的結果，組合出對應的句子並輸出
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 (字串映射) | $O(N)$ | $O(1)$ |
| V2 (陣列查表) | $O(N)$ | $O(1)$ |
| V3 (STL混搭) | $O(N)$ | $O(N)$ |

* 註：$N$ 為單筆測資字串的長度。
* **時間複雜度**：三個版本皆需走訪字串長度，故為 $O(N)$。V2 與 V3 省去了 `find()` 的內部線性搜尋步驟，常數時間更小、執行速度更快。
* **空間複雜度**：V1 與 V2 僅使用常數布林值與固定字串/陣列，為 $O(1)$。V3 為了使用 `std::reverse` 進行語意化比較，額外複製了一份原字串 `re_input`，故空間複雜度提升至 $O(N)$。

## 版本總結

| 特性 | V1 (雙字串映射法) | V2 (ASCII 陣列查表法) | V3 (查表法 + STL 演算法) |
| :--- | :--- | :--- | :--- |
| 核心思維 | 依賴 `string::find()` 查表 | 將「字元」視為「記憶體位址 (index)」直接存取 | 結合 O(1) 陣列映射與現代 STL 語意化檢查 |
| 程式碼結構 | 需額外處理 `string::npos` | 移除字串搜尋函數，全程依賴雙指標迴圈 | 鏡像檢查極致高效，回文檢查免去迴圈與邊界計算 |
| 優勢場景 | 適合對字串操作不熟的初學者 | 適合追求 $O(1)$ 空間與時間的極端競賽環境 | **業界最推薦**：兼顧底層效能與程式碼高度可讀性 |