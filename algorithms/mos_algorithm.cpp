/**Failing is always better than never trying*/
/**Winners never quit and quitters never win.*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
const int mx=1e5+5;
int n;
int block_size;

int ans[10*mx],a[mx];
int res;
int cnt[1000005];
struct query{
   int l,r,idx;
   bool operator<(query other)const
{
     if(l/block_size==other.l/block_size) return r<other.r;
     else return l/block_size<other.l/block_size;
}
};
vector<query>v;
void add(int idx)
{
    if(cnt[a[idx]]&1) ++res;
    ++cnt[a[idx]];
}
void remove(int idx)
{
     if((cnt[a[idx]]&1)==0) --res;
    --cnt[a[idx]];
}
int get_ans()
{
    return res;
}
void mos_algo()
{
    int cur_l = 1;
    int cur_r = 1;
    ++cnt[a[1]];
    for (auto q : v) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        ans[q.idx] = get_ans();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ///First find the ans for queries where 'l' lies in the first block,then for 2nd block.........Sth block.
    ///Complexity : O(N+Q)*block_size
    int q;
    cin>>n;
    block_size=sqrt(n)+1;
    for(int i=1; i<=n; i++) cin>>a[i];
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        int l,r;
        cin>>l>>r;
        v.pb({l,r,i});
    }
    sort(v.begin(),v.end());
    mos_algo();
    for(int i=1; i<=q; i++) cout<<ans[i]<<endl;
}
