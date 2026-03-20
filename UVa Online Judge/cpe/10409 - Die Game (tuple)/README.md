# 10409 - Die Game

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=242&page=show_problem&problem=1350)

## 簡介:
模擬骰子的滾動。給定一個標準骰子的初始狀態，以及一系列滾動方向（北、南、東、西），輸出最終骰子朝上的面的數字。
1. 骰子初始狀態：1 朝上，6 朝下，2 朝北，5 朝南，3 朝西，4 朝東。<br>
2. 骰子的重要性質：對面之和永遠為 7（1+6=7, 2+5=7, 3+4=7）。<br>
3. 可採用全域變數逐個交換、結構體配合推導、或 tuple 同時賦值等方式求解。

<details>
<summary><head>點擊查看 tuple 與 tie 的用法</head></summary>

### 什麼是 tuple？
`tuple` 是一個 C++ 標準函式庫中的容器，用來儲存**不同型別**的多個值。類似於結構體，但更靈活。

### 什麼是 tie？
`tie()` 是用來將 tuple 中的值**「解包」成各個獨立的變數**。簡單來說，它的反方向是 `make_tuple()`：
- `make_tuple(1, 2, 3)` → 把 3 個值打包成 1 個 tuple
- `tie(a, b, c)` → 把 1 個 tuple 拆包成 3 個變數

### 基本語法：
```cpp
#include <tuple>
using namespace std;

// 1. 建立 tuple
tuple<int, int, int> t = make_tuple(1, 2, 3);
//也可以使用auto t = make_tuple(1, 2, 3);

// 2. 取得 tuple 中的值
int first = get<0>(t);  // 取得第 1 個元素：1
int second = get<1>(t); // 取得第 2 個元素：2
int third = get<2>(t);  // 取得第 3 個元素：3

// 3. 使用 tie 進行「同時賦值」（這是骰子題最關鍵的用法）
int a, b, c;
tie(a, b, c) = t;  // 相當於：a=1, b=2, c=3

// 4. 實際例子
int x = 10, y = 20, z = 30;
tie(x, y, z) = make_tuple(y, z, x);  // x=20, y=30, z=10（循環右移）
```

### tie 在幹什麼？
`tie(a, b, c) = make_tuple(...)` 這行指令的意思是：
1. 右邊 `make_tuple(...)` 建立一個臨時的 tuple，裡面有 3 個值
2. 左邊 `tie(a, b, c)` 將這個 tuple 中的 3 個值**同時賦值**給 a、b、c
3. 關鍵是：所有賦值在**同一個時刻**發生，不會相互干擾

### 基本語法：
```cpp
#include <tuple>
using namespace std;

// 1. 建立 tuple
tuple<int, int, int> t = make_tuple(1, 2, 3);
//也可以用auto t = make_tuple(1, 2, 3);

// 2. 取得 tuple 中的值
int first = get<0>(t);  // 取得第 1 個元素：1
int second = get<1>(t); // 取得第 2 個元素：2
int third = get<2>(t);  // 取得第 3 個元素：3

// 3. 使用 tie 進行「同時賦值」
int a, b, c;
tie(a, b, c) = t;  // a=1, b=2, c=3
```

### tie + make_tuple 的威力 - 同時賦值
這題中最重要的用法：**用 tie + make_tuple 同時交換多個變數，避免繁瑣的逐個交換**
```cpp
struct Die {
    int up, north, down, south;
};

Die mydie;

// ❌ 傳統做法（4 行程式碼）
int temp = mydie.up;
mydie.up = mydie.north;
mydie.north = mydie.down;
mydie.down = mydie.south;
mydie.south = temp;

// ✅ tuple 做法（1 行程式碼）
tie(mydie.up, mydie.north, mydie.down, mydie.south) 
    = make_tuple(mydie.north, mydie.down, mydie.south, mydie.up);
```

### 為什麼 v3 使用 tuple？
- **直觀性**：清楚寫出每個變數的新值，易於理解交換邏輯
- **簡潔性**：4 行複雜邏輯濃縮成 1 行
- **原子性**：同時賦值，避免中間狀態出現 bug
- **易維護**：當需要交換的變數增加時，只需在 tie() 和 make_tuple() 中添加即可

</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | The number of operations per test case |
| `up, down, north, south, east, west` | <sub>Used in `V1`</sub> Six faces of the die stored as global variables |
| `mydie` | <sub>Used in `V2`, `V3`</sub> A `struct Die` to store the die state |
| `direction` | The rolling direction ('n', 's', 'e', 'w') |
| `temp` | <sub>Used in `V1`, `V2`</sub> Temporary variable for swapping |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `T` | 此測試用例的操作次數 |
| `up, down, north, south, east, west` | <sub>用於 `V1`</sub> 骰子的 6 個面，儲存為全域變數 |
| `mydie` | <sub>用於 `V2`, `V3`</sub> 骰子結構體，用來儲存骰子的狀態 |
| `direction` | 滾動方向（'n' 北、's' 南、'e' 東、'w' 西） |
| `temp` | <sub>用於 `V1`, `V2`</sub> 暫存變數，用於交換時保存數值 |

</details>

### version 1 - 邏輯:
```text
1. cin >> T
2. while(T != 0)
3.      Reset die to initial state
4.      for(i = 0 to T-1)
5.          cin >> direction
6.          Save up to temp, then swap 4 related faces in order
7.      cout << up
8.      cin >> T
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀入 T (此測試用例的操作次數)
2. while 迴圈 (T != 0)
3.      重置骰子到初始狀態
4.      for 迴圈 (i 從 0 到 T-1)
5.          讀入方向字元
6.          將朝上面暫存到 temp，依序交換 4 個相關面
7.      輸出朝上面的值
8.      讀入下一個 T
```
</details>

### version 2 - 邏輯:
```text
1. Define struct Die { int up, north, west }
   - Note: Only store 3 faces, derive others using "7 - value"
   - down = 7 - up, south = 7 - north, east = 7 - west
2. cin >> T
3. while(T != 0)
4.      Create Die instance
5.      for(i = 0 to T-1)
6.          cin >> direction
7.          Use "7 - value" to calculate derived faces and update
8.      cout << mydie.up
9.      cin >> T
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 定義結構體 Die { int up, north, west }
   - 注意：只存 3 個相鄰面，其他 3 個面用「7 - 值」推導
   - 下 = 7 - up, 南 = 7 - north, 東 = 7 - west
2. 讀入 T
3. while 迴圈 (T != 0)
4.      建立 Die 結構體實例
5.      for 迴圈 (i 從 0 到 T-1)
6.          讀入方向字元
7.          使用「7 - 值」計算推導面並更新
8.      輸出 mydie.up
9.      讀入下一個 T
```
</details>

### version 3 - 邏輯:
```text
1. Define struct Die { all 6 faces }
2. cin >> T
3. while(T != 0)
4.      Create Die instance
5.      for(i = 0 to T-1)
6.          cin >> direction
7.          Use tie() = make_tuple() for atomic simultaneous assignment of 4 faces
8.      cout << mydie.up
9.      cin >> T
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 定義結構體 Die { 所有 6 個面 }
2. 讀入 T
3. while 迴圈 (T != 0)
4.      建立 Die 結構體實例
5.      for 迴圈 (i 從 0 到 T-1)
6.          讀入方向字元
7.          使用 tie() = make_tuple() 同時交換 4 個相關面
8.      輸出 mydie.up
9.      讀入下一個 T
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 | O(T) per test case | O(1) - 6 global variables |
| V2 | O(T) per test case | O(1) - struct with 3 members |
| V3 | O(T) per test case | O(1) - struct with 6 members |

## 版本對比

| 特性 | V1 | V2 | V3 |
| :--- | :--- | :--- | :--- |
| 資料結構 | 全域變數 | 結構體（3個面） | 結構體（6個面） |
| 記憶體使用 | 6 個變數 | 3 個變數 | 6 個變數 |
| 邏輯複雜度 | 中 | 高（需推導） | 低（直觀） |
| 程式碼簡潔度 | 中 | 中 | 高 |
| 易讀性 | 中 | 低 | 高 |
| 推薦指數 | ⭐⭐⭐ | ⭐⭐ | ⭐⭐⭐⭐ |
