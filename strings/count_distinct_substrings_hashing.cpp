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
int diff_substr()
{
    int n=s.size();
    int p=31;
    int mod=1e9+9;
    vector<int>p_pow(n);
    p_pow[0]=1;
    for(int i=1; i<n; i++)
        p_pow[i]=(p*p_pow[i-1])%mod;
    vector<int>pref_hsh(n+3,0);
    for(int i=0; i<n; i++)
    {
        pref_hsh[i+1]=(pref_hsh[i]+(s[i]-'a'+1)*p_pow[i])%mod;
    }
   /*
 set<int>st;
    for(int i=1; i<=n; i++)
    {

        for(int j=0; j<=n-i; j++)
        {
            int x=(pref_hsh[j+i]-pref_hsh[j]+mod)%mod;
           x=(x*p_pow[n-j-1])%mod;
            st.insert(x);
        }

    }
    */
    set<int>st;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            int x=(pref_hsh[j+i]-pref_hsh[j]+mod)%mod;
           x=(x*p_pow[j-i+1])%mod;
            st.insert(x);
        }
    }
    return st.size();

}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>s;
     int ans=diff_substr();
     cout<<ans<<endl;

}


