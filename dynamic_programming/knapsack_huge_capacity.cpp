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
#define INF 1000000000000

//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
ll dp[100002];
int w[101],p[102];
int main()
{
    ///profits*n<=1e5......
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
      for(int i=1; i<=100002; i++)
        dp[i]=INF;
     int n,cap;
     cin>>n>>cap;
     int sum=0;
     for(int i=0; i<n; i++)
     {
         cin>>w[i]>>p[i];
         sum+=p[i];
     }
     for(int i=0; i<n; i++)
     {
         for(int j=sum; j>=p[i]; j--)
         {
             dp[j]=min(dp[j],w[i]+dp[j-p[i]]);///max profit with min cap..
         }
     }
     int ans=0;
     for(int i=0; i<=sum; i++)
        if(dp[i]<=cap) ans=max(ans,i);
     cout<<ans<<endl;

}


