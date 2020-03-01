//https://github.com/shashank0107/CompetitiveProgramming/blob/master/SPOJ/BRICKS.cpp
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

int n,tree[26][N],ck[26][26];
char ch[N];
void up(int cr,int idx,int v)
{
    for(;idx<=n;idx+=idx&-idx)tree[cr][idx]+=v;
}
int get(int cr,int idx)
{
    if(idx==0)return 0;
    int res=0;
    for(;idx;idx-=idx&-idx)res+=tree[cr][idx];
    return res;
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
            scanf("%s",ch);
            string s=(ch);
            n=s.size();
            forr(j,0,25)forr(i,1,n)tree[j][i]=0;

            deque<int>v[26];
            for(int i=0;i<n;i++)
            {
                int idx=i+1;
                int cr=s[i]-'a';
                up(cr,idx,1);
                v[cr].push_back(idx);
            }
            scanf("%s",ch);
            string t=(ch);
            memset(ck,0,sizeof ck);
            int m;
            scanf("%d",&m);
            forr(i,1,m)
            {
                scanf("%s",ch);
                ck[ch[0]-'a'][ch[1]-'a']=ck[ch[1]-'a'][ch[0]-'a']=1;
            }
            m=t.size();
            ll ans=0;
            for(int i=0;i<m;i++)
            {
                int cr=t[i]-'a';
                if(v[cr].empty())
                {
                    ans=-1;
                    break;
                }
                int idx=v[cr].front();
                v[cr].pop_front();
                up(cr,idx,-1);
                for(int j=0;j<26;j++)
                {
                    int cnt=get(j,idx);
                    if(cnt&&ck[cr][j]==0)
                    {
                        ans=-1;
                        break;
                    }
                    ans+=cnt;
                }
            }
            if(ans>(1LL*1<<32))ans-=(1LL*1<<32);
            printf("%lld\n",ans);

        }

return 0;
}
