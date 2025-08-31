/**Failing is always better than never trying*/
/**Winners never quit and quitters never win.*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
int n,m;
vector<int>adj[1005];
int save[1005];
int color[1005],root,found;
vector<int>v;
void check(int node)
{
    v.clear();
    found=1;
    map<int,int>vis;
    while(node!=root)
    {
        v.pb(node);
        vis[node]=1;
        node=save[node];
    }
    v.pb(root);
    vis[root]=1;
    reverse(v.begin(),v.end());
    save[root]=v[v.size()-1];
    for(auto i:v)
    {
        for(auto son:adj[i])
        {
            if(!vis[son]) continue;
            if(save[son]==i) continue;
            found=0;
            return;
        }
    }
}
void print()
{
    cout<<v.size()<<endl;
    for(auto i:v) cout<<i<<" ";
    cout<<endl;
    return;
}
void dfs(int node,int par)
{
    save[node]=par;
    color[node]=1;
    for(auto son:adj[node])
    {
        if(son==root)
        {
            check(node);
            if(found)
            {
                print();
                exit(0);
            }
        }
        if(color[son]) continue;
        dfs(son,node);
    }
}
void solve(int node)
{
    memset(save,0,sizeof save);
    memset(color,0,sizeof color);
    dfs(node,0);
}
int main()
{


    ///Complexity seems O(V+E)*V^2.... but actually not.
    ///Find only one simple cycle and print it.
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
        root=i;
        solve(i);
    }
    cout<<-1<<endl;
}
