> **Topic**: 雙層迴圈與邏輯觀察 (Nested Loops & Pattern Recognition)  
> **Language**: C++  
> **Date**: 2026-02-26  
> **Author**: Lin Pan

## 🧐 一、思路建立 (Problem Analysis)

### 1. 觀察圖形規律
假設我們要印出一棵層數 `n=3` 的樹，圖形如下：

```text
  * (Layer i=1 | Spaces=2 | Stars=1)
 *** (Layer i=2 | Spaces=1 | Stars=3)
***** (Layer i=3 | Spaces=0 | Stars=5)
2. 核心邏輯繪製順序：程式執行是由上而下 (Row by row)、由左至右 (Left to right)。拆解動作：每一層必須先印出「左側空格」，接著印出「星星」，最後「換行」。數學關係：空格 (Spaces): 隨著層數增加而減少 $\rightarrow$ n - i星星 (Stars): 隨著層數增加而變寬，且呈現奇數成長 $\rightarrow$ 2 * i - 1🚀 二、思路變化 (Evolution of Solution)v1 直觀解法：巢狀迴圈 (Nested Loops)最直覺的想法，利用多個 for loop 分別控制空格與星星。特點：邏輯拆解詳細，適合初學者理解流程。缺點：程式碼較冗長。C++// 偽代碼概念 (Pseudo Code)
for (int i = 1; i <= n; i++) {
    // Step 1: Print Spaces
    for (int j = 0; j < n - i; j++) cout << " ";
    // Step 2: Print Stars
    for (int k = 0; k < 2 * i - 1; k++) cout << "*";
    // Step 3: New Line
    cout << endl;
}
v2 進階優化：字串建構子 (String Constructor) ✨經過提示，發現可以利用 C++ std::string 的特性來簡化程式碼。語法：string(數量, '字元')優點：程式碼可讀性 (Readability) 大幅提升，減少迴圈變數寫錯的風險。C++// 優化後的寫法
for (int i = 1; i <= n; i++) {
    cout << string(n - i, ' ')        // 一次印出所有空格
         << string(2 * i - 1, '*')    // 一次印出所有星星
         << endl;
}
⚠️ 三、坑點總結 (Pitfalls & Key Takeaways)在實作過程中容易遇到的問題：1. 數學級數的計算星星的數量不是單純 +1，而是 1, 3, 5, 7... 的等差級數。💡 Formula: Star Count = 2 * i - 12. 常見錯誤檢查清單 (Checklist)[x] 迴圈起始點：確認 i 是從 0 還是 1 開始？（這會影響公式是 2i+1 還是 2i-1）。[x] 行尾空格 (Trailing Spaces)：通常星星印完需直接換行 (endl)，不要誤印多餘的空格，否則 OJ (Online Judge) 判題會錯誤。[x] 輸入邊界：當 n=0 或 n=1 時，程式是否能正常運作？📝 四、心得與延伸 (Reflections)這題讓我學到了兩個重點：觀察力：圖形題的核心在於找到 row_index (層數) 與 count (數量) 的函數關係。工具力：從手寫迴圈進化到使用 string 建構子，學會利用語言特性 (STL) 來讓程式碼更優雅。