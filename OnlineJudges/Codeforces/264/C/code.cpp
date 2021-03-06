#include <bits/stdc++.h> 

#define MAX 2100 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

ll d1[2 * MAX], d2[2 * MAX], res[2], n;
pii v[2];
int mat[MAX][MAX];

void update(int c, int i, int j, ll val){
    if(val > res[c]){
        res[c] = val;
        v[c].F = i;
        v[c].S = j;
    }
}

int main() {

    scanf("%lld", &n);
	res[0] = res[1] = -1; 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            scanf("%d", &mat[i][j]);
            d1[i + j] += mat[i][j];
            d2[i - j + n] += mat[i][j];
        }
 
    for(int i = 1; i <= n; i++)
        for(int j = 1;j <= n; j++)
            update((i+j) % 2 == 1, i, j, d1[i+j] + d2[i-j+n] - mat[i][j]);
    
	printf("%lld\n", res[0] + res[1]);
    printf("%d %d %d %d\n", v[0].F, v[0].S, v[1].F, v[1].S);
	return 0;
}
