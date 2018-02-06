#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int t,n,m;
    string s[60],res;

    cin>>t;

    while (t--)
    {
        cin>>n>>m;
        res="";

        for(int i=0;i<n;i++)
            cin>>s[i];

        int global=0;
        for(int i=0;i<m;i++)
        {
            int p1=0;
            int p2=0;
            int p3=0;
            int p4=0;

            for(int j=0;j<n;j++)
            {
                if (s[j][i]=='A')      p1++;
                else if(s[j][i]=='C')  p2++;
                else if(s[j][i]=='G')  p3++;
                else if(s[j][i]=='T')  p4++;
            }

            int q=max(p1,max(p2,(max(p3,p4))));
            global+=(n-q);

            if (q==p1)       res.push_back('A');
            else if(q==p2)   res.push_back('C');
            else if(q==p3)   res.push_back('G');
            else if(q==p4)   res.push_back('T');
        }

        cout<<res<<endl;
        cout<<global<<endl;
    }
    return 0;
}
