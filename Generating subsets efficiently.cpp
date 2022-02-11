/**Failing is always better than never trying*/
/**Winners never quit and quitters never win.*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'

int n,k;
int a[30];
int b[30];
int mat[30][30];
int mn,target,mask;

void floyd(){
    for(int l=0;l<n;l++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=min(mat[i][j],mat[i][l]+mat[l][j]);
            }
        }
    }
}
/**
Without using dp TL has come down to O(2^n) instead of O(n*2^n)
because we are itearating over 2^n possibilities....
*/
void back_track(int pos,int msk,int vis_msk,int cost)
{
    if(vis_msk==target)
    {
        if(cost<mn)
        {
            mn=cost;
            mask=msk;
        }
        return;
    }
    if(pos==n) return;
    back_track(pos+1,msk|(1LL<<pos),vis_msk|b[pos],cost+a[pos]);
    back_track(pos+1,msk,vis_msk,cost);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ///Generating all subsets
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cin>>n>>k;
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
             cin>>mat[i][j];
        floyd();
        for(int i=0; i<n; i++)
        {
            int sum=0;
            b[i]=0;
            for(int j=0; j<n; j++)
            {
                int x=mat[i][j];
                if(x<=k)
                    b[i]|=(1LL<<j);
            }
        }
        target=(1LL<<n)-1;
        mn=1e18;
        back_track(0,0,0,0);

        cout<<"Case "<<tc<<":";
        int ok=0;
        for(int i=0; i<n; i++)
        {
            if((mask>>i)&1)
            {
                cout<<" "<<i;
            }
        }
        cout<<endl;
    }
}
