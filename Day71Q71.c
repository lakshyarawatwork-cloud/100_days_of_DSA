/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int table[m];
    for (int i = 0; i < m; i++) table[i] = -1;
    
    for (int q = 0; q < n; q++) {
        char op[10];
        int k;
        scanf("%s %d", op, &k);
        
        if (op[0] == 'I') {
            int h = k % m;
            for (int i = 0; i < m; i++) {
                int idx = (h + i * i) % m;
                if (table[idx] == -1) {
                    table[idx] = k;
                    break;
                }
            }
        } else {
            int h = k % m;
            int found = 0;
            for (int i = 0; i < m; i++) {
                int idx = (h + i * i) % m;
                if (table[idx] == k) { found = 1; break; }
                if (table[idx] == -1) break;
            }
            printf("%s\n", found ? "FOUND" : "NOT FOUND");
        }
    }
}