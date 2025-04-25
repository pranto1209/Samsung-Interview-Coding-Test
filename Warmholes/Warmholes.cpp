#include <bits/stdc++.h>
using namespace std;
#define maxn 15
#define pii pair<int, int>
#define inf 1000000
int n, cost[maxn][maxn], dis[maxn];
vector<pii> g[maxn];

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for(int i=0; i<maxn; i++) dis[i] = inf;
    dis[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        for(int i=0; i < int(g[u].size()); i++) {
            int v = g[u][i].first;
            int w = g[u][i].second;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        for(int i=0; i<maxn; i++) g[i].clear(), dis[i] = 0;

        int cx[maxn], cy[maxn], c[maxn];
        cin >> n >> cx[0] >> cy[0] >> cx[1] >> cy[1];
        n = 2 * n + 2; 
        for(int i=2; i<n; i+=2) {
            cin >> cx[i] >> cy[i] >> cx[i+1] >> cy[i+1] >> c[i];
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int val = abs(cx[i] - cx[j]) + abs(cy[i] - cy[j]);
                cost[i][j] = val;
                cost[j][i] = val;
            }
        }
        for(int i=2; i<n; i+=2) {
            int val = c[i];
            cost[i][i+1] = val;
            cost[i+1][i] = val;
        }
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                g[i].push_back({j, cost[i][j]});
                g[j].push_back({i, cost[j][i]});
            }
        }

        dijkstra(0);

        cout<<dis[1]<<"\n";
    }
}
