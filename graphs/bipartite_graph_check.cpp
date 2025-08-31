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
vector<vector<int>>v;
vector<int>col;
int n,m;
bool bipartite;
int cnt=0;
int dfs(int node,int c)
{
    col[node]=c;
    for(auto son:v[node])
    {
         if(col[son]==-1)
         {
             dfs(son,c^1);
         }
         else
         {
             if(col[son]==col[node]) bipartite=false;
         }
    }

}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n>>m;
     for(int i=0; i<m; i++)
     {
         int x,y;
         cin>>x>>y;
         v[x].pb(y);
         v[y].pb(x);
     }
     bipartite=true;
     col=vector<int>(n+5,-1);
     dfs(1,0);
}


