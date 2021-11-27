#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, greater<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};

int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     /**
     Try to find out which setbit is contributing how much.....
     Consider the array 1,1,1,1,0,0,0,0,0.
     n=9
     How many subsets are there where the number of 1 is odd?

     take the leftmost 1 as pivot ...so the remaining n-1 elements form 2^(n-1) different subsets
     So,From those subsets where the number of 1 is odd we do nothing ,But where the number of 1 is even
     we just use our pivot to make it odd.........

     So the answer for our question is 2^(n-1).........

     Summary : As each bit is contributing 2^(n-1) times so,
     sum of xor for all subsets = OR value of all elements * 2^(n-1).

     It can also be proved using combinatorics .But that is not necessary.

     */

     int n;
     cin>>n;
     int a[n+5];
     for(int i=0; i<n; i++) cin>>a[i];

     int orr=0;

     for(int i=0;  i<n; i++) orr|=a[i];

     cout<<orr*pow(2LL,n-1)<<endl;


}

