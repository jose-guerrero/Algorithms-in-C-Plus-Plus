#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

string s;
int m[1003],n,memo[1003][1003];

int palindrome(int i,int j)
{
    if (memo[i][j]!=-1) return memo[i][j];

    while (i<j)
    {
        if (s[i]==s[j])
        {
            i++;j--;continue;
        }
        memo[i][j]=0;
        return 0;
    }
    memo[i][j]=1;
    return 1;
}


int dp(int num)
{
    int i;
    if (m[num]!=-1) return m[num];
    if (num>n) return 0;

    m[num]=999999;

    for (i=num;i<=n;i++)
    {
        if (palindrome(num, i))
            m[num]=min(m[num],1+dp(i+1));
    }
    return m[num];
}

int main()
{
    int t;

    scanf("%d",&t);

    while (t--)
    {
        cin>>s;

        memset(m,-1,sizeof(m));
        memset(memo,-1,sizeof(memo));
        n=int(s.size())-1;
        cout<<dp(0)<<endl;
    }

    return 0;
}
