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
vector<pii>v[100];
vector<int>ans(105,1e15);
int n,m;
void dijkstra(int node)
{
    priority_queue<pii,vector<pii>,greater<pii>>pq;///min heap....top is smallest..
    pq.push({0,node});
    ans[node]=0;
    while(!pq.empty())
    {
        pii p=pq.top();
        pq.pop();
        for(int i=0; i<v[p.second].size(); i++)
        {
            pii it=v[p.second][i];
             if(ans[it.first]>p.first+it.second)
             {
                 ans[it.first]=p.first+it.second;
                 pq.push({ans[it.first],it.first});
             }

        }
    }
    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ///Single source shortest path algorothm....that means ..Find the shortest path for all nodes from a single source node
     cin>>n>>m;
     for(int i=0; i<m; i++)
     {
         int x,y,z;
         cin>>x>>y>>z;
         v[x].pb({y,z});
         v[y].pb({x,z});
     }
     dijkstra(1);
}


