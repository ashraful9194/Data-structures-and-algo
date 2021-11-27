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
int n;
int a[5008];
int divide_and_conquor(int lo,int hi,int prev)
{
    if(hi<lo) return 0;
    int mn=min_element(a+lo,a+hi+1)-a;
    int cost=a[mn]-prev+divide_and_conquor(lo,mn-1,a[mn])+divide_and_conquor(mn+1,hi,a[mn]);
    return min(cost,hi-lo+1);
}
int main()
{
    ///painting fance codeforces......
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n;
     for(int i=0; i<n; i++)
        cin>>a[i];
     int ans=divide_and_conquor(0,n-1,0);
     cout<<ans<<endl;
}



