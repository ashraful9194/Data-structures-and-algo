#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int dp[100002];
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int tc;
     cin>>tc;
     for(int m=1; m<=tc; m++)
     {
         memset(dp,0,sizeof dp);
        int n,cap;
     cin>>n>>cap;
     for(int i=0; i<n; i++)
     {
         int w,p;
         cin>>w>>p;
         for(int j=cap; j>=w; j--)
         {
             dp[j]=max(dp[j],dp[j-w]+p);
         }

     }
     cout<<"Case "<<m<<": ";
     cout<<dp[cap]<<endl;
     }

}


