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
int basen[1000];
int baser[1000];
int solve(int x,int p,int flag)
{

}
int32_t main()
{
    ///Lucas theorem.......
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n,r,p;
     cin>>n>>r>>p;
     ///total complexity O(p+logn+logr)....
     ///just convert  n and r to base p and multiply the ncr of all coefficients  of n and r........
     ///n=p^k*x1+p^(k-1)*x2+p^(k-2)*x3+......p^0*xk.
     ///r=p^k*y1+p^(k-1)*y2+p^(k-2)*y3+......p^0*yk.
     ///our ans= x1Cy1*x2Cy2*x3Cy3*................xkCyk
     ///range of x and y is [0,p].....



}


