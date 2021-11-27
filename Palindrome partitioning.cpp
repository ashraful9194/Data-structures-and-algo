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
int n;string s;
int dp[1000][1000];
int is_palindrome(string str)
{
    int sz=str.size();
    for(int i=0; i<sz/2; i++)
    {
        if(str[i]!=str[sz-1-i]) return  0;
    }
    return 1;
}
int solve(int i,int j)
{
    if(i>=j) return  0;
    if(is_palindrome(s.substr(i,j-i+1))) return 0;
    if(dp[i][j]!=-1) return  dp[i][j];
    int ans=INT_MAX;
    for(int k=i; k<=j-1; k++)
    {
          int temp=1+solve(i,k)+solve(k+1,j);
          ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}
int main()
{
    ///O(n^3)....................................
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     memset(dp,-1,sizeof dp);
     cin>>s;
     n=s.size();
     cout<<solve(0,n-1)<<endl;
}


