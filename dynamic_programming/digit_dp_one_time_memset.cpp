/**Failing is always better than never trying*/
/**Winners never quit and quitters never win.*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
/**
   Find how many numbers are there less than N such that,
   "count of distinct digits of the number is equal to the maximum digit of the number".
*/
int dp[20][2][2][10][1LL<<10];
vector<int>num;
int n;
int solve(int pos,int is_small,int is_start,int mx,int msk)
{
    if(pos==-1)
    {
        if(!is_start) return 0;
        return  (mx==__builtin_popcount(msk));
    }
    int &ans=dp[pos][is_small][is_start][mx][msk];
    if(ans!=-1 && is_small) return ans;///return all possible answer 99999999.................
    ans=0;
    int till=(is_small?9:num[pos]);
    if(is_start)
    {
        for(int i=0; i<=till; i++)
            ans+=solve(pos-1,is_small|(i<num[pos]),1,max(mx,i),msk|(1LL<<i));
    }
    else
    {
        ans+=solve(pos-1,1,0,0,0);
        for(int i=1; i<=till; i++)
            {
                ans+=solve(pos-1,is_small|(i<num[pos]),1,max(mx,i),msk|(1LL<<i));
            }
    }
    return ans;
}
void pre_calc(int x)
{
    num.clear();
    while(x)
    {
        num.pb(x%10);
        x/=10;
    }
    n=num.size();
}
int32_t main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /**
       num :  746385
       idx :  543210
    */
    memset(dp,-1,sizeof dp);

    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        pre_calc(x);
        cout<<solve(n-1,0,0,0,0)<<endl;
    }
}
