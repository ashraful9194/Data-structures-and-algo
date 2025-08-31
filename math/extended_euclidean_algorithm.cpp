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
  /**
      If b==0 then gcd =a ....
      As ax+by=gcd....So a*1+b*0=gcd..So x1=1,y1=0.(Base case).....

      Now ax+by=g........(1)[prev stage]
          bx1+(a%b)y1=g......(2)[pres stage]

    Find x and y of prev stage using x1,y1 of present stage....

    So ,just equalize the co-efficient of a,b to find x,y.....

    From (2)..bx1+[a-floor(a/b)*b]y1=g
            or,ay1+b[x1-floor(a/b)*y1]=g

    So x=y1
       y=x1-floor(a/b)*y1....
  */
   int a,b,x,y;
   cin>>a>>b;
   int gcd=egcd(a,b,&x,&y);
   cout<<gcd<<endl;
   cout<<x<<" "<<y<<endl;
}
