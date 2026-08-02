# 217. Contains Duplicate

**難度：** `Easy`
**標籤：** `Array`, `Hash Table`, `Hash Set`

## 題目描述
給定一個整數陣列 `nums`，如果陣列中有任何數字出現 **兩次 (含) 以上**，就回傳 `true`；如果陣列中所有數字都是獨一無二的，則回傳 `false`。

## 解題思路

### 最佳解法：使用 Hash Set (空間換取時間)
這題是 LeetCode #1 (Two Sum) 的觀念延伸。既然我們只在乎數字「有沒有出現過」，而不在乎它出現的位置或次數，我們可以使用比 `unordered_map` 更精簡的 `unordered_set` (無序集合)。

1. 建立一個 `unordered_set` 當作「已經看過的數字清單」。
2. 遍歷陣列中的每一個數字 `nums[i]`：
   * 檢查清單：如果這個數字已經在清單裡，代表我們找到重複的數字了，立刻回傳 `true`。
   * 如果不在清單裡，就把這個數字加進清單中。
3. 如果整趟迴圈跑完都沒有發現重複的數字，就回傳 `false`。

## 複雜度分析
* **時間複雜度：** $O(n)$
  只需要把陣列逛過一次。在 `unordered_set` 中查詢與插入的時間複雜度平均為 $O(1)$。
* **空間複雜度：** $O(n)$
  最壞的情況下（沒有重複數字），我們需要將陣列中所有的元素都存入 Hash Set 中。

## 踩坑紀錄與常見陷阱 (Common Pitfalls)

在將 `unordered_map` 觀念轉換為 `unordered_set` 時，容易遇到以下 C++ STL 報錯（例如 `hashtable_policy.h` 相關的落落長紅字）：

1. **宣告參數錯誤 (Template Argument Mismatch)：**
   * ❌ **錯誤：** `unordered_set<int, int> appear;` (Set 只能存單一元素，不能像 Map 一樣存 Key-Value Pair，多塞一個 int 會導致編譯器在底層函式庫中迷失)。
   * ✅ **正確：** `unordered_set<int> appear;`。
2. **混淆 Map 與 Set 的寫入語法：**
   * 如果使用 Map (`unordered_map`)，寫入時需使用 `appear[nums[i]] = 1;` 或 `appear.insert({nums[i], 1});`。
   * 如果使用 Set (`unordered_set`)，因為只存 Key，直接把數字丟進去即可 `appear.insert(nums[i]);`。

## 學習心得
有了 Two Sum 的經驗，這題我成功舉一反三，將原本用來記錄「數字與位置」的 `unordered_map`，優化成只需記錄「數字是否存在」的 `unordered_set`。過程中雖然踩到了 STL 的宣告語法陷阱，但也因此更清楚 Map 和 Set 在底層機制與實作上的差異。