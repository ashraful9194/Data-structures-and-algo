#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
//int cnt[400002];
//int pref[400005];
int main()
{
    ///prob:Constant palindrome sum........
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     while(t--)
     {
         int n,k;
        // memset(cnt,0,sizeof cnt);
       //  memset(pref,0,sizeof pref);

         cin>>n>>k;
           vector<int>cnt(2*k+5,0);
          vector<int>pref(2*k+5,0);
         int a[n+5];
         for(int i=0; i<n; i++)
            cin>>a[i];
         for(int i=0; i<n/2; i++)
         {
             ++cnt[a[i]+a[n-1-i]];
             int l=min(a[i],a[n-1-i])+1;
             int r=max(a[i],a[n-1-i])+k;
             ++pref[l];
             --pref[r+1];
         }
         for(int i=1; i<=2*k; i++)
            pref[i]+=pref[i-1];
        int ans=n/2;
         for(int i=2; i<=2*k; i++)
         {
              int c0=cnt[i];
              int c1=pref[i]-c0;
              int c2=(n/2)-(c1+c0);
              c2=2*c2;
              ans=min(ans,c1+c2);
         }
         cout<<ans<<endl;

     }
}



