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
vector<int>prime;
int sz;
int solve(bitset<40>bs,int lo,int hi)
{
    int cnt=0;
    int tmp=1;
    for(int i=0; i<sz; i++)
    {
        if(bs[i]==1)
          {
              tmp=tmp*prime[i];
              ++cnt;
          }

    }
    int ans=(hi/tmp)-(lo/tmp);

    if(cnt%2) return ans;
    return -ans;
}
int32_t main()
{

    ///same GCD codeforces....
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     while(t--)
     {
         int a,m;
         cin>>a>>m;
         int g=__gcd(a,m);
         a=a/g;
         m=m/g;
         int temp=m;
         for(int i=2; i<=sqrt(m); i++)
         {
             if(temp%i==0) prime.pb(i);
             while(temp%i==0)
                temp=temp/i;
         }
         if(temp>1) prime.pb(temp);
          sz=prime.size();
         int lo=a;
         int hi=a+m-1;
         int ans=0;
         for(int i=1; i<(1<<sz); i++)///inclusion exclusion principle..................
         {
             bitset<40>bs(i);
             ans+=solve(bs,lo-1,hi);
         }
         cout<<m-ans<<endl;
         prime.clear();
     }
}



