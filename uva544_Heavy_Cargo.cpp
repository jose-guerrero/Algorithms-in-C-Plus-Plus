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
#include <map>

using namespace std;

int n;
int mat[205][205];


int main()
{
    int r,u,v,w,i,j,k,cont,tmp,cases=0;
    string s1,s2;
    map<string,int>m;

    while (1)
    {
        scanf("%d %d",&n,&r);
        if (!n && !r) break;
        m.clear();
        memset(mat,0,sizeof(mat));
        cont=1;
        while (r--)
        {
            cin>>s1>>s2;

            if (m.find(s1)!=m.end())
                u=m[s1];
            else
            {
                m[s1]=u=cont;cont++;
            }

            if (m.find(s2)!=m.end())
                v=m[s2];
            else
            {
                m[s2]=v=cont;cont++;
            }

            scanf("%d",&w);
            mat[u][v]=mat[v][u]=w;
        }

        for (k=1;k<=n;k++)
        {
            for (i=1;i<=n;i++)
            {
                for (j=1;j<=n;j++)
                {
                    tmp = min(mat[i][k],mat[k][j]);
                    mat[i][j] = mat[j][i] = max(mat[i][j],tmp);

                }
            }
        }

        cin>>s1>>s2;
        u=m[s1];v=m[s2];
        printf("Scenario #%d\n",++cases);
        printf("%d tons\n\n",mat[u][v]);
    }

    return 0;
}
