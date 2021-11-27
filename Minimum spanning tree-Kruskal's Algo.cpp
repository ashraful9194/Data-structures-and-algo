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
int n,m;
int par[1005];
int sz[1005];
struct cmp
{
    bool operator()(const pair<pii,int> p1,const pair<pii,int> p2)
    {
        return p1.second<p2.second;
    }
};
int find_par(int node)
{
    if(node==par[node]) return node;
    else return par[node]=find_par(par[node]);
}
vector<pair<pii,int>>v;
int32_t main()
{
    ///if we have a spanning tree and we want to add an edge of the graph to it,
    /// we can always find another edge to discard
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n>>m;
     for(int i=0; i<m; i++)
     {
         int x,y,z;
         cin>>x>>y>>z;
         v.pb({{x,y},z});

     }
     for(int i=1; i<=n; i++) par[i]=i;
    sort(v.begin(),v.end(),cmp());
    int ans=0;
    int cnt=0;
     for(auto i:v)///take the small cost edge if it does not form a cycle...........
     {
         int u=find_par(i.first.first);
         int v=find_par(i.first.second);
         if(u==v) continue;///two nodes are connected
         par[u]=v;
         ans+=i.second;
         ++cnt;
         if(cnt==n-1) break;
     }
     cout<<ans<<endl;
}
/*
5 7
1 2 10
1 3 8
1 4 3
1 5 25
2 3 6
3 4 7
4 5 1
ans=17..................
*/
