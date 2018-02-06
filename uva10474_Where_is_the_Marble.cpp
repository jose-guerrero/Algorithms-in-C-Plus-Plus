#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n,q,i,j,cases=0;

    while (1)
    {
        scanf("%d %d",&n,&q);
        if (n==0 && q==0) break;

        vector<int>v;

        while (n--)
        {
            scanf("%d",&i);
            v.push_back(i);
        }
        sort(v.begin(),v.end());
        vector<int>::iterator low;
        printf("CASE# %d:\n",++cases);

        while (q--)
        {
            scanf("%d",&i);
            low=lower_bound(v.begin(),v.end(),i);
            j=int(low-v.begin());

            if (v[j]==i)
                printf("%d found at %d\n",i,++j);
            else
                printf("%d not found\n",i);

        }

    }
    return 0;
}
