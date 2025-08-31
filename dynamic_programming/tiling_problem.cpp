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
/*
Given a “2 x n” board and tiles of size “2 x 1”,
count the number of ways to tile the given board using the 2 x 1 tiles.
A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.
*/
int n;
int solve(int n)
{
    if(n==1 || n==2) return n;
    int x=solve(n-1)+solve(n-2);
    return x;
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n;
     int ans=solve(n);
     cout<<ans<<endl;

}


