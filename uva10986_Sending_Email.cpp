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

struct node
{
    int dest;
    int weight;

    node(int d1,int d2)
    {
        dest=d1;
        weight=d2;
    }
};

typedef vector<node>ve;
typedef vector<ve>vve;

bool operator < (node a,node b)
{
    return a.weight>b.weight;
}

int main() {

    int n,m,t,i,j,k,u,v,s1,s2,cases=0,u1,v1;

    cin>>t;

    while (t--)
    {

        cin>>n>>m>>s1>>s2;
        vve G(n);

        while (m--)
        {
            cin>>i>>j>>k;
            G[i].push_back(node(j,k));
            G[j].push_back(node(i,k));
        }

        vector<int>vi(n);
        fill(vi.begin(),vi.end(),-1);

        priority_queue<node>pq;
        pq.push(node(s1,0));

        while (!pq.empty())
        {
            u=pq.top().dest;
            v=pq.top().weight;
            pq.pop();
            if (vi[u]!=-1) continue;
            vi[u]=v;
            if (u==s2) break;

            for (i=0;i<G[u].size();i++)
            {
                u1=G[u][i].dest;v1=G[u][i].weight;
                if (vi[u1]!=-1) continue;
                pq.push(node(u1,v+v1));
            }
        }

        if (vi[s2]==-1) cout<<"Case #"<<++cases<<": unreachable"<<endl;
        else cout<<"Case #"<<++cases<<": "<<vi[s2]<<endl;

    }

    return 0;
}
