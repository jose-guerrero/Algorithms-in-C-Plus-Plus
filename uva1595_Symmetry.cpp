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
#include <set>

using namespace std;

typedef pair<int,int>ii;

int main() {

    int t,n,i,j,maxi,mini,length;

    cin>>t;

    while (t--)
    {
        cin>>n;
        set<ii>v;
        set<ii>::iterator it;
        maxi=-20000;mini=20000;

        while (n--)
        {
            cin>>i>>j;
            v.insert(ii(i,j));
            maxi=max(maxi,i);mini=min(mini,i);
        }

        length = maxi + mini;
        bool ans = true;
        for (it=v.begin();it!=v.end();it++)
        {
            i = (*it).first;j=(*it).second;
            if (v.find(ii(length-i,j))!=v.end()) continue;
            ans = false;
            break;
        }
        if (ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
