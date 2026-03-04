# 10038 - Jolly Jumper

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=979)

## 邏輯：
```text
1. input n
2. bool jolly = true, bool number[3000] = false;
3. input first
4. for(1 -> n - 1)
5.      cin second
6.      number[abs(first - second)] = true
7.      first = second
8. for(1 -> n - 1)
9.      if(number[i] == false), jolly = false, break
10.     else, continue
11. if(jolly) cout Jolly
12. else cout Not Jolly
```