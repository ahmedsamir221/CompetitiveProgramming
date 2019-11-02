//https://discuss.codechef.com/t/matper-editorial/22233
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>


/*
#define x real()
#define y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
*/

//#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
#define NOT(x) (1^x)

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const int N=500009,M=1000000;
const double EPS= 1e-9,eps=-1e9;
const int N =300005;

int n,m,sz[20],mx;
string s,st[20];

char pat[N];
int F[N];
int vpat[16][N],vpatr[16][N];
int getNextLen(int len, char c){
  while(len && pat[len] != c)
    len = F[len-1];
  if(pat[len] == c) ++len;
  return len;
}

void computeF(int n){
  F[0] = 0;
  for(int i = 1 ; i < n ; ++i)
    F[i] = getNextLen(F[i-1], pat[i]);
}
void solvekmp(int idx)
{
    int i=0;
    for(;i<sz[idx];)pat[i]=st[idx][i],i++;
    pat[i++]='&';
    for(int j=0;j<s.size();j++)pat[i++]=s[j];
    computeF(i);
    for(int j=0;j<s.size();j++)
    {
        vpat[idx][j]=-1,vpatr[idx][j]=-1;
        if(F[j+sz[idx]+1]==sz[idx])vpat[idx][j-sz[idx]+1]=j-sz[idx]+1,vpatr[idx][j-sz[idx]+1]=j-sz[idx]+1;
    }
    int val=-1;
    for(int j=n-1;j>-1;j--)
    {
        if(vpat[idx][j]!=-1)val=vpat[idx][j];
        vpat[idx][j]=val;
    }
    val=-1;
    for(int j=0;j<n;j++)
    {
        if(vpatr[idx][j]!=-1)val=vpatr[idx][j];
        vpatr[idx][j]=val;
    }

}
vector<int>cnt[500000];
int vis1[20];
vector<int>p1;
void bk1(int idx=0,int msk=0)
{
    if(n-idx<mx)return;
    if(p1.size()==m/2)
    {
        cnt[msk].push_back(idx-1);
        return;
    }
    if(idx>=n)return ;
    for(int i=0;i<m;i++)
    {
        if(vis1[i]==0)
        {
            int it=vpat[i][idx];
            if(it==-1)continue;
            vis1[i]=1;
            p1.push_back(i);
            bk1(it+sz[i],msk|(1<<i));
            p1.pop_back();
            vis1[i]=0;
        }
    }
}
ll ans;


int vis2[20];
vector<int>p2;
void bk2(int idx=n,int msk=0)
{
    if(idx<mx)return;
    if(p2.size()==m-m/2)
    {
        msk=~msk;
        msk&=((1<<m)-1);
        ans+=lower_bound(cnt[msk].begin(),cnt[msk].end(),idx)-cnt[msk].begin();
        return;
    }
    for(int i=0;i<m;i++)
    {
        if(vis2[i]==0)
        {
            if(idx-sz[i]<0)continue;
            int it=vpatr[i][idx-sz[i]];
            if(it==-1)continue;
            vis2[i]=1;
            p2.push_back(i);
            bk2(it, msk|(1<<i));
            p2.pop_back();
            vis2[i]=0;
        }
    }
}
char gg[100007];
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;


    scanf("%d %d",&n,&m);
    scanf("%s",gg);
    s=(gg);
    vector<int>xx;
    for(int i=0;i<m;i++)
    {
        scanf("%s",gg);
        st[i]=(gg);
        sz[i]=st[i].size();
        xx.push_back(sz[i]);
        solvekmp(i);
    }
    sort(xx.begin(),xx.end());
    for(int i=0;i<m/2;i++)mx+=xx[i];

    bk1();
    for(int i=0;i<(1<<m);i++)sort(cnt[i].begin(),cnt[i].end());
    bk2();
    printf("%lld\n",ans);

return 0;
}
