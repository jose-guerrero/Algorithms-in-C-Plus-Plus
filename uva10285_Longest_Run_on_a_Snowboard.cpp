#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int memo[102][102],arr[102][102],r,c;

int dp(int x,int y)
{
    int g1=0,g2=0,g3=0,g4=0;

    if (memo[x][y]!=-1) return memo[x][y];

    if ((x-1)>=0)
    {
        if (arr[x][y]>arr[x-1][y])
            g1=1+dp(x-1,y);
    }

    if ((y-1)>=0)
    {
        if (arr[x][y]>arr[x][y-1])
            g2=1+dp(x,y-1);
    }

    if ((x+1)<r)
    {
        if (arr[x][y]>arr[x+1][y])
            g3=1+dp(x+1,y);
    }
    if ((y+1)<c)
    {
        if (arr[x][y]>arr[x][y+1])
            g4=1+dp(x,y+1);
    }

    return max(g1,max(g2,max(g3,g4)));
}


int main() {

    int t,i,j,res=0;
    char s[100];

    scanf("%d",&t);

    while (t--)
    {
        scanf("%s %d %d",s,&r,&c);
        memset(memo,-1,sizeof(memo));
        res=0;
        for (i=0;i<r;i++)
            for (j=0;j<c;j++)
                scanf("%d",&arr[i][j]);


        for (i=0;i<r;i++)
            for (j=0;j<c;j++)
            {   memo[i][j]=dp(i,j);
                res=max(res,memo[i][j]);
            }

        printf("%s: %d\n",s,(res+1));
    }


    return 0;
}
