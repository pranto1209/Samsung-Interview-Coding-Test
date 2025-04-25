#include<bits/stdc++.h>
using namespace std;
#define maxn 15
#define inf 10000000
int n, g[maxn][maxn];

int main()
{
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>g[i][j];
            }
        }

        vector<int> v;
        int ans = inf;
        for(int i=1; i<n; i++) v.push_back(i);

        do {
            int total = g[0][v[0]];
            for(int i=1; i<int(v.size()); i++) total += g[v[i-1]][v[i]];
            total += g[v.back()][0];
            ans = min(ans, total);
        }
        while(next_permutation(v.begin(), v.end()));

        cout<<ans<<"\n";
    }
}
