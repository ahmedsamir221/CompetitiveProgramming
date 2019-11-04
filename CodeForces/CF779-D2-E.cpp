//https://codeforces.com/blog/entry/50724
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
const int N=5009,M=1000000;


int n,m,t[N],mn[N],mx[N];
string a[N],b[N];
string name[N];
pair<int,int>get(int idx,int val)
{
    unordered_map<string ,int>ans;
    int zero=0, one=0;
    forr(i,1,n)
    {
        if(t[i]==1)
        {
            if(a[i][idx]=='0')zero++;
            else one++;
            ans[name[i]]=a[i][idx]-'0';
        }
        else if(t[i]==2)
        {
            int A=val,B=val;
            if(a[i][0]!='?')A=ans[a[i]];
            if(b[i][0]!='?')B=ans[b[i]];
            if(A&B)one++,ans[name[i]]=1;
            else zero++,ans[name[i]]=0;
        }
        else if(t[i]==3)
        {
            int A=val,B=val;
            if(a[i][0]!='?')A=ans[a[i]];
            if(b[i][0]!='?')B=ans[b[i]];
            if(A|B)one++,ans[name[i]]=1;
            else zero++,ans[name[i]]=0;
        }
        else
        {
            int A=val,B=val;
            if(a[i][0]!='?')A=ans[a[i]];
            if(b[i][0]!='?')B=ans[b[i]];
            if(A^B)one++,ans[name[i]]=1;
            else zero++,ans[name[i]]=0;
        }

    }
    return {zero,one};
}

void solve(int idx)
{
    pair<int,int>zero=get(idx,0);
    pair<int,int>one=get(idx,1);

    if(zero.F>=one.F)mn[idx]=0;
    else mn[idx]=1;

    if(zero.S<one.S)mx[idx]=1;
    else mx[idx]=0;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
     cin>>n>>m;
     cin.ignore();
     string s;
     forr(i,1,n)
     {
         getline(cin,s);
         int spaces=0,cc=0;
         for(auto p:s)
         {
            if(p==' ')spaces++;
            cc++;
            if(cc>50)break;
         }
         stringstream f;
         f<<s;
         if(spaces==2)
         {
             string nam,dl,v;
             f>>nam>>dl>>v;
             name[i]=nam;
             t[i]=1;
             a[i]=v;
         }
         else
         {
             string nam,dl,u,op,v;
             f>>nam>>dl>>u>>op>>v;
             name[i]=nam;
             a[i]=u,b[i]=v;
             if(op=="AND")t[i]=2;
             else if(op=="OR")t[i]=3;
             else t[i]=4;
         }
     }
     for(int i=0;i<m;i++)solve(i);
     for(int i=0;i<m;i++)cout<<mn[i];
     cout<<endl;
     for(int i=0;i<m;i++)cout<<mx[i];
     cout<<endl;


return 0;
}
