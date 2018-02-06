#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int arr[]={1,5,10,25,50};
unsigned long long memo[30005];

void init()
{int i,j;

    memset(memo,0,sizeof(memo));
    memo[0]=1;

    for (i=0;i<5;i++)
        for (j=arr[i];j<30005;j++)
            memo[j]+=memo[j-arr[i]];
}


int main() {

    int n;
    init();

    while (scanf("%d",&n)!=EOF)
    {
        if (memo[n]==1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else
            printf("There are %lld ways to produce %d cents change.\n",memo[n],n);
    }
    return 0;
}
