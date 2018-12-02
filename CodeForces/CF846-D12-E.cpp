/*
because the material will construct a tree rooted from node 1
we will store each parent node and the value to covert from each node to its children
then we will start from leaf
if(supply>needs) we will add the extra material to parent
else we take our needs from parent even its have not extra we will take it with negative value from parent supples
then we will erase this leaf
we will do that until just remains the root only
then we will decide our answer with the compare root supply with root needs
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
//typedef bitset<21> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
ll n,a[100010],pr[100010],c[100010],x,y;
map<pair<ll,ll>,ll>m;
set<pair<ll,ll>>s;
double b[100010];
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("tour.in","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n;
forr(i,1,n)cin>>b[i];
forr(i,1,n)cin>>a[i];

forr(i,2,n)
{
    cin>>x>>y;
    m[{x,i}]=y;
    c[x]++;
    pr[i]=x;
}
forr(i,1,n)
    s.insert({c[i],i});
while((int)s.size()>1)
{
    auto k=*s.begin();
    ll val=k.F;
    ll u=k.S;
    if(a[u]<=b[u])
    {
        b[pr[u]]+=b[u]-a[u];
    }
    else
    {
        b[pr[u]]-=(a[u]-b[u])*m[{pr[u],u}];
    }
    auto it=s.lower_bound({c[pr[u]],pr[u]});
    s.erase(it);
    s.erase(s.begin());
    c[pr[u]]--;
    s.insert({c[pr[u]],pr[u]});
}
auto p=*s.begin();
if(b[p.S]>=a[p.S])
    cout<<"YES";
else
    cout<<"NO";
return 0;
}
