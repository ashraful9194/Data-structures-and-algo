#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};

struct node{
    bool endmark;
    node* next[27];///pointers
    node()///constructor
    {
        endmark=false;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }

} *root;///pointer
void insert(string s,int sz)
{
    node* curr=root;///new temp pointer
    for(int i=0; i<sz; i++)
    {
        int x=s[i]-'a';
        if(curr->next[x]==NULL) ///if the pointing address not allocated yet
            curr->next[x]=new node();///then allocate the address into memory
        curr=curr->next[x];///save curr as the next address..
    }
    curr->endmark=true;
}
bool search(string s,int sz)
{
    node* curr=root;
    for(int i=0; i<sz; i++)
    {
        int x=s[i]-'a';
        if(curr->next[x]==NULL) return false;
        curr=curr->next[x];
    }
    return curr->endmark;
}
void del(node* curr)
{
    for(int i=0; i<26; i++)
    {
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);


     int n;
    // cout<<"No of strings : ";
     cin>>n;

      root = new node();///allocating into memory
     for(int i=0; i<n; i++)
     {
         string s;
         cin>>s;
         insert(s,s.size());
     }
   //  cout<<"No of queries : ";
     int q;
     cin>>q;
     for(int i=0; i<q; i++)
     {
         string s;
         cin>>s;
         if(search(s,s.size()))
            cout<<"Found."<<endl;
         else cout<<"Not found."<<endl;
     }
     del(root);///destroy the trie....


}
