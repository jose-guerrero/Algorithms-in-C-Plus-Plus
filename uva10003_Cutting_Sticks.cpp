#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int l,n,cut[55],memo[55][55];

int dp(int ini,int fin)
{
    int i;

    if (memo[ini][fin]!=-1) return memo[ini][fin];
    if ((ini+1) == fin) return 0;
    if ((ini +2) == fin) return cut[fin]-cut[ini];

    for (i=ini+1;i<fin;i++)
    {
        int tmp = cut[fin] - cut[ini] + dp(ini,i) + dp(i,fin);

        if (memo[ini][fin] == -1 || memo[ini][fin] > tmp)
            memo[ini][fin] = tmp;
    }
    return memo[ini][fin];
}


int main() {
    int i;

    while (1)
    {
        cin>>l;
        if (!l) break;
        memset(memo,-1,sizeof(memo));
        cin>>n;
        cut[0]=0;cut[n+1]=l;
        for (i=1;i<=n;i++)
            cin>>cut[i];

        printf("The minimum cutting is %d.\n",dp(0,n+1));
    }

    return 0;
}
