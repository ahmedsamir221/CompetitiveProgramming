/*
   we can represent the grid in mask then use dp and try all possible moves
*/
#include <iostream>
#include<vector>
#include<algorithm>
//#include <cmath>
//#include <complex>
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
//#define pi 3.141592654
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
const int N=55,M=2000;
int mem[1<<17];
int dp(int mask)
{
    if(mask==(1<<16)-1)return 1;
    int&ret=mem[mask];
    if(~ret)return ret;
    ret=1;
    forr(i,0,15)
      if(((1<<i)&mask)==0)
      {
          int cp=mask;
          cp|=(1<<i);
          ret&=dp(cp);
      }

   forr(i,0,3)
    for(int j=0;j<4;j+=2)
       if((((1<<(i*4+j))&mask)==0)&&(((1<<(i*4+j+1))&mask)==0))
       {
           int cp=mask;
           cp|=(1<<(i*4+j));
           cp|=(1<<(i*4+j+1));
           ret&=dp(cp);
       }

    forr(i,0,3)
    forr(j,0,1)
       if((((1<<(i*4+j))&mask)==0)&&(((1<<(i*4+j+1))&mask)==0)&&(((1<<(i*4+j+2))&mask)==0))
       {
           int cp=mask;
           cp|=(1<<(i*4+j));
           cp|=(1<<(i*4+j+1));
           cp|=(1<<(i*4+j+2));
           ret&=dp(cp);
       }

   forr(i,0,3)
    for(int j=i;j<=i+8;j+=8)
       if((((1<<j)&mask)==0)&&(((1<<(j+4))&mask)==0))
       {
           int cp=mask;
           cp|=(1<<j);
           cp|=(1<<(j+4));
           ret&=dp(cp);
       }

    forr(i,0,3)
     for(int j=i;j<=i+4;j+=4)
       if((((1<<j)&mask)==0)&&(((1<<(j+4))&mask)==0)&&(((1<<(j+8))&mask)==0))
       {
           int cp=mask;
           cp|=(1<<j);
           cp|=(1<<(j+4));
           cp|=(1<<(j+8));
           ret&=dp(cp);
       }

    return ret=!ret;
}

int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
memset(mem,-1,sizeof mem);
dp(0);
int t;
cin>>t;
while(t--)
{
    int c=0,k=0;
    char x;
    forr(i,0,3)
    forr(j,0,3)
    {
        cin>>x;
        if(x=='X')k|=(1<<c);
        c++;
    }
    if(dp(k)==1)cout<<"WINNING"<<endl;
    else cout<<"LOSING"<<endl;
}
return 0;
}
