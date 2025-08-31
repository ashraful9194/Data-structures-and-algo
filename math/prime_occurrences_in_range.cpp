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
int solve(int n,int p)
{
    int ans=0;
    while(n)
    {
        ans+=(n/p);
        n/=p;
    }
    return ans;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     /// Count the values which are divisible by P, P^2, P^3, …, P^x in the range [L, R]
     ///complexity=log(n)...................
     int l,r,p;
     cin>>l>>r>>p;
     int ans=solve(r,p)-solve(l-1,p);
     cout<<ans<<endl;


}

