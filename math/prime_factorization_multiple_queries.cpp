#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int lpf[1000003];///least prime factor
int sieve(int n)
{
    lpf[1]=1;

    for(int i=2; i<=sqrt(n); i++)
    {
        if(lpf[i]==0)
        {
            lpf[i]=i;
            for(int j=i*i; j<=n; j+=i)
                if(lpf[j]==0) lpf[j]=i;
        }
    }
    for(int i=2; i<=n; i++)
        if(lpf[i]==0) lpf[i]=i;
}
int main()
{
    int n,q;
    cin>>n>>q;
    sieve(1000000);
    while(q--)///q*logn
    {
        vector<int>v;
       cin>>n;
       while(n>1)///logn
        {
            v.pb(lpf[n]);
            n=n/lpf[n];
        }
        for(auto i:v) cout<<i<<" ";
        cout<<endl;
    }
}
