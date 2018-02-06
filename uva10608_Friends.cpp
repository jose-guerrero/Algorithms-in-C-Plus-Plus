#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector <int> ve;
typedef vector <ve> vve;
typedef vector <bool> vi;


int main() {

    int n,m,t,i,u,v,res,tmp;

    cin>>t;

    while (t--)
    {
        cin>>n>>m;
        vve G(n+1);
        while (m--)
        {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        res=0;
        vi known(n+1,false);

        for (i=1;i<=n;i++)
        {
            if (known[i]) continue;
            tmp = 0;
            queue<int>q;
            q.push(i);

            while (!q.empty())
            {
                u=q.front();
                q.pop();
                if (known[u]) continue;
                tmp++;
                known[u]=true;

                for (i=0;i<G[u].size();i++)
                {
                    v=G[u][i];
                    if (known[v]) continue;
                    q.push(v);
                }
            }
            res=max(res,tmp);
        }
        cout<<res<<endl;
    }

    return 0;
}
