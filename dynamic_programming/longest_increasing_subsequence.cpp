#include<bits/stdc++.h>
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
    ///...........................O(n^2)..................
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n;
     cin>>n;
     int a[n+5];
     for(int i=0; i<n; i++)
        cin>>a[i];
    vector<int>dp(n+5,1);
    int mx=1,ind=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[j]<a[i])
               {
                    dp[i]=max(dp[i],1+dp[j]);
                    if(dp[i]>mx)
                    {
                        mx=dp[i];
                        ind=i;
                    }
               }
        }
    }
    cout<<mx<<endl;

    ///printing solution
     vector<int>ans;
     int prev=ind;
     ans.pb(a[prev]);
     --ind;
    while(ind>=0)
    {
        if(a[ind]<a[prev] && dp[ind]+1==dp[prev])
        {
             ans.pb(a[ind]);
             prev=ind;

        }
        --ind;
    }
  reverse(ans.begin(),ans.end());
    for(int i:ans) cout<<i<<" ";
    cout<<endl;
 ///...........................Another soln. is LCS(main array,sorted array)..................

}


