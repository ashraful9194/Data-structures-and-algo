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
int dp[1000][10001];
ll weight[1000],profit[1000];
ll W,n;
ll knapsack(ll pos,ll w)
{
    if(pos==n || w==W) return 0;
    if(dp[pos][w]!=-1) return dp[pos][w];
    if(weight[pos]+w<=W)
    {
        dp[pos][w]=max(knapsack(pos+1,w),profit[pos]+knapsack(pos+1,w+weight[pos]));
    }
    else
    {
        dp[pos][w]=knapsack(pos+1,w);
    }
    return dp[pos][w];
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     for(ll i=0; i<=100; i++)
        for(ll j=0; j<=100001; j++)
        dp[i][j]=-1;
     cin>>n>>W;
     for(ll i=0; i<n; i++)
     {
         cin>>weight[i]>>profit[i];
     }
    cout<< knapsack(0,0)<<endl;

}


