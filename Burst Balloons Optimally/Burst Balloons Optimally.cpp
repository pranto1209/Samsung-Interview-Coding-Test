#include <bits/stdc++.h>
#define maxn 15
using namespace std;
int n, a[maxn], dp[maxn][maxn];

int solve(int l, int r)
{
    if(dp[l][r] != -1) return dp[l][r];
    int ans = 0;
    for(int i = l + 1; i < r; i++) {
        int sum = solve(l, i) + solve(i, r);
        if(l == 0 and r == n) sum += a[i];
        else sum += (a[l] * a[r]);
        ans = max(ans, sum);
    }
    return dp[l][r] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>n;
    a[0] = 1;
    a[n+1] = 1;
    for(int i=1; i<=n; i++) cin>>a[i];
    n++;
    int ans = solve(0, n);
    cout<<ans<<"\n";
}
