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

string s1,s2;
vector <string> s,res;
map<string,bool>m,m1;

int main() {
    int i,j;

    while (cin>>s1)
    {
        s.push_back(s1);
        m[s1]=true;
    }

    for (i=0;i<s.size();i++)
    {
        for (j=1;j<s[i].size();j++)
        {
            s1=s[i].substr(0,j);
            s2=s[i].substr(j,s[i].size()-j);

            if (m[s1] && m[s2] && !m1[s[i]])
            {
                m1[s[i]]=true;
                res.push_back(s[i]);
            }
        }

    }

    sort(res.begin(),res.end());

    for (i=0;i<res.size();i++)
        cout<<res[i]<<endl;

    return 0;
}
