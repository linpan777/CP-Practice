# 217. Contains Duplicate

[LeetCode 連結](https://leetcode.com/problems/contains-duplicate/) | **難度：** `Easy` | **標籤：** `Array`, `Hash Table`, `Hash Set`

## 📝 題目大意
判斷整數陣列 `nums` 中是否有數字重複出現。
若有任何數字出現兩次 (含) 以上回傳 `true`，全都不重複則回傳 `false`。

## 💡 解法：Hash Set (無序集合)
這題是 Two Sum 的觀念延伸。既然只在乎「有沒有出現過」，不關心次數與位置，使用更輕量的 `unordered_set` 是最佳解：
1. **查閱清單：** 遍歷陣列，用 `appear.find(nums[i])` 檢查數字是否在 Set 中。若有，代表重複，回傳 `true`。
2. **加入清單：** 若不在 Set 中，將其存入清單，繼續往下找。
3. **安全下莊：** 迴圈結束都沒觸發 `true`，代表全不重複，回傳 `false`。

## ⏱️ 複雜度
* **時間複雜度：** $O(n)$。僅需遍歷陣列一次，Set 的查詢與插入平均皆為極速的 $O(1)$。
* **空間複雜度：** $O(n)$。最壞情況下（完全無重複數字）需將所有元素存入 Set。

## ⚠️ 避坑指南與核心觀念
1. **宣告參數別搞混：** 
   Set 只存單一元素 (Key)，宣告必須是 `unordered_set<int> appear;`。千萬別習慣性寫成 `<int, int>`，會引發一連串底層函式庫 (`hashtable_policy.h`) 的編譯報錯。
2. **Set 的寫入語法：** 
   Map 可以用中括號寫入 (`table[nums[i]] = 1;`)；但 Set 沒有 Value，只能透過 `insert` 方法將數字丟進去：`appear.insert(nums[i]);`。
3. **武器選擇：** 
   不需要記錄額外資訊 (Value) 時，果斷把 `unordered_map` 換成 `unordered_set` 來減輕記憶體與運算負擔。