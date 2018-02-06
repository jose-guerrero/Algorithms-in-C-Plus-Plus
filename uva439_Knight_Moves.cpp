#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

int movx[]={-2,-2,-1,-1,1,1,2,2};
int movy[]={1,-1,-2,2,2,-2,1,-1};
int counts[10][10];

int main()
{
    int i,i1,i2,x1,x2,subx,suby;
    string s1,s2;

    while (cin>>s1>>s2)
    {
        i1=s1[0]-'a'+1;
        x1=s1[1]-'0';

        i2=s2[0]-'a'+1;
        x2=s2[1]-'0';

        memset(counts,-1,sizeof(counts));
        pair<int,int>p;
        p.first=i1;p.second=x1;
        counts[i1][x1]=0;

        queue<pair<int,int>>q;
        q.push(p);

        while(!q.empty())
        {
            p=q.front();
            q.pop();

            if (p.first==i2 && p.second==x2) break;

            for (i=0;i<8;i++)
            {
                subx=p.first+movx[i];
                suby=p.second+movy[i];


                if ((subx>=1 && subx<=8)&&(suby>=1 && suby<=8))
                {
                    if (counts[subx][suby]!=-1) continue;
                    counts[subx][suby]=1+counts[p.first][p.second];
                    q.push(make_pair(subx,suby));
                }
            }
        }

        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<counts[i2][x2]<<" knight moves.\n";
    }

    return 0;
}
