#include<bits/stdc++.h>///works till 1e8.......
using namespace std;
int mark[100000000/32];
int checkbit(int ind,int pos)
{
  return ind&(1<<pos);
}
int setbit(int ind,int pos)
{
    return  ind|=(1<<pos);
}
int bitwise_sieve(int n)
{

    for(int i=3; i<=sqrt(n); i+=2)
    {
        if(!checkbit(mark[i/32],i%32))
        {
            for(int j=i*i; j<=n; j+=i*2)
                if(!checkbit(mark[i/32],i%32)) mark[j/32]=setbit(mark[j/32],j%32);
        }
    }
    cout<<2<<" ";
    for(int i=3; i<=n; i+=2)
         if(!checkbit(mark[i/32],i%32)) cout<<i<<" ";
    cout<<endl;
}
int main()
{
   int n;
   cin>>n;
   bitwise_sieve(n);
}
