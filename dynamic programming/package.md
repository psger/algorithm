#### 有N件物品和一个容量为V的背包。第i件物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使价值总和最大。  
背包容积为10，5种物品，    
价值->重量  
8 6  
7 4  
4 2  
5 4  
5 3  
```c
#include "stdio.h"
define max(a,b) ((a)>(b)?(a):(b))

main(){
  int v = 10;
  int n = 5;

  int value[] = {0, 8, 7, 4, 5, 5};
  int weight[] = {0, 6, 4, 2, 4, 3};

  int i, j;
  int dp[][];
}
```
