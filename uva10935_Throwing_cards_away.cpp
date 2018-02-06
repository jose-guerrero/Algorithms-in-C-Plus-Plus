#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main() {

    int n,i;
    bool first;

    while (1)
    {
        scanf("%d",&n);
        if (!n) break;

        queue<int>q;

        for (i=1;i<=n;i++)
            q.push(i);

        printf("Discarded cards:");
        first=false;
        while (int(q.size())!=1)
        {
            int v=q.front();
            if (first) printf(",");
            first=true;
            printf(" %d",v);
            q.pop();
            int u=q.front();
            q.pop();
            q.push(u);
        }
        printf("\nRemaining card: %d\n",q.front());
    }
    return 0;
}
