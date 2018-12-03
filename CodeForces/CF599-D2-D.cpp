/*
first we want to calculate number of pair (n,m) that number of squares in it = X
so we will fix n and get m then swap them to get the two pairs
we will use that formula to get m;

  X = d * sum(1 to n) + sum(1^2 to n^2);
  that d =(m-n)
  so m=d+n;

according to that formula we do not need to iterate in n greater than 1e7
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
//typedef bitset<3> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
ll sumn[10000100],sumn2[10000100],x;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("tour.in","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>x;
forr(i,1,10000098)
{
    sumn[i]=sumn[i-1]+(ll)i;
    sumn2[i]=sumn2[i-1]+(ll)i*(ll)i;
}
set<pair<ll,ll>>ans;
forr(i,1,10000098)
{
    ll g=x-sumn2[i];
    if(g>=0&&g%sumn[i]==0)
    {
    ans.insert({i,i+g/sumn[i]});
    ans.insert({i+g/sumn[i],i});
    }
}
cout<<(int)ans.size()<<endl;
for(auto p:ans)
    cout<<p.F<<" "<<p.S<<endl;
return 0;
}
