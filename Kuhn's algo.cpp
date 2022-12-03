/**Failing is always better than never trying*/
/**Winners never quit and quitters never win.*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
int n,m;
string s[30];
vector<int>adj[500];
int mark[500][500];
int used[500],mt[500];
#define boundary(x,y) (x>=0 && y>=0 && x<n && y<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (auto to : adj[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}
void all_clear()
{
    for(int i=0; i<=400; i++)
    {
        adj[i].clear();
        used[i]=0;
        mt[i]=0;
    }
    memset(mark,0,sizeof mark);
}
int32_t main()
{
    ///grid is always a bipartite graph..........
    ///kuhn algo can find the max matching in any bipartite graph
    ///flow can find max match in two sets.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++) cin>>s[i];
        int gold=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='o')  continue;
                mark[i][j]=++gold;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='o')  continue;
                for(int k=0; k<4; k++)
                {
                    int x=i+X[k];
                    int y=j+Y[k];
                    if(boundary(x,y) && mark[x][y])
                    {
                        adj[mark[i][j]].pb(mark[x][y]);
                    }
                }
            }
        }
        memset(mt,-1,sizeof mt);
        int matching=0;///total matching node size.
        for(int i=1; i<=gold; i++)
        {
            memset(used,0,sizeof used);
            matching+=try_kuhn(i);
        }
        int ans=gold-matching+(matching/2);
        cout<<"Case "<<++tc<<": ";
        cout<<ans<<endl;
        all_clear();
    }
}
///Debug tips : Look for corner logic that is not handled.

