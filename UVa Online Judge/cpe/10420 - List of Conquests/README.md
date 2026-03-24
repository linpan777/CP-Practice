# 10420 - List of Conquests

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1361)

## 簡介:
給定 $T$ 行字串，每一行代表唐璜愛過的女人記錄。每行的第一個單字是「國家」，後面的字串是「女人的名字」。
任務要求：**統計每個國家出現的次數，並將國家名稱按照字母順序 (Alphabetical order) 排序輸出。**

<details>
<summary><head>點擊查看 V1 的致命傷：為什麼傳統陣列會拿 WA/RE？</head></summary>

### 陣列與 Switch 的侷限性
在 V1 中，使用了 `switch(list[0])` 來判斷國家的第一個字母，並對應到寫死的長度為 6 的陣列 `girl[6]`。這在測資較弱的平台（如瘋狂程設）可能過關，但在 UVa 會遇到兩個致命問題：
1. **隱藏國家**：UVa 的測資絕對不只故事中提到的那 6 個國家，一旦出現 `Taiwan` 等未定義的國家，陣列無法處理。
2. **首字母重複**：如果測資同時出現 `Spain` 與 `Sweden`，兩者的首字母都是 `'S'`，V1 的寫法會將它們混為一談，導致統計錯誤。

</details>

<details>
<summary><head>點擊查看 V2 的救星：std::map 的魔法</head></summary>

### 完美解法：`std::map<string, int>`
`map` 是一個關聯式容器，擁有兩個這題完美需要的特性：
1. **動態擴充**：當我們呼叫 `list[country]++` 時，若遇到第一次出現的國家，`map` 會自動建立該字串的 Key，並將 Value 初始化為 0，再執行 `++` 變成 1。完全不需要預先知道有幾種國家！
2. **自動排序**：`map` 底層實作是紅黑樹 (Red-Black Tree)，這代表存入的 Key 會**自動按照字母的 A 到 Z 排好序**。我們甚至連 `sort()` 都不用呼叫，直接走訪輸出就符合題意。

### 字串讀取技巧
因為題目保證國家名稱只有「一個單字」，我們直接用 `cin >> country;` 就能完美切割出國家名稱。剩下的女人名字因為對統計無用，直接利用 `getline(cin, girl);` 將整行剩餘內容吃掉並丟棄即可。

</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | The number of lines (records) to process |
| `country` | The first word of each line, representing the country |
| `girl` / `woman_name` | The remainder of the line, read and ignored in the logic |
| `girl[6]` | (V1 only) Array used to store counts for 6 hardcoded countries |
| `list` | (V2 only) A `std::map<string, int>` storing the country as Key and the frequency as Value |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `T` | 總共需要處理的資料行數 |
| `country` | 每行的第一個單字 (國家名稱) |
| `girl` / `woman_name` | 每行剩下的字串 (女人的名字)，讀取後捨棄 |
| `girl[6]` | (僅 V1) 預先寫死用來記錄 6 個國家出現次數的陣列 |
| `list` | (僅 V2) 統計字典，Key 存國家名稱，Value 存出現次數 |

</details>

### version 1 (WA) - 邏輯:
```text
1. Initialize an array girl[6] with 0
2. Read T, then use cin.ignore() to clear the newline
3. Loop T times:
4.      Read the entire line into 'list' using getline
5.      Switch based on the first character list[0]:
6.          Increment the corresponding index in girl[] for 'E', 'F', 'G', etc.
7. Print the hardcoded country names and their non-zero counts
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 宣告大小為 6 的陣列 girl 並歸零
2. 讀取 T，並使用 cin.ignore() 清除緩衝區的換行符號
3. 執行 T 次迴圈：
4.      用 getline 讀取一整行存入字串 list
5.      使用 switch 判斷字串的第一個字元 list[0]：
6.          如果是 'E'、'F' 等，則將對應的陣列格子 +1
7. 走訪陣列，印出預先寫死的國家名稱與其次數
```
</details>

### version 2 (AC) - 邏輯:
```text
1. Create a std::map<string, int> named list
2. Read T, then use cin.ignore() to clear the newline
3. Loop T times:
4.      Read the first word into 'country' using cin
5.      Read the rest of the line into 'girl' using getline and ignore it
6.      Increment the map value: list[country]++
7. Iterate through the map:
8.      Print the key (it.first) and the value (it.second)
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 宣告一個 std::map 命名為 list 來當作統計字典
2. 讀取 T，並使用 cin.ignore() 清除緩衝區的換行符號
3. 執行 T 次迴圈：
4.      使用 cin 讀取首個單字存入 country
5.      使用 getline 讀取整行剩餘內容存入 girl (捨棄不處理)
6.      將字典中該國家對應的次數 +1：list[country]++
7. 使用 for-each 迴圈走訪 map：
8.      印出國家名稱 (it.first) 與其次數 (it.second)
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 (Array) | $O(N)$ | $O(1)$ |
| V2 (Map) | $O(N \log K)$ | $O(K)$ |

* 註：$N$ 為總資料行數，$K$ 為相異的國家數量。V1 寫法雖然擁有 $O(N)$ 的時間優勢，但無法應付動態的字串查詢；V2 每次在 `map` 中尋找或插入字串的時間複雜度為 $O(\log K)$，總共執行 $N$ 次，空間複雜度僅取決於有幾種不同的國家被存入。

## 版本總結

| 特性 | V1 (Switch 陣列法) ❌ WA | V2 (std::map 字典法) ✅ AC |
| :--- | :--- | :--- |
| 資料結構 | 一維陣列 `int girl[6]` | 關聯式容器 `std::map<string, int>` |
| 擴充性 | 極差，僅能處理預先定義的 6 個國家 | 極佳，動態生成不限種類的國家記錄 |
| 排序方式 | 依賴人工排列輸出的順序 | `map` 底層自動按字母順序排列 |
| 風險 | 首字母重複、未預期國家會導致結果錯誤或 RE | 無，完美解決字串統計與排序問題 |
| 推薦指數 | ⭐ | ⭐⭐⭐⭐⭐ |