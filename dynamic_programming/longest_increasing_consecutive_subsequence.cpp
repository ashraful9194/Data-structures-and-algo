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
map<int,int>mp;
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n;
     cin>>n;
     int a[n+5];
     for(int i=1; i<=n; i++) cin>>a[i];
     vector<int>dp(n+5,1);
     int ind=0,mx=0;
     for(int i=1; i<=n; i++)
     {
         int x=a[i]-1;
         if(mp.find(x)!=mp.end())
         {
             dp[i]+=dp[mp[x]];
             if(dp[i]>mx)
             {
                 mx=dp[i];
                 ind=i;
             }

         }
         mp[a[i]]=i;
     }
     int prev=a[ind]+1;
     if(mx==0)
     {
         cout<<1<<endl;
         cout<<1<<endl;
         return 0;
     }
     cout<<mx<<endl;
     vector<int>ans;
     while(ind>=1)
     {
           if(a[ind]==prev-1)
           {
               ans.pb(ind);
               prev=a[ind];
           }
           --ind;
     }
     sort(ans.begin(),ans.end());
     for(int i:ans) cout<<i<<"  ";
     cout<<endl;
}



