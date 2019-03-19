/*
    we can easy check if there string that achieve subsequences  of   00   and   11 which must be one of
    n*(n-1)/2 for any n >= 0 .
    if we get any order to achieve subsequences 10 we get the same number of subsequences 01 
    so we can achieve any order and check number of subsequences 01 
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
ll a,b,c,d;
map<ll,ll>ck,k;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
ll sum=0;
for(ll i=0;i<=1000000;i++)
{
    sum+=i;
    ck[sum]=1;
    k[sum]=i+1;
}
cin>>a>>b>>c>>d;
if(a+b+c==0)
{
    if(ck[d])forr(i,1,k[d])cout<<"1";
    else cout<<"Impossible";
    return 0;
}
if(b+c+d==0)
{
    if(ck[a])forr(i,1,k[a])cout<<"0";
    else cout<<"Impossible";
    return 0;
}
if(ck[a]==0||ck[d]==0||k[a]+k[d]>1000000)
{
    cout<<"Impossible";
    return 0;
}

if(c>k[d]*k[a]||b>k[d]*k[a])
{
    cout<<"Impossible";
    return 0;
}
ll div=c/k[a];
ll rem=c%k[a];
ll e=k[d]-(div+(rem>0?1:0));

if(k[a]*e+(k[a]-rem)*(rem>0?1:0)!=b)
{
    cout<<"Impossible";
    return 0;
}
forr(i,1,div)cout<<"1";
if(rem>0)
{
    forr(i,1,k[a]-rem)cout<<"0";
    cout<<"1";
    forr(i,1,rem)cout<<"0";
}
else
    forr(i,1,k[a])cout<<"0";

forr(i,1,e)cout<<"1";

return 0;
}
