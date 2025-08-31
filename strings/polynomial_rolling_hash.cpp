#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
string s;
int hash_func()
{
    int p=31;
    int p_pow=1;
    int mod=1e9+9;
    int hash_val=0;
    for(char i:s)
    {
        hash_val=(hash_val%mod+((i-'a'+1)*p_pow)%mod)%mod;
        p_pow=(p_pow*p)%mod;
    }
    return hash_val;

}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     while(cin>>s)
     {
           int ans=hash_func();
          cout<<ans<<endl;
     }

}


