//https://github.com/aboodJAD/CompetitiveProgramming/blob/master/UVA/UVA%201555.cpp
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
int n;
double a,e;
bool ok(double x)
{
    int ck=1;
    vector<double>v;
    v.push_back(a);
    v.push_back(x);
    forr(i,2,n-1)
    {
        double g=(v[i-1]+1)*2-v[i-2];
        e=g;
        if(g<0.0)ck=0;
        v.push_back(g);
    }
    if(ck)return 1;
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
    cin>>a;

    double l=0.0,r=1e18,mid,ans;
    forr(i,1,10000)
    {
        mid=(l+r)/2.0;
        if (ok(mid))r=mid,ans=e;
        else l=mid;
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
}

return 0;
}
