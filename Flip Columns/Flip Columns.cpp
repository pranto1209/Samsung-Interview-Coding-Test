#include <bits/stdc++.h>
#define maxn 105
using namespace std;
int n, m, k, a[maxn][maxn];

int main()
{
    cin>>n>>m>>k;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>a[i][j];

    map<string, int> nums;
    for(int i=0; i<n; i++) {
        string s;
        for(int j=0; j<m; j++) s.push_back(a[i][j] + '0');
        nums[s]++;
    }

    int ans = 0;
    for(auto i: nums) {
        string s = i.first;
        int x = 0;
        for(auto c: s) if(c == '0') x++;
        if(k >= x) {
            if((k - x) % 2 == 0) ans = max(ans, i.second);
        }
    }
    cout<<ans<<"\n";
}
