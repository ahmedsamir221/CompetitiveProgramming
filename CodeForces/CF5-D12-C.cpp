/*
   we will get all separated regular bracket sequence by detect its begin and end
   and if any sequence inside another we will remove it
   and if any of them is touch each other we will merge them 
   then get max sequence and its number
   
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
int ans[1000005];
string x;
vector<int>v;
vector<pair<int,int>>s;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("trip.in","r",stdin);
//freopen("trip.out","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>x;
for(int i=0;i<(int)x.size();i++)
{
    if(x[i]=='(')
       v.push_back(i);
    else if((int)v.size())
    {
        while((int)s.size()&&v[(int)v.size()-1]<s[(int)s.size()-1].F&&i>s[(int)s.size()-1].S)s.pop_back();
        s.push_back({v[(int)v.size()-1],i});
        v.pop_back();
    }
}
int mx=0;
ans[mx]=1;

for(int i=0;i<(int)s.size();i++)
{
    if(i>0&&s[i].F-s[i-1].S==1)s[i].F=s[i-1].F;
    ans[s[i].S-s[i].F+1]++;
    if(s[i].S-s[i].F+1>mx)mx=s[i].S-s[i].F+1;
}

cout<<mx<<" "<<ans[mx];
return 0;
}
