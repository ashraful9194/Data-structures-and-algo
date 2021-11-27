#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
#define int long long
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int n,q,c;
int cnt[15][105][105];
///codeforces problem star sky....................................................
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n>>q>>c;
     for(int i=0; i<n; i++)
     {
         int x,y,s;
         cin>>x>>y>>s;
         ++cnt[s][x][y];
     }
     for(int i=0; i<=c; i++)
     {
         for(int j=1; j<=100; j++)
         {
             for(int k=1; k<=100; k++)
             {
                 cnt[i][j][k]+=cnt[i][j-1][k]+cnt[i][j][k-1]-cnt[i][j-1][k-1];
             }
         }
     }
     while(q--)
     {
         int t,x1,x2,y1,y2;
         cin>>t>>x1>>y1>>x2>>y2;
         int ans=0;
         for(int i=0; i<=c; i++)
         {
             int x=(t+i)%(c+1);
             int y=cnt[i][x2][y2]-cnt[i][x1-1][y2]-cnt[i][x2][y1-1]+cnt[i][x1-1][y1-1];
             ans+=(x*y);
         }
         cout<<ans<<endl;
     }
}



