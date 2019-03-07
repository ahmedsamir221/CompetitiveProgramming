//https://codeforces.com/blog/entry/10972
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
int n,m,a[5005],x;
map<int,int>ck;
map<int,int>f;
int get(int t)
{
    int v=0;
    forr(i,2,sqrt(t))
    {
        while(t%i==0)
        {
            if(ck.count(i))v++;
            else v--;
            t/=i;
        }
    }
    if(t>1)
    {
        if(ck.count(t))v++;
        else v--;
    }
    return v;
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
cin>>n>>m;
forr(i,1,n)cin>>a[i];

forr(i,1,m)
{
    cin>>x;
    ck[x]=1;
}

for(int s=n;s>=1;s--)
{
    int g=a[1];
    forr(i,2,s)g=__gcd(g,a[i]);

    int val=get(g);
    f[g]=-val;
    if(val>0)
        forr(i,1,s)a[i]/=g;
}

int ans=0;
forr(i,1,n)
{
if(f.count(a[i]))ans+=f[a[i]];
else ans+=-get(a[i]);
}
cout<<ans;
return 0;
}
