#include <bits/stdc++.h>
#define maxn 11
using namespace std;
vector<int>g[maxn];
vector<int> cycle, parent;
int color[maxn];
int n, m, min_sum = 10000000;;

void dfs(int u)
{
    if(color[u] == 1) {
        int sum = 0, fl = 0;
        vector<int> tmp_cycle;
        for(auto x: parent) {
            if(x == u) fl = 1;
            if(fl) {
                tmp_cycle.push_back(x);
                sum += x;
            }
        }
        tmp_cycle.pop_back();
        sum -= u;
        if(sum < min_sum) {
            min_sum = sum;
            cycle.clear();
            cycle = tmp_cycle;
        }
        return;
    }

    color[u] = 1;
    for(int v: g[u]) {
        parent.push_back(v);
        dfs(v);
        parent.pop_back();
    }
    color[u] = 0;
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
    }

    for(int u=1; u<=n; u++) {
        if(color[u] == 0) {
            parent.push_back(u);
            dfs(u);
            parent.pop_back();
        }
    }

    sort(cycle.begin(), cycle.end());
    for(int x: cycle) cout<<x<<" ";
}
