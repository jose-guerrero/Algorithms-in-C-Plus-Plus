#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

int arr[105][105],n;

void init()
{
    int i,j;

    for (i=0;i<=n;i++)
        for (j=0;j<=n;j++)
            arr[i][j] = INT_MAX;
}

int main() {

    int m,q,u,v,w,r,c,cases=0,i,j,k,tmp;
    bool ans = true;

    while (1)
    {
        cin>>n>>m>>q;
        if (!n && !m && !q) break;

        init();

        while (m--)
        {
            cin>>u>>v>>w;
            arr[u][v]=w;
            arr[v][u]=w;
        }

        for (k=1;k<=n;k++)
        {
            for (i=1;i<=n;i++)
            {
                for (j=1;j<=n;j++)
                {
                    tmp = max(arr[i][k],arr[k][j]);
                    arr[i][j] = arr[j][i] = min(arr[i][j],tmp);
                }
            }
        }

        if (!ans) puts("");
        ans = false;
        printf("Case #%d\n",++cases);
        while (q--)
        {
            cin>>r>>c;
            if (arr[r][c] == INT_MAX) printf("no path\n");
            else printf("%d\n",arr[r][c]);
        }
    }

    return 0;
}
