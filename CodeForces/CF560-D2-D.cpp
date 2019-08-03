/*
   we can simulate the normal process with some optimization like check if the size of our substring is odd
   so we can not split it or if the two substring not equal after sorting them so them will never be equal .
*/
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

const int N=50000,M=1000000;
const double EPS= 1e-9;


int n;
string a,b;
int get(int l,int r,int s,int e)
{
    string A=a.substr(l,r-l+1);
    string B=b.substr(s,e-s+1);
    if(A==B)return 1;
    if((r-l+1)%2)return 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    if(A!=B)return 0;
    int m1=(r+l)/2,m2=(e+s)/2;
    int k=get(l,m1,m2+1,e)&&get(m1+1,r,s,m2);
    if(k)return 1;
    int v=get(l,m1,s,m2)&&get(m1+1,r,m2+1,e);
    if(v)return 1;
    return 0;
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
cin>>a>>b;
n=a.size();
if(get(0,n-1,0,n-1))cout<<"YES";
else cout<<"NO";
return 0;
}
