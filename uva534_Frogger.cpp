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

double x[205],y[205],arr[205][205];

double distance (double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main() {

    int i,j,k,n,cases=0;
    double tmp;

    while (1)
    {
        cin>>n;
        if (!n) break;

        for (i=1;i<=n;i++)
            cin>>x[i]>>y[i];

        for (i=1;i<=n;i++)
            for (j=i+1;j<=n;j++)
                arr[i][j]=arr[j][i]=distance(x[i],y[i],x[j],y[j]);


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

        printf("Scenario #%d\n",++cases);
        printf("Frog Distance = %0.3lf\n\n",arr[1][2]);
    }
    return 0;
}
