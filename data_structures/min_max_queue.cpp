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
///Problem realted to this topic:Codeforces --Mind Control................
int32_t main()
{

    ///Find the maximum value from all subarray of length m and print the minimum among them......
    ///Run time complexity of min-max  queue is O(n)...........................................................
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n,q;
     cin>>n>>q;
     int a[n+5];
     for(int i=0; i<n; i++) cin>>a[i];
     while(q--)
     {
         int m;
         cin>>m;
         deque<pii>dq;
         int cnt_remove=-1;
         int mn=1e18;
         for(int i=0; i<n; i++)
         {
             if(i>=m && !dq.empty() &&  dq.front().second==cnt_remove)///remove if exceedeed
             {
                 dq.pop_front();
             }
             ///adding value
             while(!dq.empty() && dq.back().first<a[i])
             {
                 dq.pop_back();
             }
             dq.push_back({a[i],i});
             if(i>=m-1)
             {
                 ++cnt_remove;
                int mx=dq.front().first;
                mn=min(mn,mx);
             }
         }
         cout<<mn<<endl;
     }
}
