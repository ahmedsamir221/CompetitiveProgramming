/*
  we will use dp , our state will be the start and  the end of our sequence
  then each time we will try to split the sequence to two parts  and add it's cost
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
int n,mem[12][12],u;
pair<int,int>a[16];
int dp(int l=1,int r=n)
{
    if(l==r)return 0;
    int&ret=mem[l][r];
    if(~ret)return ret;
    ret=1e9;
    forr(j,l,r-1)
    {
        ret=min(ret,dp(l,j)+dp(j+1,r)+a[l].F*a[j].S*a[r].S);
    }
    return ret;
}


void bulid(int l=1,int r=n)
{
    if(l==r)
    {
        cout<<"A"<<l;
        return;
    }
    forr(j,l,r-1)
    {
        if(dp(l,r)==dp(l,j)+dp(j+1,r)+a[l].F*a[j].S*a[r].S)
        {
            cout<<"(";
            bulid(l,j);
            cout<<" x ";
            bulid(j+1,r);
            cout<<")";
            break;
        }
    }
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("let_it_flow.txt","r",stdin);
//freopen("samir.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//input;

while(1)
{
cin>>n;
if(n==0)break;

forr(i,1,n)
cin>>a[i].F>>a[i].S;

cout<<"Case "<<++u<<": ";
memset(mem,-1,sizeof mem);
dp();
bulid();
cout<<endl;

}

return 0;
}
