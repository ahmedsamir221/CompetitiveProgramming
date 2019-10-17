/*
   we have to cases
        1-put the first switch on .
        2-put the first switch off .
   then will be one case to the remaining switches  , we need to get the one with min flipping switches .
*/
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
const int N =500005;
int n;
vector<int> tobinary(string s)
{
    reverse(s.begin(),s.end());
    vector<int>x;
    while((int)s.size())
    {
        int g=s[0]-'0';
        if(g%2)x.push_back(1);
        else x.push_back(0);

        int r=0;
        for(int i=s.size()-1;i>-1;i--)
        {
            int num=s[i]-'0'+r;
            if(num%2)r=10;
            else r=0;
            s[i]=num/2+'0';
        }
        if(s[s.size()-1]=='0')s.pop_back();
    }
    return x;
}

pair<int,vector<int>> get(vector<int>a,vector<int>b,int pr)
{
    vector<int>x;
    int ans=0;
    if(pr==1){
        b[0]=!b[0];
        if(n>1)b[1]=!b[1];
        x.push_back(1),ans++;
    }
    else x.push_back(0);

    for(int i=1;i<n;i++)
    {
        if(a[i-1]!=b[i-1])
        {
            b[i]=!b[i];
            if(i+1<n)b[i+1]=!b[i+1];
            x.push_back(1);
            ans++;
        }
        else x.push_back(0);
    }
    if(a[n-1]!=b[n-1])ans+=1e8;
    return {ans,x};
}

vector<int> todec( vector<int>x)
{
    vector<int>f;
    for(int i=0;i<x.size();i++)
    {
        int r=x[i];
        for(int j=0;j<f.size();j++)
        {
            int num=f[j]*2+r;
            f[j]=num%10;
            r=num/10;
        }
        if(r)f.push_back(1);
    }
    reverse(f.begin(),f.end());
    if(f.size()==0)
    {
        vector<int>k;k.push_back(0);
        return k;
    }
    return f;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
  int cas=0;
  while(1)
  {
      string s,t;
      cin>>s>>t;
      if(s[0]=='0'&&t[0]=='0')break;
      vector<int>a=tobinary(s);
      vector<int>b=tobinary(t);
      while(a.size()>b.size())b.push_back(0);
      while(b.size()>a.size())a.push_back(0);
      n=a.size();
      reverse(a.begin(),a.end());
      reverse(b.begin(),b.end());
      pair<int,vector<int>>ans=min(get(a,b,0),get(a,b,1));
      if(cas)cout<<endl;
      cout<<"Case Number "<<++cas<<": ";
      if(ans.F>=1e8)cout<<"impossible"<<endl;
      else{
        vector<int>k=todec(ans.S);
        for(auto p:k)cout<<p;
        cout<<endl;
      }
  }


return 0;
}
