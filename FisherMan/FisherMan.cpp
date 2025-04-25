#include <bits/stdc++.h>
#define inf 10000000
using namespace std;

int main()
{
    int n, g1, g2, g3, gn1, gn2, gn3;
    cin>>n;
    cin>>g1>>g2>>g3;
    cin>>gn1>>gn2>>gn3;
    int ans = inf;
    for(int i=1; i+gn1 <= n-gn2-gn3+1; i++) {
        for(int j=i+gn1; j+gn2 <= n-gn3+1; j++) {
            for(int k=j+gn2; k+gn3 <= n+1; k++) {
                int cost = 0;
                for(int u=i; u<gn1+i; u++) cost += abs(g1 - u);
                for(int u=j; u<gn2+j; u++) cost += abs(g2 - u);
                for(int u=k; u<gn3+k; u++) cost += abs(g3 - u);
                cost += gn1 + gn2 +gn3;
                ans = min(ans, cost);
            }
        }
    }
    cout<<ans<<"\n";
}
