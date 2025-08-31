#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
bool mark[100002];
int sieve(int n)
{
    memset(mark,false,sizeof mark);
    for(int i=2; i<=sqrt(n); i++)
    {
        if(!mark[i])
            for(int j=i*i; j<=n; j+=i)
            mark[j]=true;
    }
    for(int i=2; i<=n; i++)
        if(!mark[i]) cout<<i<<" ";
    cout<<endl;

}
int main()
{
    int n;
    cin>>n;
    sieve(n);
}
