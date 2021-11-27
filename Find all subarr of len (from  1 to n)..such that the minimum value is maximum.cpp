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
vector<int>sz(200005,0);
vector<int>par(200005,0);
int find_par(int node)
{
    if(node==par[node]) return node;
    else return  par[node]=find_par(par[node]);
}
int merge(int u,int v)
{
    u=find_par(u);
    v=find_par(v);
    if(sz[u]<sz[v]) swap(u,v);
    sz[u]+=sz[v];
    par[v]=u;
    return sz[u];
}
int32_t main()
{
    ///Find such subarray of length (from  1 to n)..such that the minimum value is maximum........
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n;
     cin>>n;
     int x;
     vector<pii>v(n);
     for(int i=0; i<=n; i++)
     {
         sz[i]=1;
         par[i]=i;
     }
     vector<int>vis(n+5,0);
     for(int i=0; i<n; i++)
     {
         cin>>x;
         v[i]={x,i};
     }
     sort(v.begin(),v.end(),greater<pii>());
    vector<int>ans(n+5,0);
    int idx=1;
    for(int i=0; i<n; i++)
    {
         int val=v[i].first;
         int pos=v[i].second;
         vis[pos]=1;
         int x=1;
         if(pos>0 && vis[pos-1])
            {
                x=merge(pos,pos-1);
            }
         if(pos<n-1 && vis[pos+1])
            {
                x=merge(pos,pos+1);
            }
          while(idx<=x)
            ans[idx++]=val;
    }
    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;

}



