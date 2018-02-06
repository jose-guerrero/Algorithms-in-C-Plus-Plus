#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <map>
using namespace std;


string s;
int memo[1005][1005];


int dp(int x,int y)
{
    if (x==y) return 1;
    if (y-x==1)
    {
        if (s[x]==s[y])
            return 2;
        else
            return 1;
    }
    if (memo[x][y]!=-1) return memo[x][y];

    if (s[x]==s[y])
        memo[x][y]=2+dp(x+1,y-1);
    else
        memo[x][y]=max(dp(x+1,y),dp(x,y-1));

    return memo[x][y];
}


int main() {

    int t;

    cin>>t;
    cin.ignore();

    while (t--)
    {
        getline(cin,s);
        memset(memo,-1,sizeof(memo));
        cout<<dp(0,int(s.size())-1)<<'\n';
    }
    return 0;
}
