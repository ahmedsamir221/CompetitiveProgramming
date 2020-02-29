//https://github.com/MeGaCrazy/CompetitiveProgramming/blob/1804aa9c2f7169786363d83eeacd7a0a392653cb/SPOJ/SPOJ_ORDERSET.cpp
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
const int N = 9e5 + 9;

int n,tree[N],x[N],sz,ck[N],rv[N];
char c[N];
void up(int idx,int v)
{
    for(;idx<=sz;idx+=idx&-idx)tree[idx]+=v;
}
int get(int idx)
{
    if(idx==0)return 0;
    int res=0;
    for(;idx;idx-=idx&-idx)res+=tree[idx];
    return res;
}

 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
//input
            scanf("%d",&n);
            set<int>s;
            forr(i,1,n)
            {
                scanf(" %c%d",&c[i],&x[i]);
                s.insert(x[i]);
            }
            int cnt=0;
            map<int,int>re;
            set<int>::iterator it=s.begin();
            for(;it!=s.end();it++){
                int p=*it;
                re[p]=++cnt,rv[cnt]=p;
            }
            sz=re.size();
            sz=(int)log2(sz)+1;
            sz=(1<<sz);
            //cout<<sz<<endl;
            forr(i,1,n)
            {
                int idx=re[x[i]];
                if(c[i]=='I')
                {
                    if(ck[idx]==0)up(idx,1),ck[idx]=1;
                }
                else if(c[i]=='D')
                {
                    if(ck[idx]==1)up(idx,-1),ck[idx]=0;
                }
                else if(c[i]=='C')
                {
                    printf("%d\n",get(idx-1));
                }
                else
                {
                    if(x[i]>get(sz))printf("invalid\n");
                    else{
                    int l=1,r=sz,mid;
                    //cout<<l<<"  "<<r<<endl;
                    while(l<r)
                    {
                        mid=(l+r)/2;
                        if(tree[mid]<x[i])l=mid+1,x[i]-=tree[mid];
                        else r=mid;
                    }
                    printf("%d\n",rv[l]);
                    }
                }
            }





return 0;
}
