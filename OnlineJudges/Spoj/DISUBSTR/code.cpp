#include <bits/stdc++.h> 

#define MAX 10010
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m;
char T[MAX], P[MAX];
int RA[MAX], tempRA[MAX];
int SA[MAX], tempSA[MAX];
int c[MAX], phi[MAX];
int LCP[MAX], PLCP[MAX];

void countSort(int k) {
	int sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (int i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for (int i = sum = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (int i = 0; i < n; i++)
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for (int i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void makeSA() {
	int r;
	for (int i = 0; i < n; i++) {
		RA[i] = T[i];
		SA[i] = i;
	}
	for (int k = 1; k < n; k <<= 1) {
		countSort(k);
		countSort(0);
		tempRA[SA[0]] = r = 0;
		for (int i = 1; i < n; i++)
			tempRA[SA[i]] =
					(RA[SA[i]] == RA[SA[i - 1]]
							&& RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (int i = 0; i < n; i++)
			RA[i] = tempRA[i];

		if(RA[SA[n-1]] == n - 1) break;
	}
}

pii strMatch() {
	int lo = 0, hi = n - 1, mid = lo;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], P, m);
		if (res >= 0)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (strncmp(T + SA[lo], P, m) != 0)
		return pii(-1, -1);
	pii ans;
	ans.F = lo;
	lo = 0;
	hi = n - 1;
	mid = lo;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], P, m);
		if (res > 0)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (strncmp(T + SA[hi], P, m) != 0)
		hi--;
	ans.S = hi;
	return ans;
}

void compLCP() {
	int i, L;
	phi[SA[0]] = -1;
	for (i = 1; i < n; i++)
		phi[SA[i]] = SA[i - 1];
	for (i = L = 0; i < n; i++) {
		if (phi[i] == -1) { PLCP[i] = 0; continue; }
		while (T[i + L] == T[phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L - 1, 0);
	}
	for (i = 0; i < n; i++)
		LCP[i] = PLCP[SA[i]];
}

int main() {

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", T);
		strcat(T, "$");
		n = strlen(T);
		makeSA();
		compLCP();
		
		int ans = 0;
		for(int i = 1; i <= n-1; i++){
			//printf("%d %d\n",SA[i],LCP[i]);
            ans += (n - SA[i] - 1) - LCP[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
