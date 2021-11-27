#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, greater<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
const int mx=10005;
vector<int>adj[mx];
int in[mx],lo[mx];///For storing entering time and back-edge time.......
int vis[mx];
int n,m;
int timer;
void dfs(int node,int par)
{
    in[node]=lo[node]=timer++;
    vis[node]=1;
    for(auto son:adj[node])
    {
        if(son==par) continue;
        if(vis[son])
        {
            lo[node]=min(lo[node],in[son]);///save the time of back-edge
        }
        else
        {
           dfs(son,node);
           if(in[node]<lo[son])
           {
               cout<<node<<"-"<<son<<" is a bridge."<<endl;
           }
           lo[node]=min(lo[node],lo[son]);
        }
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n>>m;
     for(int i=0; i<m; i++)
     {
         int x,y;
         cin>>x>>y;
         adj[x].pb(y);
         adj[y].pb(x);
     }
     dfs(1,0);
}
/**
4 4
1 2
2 3
2 4
3 4
ans:1-2
*/
