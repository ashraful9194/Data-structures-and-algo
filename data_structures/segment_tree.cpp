#include<bits/stdc++.h>
#define mx 1000005
using namespace std;
int arr[mx];
int tree[mx*3];
void init(int node,int b,int e)///nlogn
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j)///logn
{
    if(i>e || j<b)
        return mx;
    if(b>=i && e<=j)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int q1=query(left,b,mid,i,j);
    int q2=query(right,mid+1,e,i,j);
    return q1+q2;
}
void update(int node,int b,int e,int ind,int val)///logn
{
    if(b>ind || e<ind) return;
    if(b==e && b==ind)
    {
        arr[b]=val;
        tree[node]=val;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    update(left,b,mid,ind,val);
    update(right,mid+1,e,ind,val);
    tree[node]=tree[left]+tree[right];

}
int main()
{
    int t,n,q,i,j,x,y,min;

        scanf("%d %d",&n,&q);
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&arr[j]);
        }
        init(1,1,n);
        cout<<tree[1]<<" "<<tree[2]<<" "<<tree[3]<<endl;
        update(1,1,n,2,10);
        cout<<tree[1]<<" "<<tree[2]<<" "<<tree[3]<<endl;
}
