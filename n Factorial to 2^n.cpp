#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, greater<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
///cses:Elevator rides................
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n,x;
     cin>>n>>x;
     int a[n+5];
     for(int i=0; i<n; i++) cin>>a[i];
     pii dp[(1LL<<n)+5];
     dp[0]={1,0};

     for(int msk=1; msk<(1LL<<n); msk++)
     {
         dp[msk]={25,500};
         for(int i=0; i<n; i++)
         {
             if((msk>>i)&1)
             {
                 ///For a mask we are trying to minimize the number of rides at first by involving the previous mask
                 ///If number of rides are same then we are trying to minimize the occupied weight.
                 ///We will try to minimize the number of rides thats obvious .But why are we trying to
                 /// minimize the occupied weight?.....It's because if we can minimize the occupied weight at current
                 ///operation then the possibility of increasing the number of rides in our future opearation will be less.
                 int op=dp[msk^(1LL<<i)].first,w=dp[msk^(1LL<<i)].second;
                 if(w+a[i]<=x)
                    w+=a[i];
                 else
                 {
                     ++op;
                     w=a[i];
                 }
                 dp[msk]=min(dp[msk],{op,w});
             }
         }
     }
     cout<<dp[(1LL<<n)-1].first<<endl;

}


