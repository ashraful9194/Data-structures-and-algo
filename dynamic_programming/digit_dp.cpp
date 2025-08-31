#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
#define int long long
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int dp[20][2][82][82];
int sz;
vector<int>v;
int x,y,k;
///1 no:Lightoj investigation ......2 no:How many zeros
int solve(int pos,int prev_small,int num,int dig)
{
     int &ans=dp[pos][prev_small][num][dig];
     if(ans!=-1) return ans;
     if(pos==sz)
     {
          return !(num|dig);
     }
     int till=prev_small?9:v[pos];
     int res=0;

         for(int i=0; i<=till; i++)
         {
             res+=solve(pos+1,i<v[pos]|prev_small,(num*10+i)%k,(dig+i)%k);///put any digit in range ....does not matter
         }

     return ans=res;
}
int calc(int n)
{
    if(k>81) return 0;
    v.clear();
    memset(dp,-1,sizeof dp);
    while(n)
    {
        v.pb(n%10);
        n=n/10;
    }
    sz=v.size();
    reverse(v.begin(),v.end());
    return solve(0,0,0,0);
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     for(int tc=1; tc<=t; tc++)
     {
         cin>>x>>y>>k;
         int ans=calc(y)-calc(x-1);
         cout<<"Case "<<tc<<": ";
         cout<<ans<<endl;
     }

}
/*
#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
#define int long long
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int dp[30][2][2][30];
int sz;
vector<int>v;
int solve(int pos,int start,int prev_small,int cnt)
{
    int &ans=dp[pos][start][prev_small][cnt];
    if(ans!=-1) return ans;
    if(pos==sz) return cnt;
    int till=prev_small?9:v[pos];
    int res=0;
    if(start)
    {
        for(int i=1; i<=till; i++)
        {
            res+=solve(pos+1,0,i<v[pos]|prev_small,(i==0)+cnt);
        }
        res+=solve(pos+1,1,1,cnt);
    }
    else
    {
        for(int i=0; i<=till; i++)
        {
            res+=solve(pos+1,0,i<v[pos]|prev_small,(i==0)+cnt);
        }
    }
    return ans=res;

}
int calc(int n)
{
    if(n<0) return 0;
   if(n<=9) return 1;
    v.clear();
    memset(dp,-1,sizeof dp);
    while(n)
    {
        v.pb(n%10);
        n=n/10;
    }
    sz=v.size();
    reverse(v.begin(),v.end());
    return solve(0,1,0,0)+1;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     for(int tc=1; tc<=t; tc++)
     {
         int x,y;
         cin>>x>>y;
         int ans=calc(y)-calc(x-1);
         cout<<"Case "<<tc<<": ";
         cout<<ans<<endl;
     }

}
*/
