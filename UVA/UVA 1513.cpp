/*
    using BIT we can get the answer of the first occurrence of each number by count the number of elements
    bigger than it that moved to the top of the stack  + number of elements smaller than it .

    the other occurrences we need to get the number of distinct elements  between every tow occurrences
    and we can do that by segment tree .
*/
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

//const double PI  = acos(-1.0);
using namespace std;
//typedef pair<double,double>pdd;
typedef long long  ll;
//typedef pair<ll, ll>pii;
//typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const double EPS = 1e-9;
const int N = 1e5 + 9;

int n,m,tree[N],id[N],k[N],a[N];
void up(int idx,int v)
{
    for(;idx<=n;idx+=idx&-idx)tree[idx]+=v;
}
int get(int idx)
{
    if(idx==0)return 0;
    int res=0;
    for(;idx;idx-=idx&-idx)res+=tree[idx];
    return res;
}

vector<int>val[N*20];

void bulid(int s,int e,int p)
{
    val[p].clear();
    val[p].resize(e-s+1);
    if(s==e)
    {
        val[p][0]=a[s];
        return ;
    }
    int mid=(s+e)/2;
    bulid(s,mid,p*2);
    bulid(mid+1,e,p*2+1);
    merge(val[p*2].begin(),val[p*2].end(),val[p*2+1].begin(),val[p*2+1].end(),val[p].begin());
}

int get(int s,int e,int p,int l,int r)
{
    if(l>r)return 0;
    if(e<l||s>r)return 0;
    if(s>=l&&e<=r)
    {
        auto it=lower_bound(val[p].begin(),val[p].end(),l);
        return (it-val[p].begin());
    }
    int mid=(s+e)/2;
    return get(s,mid,p*2,l,r)+get(mid+1,e,p*2+1,l,r);
}

 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
//input
        int t;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d",&n,&m);
            memset(id,0,(n+5)*sizeof id[0]);
            memset(tree,0,(n+5)*sizeof tree[0]);
            int x;
            forr(i,1,m)
            {
                scanf("%d",&k[i]);
                x=k[i];
                a[i]=id[x];
                id[x]=i;
            }
            bulid(1,m,1);
            vector<int>ans;
            forr(i,1,m)
            {
                x=k[i];
                if(a[i])
                {
                    ans.push_back(get(1,m,1,a[i]+1,i-1));
                    continue;
                }
                int c=x-1+(get(n)-get(x));
                ans.push_back(c);
                up(x,1);
            }
            printf("%d",ans[0]);
            for(int i=1;i<m;i++)printf(" %d",ans[i]);
            printf("\n");

        }

return 0;
}
