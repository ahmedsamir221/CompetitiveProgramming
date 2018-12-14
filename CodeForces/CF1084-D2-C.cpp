
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
string s;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("tour.in","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>s;
vector<int>v;
int c=0;
forr(i,0,(int)s.size()-1)
{
    if(s[i]=='a')c++;
    else if(s[i]=='b'&&c)
    {
        v.push_back(c);
        c=0;
    }
}
if(c)v.push_back(c);
ll ans=0,m=1e9+7,g=0;
if((int)v.size())
forr(i,0,(int)v.size()-1)
{
    //cout<<v[i]<<endl;
    ans+=(g*v[i])+v[i];
    ans%=m;
    g=ans;
    g%=m;
}

cout<<(ans+m)%m;
return 0;
}
