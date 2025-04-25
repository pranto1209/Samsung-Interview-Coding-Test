#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    string s;
    cin>>k>>s;
    int sum = 0, cur = -1;
    for(int i=0; i<int(s.size()); i++) {
        if(s[i] == '(') cur++;
        else if(s[i] == ')') cur--;
        else if(cur == k) {
            string num;
            while(i<int(s.size()) and s[i]>='0' and s[i]<='9') num.push_back(s[i]), i++;
            int val = 0;
            for(int j=0; j+1<int(num.size()); j++) {
                val += (num[j]-'0');
                val *= 10;
            }
            val += (num.back()-'0');
            sum += val;
            i--;
        }
    }
    cout<<sum<<"\n";
}
