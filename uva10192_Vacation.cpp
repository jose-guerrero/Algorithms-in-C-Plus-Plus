#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <map>
using namespace std;

string s1,s2;

int main()
{
    int n,m,i,j,cases=0,arr[105][105];

    memset(arr,0,sizeof(arr));

    while (1)
    {
        getline(cin,s1);
        if (s1[0]=='#') break;
        getline(cin,s2);

        n=int(s1.size());
        m=int(s2.size());

        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
            {
                if (s1[i]==s2[j])
                    arr[i+1][j+1]=arr[i][j]+1;
                else
                    arr[i+1][j+1]=max(arr[i+1][j],arr[i][j+1]);
            }

        printf("Case #%d: you can visit at most %d cities.\n",++cases,arr[n][m]);
    }

    return 0;
}
