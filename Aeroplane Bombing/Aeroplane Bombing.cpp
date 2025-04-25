#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define maxn 15

int main()
{
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) {
        int n, a[maxn][7] = {}, ta[maxn][7] = {}, dp[maxn][7] = {};
        for(int i=0; i<maxn; i++) for(int j=0; j<7; j++) dp[i][j] = -inf;
        dp[0][3] = 0;

        cin>>n;
        for(int i=n; i>0; i--) {
            for(int j=1; j<=5; j++) cin>>a[i][j];
        }

        int ans = 0;
        for(int k=1; k+5-1 <= max(n, 5); k++) {
            for(int i=1; i<=n; i++) for(int j=1; j<=5; j++) ta[i][j] = a[i][j];
            for(int i=k; i <= min(k+5-1, n); i++) {
                for(int j=1; j<=5; j++) {
                    if(ta[i][j] == 2) ta[i][j] = 0;
                }
            }
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=5; j++) {
                    if(ta[i][j] == 2) dp[i][j] = -inf;
                    else {
                        dp[i][j] = ta[i][j] + max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
                        if(dp[i][j] - ta[i][j] == -inf) dp[i][j] = -inf;
                    }
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
}
