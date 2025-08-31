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
int ways[1000];
int coins[1000];
int main()
{
    ///order does not matter
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ways[0]=1;
     int n,sum;
     cin>>n>>sum;
     for(int i=0; i<n; i++)
        cin>>coins[i];
    for(int i=0; i<n; i++)
    {
        for(int j=coins[i]; j<=sum; j++)
        {
            ways[j]+=ways[j-coins[i]];
        }
    }
    cout<<ways[sum]<<endl;


}


