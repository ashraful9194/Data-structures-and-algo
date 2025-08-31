#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
ll l,r;
vector<int>prime;
void simpleSieve(int n)
{
     bool mark[1000000];
     memset(mark,false,sizeof mark);
     for(int i=3; i<=sqrt(n); i+=2)
     {
         if(!mark[i])
         {
             for(int j=i*i; j<=n; j+=i*2) mark[j]=true;
         }
     }
     prime.pb(2);
     for(int i=3; i<=n; i+=2)
        if(!mark[i]) prime.pb(i);
}
void segmentedSieve(ll l,ll r)
{
    simpleSieve(sqrt(r));
    bool mark2[r-l+1];
    memset(mark2,false,sizeof mark2);
    for(int i=0; i<prime.size(); i++)
    {
        ll x=prime[i]*1LL;
        prime[i]=prime[i]*1LL;
        x=(l/x)*x;
        if(x<l) x+= prime[i];
        if(x==prime[i]) x+= prime[i];
        for(ll j=x; j<=r; j+=prime[i])
        {
            int ind=j-l;
            mark2[ind]=true;
        }
    }
    for(ll i=l; i<=r; i++)
    {
          int ind=i-l;
          if(!mark2[ind]) cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
     cin>>l>>r;
     segmentedSieve(l,r);
}

