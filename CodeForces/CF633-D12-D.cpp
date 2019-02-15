//http://codeforces.com/blog/entry/43392
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
int x[1003],n,ans;
map<int,int>a;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("CAMP.IN","r",stdin);
//freopen("CAMP.OUT","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n;
forr(i,1,n)
{
    cin>>x[i];
    a[x[i]]++;
}
forr(i,1,n)
{
    forr(j,1,n)
    {
        if(i==j||(x[i]==0&&x[j]==0))continue;
        map<int,int>b;
        b[x[i]]++;
        b[x[j]]++;
        int l=x[i],r=x[j],c=2;
        while(1)
        {
        if(a.count(l+r)&&(b.count(l+r)==0||b[l+r]<a[l+r]))
        {
            b[l+r]++;
            c++;
            int t=r;
            r=l+r;
            l=t;
        }
        else break;
        }
        ans=max(ans,c);
    }
}
cout<<max(ans,a[0]);
return 0;
}
