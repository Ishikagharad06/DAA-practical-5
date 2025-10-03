#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
int val;
char dir;
} Array;
Array c[MAX][MAX];
void LCS(char a[], char b[], int m, int n) {
for (int i = 0; i <= m; i++) {
c[i][0].val = 0;
c[i][0].dir = 'H';
}
for (int j = 0; j <= n; j++) {
c[0][j].val = 0;
c[0][j].dir = 'V';
}

for (int i = 1; i <= m; i++) {
for (int j = 1; j <= n; j++) {
if (a[i - 1] == b[j - 1]) {
c[i][j].val = c[i - 1][j - 1].val + 1;
c[i][j].dir = 'D'; // Diagonal
} else {
if (c[i - 1][j].val >= c[i][j - 1].val) {
c[i][j].val = c[i - 1][j].val;
c[i][j].dir = 'U'; // Up
} else {
c[i][j].val = c[i][j - 1].val;
c[i][j].dir = 'L'; // Left
}
}
}
}
}
void Print_LCS(int i, int j, char a[]) {
if (i == 0 || j == 0) {
return;
}
if (c[i][j].dir == 'D') {
Print_LCS(i - 1, j - 1, a);
printf("%c", a[i - 1]);
} else if (c[i][j].dir == 'U') {
Print_LCS(i - 1, j, a);
} else { // c[i][j].dir == 'L'
Print_LCS(i, j - 1, a);
}
}
int main() {
char a[MAX], b[MAX];
printf("Enter the first string: ");
scanf("%s", a);
printf("Enter the second string: ");
scanf("%s", b);
int m = strlen(a);
int n = strlen(b);
LCS(a, b, m, n);

printf("LCS: ");
Print_LCS(m, n, a);
printf("\n");
printf("Cost of LCS: %d\n", c[m][n].val);
return 0;
}