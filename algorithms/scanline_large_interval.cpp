#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
       int n,cost;
     cin>>n>>cost;
     for(int i=0; i<n; i++)
     {
         int a,b,c;
         cin>>a>>b>>c;
         mp[a]+=c;
         mp[b+1]-=c;
     }
     auto it=mp.begin();
     int curr=it->second;
     auto pre=it;
     int ans=0;
    ++it;
    while(it!=mp.end())
    {
        ans+=(it->first-pre->first)*min(cost,curr);
        curr+=it->second;
        pre=it;
        ++it;
    }
    cout<<ans<<endl;
}


