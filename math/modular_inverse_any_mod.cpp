#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int egcd(int a,int b,int *x,int *y)
{
    if(b==0)
    {
        *x=1;
        *y=0;
        return a;
    }
  int x1,y1;
  int g=egcd(b,a%b,&x1,&y1);
  *x=y1;
  *y=x1-(a/b)*y1;
  return  g;

}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    ///This works  for all mods.....
  ///a and mod must be co-prime.....
  /*
     1/12(mod 25)=??
     1/12(mod 25)=x;
     12x=1(mod 25)
     12x+25y=1(mod 25)...Diophantine equation///(ax+by=gcd(a,b))...Bezouts identity......
     now ,by solving this equation with extended eucledean algo our ans=value of x.......
     by egcd ax+by=gcd(a,b)

     gcd(a,b)=gcd(b,a%b)..///always keep small .....
  */
   int a,m,x,y;
   cin>>a>>m;
   int gcd=egcd(a,m,&x,&y);
   cout<<gcd<<endl;
   cout<<x<<" "<<y<<endl;
   cout<<(x+m)%m<<endl;

}


