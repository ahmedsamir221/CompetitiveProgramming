// https://codeforces.com/blog/entry/7093
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
int n;
map<pair<pair<int,int>,int>,int>mem;
int dp(int mask=0,int i=1,int t=0)
{
    if(i>n)
    {
        if(mask==((1<<n)-1))
        return 1;
        else
        return 0;
    }
    if(mem.count({{mask,i},t}))return mem[{{mask,i},t}];
    int&ret=mem[{{mask,i},t}];
   // if(~ret)return ret;
    ret=0;
    forr(j,1,n)
    {
        int g=(i+j-2)%n+1;
        g--;
        if((mask&(1<<g))==0&&(t&(1<<(j-1)))==0)
        {
            //cout<<g<<endl;
            ret+=dp((mask|(1<<g)),i+1,(t|(1<<(j-1))));
        }
    }
    return ret;
}
ll a[17]={0,1,0,3,0,15,0,133,0,2025,0,37851,0,1030367,0,36362925,0};
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

ll ans=a[n];
ll m=1e9+7;
forr(i,1,n)
{
    ans*=(ll)i;
    ans%=m;
}
cout<<(ans+m)%m;
return 0;
}
