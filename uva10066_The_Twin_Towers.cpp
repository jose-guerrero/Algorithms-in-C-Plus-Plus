#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;


int main() {

    int i,j,n,m,cases=0;
    int x[101],y[101],arr[101][101];

    memset(arr,0,sizeof(arr));

    while (1)
    {
        cin>>n>>m;
        if (n==0 && m==0) break;

        for (i=1;i<=n;i++)
            cin>>x[i];

        for (j=1;j<=m;j++)
            cin>>y[j];

        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                if (x[i]==y[j])
                    arr[i][j]=arr[i-1][j-1]+1;
                else
                    arr[i][j]=max(arr[i][j-1],arr[i-1][j]);

        printf("Twin Towers #%d\n",++cases);
        printf("Number of Tiles : %d\n\n",arr[n][m]);
    }

    return 0;
}
