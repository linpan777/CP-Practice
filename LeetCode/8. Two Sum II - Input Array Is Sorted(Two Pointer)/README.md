# 167. Two Sum II - Input Array Is Sorted

[LeetCode 連結](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | **難度：** `Medium` | **標籤：** `Array`, `Two Pointers`

## 📝 題目大意
給定一個**已由小到大排序**的整數陣列 `numbers` 與一個 `target`。
請找出兩數之和等於 `target` 的組合，並回傳它們的索引值（注意：索引值從 1 開始計算）。
*題目保證必定恰有一組解答，且不能重複使用同一個元素。*

## 💡 解法：相向雙指標 (Two Pointers)
因為陣列「已經排序」，我們可以直接捨棄 Hash Map 帶來的 $O(n)$ 空間消耗，改用雙指標夾攻：
1. **初始站位：** 左指標 `left` 站最前面 (最小值)，右指標 `right` 站最後面 (最大值)。
2. **條件判斷：** 計算兩數之和 `sum = numbers[left] + numbers[right]`：
   * 若 `sum == target`：找到答案，結束迴圈。
   * 若 `sum > target`：總和太大，右指標往左退一步 (`right--`) 讓總和變小。
   * 若 `sum < target`：總和太小，左指標往右走一步 (`left++`) 讓總和變大。
3. **回傳結果：** 將找出的索引值各加 1 後回傳。

## ⏱️ 複雜度
* **時間複雜度：** $O(n)$。左右指標最多共同遍歷陣列一次。
* **空間複雜度：** $O(1)$。只用了兩個整數指標，完美將空間壓縮到極致。

## ⚠️ 避坑指南與核心優化技巧
1. **快取計算結果：** 迴圈內先宣告 `int sum = numbers[left] + numbers[right];` 存起來，避免在 `if-else` 判斷時讓 CPU 重複去記憶體抓值與計算。
2. **初始化串列 (Initializer List)：** 放棄使用 `vector<int> ans` 加上 `push_back()` 的傳統寫法，直接回傳 `{left + 1, right + 1}`，讓編譯器瞬間打包陣列，省下動態配置記憶體的時間。