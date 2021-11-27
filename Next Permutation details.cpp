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
int a[1000],b[1000];
int x=1;
int n;
void nextpermutation()
{
    int i=n-2;
    while(a[i]>a[i+1])
        --i;
    if(i<0) return;
    int j=n-1;
    while(a[i]>a[j]) --j;
    if(j<0) return;
    swap(a[i],a[j]);

    j=n-1;
    for(int k=i+1; k<n-1; k++,j--)
        swap(a[k],a[j]);
    for( i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
   cout<<endl;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n;
     for(int i=0; i<n; i++)
     {
         cout<<i+1<<" ";
         a[i]=i+1;
     }
     cout<<endl;
     for(int i=1; i<=n; i++)
        x=x*i;
    --x;
     while(x--)
     {
         nextpermutation();
     }

}


