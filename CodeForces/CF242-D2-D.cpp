//http://codeforces.com/blog/entry/5837
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
int n,m,u,v,a[100010],b[100010],vis[100010];
vector<int>adj[100010],ans;
void get()
{
    queue<int>q;
    forr(i,1,n)
    {
        if(a[i]==0)
        {
            vis[i]=1;
            q.push(i);
            ans.push_back(i);
        }
    }
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(auto p:adj[u])
        {
            b[p]++;
            if(vis[p]==0&&b[p]==a[p])
            {
                q.push(p);
                ans.push_back(p);
            }
        }
    }
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//input;
cin>>n>>m;
forr(i,1,m)
{
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

forr(i,1,n)cin>>a[i];

get();
cout<<(int)ans.size()<<endl;
for(auto p:ans)cout<<p<<" ";

return 0;
}
