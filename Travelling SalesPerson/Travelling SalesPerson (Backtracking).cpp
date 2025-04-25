#include <bits/stdc++.h>
using namespace std;
#define inf 10000000
#define maxn 20
int n, m, ans, g[maxn][maxn], vis[maxn];

void solve(int id, int mask, int cost)
{
    if(mask == n-1) {
        ans = min(ans, g[id][0] + cost);
        return;
    }

    for(int i=1; i<n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            solve(i, mask + 1, g[id][i] + cost);
            vis[i] = 0;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) {
        memset(vis, 0, sizeof(vis));
        cin>>n;
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>g[i][j];

        ans = inf;
        solve(0, 0, 0);
        cout<<ans<<"\n";
    }
}
