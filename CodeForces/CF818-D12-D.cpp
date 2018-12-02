/*
first we will the number of each color then will insert them in set
then will begin from back and decrease the number of color when it appear and every time the number of any color at any
time less than the number of alice color we will erase it from the set
and at end if still any number in the set it will be the answer
else there will be no answer
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
//typedef bitset<21> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
int n,k,a[100010],c[1000010];
set<pair<int,int>>s;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("tour.in","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>k;
forr(i,1,n)
{
    cin>>a[i];
    c[a[i]]++;
}

forr(i,1,1000000)
{
    if(i==k)continue;
    if(c[i])s.insert({c[i],i});
}
if(c[k])
for(int i=n;i>0;i--)
{
    if(a[i]==k)
    {
        while((int)s.size())
        {
            auto p=*s.begin();
            if(p.F<c[k])
            {
                s.erase(s.begin());
                c[p.S]=0;
            }
            else break;
        }
    }
    if(a[i]==k)
    {
        c[k]--;
        if(c[k]==0)break;
        else
         continue;
    }
    if(c[a[i]]==0)continue;
    auto it=s.lower_bound({c[a[i]],a[i]});
    c[a[i]]--;
    s.erase(it);
    if(c[a[i]])
    s.insert({c[a[i]],a[i]});
}

if((int)s.size())
{
    auto p=*s.begin();
    cout<<p.S;
}
else
    cout<<"-1";
return 0;
}
