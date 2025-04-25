#include <bits/stdc++.h>
#define maxn 1005
#define pii pair<int, int>
using namespace std;
int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, -1, 1};
int a[maxn][maxn], vis[maxn][maxn], dis[maxn][maxn];
int n, m, r, c, ml;

bool valid(int x, int y)
{
    if(x >= 0 and x < n and y >= 0 and y < m and !vis[x][y] and a[x][y]) return true;
    else return false;
}

void bfs(int sx, int sy)
{
    queue<pii> q;
    if(a[sx][sy]) {
        vis[sx][sy] = 1;
        dis[sx][sy] = 1;
        q.push({sx, sy});
    }
    while(!q.empty()) {
        pii top = q.front();
        q.pop();
        int dir[4] = {0};
        int x = top.first, y = top.second;
        if(a[x][y] == 1) {
            if(valid(x-1, y) and (a[x-1][y] == 2 or a[x-1][y] == 5 or a[x-1][y] == 6 or a[x-1][y] == 1)) dir[0] = 1; //Up
            if(valid(x+1, y) and (a[x+1][y] == 2 or a[x+1][y] == 4 or a[x+1][y] == 7 or a[x+1][y] == 1)) dir[1] = 1; //Down
            if(valid(x, y-1) and (a[x][y-1] == 3 or a[x][y-1] == 4 or a[x][y-1] == 5 or a[x][y-1] == 1)) dir[2] = 1; //Left
            if(valid(x, y+1) and (a[x][y+1] == 3 or a[x][y+1] == 6 or a[x][y+1] == 7 or a[x][y+1] == 1)) dir[3] = 1; //Right
        }
        else if(a[x][y] == 2) {
            if(valid(x-1, y) and (a[x-1][y] == 1 or a[x-1][y] == 5 or a[x-1][y] ==6 or a[x-1][y] == 2)) dir[0] = 1; //Up
            if(valid(x+1, y) and (a[x+1][y] == 1 or a[x+1][y] == 4 or a[x+1][y] == 7 or a[x+1][y] == 2)) dir[1] = 1; //Down
        }
        else if(a[x][y] == 3) {
            if(valid(x, y-1) and (a[x][y-1] == 1 or a[x][y-1] == 4 or a[x][y-1] == 5 or a[x][y-1] == 3)) dir[2] = 1; //Left
            if(valid(x, y+1) and (a[x][y+1] == 1 or a[x][y+1] == 6 or a[x][y+1] == 7 or a[x][y+1] == 3)) dir[3] = 1; //Right
        }
        else if(a[x][y] == 4) {
            if(valid(x-1, y) and (a[x-1][y] == 1 or a[x-1][y] == 2 or a[x-1][y] == 5 or a[x-1][y] == 6)) dir[0] = 1; //Up
            if(valid(x, y+1) and (a[x][y+1] == 1 or a[x][y+1] == 3 or a[x][y+1] == 6 or a[x][y+1] == 7)) dir[3] = 1; //Right
        }
        else if(a[x][y] == 5) {
            if(valid(x+1, y) and (a[x+1][y] == 1 or a[x+1][y] == 2 or a[x+1][y] == 7 or a[x+1][y] == 4)) dir[1] = 1; //Down
            if(valid(x, y+1) and (a[x][y+1] == 1 or a[x][y+1] == 3 or a[x][y+1] == 6 or a[x][y+1] == 7)) dir[3] = 1; //Right
        }
        else if(a[x][y] == 6) {
            if(valid(x+1, y) and (a[x+1][y] == 1 or a[x+1][y] == 2 or a[x+1][y] == 7 or a[x+1][y] == 4)) dir[1] = 1; //Down
            if(valid(x, y-1) and (a[x][y-1] == 1 or a[x][y-1] == 3 or a[x][y-1] == 5 or a[x][y-1] == 4)) dir[2] = 1; //Left
        }
        else if(a[x][y] == 7) {
            if(valid(x-1, y) and (a[x-1][y] == 1 or a[x-1][y] == 2 or a[x-1][y] == 5 or a[x-1][y] == 6)) dir[0] = 1; //Up
            if(valid(x, y-1) and (a[x][y-1] == 1 or a[x][y-1] == 3 or a[x][y-1] == 4 or a[x][y-1] == 5)) dir[2] = 1; //Left
        }
        for(int k=0; k<4; k++) {
            if(dir[k]) {
                int tx = top.first + fx[k];
                int ty = top.second + fy[k];
                if(valid(tx, ty)) {
                    vis[tx][ty] = 1;
                    dis[tx][ty] = dis[top.first][top.second] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        cin>>n>>m>>r>>c>>ml;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>a[i][j];
        bfs(r, c);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dis[i][j] > 0 and dis[i][j] <= ml) cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
}
