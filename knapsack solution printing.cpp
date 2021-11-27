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
int dp[1000][1000];
int w[1000],p[1000];
int n,cap;
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n>>cap;
     for(int i=1; i<=n; i++)
        cin>>w[i]>>p[i];
     for(int i=1; i<=n; i++)
     {
         for(int j=1; j<=cap; j++)
         {
             if(w[i]<=j)
             {
                 dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
             }
             else dp[i][j]=dp[i-1][j];
         }
     }
     vector<int>v;
    int i=n,j=cap;
    while(i>=1 && j>=1)
    {
        if(dp[i][j]==dp[i-1][j])
        {
            --i;
        }
        else
        {
            v.pb(p[i]);
            j=j-w[i];
            --i;
        }
    }
    for(int i:v) cout<<i<<" ";
    cout<<endl;
    cout<<dp[n][cap]<<endl;
}


