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
string s;
int dp[1000][1000];
int cnt;
int solve(int i,int j)
{

    if(i==j) return 1;
    if(i>j) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
    int res;
    if(s[i]==s[j])
    {
       res=2+solve(i+1,j-1);
    }
    else
    {
      res=max(solve(i+1,j),solve(i,j-1));
    }
    return  dp[i][j]=res;
}
int main()
{
    ///another tricks is LPS=LCS(string,reversed string)..........
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     memset(dp,-1,sizeof dp);
     cin>>s;
     int n=s.size();
     int ans=solve(0,n-1);
     cout<<ans<<endl;
}


