#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define maxn 20
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
    if(mask == (1<<n)-1) return g[id][0];
    if(dp[id][mask] != -1) return dp[id][mask];
    int ans = inf;
    for(int i=0; i<n; i++) {
        if(isOn(i, mask) == false) {
            ans = min(ans, g[id][i] + solve(i, turnOn(i, mask)));
        }
    }
    return dp[id][mask] = ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        cin>>n;
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>g[i][j];
        
        int ans = solve(0, 1);
        cout<<ans<<"\n";
    }
}
