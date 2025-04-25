#include<bits/stdc++.h>
using namespace std;
#define maxn 15
#define inf 10000000
int n, g[maxn][maxn];

int main()
{
    for(int tc = 1; tc<=10; tc++) {
        memset(g, 0, sizeof(g));
        cin>>n;
        int ox, oy, hx, hy, cx[maxn], cy[maxn];
        cin >> ox >> oy >> hx >> hy;
        for(int i=1; i<=n; i++) {
            cin >> cx[i] >>cy[i];
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

        vector<int> v;
        int ans = inf;
        for(int i=1; i<=n; i++) v.push_back(i);

        do {
            int total = g[0][v[0]];
            for(int i=1; i<int(v.size()); i++) total += g[v[i-1]][v[i]];
            total += g[v.back()][n+1];
            ans = min(ans, total);
        }
        while(next_permutation(v.begin(), v.end()));

        cout<<"# "<<tc<<" "<<ans<<"\n";
    }
}
