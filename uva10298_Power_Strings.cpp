#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
int main() {

    string s,s1="",s2="";
    int i,j;
    bool flag;

    while (1)
    {

        cin>>s;

        if (s==".") break;

        flag=false;

        for (i=1;i<s.size();i++)
        {
            if (s.size()%i==0)
            {
                for (j=0;j<s.size()-i;j=j+i)
                {
                    s1=s.substr(j,i);
                    s2=s.substr(j+i,i);
                    if (s1.compare(s2)!=0) {flag=false;break;}
                    flag=true;
                }
                if (!flag) continue;
                break;
            }
        }
        cout<<s.size()/i<<endl;

    }

    return 0;
}
