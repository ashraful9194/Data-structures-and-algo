///E. Maximum Subsequence....codeforces
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
int n,m;
int a[40];
set<int>st1,st2;
void solve(int sum,int l,int r,int xx)
{
    if(l>r)
    {
        if(xx==1) st1.insert(sum%m);
        else st2.insert(sum%m);
        return;
    }
    solve(sum+a[l],l+1,r,xx);
    solve(sum,l+1,r,xx);
}
int32_t main()
{
    ///by dividing into two parts ....this reduces the complexity from O(2^n) to O((2^(n/2))*log(2^(n/2)))............
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n>>m;
     for(int i=0; i<n; i++) cin>>a[i];
     solve(0,0,n/2,1);
     solve(0,n/2+1,n-1,2);
     int ans=0;
     for(auto it:st1)
     {
         auto xx=st2.upper_bound(m-1-it);
         if(xx==st2.begin()) continue;
         --xx;
         ans=max(ans,it+*xx);
     }
     cout<<ans<<endl;

}


