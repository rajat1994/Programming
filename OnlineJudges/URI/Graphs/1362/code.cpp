#include <bits/stdc++.h>
#define MAX 230
#define pb push_back

using namespace std;

map<string, int> mapa;
bool visited[MAX];
vector<int> adj[MAX];
int n, t, q, matched[MAX];
string c1,c2;

bool match(int x) {

    visited[x] = true;
    for(int i = 0; i < adj[x].size(); i++){
        
        int v = adj[x][i];

        if(!visited[v]){
            visited[v] = true;
            if(matched[v] < 0 || match(matched[v]))
            {
                matched[v] = x;
                matched[x] = v;
                return true;
            }
        }
    }
    return false;
}

void matchMaker() {

    int ans = 0;
    for(int i = 1; i <= n; i++){
        memset(visited, false,sizeof visited);
        if(match(i))
            ans++;
    }

    if(ans == n) printf("YES\n");
    else printf("NO\n");
}


int main() {

    mapa["L"] = 6; mapa["M"] = 7; mapa["XL"] = 8; mapa["XXL"] = 9;
    mapa["S"] = 10; mapa["XS"] = 11;
    
    scanf("%d",&q);

    while(q--) {
        scanf("%d %d",&t,&n);
        
        for(int i = 0; i <= n; i++) adj[i].clear();
        
        for(int i = 1; i <= n; i++) {
            cin >> c1 >> c2;
            for(int j = 0; j < t/6; j++){
                adj[i].pb(mapa[c1]*6 + j);
                adj[i].pb(mapa[c2]*6 + j);
            }
        }
    
        memset(matched, -1, sizeof matched);
        matchMaker();
    }
    return 0;
}
