/**Failing is always better than never trying*/
/**Winners never quit and quitters never win.*/
#include<algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

#define pb push_back
//#define endl '\n'
int dp[90][90];
char a[90],b[90];
set<string>ans;
map<string,int>processed[81][81];

void sol_printing(int x,int y,string s)
{

    if(processed[x][y][s]) return;
    if(x==0 || y==0)
    {
          ans.insert(s);
          return;
    }
    if(a[x-1]==b[y-1])
    {
        s=a[x-1]+s;
        sol_printing(x-1,y-1,s);
    }
    else
    {
        if(dp[x][y-1]>=dp[x-1][y])
        {
            sol_printing(x,y-1,s);
        }
        if(dp[x-1][y]>=dp[x][y-1])
        {
           sol_printing(x-1,y,s);

        }
    }
    processed[x][y][s]=1;
}
int main()
{

    /**
      2D map visiting.............................
      map<string,int>mp
      mp["str"]=int;
      map<string,int>mp[5];
      mp[idx]["str"]=int;
      map<string,int>mp[5][5];
      mp[idx1][idx2]["str"]=int;

    */
    int t;
    cin>>t;
    while(t--)
    {
       ans.clear();
        scanf("%s %s",a,b);
        int n=strlen(a);
        int m=strlen(b);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
              dp[i][j]=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i]==b[j])
                {
                    dp[i+1][j+1]=1+dp[i][j];
                }
                else
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        string s="";

        sol_printing(n,m,s);
        for(auto i:ans)
        {
            cout<<i<<'\n';
        }
        if(t) printf("\n");
    }
}
