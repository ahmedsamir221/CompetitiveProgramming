/*
   we do not matter of characters of string we just need its size
   so we can with simple dp to know number of palindromic we can construct from that size
   then the answer will be 2^size - number of palindromic

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
ll t,n,m=1000000007,z,u,p2[110];
string s;
vector<char>v;
ll mem[52][2];
ll dp(int i,int ck)
{
    if(i>n)return 1;
    ll&ret=mem[i][ck];
    if(~ret)return ret;
    ret=0;
    if(ck==0)
    {
       ret+=dp(i+1,0)%m;
       ret+=(dp(i+1,1)*3)%m;
    }
    else
    ret+=(dp(i+1,ck)*2)%m;

    return ret%m;
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
p2[0]=1;
forr(i,1,100)
p2[i]=(p2[i-1]*2)%m;

cin>>t;
while(t--)
{
    cin>>s;
    z=(ll)s.size();
    n=z/2;
    memset(mem,-1,sizeof mem);
    if(z%2==0)
        cout<<(p2[z]%m-dp(1,0)%m+m)%m<<endl;
    else
    {
        ll ans=dp(1,0);
        memset(mem,-1,sizeof mem);
        ans+=dp(1,1);
        cout<<(p2[z]%m-ans%m+m)%m<<endl;
    }
}

return 0;
}
