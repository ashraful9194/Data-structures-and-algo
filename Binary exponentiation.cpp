#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define endl '\n'
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
#define mod 1000000007
ll binary_exp(ll n,ll m)
{
    if(m==1)  return n;
    if(m%2==1)
        return  ((n%mod)*(binary_exp(n,m-1)%mod))%mod;
    else
    {
        ll temp=binary_exp(n,m/2)%mod;
        return (temp*temp)%mod;
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    cout<<binary_exp(n,m)<<endl;

}



