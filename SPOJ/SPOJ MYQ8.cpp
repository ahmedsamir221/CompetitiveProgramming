/*
   first we will check the invalid case :
   if number of O > number of X oR  number of X  - number of O  > 1
   if player X won and also player O  won
   if player X won and number of played turns is even
   if player O won and number of played turns is odd


   other that we will use back tracking to detect our state

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
int t,a[4][4],c[4],r[4],d[4];
string s;
int bk(int x,int o)
{
    memset(r,0,sizeof r);
    memset(c,0,sizeof c);
    forr(i,0,2)
    forr(j,0,2)
    r[i]+=a[i][j];

    forr(j,0,2)
    forr(i,0,2)
    c[j]+=a[i][j];

    d[1]=a[0][2]+a[1][1]+a[2][0];
    d[2]=a[0][0]+a[1][1]+a[2][2];
    if((r[0]==3||r[1]==3||r[2]==3||c[0]==3||c[1]==3||c[2]==3||d[1]==3||d[2]==3)||(r[0]==-3||r[1]==-3||r[2]==-3||c[0]==-3||c[1]==-3||c[2]==-3||d[1]==-3||d[2]==-3))return 1;

    if(x+o==9)return 2;
    set<int>g;
    if((x+o)%2==0)
    {
          forr(i,0,2)
          forr(j,0,2)
          {
           if(a[i][j]==0)
            {
                a[i][j]=1;
                g.insert(bk(x+1,o));
                a[i][j]=0;
            }
          }
    }
    else
    {
          forr(i,0,2)
          forr(j,0,2)
          {
           if(a[i][j]==0)
            {
                a[i][j]=-1;
                g.insert(bk(x,o+1));
                a[i][j]=0;
            }
          }
    }
    if(*g.lower_bound(1)==1&&g.lower_bound(1)!=g.end())return 0;
    else if(*g.lower_bound(2)==2&&g.lower_bound(2)!=g.end())return 2;
    else return 1;
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("trip.in","r",stdin);
//freopen("trip.out","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>t;
while(t--)
{
  int x=0,o=0;
  forr(i,0,2)
  {
      cin>>s;
      forr(j,0,2)
      {
          if(s[j]=='x')a[i][j]=1,x++;
          else if(s[j]=='o')a[i][j]=-1,o++;
          else a[i][j]=0;
      }
  }
    memset(r,0,sizeof r);
    memset(c,0,sizeof c);
    forr(i,0,2)
    forr(j,0,2)
    r[i]+=a[i][j];

    forr(j,0,2)
    forr(i,0,2)
    c[j]+=a[i][j];

    d[1]=a[0][2]+a[1][1]+a[2][0];
    d[2]=a[0][0]+a[1][1]+a[2][2];

    int h=0;
    if((r[0]==-3||r[1]==-3||r[2]==-3||c[0]==-3||c[1]==-3||c[2]==-3||d[1]==-3||d[2]==-3)&&(x!=o))h=1;
    if((r[0]==3||r[1]==3||r[2]==3||c[0]==3||c[1]==3||c[2]==3||d[1]==3||d[2]==3)&&(x==o))h=1;
    if((r[0]==3||r[1]==3||r[2]==3||c[0]==3||c[1]==3||c[2]==3||d[1]==3||d[2]==3)&&(r[0]==-3||r[1]==-3||r[2]==-3||c[0]==-3||c[1]==-3||c[2]==-3||d[1]==-3||d[2]==-3)) h=1;

   if((!(x==o||x-o==1))||h)
        cout<<"invalid"<<endl;
   else
   {
       int ans=bk(x,o);
       if(ans==0)cout<<"win"<<endl;
       else if(ans==1)cout<<"lose"<<endl;
       else cout<<"tie"<<endl;
   }
}
return 0;
}
