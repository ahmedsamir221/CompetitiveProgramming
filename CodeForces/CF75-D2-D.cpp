//http://codeforces.com/blog/entry/1715
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
int n,m,z[55],a[55][5005],d[250005];
ll sum[55],l[55],r[55],ck[55],ans=-1e18;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>m;
forr(i,1,n)
{
    cin>>z[i];
    l[i]=-1e18;
    r[i]=-1e18;
    ck[i]=-1e18;
    forr(j,1,z[i])
    {
        cin>>a[i][j];
        sum[i]+=a[i][j];
    }
    ll c=0,cc=0;
    forr(j,1,z[i])
    {
        cc+=a[i][j];
        l[i]=max(l[i],cc);
        c+=a[i][j];
        ck[i]=max(ck[i],c);
        if(c<0)c=0;
    }
    c=0,cc=0;
    for(int j=z[i];j>=1;j--)
    {
        cc+=a[i][j];
        r[i]=max(r[i],cc);
        c+=a[i][j];
        ck[i]=max(ck[i],c);
        if(c<0)c=0;
    }
}
forr(i,1,m)cin>>d[i];

ll c=0;
forr(i,1,m)
{
    ans=max(ans,ck[d[i]]);
    ans=max(ans,c+l[d[i]]);
    c=max(r[d[i]],c+sum[d[i]]);
    if(c<0) c=0;
}
cout<<ans;
return 0;
}
