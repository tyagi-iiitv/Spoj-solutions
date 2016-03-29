#include <stdio.h>
#include <iostream>
using namespace std;
char s[10001];
int i;
int max(int p,int q)
{
        return p > q ? p : q;
}

int length()
{
        if (s[i++] =='l'){
            // cout<<i<<endl;
            // cout<<"returning 1 for: "<<s[i]<<endl;
            return 1;
        } 
        else{
            // cout<<"returning "<<max(length(), length<<"for: "<<s[i]<<endl;
            return max(length(),length())+1;
        }
}
int main()
{
        int t;
        scanf("%d",&t);
        while (t--)
        {
                scanf("%s", s);
                i=0;
                printf("%d\n",length() - 1);
        }
        return 0;
}
