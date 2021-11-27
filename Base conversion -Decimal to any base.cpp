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
vector<int>v;
void solve(int n,int b)
{

    while(n)
    {
         v.pb(n%b);
         n=n/b;
    }
    reverse(v.begin(),v.end());
    for(auto i:v) cout<<i;
    cout<<endl;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n,b;
     cin>>n>>b;
     solve(n,b);
}


