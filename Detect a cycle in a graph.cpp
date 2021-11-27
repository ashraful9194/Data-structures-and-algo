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
vector<int>vis(1004,0);
vector<int>save(1005,0);
int n,m;
int flag;
void dfs(int node,int par)
{
    vis[node]=1;
    save[node]=par;
    for(auto son:v[node])
    {
        if(son==par) continue;
        if(vis[son] )
        {
            if(flag) continue;
            save[son]=node;
            flag=son;
            return;
        }
        else
        dfs(son,node);
    }
}
int main()
{

    ///.......................This algorithm can detect any cycle but this algo can only print 1 cycle in a graph..........................
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
     dfs(1,0);
     if(flag) cout<<"Cycle found"<<endl;
     else cout<<"No cycle found"<<endl;
     int temp=flag;
     while(save[temp]!=flag)
     {
         cout<<temp<<" ";
         temp=save[temp];
     }
     cout<<temp<<" "<<flag<<endl;

}


