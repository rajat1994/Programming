#include <bits/stdc++.h>

using namespace std;

#define MAX 530

char m[MAX][MAX];
int n, k;

void run(int x) {
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= x; j++){
            m[i][j + x] = m[i][j];
            m[i + x][j] = m[i][j];
            m[i + x][j + x] = m[i][j] == '*'? '+' : '*';
        }
}

int main() {

    while(scanf("%d", &n) != EOF) {
		
		m[1][1] = '+';
		k = 1;		
		while (n--) { run(k); k *= 2; }
		
		for(int i = 1; i <= k; i++) {
		    for(int j = 1; j <= k; j++)
		        printf ("%c", m[i][j]);
		    printf ("\n");
		}
	}
    return 0;
}
