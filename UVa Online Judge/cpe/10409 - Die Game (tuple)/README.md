# 10409 - Die Game

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=242&page=show_problem&problem=1350)

## 簡介:
模擬骰子的滾動。給定一個標準骰子的初始狀態，以及一系列滾動方向（北、南、東、西），輸出最終骰子朝上的面的數字。
- 骰子初始狀態：1 朝上，6 朝下，2 朝北，5 朝南，3 朝西，4 朝東
- 骰子的重要性質：對面之和永遠為 7（1+6=7, 2+5=7, 3+4=7）

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | The number of operations |
| `up, down, north, south, east, west` | <sub>Used in `V1`</sub> Six faces of the die |
| `mydie` | <sub>Used in `V2`, `V3`</sub> A `struct Die` to store the die state |
| `direction` | The rolling direction ('n', 's', 'e', 'w') |

### version 1 - 邏輯 (全域變數逐個交換):
```text
1. cin >> T
2. while(T != 0)
3.      重置骰子初始狀態
4.      for(i = 0 -> T-1)
5.          cin >> direction
6.          根據方向執行旋轉：使用臨時變數進行 4 個相關面的交換
7.      輸出 up
8.      cin >> T
```

<details>
<summary><head>核心概念：</head></summary>

- 使用 6 個全域變數分別代表骰子的 6 個面
- 每次旋轉時，臨時保存朝上面，再依序交換 4 個相關面
- 例如向北滾動：上→北, 北→下, 下→南, 南→上

</details>

### version 2 - 邏輯 (結構體 + 骰子性質推導):
```text
1. 定義 struct Die { int up, north, west }
2. 注意：只存 3 個面，其他 3 個面用「7 - value」推導
   - down = 7 - up
   - south = 7 - north
   - east = 7 - west
3. cin >> T
4. while(T != 0)
5.      創建 Die 結構體實例
6.      for(i = 0 -> T-1)
7.          cin >> direction
8.          根據方向執行旋轉：利用「7 - value」進行計算
9.      輸出 mydie.up
10.     cin >> T
```

<details>
<summary><head>核心概念：</head></summary>

- 利用骰子的數學性質：**對面之和為 7**
- 只需存儲 3 個相鄰面（up, north, west）
- 其他 3 個面（下、南、東）可動態推導，節省記憶體
- 例如向北滾動：下(7-north) → 上, 上 → 北, 北 → 下, 南 → 南 (無變化)

</details>

### version 3 - 邏輯 (結構體 + tuple 同時賦值):
```text
1. 定義 struct Die { 存儲所有 6 個面 }
2. cin >> T
3. while(T != 0)
4.      創建 Die 結構體實例
5.      for(i = 0 -> T-1)
6.          cin >> direction
7.          根據方向執行旋轉：使用 tie() = make_tuple() 同時交換
8.      輸出 mydie.up
9.      cin >> T
```

<details>
<summary><head>核心概念：</head></summary>

- 使用結構體存儲所有 6 個面
- 利用 C++ 的 `tie()` 和 `make_tuple()` 進行原子性的同時賦值
- 避免心智負擔和計算錯誤
- 邏輯最直觀：明確寫出每個面的新值
- 例如向北滾動：`tie(up, north, down, south) = make_tuple(south, up, north, down)`

</details>

## 版本對比

| 特性 | V1 | V2 | V3 |
| :--- | :--- | :--- | :--- |
| 資料結構 | 全域變數 | 結構體（3個面） | 結構體（6個面） |
| 記憶體使用 | 6 個變數 | 3 個變數 | 6 個變數 |
| 邏輯複雜度 | 中 | 高（需推導） | 低（直觀） |
| 程式碼簡潔度 | 中 | 中 | 高 |
| 易讀性 | 中 | 低 | 高 |
| 推薦指數 | ⭐⭐⭐ | ⭐⭐ | ⭐⭐⭐⭐ |
