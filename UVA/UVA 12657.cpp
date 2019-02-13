/*
   we need every time to know for each element it's left and it's right element and
   if line is reversed or no;
   then perform the commands by change the left and right element for X and Y;
   if line is reversed we will exchange command 1 && 2
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
#include <iostream>
#include <cmath>
#include <complex>
#include<queue>
#include <string>
#include<bits/stdc++.h>
#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
//#define x real()
//#define y imag()
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
int n,m,l[100010],r[100010],t,x,y,u;
ll getl(int i,int c)
{
    if(i>n)return 0;
    if(c%2)return (ll)i+getl(r[i],c+1);
    else return getl(r[i],c+1);
}

ll getr(int i,int c)
{
    if(i<1)return 0;
    if(c%2)return (ll)i+getr(l[i],c+1);
    else return getr(l[i],c+1);
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("CAMP.IN","r",stdin);
//freopen("CAMP.OUT","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
while(cin>>n)
{
    r[0]=1;
    l[n+1]=n;
    forr(i,1,n)
    l[i]=i-1,r[i]=i+1;
    int ck=0;
    cin>>m;
    forr(i,1,m)
    {
        cin>>t;
        t--;
        if(t==3)ck=!ck;
        else
        {
            cin>>x>>y;
            if(ck&&t!=2)t=!t;

            if(t==0||(t==2&&r[y]==x))
            {
                r[l[x]]=r[x];
                l[r[x]]=l[x];
                r[l[y]]=x;
                l[x]=l[y];
                l[y]=x;
                r[x]=y;
            }
            else if(t==1||(t==2&&r[x]==y))
            {
                r[l[x]]=r[x];
                l[r[x]]=l[x];
                l[r[y]]=x;
                r[x]=r[y];
                r[y]=x;
                l[x]=y;
            }
            else
            {
               int l1=l[y],r1=r[y];
               l[y]=l[x];
               r[y]=r[x];
               r[l[x]]=y;
               l[r[x]]=y;

               l[x]=l1;
               r[x]=r1;
               r[l1]=x;
               l[r1]=x;
            }

        }
    }
    cout<<"Case "<<++u<<": ";
    if(ck==0)
        cout<<getl(r[0],1)<<endl;
    else
        cout<<getr(l[n+1],1)<<endl;
}



return 0;
}
