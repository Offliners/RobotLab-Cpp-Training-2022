### Pointer Graph
![Point table](./Pointer%20Graph.png)

### Answer
|Expression|Address or variable|Data type|
|-|-|-|
|arr|{A, B, C, D}|int [4]|
|arr[0]|A|int|
|arr+1|b|int *|
|tab+1|h|int (*)[2]|
|tab[1]|{G, H}|int [2]|
|tab[1]+1|i|int*|
|tab[1][1]|H|int|		
|&tab[1][1]|i|int*|	
|&tab[1][1]+1|j|int*|		
|p+0|b|int*|	
|p+1|c|int*|		
|*p|B|int|
|p[2]|D|int|		
|mp[0][1]|B|int|		
|mp[1][1]|J|int|		
|*pp+2|d|int*|		
|qq[1]|j|int*|		
|qq[1]+1|k|int*|		
|qq[0][0]|A|int|		
|qq[1][0]|I|int|		
|s[0][1]|F|int|		
|s[1][0]|G|int|	