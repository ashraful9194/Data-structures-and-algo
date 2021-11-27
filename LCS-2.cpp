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
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ///iterative approach............
     string a,b;
     cin>>a>>b;
     for(int i=0; i<a.size(); i++)
     {
         for(int j=0; j<b.size(); j++)
         {
             if(a[i]==b[j])
             {
                 dp[i+1][j+1]=1+dp[i][j];
             }
             else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
         }
     }
     cout<<dp[a.size()][b.size()]<<endl;

}


