#include <bits/stdc++.h>
using namespace std;
#define maxn 55
int n, m, l, fl;
int a[maxn][maxn], vis[maxn][maxn];

bool valid(int x, int y)
{
    if(x >= 0 and x < n and y >= 0 and y < m and !vis[x][y] and a[x][y]) return true;
    else return false;
}

void dfs(int x, int y)
{
    if(valid(x, y)) {
        vis[x][y] = 1;
        if(a[x][y] == 3) {
            fl = 1;
            return;
        }
        dfs(x, y+1);
        dfs(x, y-1);
        for(int h=0; h<=l; h++) dfs(x+h, y);
        for(int h=0; h<=l; h++) dfs(x-h, y);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>a[i][j];
    
    for(l=0; l<n; l++) {
        memset(vis, 0, sizeof(vis));
        fl = 0;
        dfs(n-1, 0);
        if(fl) {
            cout<<l;
            break;
        }
    }
}
