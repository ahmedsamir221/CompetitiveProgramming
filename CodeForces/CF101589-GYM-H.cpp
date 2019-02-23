/*
   we will use dp to get the answer , our state will be previous hight ,current hight and the check condition.
   then we will try to hold the condition by min sum of remaining hight
   the answer will be the over all sum of hight - dp();
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
int n,h[55],mem[52][52][5005],t,th,ck[55];
vector<int>ans;
int dp(int p=0,int i=1,int sum=0)
{
    if(i>n)
    {
        if(sum+h[p]>=t/2)return 0;
        else return 1e7;
    }
    int&ret=mem[p][i][sum];
    if(~ret)return ret;
    int c1=dp(i,i+1,sum+2+abs(h[i]-h[p]))+h[i];
    int c2=dp(p,i+1,sum);
    return ret=min(c1,c2);

}


void bulid(int p=0,int i=1,int sum=0)
{
    if(i>n)return;
    int c1=dp(i,i+1,sum+2+abs(h[i]-h[p]))+h[i];
    int c2=dp(p,i+1,sum);
    if(dp(p,i,sum)==c1)
    {
        ck[i]=1;
        bulid(i,i+1,sum+2+abs(h[i]-h[p]));
    }
    else bulid(p,i+1,sum);
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n;
forr(i,1,n)
{
cin>>h[i];
th+=h[i];
if(i==n)t+=h[i];
t+=2+abs(h[i]-h[i-1]);
}
memset(mem,-1,sizeof mem);
cout<<th-dp()<<endl;
bulid();
forr(i,1,n)
    if(!ck[i])ans.push_back(i);

cout<<(int)ans.size()<<endl;
for(auto p:ans)cout<<p<<" ";
return 0;
}
