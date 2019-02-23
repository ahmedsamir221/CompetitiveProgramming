//http://codeforces.com/blog/entry/60920
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
int n,a[5005],mem[5005][2505][2];
int dp(int i,int c,int ck)
{
    if(c==0)return 0;
    if(i>n)return 6e8;
    int&ret=mem[i][c][ck];
    if(~ret)return ret;
    if(ck)
    {
        int b=min(a[i-1],a[i-2]-1);
        return ret=min(dp(i+1,c,0),dp(i+2,c-1,1)+max(0,b-a[i]+1)+max(0,a[i+1]-a[i]+1));
    }
    else
    {
        return ret=min(dp(i+1,c,0),dp(i+2,c-1,1)+max(0,a[i-1]-a[i]+1)+max(0,a[i+1]-a[i]+1));
    }
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
cin>>n;
forr(i,1,n)cin>>a[i];
memset(mem,-1,sizeof mem);
forr(i,1,(n+1)/2)
{
    cout<<dp(1,i,0)<<" ";
}
return 0;
}
