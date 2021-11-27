#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int a[1000];
int dp[1000][1000];
int n;
int solve(int i,int j)
{
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i; k<=j-1; k++)
    {
        int temp=solve(i,k)+solve(k+1,j)+a[i-1]*a[k]*a[j];
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ///i....k....j break the problem into subproblems by dividing into point k.........
     ///find the lowest cost of multiplying  n-1 matrices...... a,b,c,d.........a*b=matrix dimension
     memset(dp,-1,sizeof dp);
     cin>>n;
     for(int i=0; i<n; i++)
        cin>>a[i];
     cout<<solve(1,n-1)<<endl;

}


