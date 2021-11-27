#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int dp[1000][1000];
int nCr(int n,int r)
{

    int &ans=dp[n][r];
    if(ans!=-1) return  ans;
    if(n==r) return ans=1;
    if(r==1) return ans=n;
    if(r==0) return ans=1;
    return  ans=nCr(n-1,r)+nCr(n-1,r-1);
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ///nCr=(n-1)Cr+(n-1)C(r-1);
     ///nCr=nC(n-r)
     memset(dp,-1,sizeof dp);
     int n,r;
     cin>>n>>r;
     int ans=nCr(n,r);
     cout<<ans<<endl;
}
