//https://github.com/abdullaAshraf/Problem-Solving/blob/master/UVA/1362.cpp
#include <iostream>
#include<vector>
#include<algorithm>
//#include <cmath>
//#include <complex>
#include<queue>
#include<map>
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
string s;
ll n,mem[303][303],ck[303][303],m=1e9;
ll dp(int l,int r)
{
     if(s[l]!=s[r])return 0;
     if((r-l)%2)return 0;
     if(l==r)return 1;
     ll&ret=mem[l][r];
     if(~ret)return ret;
     ret=dp(l+1,r-1)%m;
     for(int i=l+2;i<=r-2;i++)
     {
         if(s[i]==s[l])
         {
            ret+=((dp(l+1,i-1)%m)*(dp(i,r)%m))%m;
         }
     }
     return ret%m;
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
while(cin>>s)
{
n=s.size();
memset(mem,-1,sizeof mem);
ll ans=dp(0,n-1);
cout<<(ans+m)%m<<endl;
}
return 0;
}
