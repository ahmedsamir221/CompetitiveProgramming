/*
   we just need to binary search about the answer and inside it's function we will use another
   binary search ,from each position we will get the number of segments that ends in that position
   and it's sum is less or equal the sum of first binary search
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
int n,k;
ll sum[50005],a[50005];
ll ok(ll x)
{
    ll t=0;
    forr(i,1,n)
    {
        int l=1,r=i,mid,ans=0;
        while(l<r)
        {
            mid=(l+r)/2;
            ll g=sum[i]-sum[mid-1];
            if(g>x)l=mid+1;
            else r=mid;
        }
        if(r==i&&a[i]>x)continue;
        t+=i-r+1;
    }
    if(t>=k)return 1;
    else return 0;
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
while(cin>>n)
{
    cin>>k;
    forr(i,1,n)
    {
    cin>>a[i];
    sum[i]=a[i]+sum[i-1];
    }

    ll l=0,r=1e16,mid;
    ll g=0,ans;
    while(l<r)
    {
        mid=(l+r)/2;
        if(ok(mid))r=mid,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
}
return 0;
}
