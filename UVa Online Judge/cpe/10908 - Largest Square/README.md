# 10908 - Largest Square

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1849)

## Introduction:
The core of this problem is "matrix expansion" or "center-based search." Given a grid and a fixed center coordinate $(r, c)$, we need to find the largest square where all characters are identical. 
1. Since the center point is fixed at a specific cell, the side length of any valid square must be an odd number. We solve this by setting a radius `d` to expand outward. In each expansion step, we check if the new boundaries are within the grid bounds, and verify that all characters within the current radius match the center character (`goalChar`).

<details>
<summary><head>點擊查看中文版</head></summary>

核心是「矩陣擴張」或「中心點搜索」。給定一個網格和一個中心座標 $(r, c)$，需要找出所有字元都相同的最大正方形。
1. 中心點固定在特定的格子上，所以合法正方形的邊長一定會是奇數，透過設定一個半徑 `d` 向外擴張，每次擴張時檢查新的邊界是否超出網格，並確認該範圍內的所有字元是否與中心點的字元（`goalChar`）相同。

> [!NOTE]
> 一句話筆記：遇到固定中心的矩陣擴張，邊長必為奇數，用半徑 d 向外擴張檢查邊界與字元。
</details>

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `M`, `N` | The height and width of the grid |
| `square` | The 2D array storing the grid characters |
| `r`, `c` | The center coordinates for the current query |
| `goalChar` | The target character located at `square[r][c]` |
| `d` | The expansion radius (starts at 1) |

<details>
<summary><head>點擊查看中文版</head></summary>

### 變數參考：
| variable | meaning |
| :--- | :--- |
| `M`, `N` | 網格的高度和寬度 |
| `square` | 儲存網格字元的二維陣列 |
| `r`, `c` | 當前查詢的中心座標 |
| `goalChar` | 位於 `square[r][c]` 的目標字元 |
| `d` | 擴張半徑（初始值為 1） |
</details>

## 邏輯:
```text
1. Read T (test cases)
2. For each test case:
3.     Read M, N, Q and print them as required
4.     Read the M×N grid
5.     For each query (r, c):
6.         Set goalChar = square[r][c]
7.         Initialize d = 1
8.         While (r±d, c±d) is within grid bounds:
9.             If all chars in this square boundary equal goalChar:
10.                d++
11.            Else:
12.                Output 2*d - 1 and break
13.        If loop ends naturally (hit boundary):
14.            Output 2*d - 1
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀取測資數量 T
2. 對每個測資:
3.     讀取 M, N, Q 並輸出
4.     讀取 M×N 網格
5.     對每個查詢 (r, c):
6.         設定 goalChar = square[r][c]
7.         初始化 d = 1
8.         當 (r±d, c±d) 在網格內:
9.             若正方形邊界內的字元都等於 goalChar:
10.                d++
11.            否則:
12.                輸出 2*d - 1 並結束
13.        若迴圈自然結束: //撞到邊界
14.            輸出 2*d - 1
```
</details>

## Complexity
### Time Complexity: $O(T \cdot (M \cdot N + Q \cdot \min(M, N)^2))$
> For each test case, reading the grid takes $O(M \cdot N)$. For each query $Q$, expanding and checking the square takes at most $O(\min(M, N)^2)$ operations.
### Space Complexity: $O(M \cdot N)$
> The memory is mainly used to store the 2D character grid `square` of size $101 \times 101$.

<details>
<summary><head>點擊查看中文版</head></summary>

### Time Complexity: $O(T \cdot (M \cdot N + Q \cdot \min(M, N)^2))$
> 每個測資讀取網格需 $O(M \cdot N)$。每次詢問 $Q$ 在最壞情況下（整個網格字元都一樣），向外擴張檢查的次數約為 $O(\min(M, N)^2)$。雖然有三層迴圈，但因題目限制 $M, N \le 100$，運算量完全在安全範圍內。
### Space Complexity: $O(M \cdot N)$
> 空間複雜度取決於儲存網格的二維字元陣列 `square`，大小為常數級別的 $101 \times 101$，非常節省記憶體。
</details>