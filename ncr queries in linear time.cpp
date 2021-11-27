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
int fact[1000];
int modinv[1000];
int p;
int modIverse(int x,int y)
{
    int res = 1;

    x = x % p;
    while (y > 0) {
        if (y & 1)
            {
                res = (res * x) % p;
                --y;
                if(y==0) break;
            }

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>p;
     fact[0]=1;
     for(int i=1; i<=100; i++) fact[i]=(i*fact[i-1])%p;
     modinv[100]=modIverse(fact[100],p-2);
     for(int i=99; i>=1; i--) modinv[i]=(modinv[i+1]*(i+1))%p;
     int q;
     cin>>q;
     while(q--)
     {
         int n,r;
         cin>>n>>r;
         int ans=((fact[n]*modinv[r])%p*modinv[n-r])%p;
         cout<<ans<<endl;
     }


}


