//http://codeforces.com/blog/entry/6478
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
int n,q,v[100010],c[100010],a,b;
ll arr[100010];
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("CAMP.IN","r",stdin);
//freopen("CAMP.OUT","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>q;
forr(i,1,n)cin>>v[i];
forr(i,1,n)cin>>c[i];

while(q--)
{
    cin>>a>>b;
    pair<ll,int>mx1={0,0},mx2={0,0};
    fill(arr+1,arr+n+1,-1e17);
    ll ans=0;
    forr(i,1,n)
    {
        if(arr[c[i]]!=-1e17)
            arr[c[i]]=max(arr[c[i]],arr[c[i]]+(ll)a*(ll)v[i]);
        else
            arr[c[i]]=(ll)b*(ll)v[i];

        pair<ll,int> p;
        if(mx1.S!=c[i])
        {
        p=mx1;
        arr[c[i]]=max(arr[c[i]],p.F+(ll)b*(ll)v[i]);
        mx2=max(mx2,{arr[c[i]],c[i]});
        }
        else
        {
            p=mx2;
            arr[c[i]]=max(arr[c[i]],p.F+(ll)b*(ll)v[i]);
            mx1=max(mx1,{arr[c[i]],c[i]});
        }
        ans=max(ans, arr[c[i]]);
        if(mx1<mx2)swap(mx1,mx2);
    }
    cout<<ans<<endl;

}
return 0;
}
