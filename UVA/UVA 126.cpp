/*
     we just need to simulate the process of product  .
*/
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=500005,M=1000000;
const double EPS= 1e-9;

string a,b;
int f[100],x[100],y[100],ff[100],xx[100],yy[100],cas;
char ch;

string get(int g)
{
    string num;
    while(g){
    num.push_back(g%10+'0');
    g/=10;}
    reverse(num.begin(),num.end());
    return num;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
input;
while(1)
{
    cin>>a;
    memset(f,0,sizeof f);
    memset(ff,0,sizeof ff);
    memset(x,0,sizeof x);
    memset(xx,0,sizeof xx);
    memset(y,0,sizeof y);
    memset(yy,0,sizeof yy);
    int n=0,ck=0,d=0,k=1,t[2]={0,0};
    if(a[0]!='-')n++;
    if(a=="#")break;
    for(auto p:a)
    {
       if(p=='+'||p=='-')
       {
        if(n&&f[n]==0)f[n]=k;
        else if(n)f[n]*=k;
        if(t[0]&&x[n]==0)x[n]=1;
        if(t[1]&&y[n]==0)y[n]=1;
        t[0]=0;
        t[1]=0;
        ck=0,n++;
        if(p=='+')k=1;
        else k=-1;
       }
       else if(p=='x')ck=1,t[0]=1;
       else if(p=='y')ck=2,t[1]=1;
       else
       {
           if(ck==0)f[n]=f[n]*10+p-'0';
           else if(ck==1)x[n]=x[n]*10+p-'0';
           else y[n]=y[n]*10+p-'0';
       }
    }
    if(n&&f[n]==0)f[n]=k;
    else if(n)f[n]*=k;
    if(t[0]&&x[n]==0)x[n]=1;
    if(t[1]&&y[n]==0)y[n]=1;

    cin>>b;
    int nn=0;
    if(b[0]!='-')nn++;
    ck=0,d=0,k=1,t[0]=0,t[1]=0;
    for(auto p:b)
    {
       if(p=='+'||p=='-')
       {
        if(nn&&ff[nn]==0)ff[nn]=k;
        else if(nn)ff[nn]*=k;
        if(t[0]&&xx[nn]==0)xx[nn]=1;
        if(t[1]&&yy[nn]==0)yy[nn]=1;
        t[0]=0;
        t[1]=0;
        ck=0,nn++;
        if(p=='+')k=1;
        else k=-1;
       }
       else if(p=='x')ck=1,t[0]=1;
       else if(p=='y')ck=2,t[1]=1;
       else
       {
           if(ck==0)ff[nn]=ff[nn]*10+p-'0';
           else if(ck==1)xx[nn]=xx[nn]*10+p-'0';
           else yy[nn]=yy[nn]*10+p-'0';
       }
    }
    if(nn&&ff[nn]==0)ff[nn]=k;
    else if(nn)ff[nn]*=k;
    if(t[0]&&xx[nn]==0)xx[nn]=1;
    if(t[1]&&yy[nn]==0)yy[nn]=1;

   // for(int i=1;i<=n;i++)cout<<x[i]<<" "<<y[i]<<" "<<f[i]<<endl;

    map<pair<int,int>,int>ans;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=nn;j++)
        {
            ans[{-x[i]-xx[j],y[i]+yy[j]}]+=f[i]*ff[j];
        }
    }
    string  ans1,ans2;
    int c=0;
    for(auto p:ans)
    {
        if(p.S==0)continue;
        while(ans2.size()<ans1.size())ans2+=" ";
        if(ans2.size()==0&&p.S<0)ans2+="-";
        else if(ans2.size()&&p.S>0)ans2+=" + ";
        else if(ans2.size())ans2+=" - ";

        if(abs(p.S)>1)ans2+=get(abs(p.S));
        else if(p.F.F==0&&p.F.S==0)ans2+=get(abs(p.S));

        while(ans2.size()<ans1.size())ans2+=" ";
        if(p.F.F) ans2+="x";

        while(ans1.size()<ans2.size())ans1+=" ";
        if(-p.F.F>1)ans1+=get(-p.F.F);


        while(ans2.size()<ans1.size())ans2+=" ";
        if(p.F.S) ans2+="y";

        while(ans1.size()<ans2.size())ans1+=" ";
        if(p.F.S>1)ans1+=get(p.F.S);

    }
   if(ans1.size()==0&&ans2.size()==0)ans2+="0";

     while(ans1.size()<ans2.size())ans1+=" ";
     while(ans2.size()<ans1.size())ans2+=" ";
     cout<<ans1<<endl;
     cout<<ans2<<endl;

}
return 0;
}
