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
vector<int>v[1000];
int enter_time[1000];
int out_time[1000];
int save[2000];
int n;
int timer=1;
int dfs(int node,int par)
{
    enter_time[node]=timer;
    save[timer]=node;
    ++timer;
    for(auto son:v[node])
    {
        if(son==par) continue;
        dfs(son,node);
    }
    out_time[node]=timer;
   save[timer]=node;
    ++timer;

}
int main()
{
    ///needed for tree queries.......................
    ///nodes in a subtree is (out_time[node]-enter_time[node])/2...............
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n;
     for(int i=0; i<n-1; i++)
     {
         int x,y;
         cin>>x>>y;
         v[x].pb(y);
         v[y].pb(x);
     }
     dfs(1,0);
     for(int i=1; i<=2*n; i++) cout<<save[i]<<" ";
     cout<<endl;
}


