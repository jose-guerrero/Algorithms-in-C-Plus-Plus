#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int arr[]={1,5,10,25,50};
int memo[8500];

void init()
{int i,j;

    memset(memo,0,sizeof(memo));
    memo[0]=1;

    for (i=0;i<5;i++)
        for (j=arr[i];j<8500;j++)
            memo[j]+=memo[j-arr[i]];
}


int main() {

    int n;
    init();

    while (cin>>n)
    {
        cout<<memo[n]<<endl;
    }
    return 0;
}
