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
int in[100002];
int out[100002];
vector<int>adj[100003];
int n;
void dfs1(int node,int parent)
{
    for(int son:adj[node])
    {
        if(son==parent) continue;
        dfs1(son,node);
        in[node]=max(in[node],1+in[son]);
    }
}
void dfs2(int node,int parent)
{
      int mx1=-1,mx2=-1;
      for(int son:adj[node])
      {
          if(son==parent) continue;
          if(in[son]>=mx1)
            mx2=mx1,mx1=in[son];
          else if(in[son]>mx2)
            mx2=in[son];
      }
      for(int son:adj[node])
      {
          if(son==parent) continue;
          int use=mx1;
          if(in[son]==use) use=mx2;
          out[son]=max(1+out[node],2+use);
          dfs2(son,node);
      }
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ///find the height of the tree from every node.........................
     cin>>n;///how many nodes
     for(int i=0; i<n-1; i++)
     {
         int u,v;
         cin>>u>>v;
         adj[u].pb(v);
         adj[v].pb(u);
     }
     dfs1(1,0);///calculate in values from node 1......
     dfs2(1,0);///calculate out values from node  1...
     for(int i=1; i<=n; i++)
        cout<<max(in[i],out[i])<<endl;

}


