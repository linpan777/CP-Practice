# 10242 - Fourth Point !!

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1183)

## 簡介

給定平行四邊形兩個相鄰邊的端點座標（輸入 4 個點，其中必定有 2 個點座標完全相同，即為兩邊的交點）。要求找出平行四邊形第四個對角點的座標。

1. **核心幾何性質**：第四點公式為 `D = A + B - C`（其中 `C` 為交點，`A`、`B` 為另外兩端點）
2. **數學降維優化**：利用 4 個輸入點的總和 `Sum = A + B + 2C`，推導出 `D = Sum - 3C` 來簡化程式碼
3. 可採用函式逐一配對找出 A、B、C（V1），或是使用結構體配合數學公式降維打擊（V2）

<details>
<summary><head>點擊查看「D = Sum - 3C」數學降維打擊的原理</head></summary>

### 基礎向量公式

在平行四邊形中，`D = A + B - C`

從交點 `C` 走到端點 `A` 的位移量（向量 `A - C`），必定等於從端點 `B` 走到第四點 `D` 的位移量（向量 `D - B`）。

**推導過程：**

```
A - C = D - B
```

**移項得：**

```
D = A + B - C
```

### 進階優化公式

`D = Sum - 3C`

題目輸入會給我們 4 個點（第一條邊 2 個、第二條邊 2 個）。因為兩邊相鄰，所以這 4 個點裡面，包含了：**一個 A、一個 B、和兩個重複的 C**。

**步驟一**：計算 4 個點的總和

```
Sum = A + B + 2C
```

**步驟二**：我們需要的答案是

```
A + B - C
```

**步驟三**：觀察兩式的關係

只要拿總和 `Sum` 減去 3 個 `C`，就會剛好等於答案：

```
Sum - 3C = (A + B + 2C) - 3C = A + B - C
```

### 為什麼 V2 要用這個數學技巧？

- **免去分配煩惱**：不需要寫一堆 `if-else` 去把剩下的點指派給變數 A 或 B，只要找出重複的點 C 是誰就好
- **大幅縮減程式碼**：不用傳遞多達 14 個參數的函式，邏輯超乾淨

</details>

<details>
<summary><head>點擊查看 setprecision 的用法</head></summary>

### setprecision 的基本用法

`setprecision(n)` 用來控制浮點數的精度（小數位數）。但其行為取決於是否搭配 `fixed` 使用。

### 有無 `fixed` 的區別

#### 情況一：單獨使用 `setprecision(n)`（無 `fixed`）

顯示**總共 n 位有效數字**（科學記號法）

```cpp
double x = 123.456789;
cout << setprecision(3) << x;  // 輸出：123 (3個有效數字)

double y = 0.00456789;
cout << setprecision(3) << y;  // 輸出：4.57e-03 (科學記號)
```

#### 情況二：搭配 `fixed` 使用

顯示**小數點後 n 位**（固定點法）

```cpp
double x = 123.456789;
cout << fixed << setprecision(3) << x;  // 輸出：123.457 (小數點後3位)

double y = 0.00456789;
cout << fixed << setprecision(3) << y;  // 輸出：0.005 (小數點後3位)
```

### 這題的做法

```cpp
cout << fixed << setprecision(3) << resultX << ' ' << resultY << '\n';
```

使用 `fixed + setprecision(3)` 確保：
- ✅ 輸出結果精確到小數點後 3 位
- ✅ 避免科學記號
- ✅ 符合題目要求的輸出格式

</details>

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `x1~y4` / `a, b, c, d` | The coordinates of the 4 input points |
| `xA, yA, xB, yB` | <sub>Used in `V1`</sub> The coordinates of the two non-intersecting endpoints |
| `xC, yC` / `samePoint` | The coordinates of the intersecting point (Point C) |
| `sumX, sumY` | <sub>Used in `V2`</sub> The sum of the X and Y coordinates of all 4 input points |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `x1~y4` / `a, b, c, d` | 輸入的 4 個點座標 |
| `xA, yA, xB, yB` | <sub>用於 `V1`</sub> 兩個非交點的端點座標 |
| `xC, yC` / `samePoint` | 兩條邊相交的交點座標（點 C） |
| `sumX, sumY` | <sub>用於 `V2`</sub> 輸入的 4 個點之 X 與 Y 座標總和 |

</details>

### version 1 - 邏輯:
```text
1. while cin >> 8 coordinates (Points: P1, P2, P3, P4)
2.      Inside judge(), compare points to find the identical pair (Point C):
3.          If P1 == P3 or P1 == P4 -> C = P1, remaining points are A and B
4.          If P2 == P3 or P2 == P4 -> C = P2, remaining points are A and B
5.      Print (xA + xB - xC) and (yA + yB - yC) formatted to 3 decimal places
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀取 8 個浮點數 (代表 P1, P2, P3, P4 四個點) 直到 EOF
2.      在 judge() 內比對座標，尋找重複的交點 C：
3.          若 P1 等於 P3 或 P4，則 C = P1，剩餘兩點為 A 和 B
4.          若 P2 等於 P3 或 P4，則 C = P2，剩餘兩點為 A 和 B
5.      利用公式 (A + B - C)，精準輸出小數點後 3 位的座標
```
</details>

### version 2 - 邏輯:
```text
1. Define struct Point { double x, y }
2. while cin >> 4 Points (a, b, c, d)
3.      sumX = a.x + b.x + c.x + d.x
4.      sumY = a.y + b.y + c.y + d.y
5.      Use if/else to find the identical point and store it in samePoint (C)
6.      Print (sumX - 3 * samePoint.x) and (sumY - 3 * samePoint.y) formatted to 3 decimal places
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 定義結構體 Point 包含 x 和 y 座標
2. 讀取 4 個 Point (a, b, c, d) 直到 EOF
3.      計算 4 個點的 x 座標總和 sumX
4.      計算 4 個點的 y 座標總和 sumY
5.      使用 if/else 找出座標相同的點，並存入 samePoint (即交點 C)
6.      利用優化公式 (Sum - 3C)，精準輸出小數點後 3 位的座標
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 | $O(1)$ per test case | $O(1)$ - uses standard local double variables |
| V2 | $O(1)$ per test case | $O(1)$ - uses Point structs |

<details>
<summary><head>點擊查看中文版</head></summary>

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 | $O(1)$ 每個測資 | $O(1)$ - 使用基本的區域變數 |
| V2 | $O(1)$ 每個測資 | $O(1)$ - 使用 Point 結構體 |

</details>

## 版本對比

| 特性 | V1 | V2 |
| :--- | :--- | :--- |
| 資料結構 | 散裝區域變數 (`double`) | 結構體封裝 (`struct Point`) |
| 函式參數數量 | 14 個參數（易傳錯） | 無額外函式，直接在主程式運算 |
| 數學邏輯 | $D = A + B - C$ | $D = Sum - 3C$ |
| 程式碼簡潔度 | 低 | 高 |
| 易讀性 | 中（找 A、B 略顯繁瑣） | 高（直接找 C 即可） |
| 推薦指數 | ⭐⭐⭐ | ⭐⭐⭐⭐⭐ |