/**Failing is always better than never trying*/
/**Winners never quit and quitters never win.*/
///Atcode dp contest : M-Candies
///Dp optimization using BIT.
///TLE using segment tree.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
const int mx=1e5+6;
int a[102];
int fentree[mx];
const int p=1e9+7;
int dp[mx];
void add(int idx, int x, int n)
{
       while(idx<=n)
       {
             fentree[idx]+=x;
             fentree[idx]%=p;
             idx += idx & (-idx);
       }
}
int query(int idx){
       int sum=0;
       while(idx>0){
             sum+=fentree[idx];
             sum%=p;
             idx -= idx & (-idx);
       }
       return sum;
}
int range_query(int l,int r)
{
    int ans=(query(r)-query(l-1)+p)%p;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];

     for(int j=0; j<=min(k,a[n-1]); j++)
        {
            add(j+1,1,100002);
            dp[j]=1;
        }
    for(int i=n-2; i>=0; i--)
    {
        int now[k+5]={0};
        for(int j=k; j>=0; j--)
        {
            int x=min(a[i],j);
            int l=j-x,r=j;
            now[j]=range_query(l+1,r+1);
           add(j+1,now[j]-dp[j],100004);
           dp[j]=now[j];
        }
    }
    cout<<dp[k]<<endl;
}
