#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <map>
#include <string>


using namespace std;

int n;
string s,top;


int main() {

    int t,i,j,minimo,counter;
    bool games;

    scanf("%d",&t);

    while (t--)
    {
        cin>>s;
        map<string,int>m;
        map<string,bool>known;
        counter=0;
        for (i=0;i<s.size();i++)
            if (s[i]=='o')
                counter++;
        m[s]=counter;
        known[s]=false;

        queue<string>q;
        q.push(s);
        minimo=9999999;
        while (!q.empty())
        {
            top=q.front();
            q.pop();
            if (known[top]) continue;
            known[top]=true;
            j=m[top];
            games=false;
            for (i=0;i<top.size();i++)
            {
                if (top[i]=='o' && top[i+1]=='o')
                {
                    if (i>=1)
                    {
                        if (top[i-1]=='-')
                        {
                            games=true;
                            top[i]='-';
                            top[i+1]='-';
                            top[i-1]='o';
                            m[top]=j-1;
                            q.push(top);
                            top[i]='o';
                            top[i+1]='o';
                            top[i-1]='-';
                        }
                    }

                    if (i<10)
                    {
                        if (top[i+2]=='-')
                        {
                            games=true;
                            top[i]='-';
                            top[i+1]='-';
                            top[i+2]='o';
                            m[top]=j-1;
                            q.push(top);
                            top[i]='o';
                            top[i+1]='o';
                            top[i+2]='-';
                        }
                    }
                }
            }

            if (!games)
                minimo=min(minimo,j);

        }
        printf("%d\n",minimo);
    }
    return 0;
}
