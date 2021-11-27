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
string a,b;
int dp[1000][1000];
int solve(int i,int j)
{
    if(i==-1 || j==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j])
    {
        dp[i][j]=1+solve(i-1,j-1);
    }
    else dp[i][j]=max(solve(i,j-1),solve(i-1,j));
    return dp[i][j];
}
int main()
{
    ///length of longest common subsequence   recursive......................
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     memset(dp,-1,sizeof dp);
     cin>>a>>b;
     int ans=solve(a.size()-1,b.size()-1);
     cout<<ans<<endl;
}


