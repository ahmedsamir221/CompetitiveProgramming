/*
    we can use trie in the bits of numbers , when we add a number we will add it's index in each bit ,
    and keep them in sorted way .
    when we query we will check if our interval exist in the zero branch or the one branch and choose
    the one that maximize our answer .
*/
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N = 2e5 + 9;
int ans;
struct node{
    vector<int>id;
    node*left=NULL;
    node*right=NULL;
};

void add(node*root,int x,int i,int idx)
{
    if(i==-1)return;
    if(x&(1<<i))
    {
        if(root->right==NULL)root->right=new node();
        root->right->id.push_back(idx);
        add(root->right,x,i-1,idx);
    }
    else
    {
        if(root->left==NULL)root->left=new node();
        root->left->id.push_back(idx);
        add(root->left,x,i-1,idx);
    }
}

void get(node*root,int a,int i,int l,int r)
{
    if(i==-1)return ;

    if(a&(1<<i))
    {
        if(root->left==NULL)
        {
            get(root->right,a,i-1,l,r);
            return;
        }
        auto it=lower_bound(root->left->id.begin(),root->left->id.end(),l);
        if(it==root->left->id.end()||*it>r)get(root->right,a,i-1,l,r);
        else
        {
            ans|=(1<<i);
            get(root->left,a,i-1,l,r);
        }
    }
    else
    {
        if(root->right==NULL)
        {
            get(root->left,a,i-1,l,r);
            return;
        }
        auto it=lower_bound(root->right->id.begin(),root->right->id.end(),l);
        if(it==root->right->id.end()||*it>r)get(root->left,a,i-1,l,r);
        else
        {
            ans|=(1<<i);
            get(root->right,a,i-1,l,r);
        }
    }
}

 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input
    int t;
    scanf("%d",&t);
    while(t--)
    {
        node*root=new node();
        int n,q,x;
        scanf("%d %d",&n,&q);
        forr(i,1,n)
        {
            scanf("%d",&x);
            add(root,x,15,i);
        }
        int a,l,r;
        forr(i,1,q)
        {
            scanf("%d %d %d",&a,&l,&r);
            ans=0;
            get(root,a,15,l,r);
            printf("%d\n",ans);
        }
    }

return 0;
}
