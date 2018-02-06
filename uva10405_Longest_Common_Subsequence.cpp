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

    int i,j,n,m;
    string x,y;
    int arr[1002][1002];

    memset(arr,0,sizeof(arr));

    while (getline(cin,x))
    {
        getline(cin,y);

        n=int(x.size());
        m=int(y.size());

        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                if (x[i]==y[j])
                    arr[i+1][j+1]=arr[i][j]+1;
                else
                    arr[i+1][j+1]=max(arr[i+1][j],arr[i][j+1]);

        printf("%d\n",arr[n][m]);
    }

    return 0;
}
