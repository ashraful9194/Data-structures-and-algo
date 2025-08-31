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
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};

int main()
{
    ///............................only length in nlogn,.................
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n;
     cin>>n;
     int a[n+5];
     for(int i=0; i<n; i++)
        cin>>a[i];
     vector<int>ans;
     ans.pb(a[0]);
     for(int i=1; i<n; i++)
     {
         if(a[i]>ans.back())
            ans.pb(a[i]);
         else
         {
             int x=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
             ans[x]=a[i];
         }
     }
     cout<<ans.size()<<endl;
}


