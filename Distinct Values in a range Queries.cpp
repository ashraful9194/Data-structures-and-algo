#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
#define int long long
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int n,q;
vector<int>range[500005];
vector<int>ind[500005];
int ans[500005];
int pre[500005];
int BIT[500005];
void update(int idx,int val)
{
     for(; idx<=n; idx+=(idx&-idx)) BIT[idx]+=val;
}
int query(int idx)
{
    int res=0;
    while(idx>0)
    {
        res+=BIT[idx];
        idx-=(idx&-idx);
    }
    return res;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     cin>>n>>q;
     int col[n+4];
     for(int i=1; i<=n; i++) cin>>col[i];
     for(int i=1; i<=q; i++)
     {
         int x,y;
         cin>>x>>y;
         range[y].pb(x);
         ind[y].pb(i);
     }
     for(int i=1; i<=n; i++)
     {
           if(pre[col[i]]>0) update(pre[col[i]],-1);
           update(i,+1);
           pre[col[i]]=i;
           for(int j=0; j<range[i].size(); j++)
           {
               ans[ind[i][j]]=query(i)-query(range[i][j]-1);
           }
     }
    for(int i=1; i<=q; i++) cout<<ans[i]<<endl;
}
