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
vector<int>adj[100004];
int n,m;
int vis[100005];
stack<int>st;
int on_stack[100004];
int in[100005];
int lo[100005];
int tme;
int cnt;
int scc_num[10004];
void dfs(int node)
{
    in[node]=lo[node]=++tme;
    vis[node]=1;
    on_stack[node]=1;
    st.push(node);
    for(auto son:adj[node])
    {
        if(on_stack[son] && vis[son])
        {
            lo[node]=min(lo[node],in[son]);
        }
        else if(!vis[son])
        {
            dfs(son);
            if(on_stack[son]) lo[node]=min(lo[node],lo[son]);
        }
    }
    if(in[node]==lo[node])
    {
        cout<<"SCC num "<<++cnt<<":"<<endl;
        while(1)
        {
            int x=st.top();
            st.pop();
            cout<<x<<" ";
            scc_num[x]=cnt;///Marked the scc num for graph condensation....
            on_stack[x]=0;
            if(x==node) break;
        }
        cout<<endl;
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
     }
     for(int i=1; i<=n; i++)
     {
         if(vis[i]) continue;
         dfs(i);
     }

     ///Graph condensation
     vector<int>v[cnt+3];
     for(int i=1; i<=n; i++)
     {
         for(auto j:adj[i])
         {
             if(scc_num[i]==scc_num[j]) continue;
             v[scc_num[i]].pb(scc_num[j]);///scc_num will be the node numbers
         }
     }

}
/**
7 8
1 2
2 3
3 4
4 5
5 6
6 7
7 3
6 1
*/
