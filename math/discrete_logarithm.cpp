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
int a,b,m;
///this find the minimum x.....
int discreet_log(int a,int b,int m)
{
    if(a==0)
        return  b==0?1:-1;
    a=a%m,b=b%m;
    int n=sqrt(m)+1;
    int res=1;
    for(int i=0; i<n; i++)
        res=(res*a)%m;///a^n
    unordered_map<int,int>vals;///O(1)
    int cur=b;
    for(int q=0; q<n; q++)///a^q
    {
        vals[cur]=q;
        cur=(cur*a)%m;
    }
    cur=1;
    for(int p=1; p<=n; p++)
    {
        cur=(cur*res)%m;
        if(vals.count(cur))///O(1)
            return  n*p-vals[cur];
    }
    return -1;
}
int32_t main()
{
    ///this works only if gcd(a,m)=1.........
    ///shanks baby step giant algo......
    ///Best implementation......O(sqrt(m)).......using hashmap..
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     /*
     a^x=b(mod m)
     find x
     or, find x=loga(b)(mod m)
     log a base b mod m
     */
     cin>>a>>b>>m;
     int ans=discreet_log(a,b,m);
     cout<<ans<<endl;
}


