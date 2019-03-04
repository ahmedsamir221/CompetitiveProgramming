/*
  there are two cases .
  1 --> all element in one sequence.
  2 --> smallest element in sequence alone and all the other elements in the second sequence

  the answer is the min of the two cases
*/
#include <iostream>
#include<vector>
#include<algorithm>
//#include <cmath>
//#include <complex>
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
//#define pi 3.141592654
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
ll n,h;
pair<ll,ll>a[100010];
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>h;
forr(i,1,n)
{
    cin>>a[i].F;
    a[i].S=i;
}
if(n==2)
{
    cout<<"0"<<endl;
    cout<<"1 1";
    return 0;
}
sort(a+1,a+1+n);

ll c1=(a[n].F+a[n-1].F)-(a[2].F+a[1].F);
ll c2=max(a[n].F+a[n-1].F,a[1].F+a[n].F+h)-min(a[3].F+a[2].F,a[2].F+a[1].F+h);

if(c1<=c2)
{
    cout<<c1<<endl;
    forr(i,1,n)cout<<"1 ";
}
else
{
    cout<<c2<<endl;
    forr(i,1,n)
    if(i==a[1].S)cout<<"1 ";
    else cout<<"2 ";
}
return 0;
}
