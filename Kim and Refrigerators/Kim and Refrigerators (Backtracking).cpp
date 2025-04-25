#include <bits/stdc++.h>
#define inf 10000000
#define maxn 15
using namespace std;
int n, ans, g[maxn][maxn], vis[maxn];

void solve(int id, int mask, int cost)
{
    if(mask == n) {
        ans = min(ans, g[id][n+1] + cost);
        return;
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i] and g[id][i] != -1) {
            vis[i] = 1;
            solve(i, mask+1, g[id][i] + cost);
            vis[i] = 0;
        }
    }
}

int main()
{
    for(int tc = 1; tc<=10; tc++) {
        memset(g, -1, sizeof(g));
        memset(vis, 0, sizeof(vis));
        cin >> n;
        int ox, oy, hx, hy, cx[maxn], cy[maxn];
        cin >> ox >> oy >> hx >> hy;
        for(int i=1; i<=n; i++) {
            cin >> cx[i] >> cy[i];
        }
        for(int i=1; i<=n; i++) {
            int val = abs(ox - cx[i]) + abs(oy - cy[i]);
            g[0][i] = val;
        }
        for(int i=1; i<=n; i++) {
            int val = abs(hx - cx[i]) + abs(hy - cy[i]);
            g[i][n+1] = val;
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int val = abs(cx[i] - cx[j]) + abs(cy[i] - cy[j]);
                g[i][j] = val;
                g[j][i] = val;
            }
        }

        ans = inf;
        solve(0, 0, 0);
        cout<<"# "<<tc<<" "<<ans<<"\n";
    }
}
