#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n;
double x[800],y[800],parents[800];

struct node
{
    int ini;
    int fin;
    double weight;

    node (int u,int v,double w)
    {
        ini=u;fin=v;weight=w;
    }
};

typedef vector<node>ve;

double distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

bool operator < (node a,node b)
{
    return a.weight<b.weight;
}

int find(int u)
{
    if (parents[u]==u) return u;
    else
        return find(parents[u]);
}

void Union(int u,int v)
{
    int x = find(u);
    int y = find(v);
    parents[x] = y;
}

int main() {

    int m,i,j,u,v;
    double k,res;


    while (cin>>n)
    {
        ve edges;

        for (i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
            parents[i]=i;
        }
        cin>>m;
        while (m--)
        {
            cin>>i>>j;
            i--;j--;
            Union(i,j);
        }

        for (i=0;i<n;i++)
            for (j=i+1;j<n;j++)
            {
                k=distance(x[i],y[i],x[j],y[j]);
                edges.push_back(node(i,j,k));
            }
        sort(edges.begin(),edges.end());
        res=0;
        for (i=0;i<edges.size();i++)
        {
            u=edges[i].ini;
            v=edges[i].fin;

            if (find(u)!=find(v))
            {
                Union(u,v);
                res+=edges[i].weight;

            }
        }
        printf("%.2lf\n",res);
    }
    return 0;
}
