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
vector<vector<int>>adj(500);
vector<int>res;
queue<int>q;
int indegree[500];
int n,qq;
void topsort()
{
    for(int i=1; i<=n; i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        res.pb(x);
        for(auto i:adj[x])
        {
            --indegree[i];
            if(indegree[i]==0) q.push(i);
        }
    }
}
int main()
{
    /**
    Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices
     such that for every directed edge u v, vertex u comes before v in the ordering.
     Topological Sorting for a graph is not possible if the graph is not a DAG.
    */
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n>>qq;
     for(int i=0; i<qq; i++)
     {
         int x,y;
         cin>>x>>y;
         adj[x].pb(y);
        ++indegree[y];
     }
     topsort();
     for(auto i:res)
        cout<<i<<" ";
     cout<<endl;
     /*
     9 10
1 2
3 4
1 8
2 9
2 5
4 5
4 8
5 9
5 7
6 7
     */
}


