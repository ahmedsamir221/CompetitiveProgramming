//https://codeforces.com/blog/entry/45425
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
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=500005,M=1000000;
const double EPS= 1e-9;
int n,m,db[100010],val[100010];
vector<int>b[100010],ans;
stack<int>k;

void get(int u)
{
    k.push(u);
    for(auto v:b[u])get(v);
    if(val[u]==u)
    {
        set<int>s;
        stack<int>v;
        while(k.size())
        {
            int g=k.top();
            k.pop();
            s.insert(val[g]);
            v.push(g);
            if(g==u)break;
        }
        while(v.size())ans.push_back(v.top()),v.pop();
        if((int)s.size()>1)
        {
            cout<<"-1";
            exit(0);
        }
    }
}


 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
input;


cin>>n>>m;
int u,v;
forr(i,1,m)
{
    cin>>u>>v;
    b[u].push_back(v);
    db[v]++;
}
forr(i,1,n)cin>>val[i];

forr(i,1,n)
    if(db[i]==0)get(i);


cout<<(int)ans.size()<<endl;
for(auto p:ans)cout<<p<<endl;

return 0;
}
