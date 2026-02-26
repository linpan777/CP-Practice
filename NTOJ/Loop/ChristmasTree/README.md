> **Topic**: 雙層迴圈與邏輯觀察 (Nested Loops & Pattern Recognition)  
> **Language**: C++  
> **Date**: 2026-02-26  
> **Author**: Lin Pan

## 一、思路建立
### 1. 觀察圖形規律
假設我們要印出一棵層數 `n=3` 的樹，圖形如下：
```C++
  * (Layer i=1 | Spaces=2<kbd>(n-i)</kbd> | Stars=1)
 *** (Layer i=2 | Spaces=1<kbd>(n-i)</kbd> | Stars=3)
***** (Layer i=3 | Spaces=0<kbd>(n-i)</kbd> | Stars=5)
```

### 2. 核心邏輯繪製順序：
程式執行是由上而下 (Row by row)、由左至右 (Left to right)。拆解動作：每一層必須先印出「左側空格」，接著印出「星星」，最後「換行」。數學關係：空格 (Spaces): 隨著層數增加而減少 $\rightarrow$ n - i星星 (Stars): 隨著層數增加而變寬，且呈現奇數成長 $\rightarrow$ 2 * i - 1

## 二、思路變化
### v1 直觀解法：
巢狀迴圈最直覺的想法，利用多個 for loop 分別控制空格與星星。特點：邏輯拆解詳細，適合初學者理解流程。缺點：程式碼較冗長。
```C++
for (int i = 1; i <= n; i++) {
    // Step 1: Print Spaces
    for (int j = 0; j < n - i; j++) cout << " ";
    // Step 2: Print Stars
    for (int k = 0; k < 2 * i - 1; k++) cout << "*";
    // Step 3: New Line
    cout << endl;
}
```

### v2 進階優化：字串建構子
經過提示，發現可以利用 C++ std::string 的特性來簡化程式碼。語法：string(數量, '字元')優點：程式碼可讀性大幅提升，減少迴圈變數寫錯的風險。
```C++
for (int i = 1; i <= n; i++) {
    
	for (int i{ 1 }; i <= input; i++)
		cout << string(input - i, ' ') 
         <<  string(i * 2 - 1, '*') 
         << '\n';
}
```
## 三、坑點總結
### 1.數學級數的計算
\*為 2\*i-1的級數而非純等差

## 四、最終邏輯
### 1. 變數對照表
| 變數 (Variable) | 意義 (Meaning) | 計算公式 (Formula) |
| :--- | :--- | :--- |
| `n` | 樹的總高度 | Input |
| `i` | 目前第幾層 | Loop `1` to `n` |
| `Space` | 左側空格數 | `n - i` |
| `Star` | 星星數量 | `2 * i - 1` |

### 2. 執行流程 (Execution)
程式碼的最終型態是一個 **單層迴圈**，內容如下：
```cpp
// Pseudo Code
Loop (i from 1 to n) {
    Print( Spaces(n-i) );   // 先印空格
    Print( Stars(2*i-1) );  // 再印星星
    Print( NewLine );       // 最後換行
}
```
