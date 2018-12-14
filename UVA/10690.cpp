/*
   we just use dp to try all possible set of number to get max and min answer

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
int n,m,mem[53][53][2505],all,a[40000];
int dpmx(int g=0,int k=0,int sum=0)
{
    if(g==n) return (all-sum)*sum;
    if(k>m) return -1e9;
    int&ret=mem[g][k][sum];
    if(~ret)return ret;

    ret=dpmx(g,k+1,sum);

    ret=max(ret,dpmx(g+1,k,sum+a[g+k+1]));
    return ret;
}


int dpmn(int g=0,int k=0,int sum=0)
{
    if(g==n) return (all-sum)*sum;
    if(k>m) return 1e9;
    int&ret=mem[g][k][sum];
    if(~ret)return ret;

    ret=dpmn(g,k+1,sum);

    ret=min(ret,dpmn(g+1,k,sum+a[g+k+1]));
    return ret;
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
while(cin>>n)
{
    cin>>m;
    all=0;
    forr(i,1,n+m)
    cin>>a[i],all+=a[i];

    if(n<m)swap(n,m);
    memset(mem,-1,sizeof mem);
    cout<<dpmx()<<" ";

    memset(mem,-1,sizeof mem);
    cout<<dpmn()<<endl;

}
return 0;
}
