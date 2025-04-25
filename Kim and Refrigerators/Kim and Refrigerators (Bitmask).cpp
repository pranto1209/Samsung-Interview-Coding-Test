#include<bits/stdc++.h>
using namespace std;
#define maxn 15
#define inf 10000000
int n, g[maxn][maxn], dp[maxn][1<<maxn];

int turnOn(int id, int mask)
{
    return mask | (1<<id);
}

bool isOn(int id, int mask)
{
    return mask & (1<<id);
}

int solve(int id, int mask)
{
    if(mask == (1<<n+1)-1) return g[id][n+1];
    if(dp[id][mask] != -1) return dp[id][mask];
    int ans = inf;
    for(int i=0; i<n+1; i++) {
        if(g[id][i] == -1) continue;
        if(isOn(i, mask) == false) {
            ans = min(ans, g[id][i] + solve(i, turnOn(i, mask)));
        }
    }
    return dp[id][mask] = ans;
}

int main()
{
    for(int tc = 1; tc<=10; tc++) {
        memset(dp, -1, sizeof (dp));
        memset(g, -1, sizeof (g));
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
        
        int ans = solve(0, 1);
        cout<<"# "<<tc<<" "<<ans<<"\n";
    }
}
