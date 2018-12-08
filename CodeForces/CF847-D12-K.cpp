/*
   first we will save numbers of trips of each rout then will use dp
   to choose which rout will use travel card and which will not
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
int n,a,b,k,f,t,mem[305][305];
string x[305],y[305];
vector<int>trip[305];
int dp(int i=1,int v=k)
{
    if(i>t)return 0;
    int&ret=mem[i][v];
    if(~ret)return ret;
    int cost=0;
    for(auto p:trip[i])
    {
        if(x[p]==y[p-1])cost+=b;
        else cost+=a;
    }
    ret=dp(i+1,v)+cost;

    if(v)
    ret=min(ret,dp(i+1,v-1)+f);

    return ret;
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("tour.in","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>a>>b>>k>>f;
map<pair<string,string>,vector<int>>m;
forr(i,1,n)
{
    cin>>x[i]>>y[i];
    m[{min(x[i],y[i]),max(x[i],y[i])}].push_back(i);
}
t=0;
for(auto p:m)
{
   trip[++t]=p.S;
}
memset(mem,-1,sizeof mem);
cout<<dp();
return 0;
}
