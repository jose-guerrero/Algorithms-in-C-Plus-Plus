#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>


using namespace std;


int main() {
    int n,i,count,casos=0;

    while (1)
    {
        cin>>n;
        if (n<=0) break;
        i=1;count=0;

        while (i<n)
        {
            i=i<<1;
            count++;
        }
        cout<<"Case "<<++casos<<": "<<count<<endl;
    }
    return 0;
}
