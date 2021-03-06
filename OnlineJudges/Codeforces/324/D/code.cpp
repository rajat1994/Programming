#include <bits/stdc++.h> 

#define MAX 1000100 
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

int n;

bool isPrime(int x) {
    if(x < 2) return false;
    if(x == 2) return true;
    for(int i = 2; i <= sqrt(x); i++)
        if(x % i == 0) return false;
    return true;
}

int main() {
 
    while(scanf("%d",&n) != EOF){
        vector<int> ans;
        int aux = n;
        int cont = 0;
        while(n > 0) {
            if (cont == 1 && isPrime(aux) && n-aux == 0) { ans.pb(aux);  n -= aux; aux = n; cont++; }
            else if(cont == 1 && isPrime(aux) && isPrime(n-aux)) { ans.pb(aux); ans.pb(n-aux); cont++; n = 0; }
            else if(cont != 1 && isPrime(aux)) { ans.pb(aux);  n -= aux; aux = n; cont++; }
            else aux--;
        }

        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    }

	return 0; 
}
