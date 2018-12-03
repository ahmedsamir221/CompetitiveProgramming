
/*
http://javadecoder.blogspot.com/2013/08/spoj-multii.html
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
//typedef bitset<3> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
int n,m,ck[12],u,ans[10010],vis[10010],e,pr[10010];
vector<int>v;
int bfs()
{
    queue<int>q;
    memset(vis,0,sizeof vis);
    fill(ans,ans+n+1,1e9);
    for(auto p:v)
    {
        if(p==0)continue;
        q.push(p%n);
        vis[p%n]=1;
        pr[p%n]=-1;
        ans[p%n]=min(p,ans[p%n]);
    }
    while((int)q.size())
    {
        int val=q.front();
        q.pop();
        if(val==0)
         return val;

        for(auto p:v)
        {
         if(!vis[((val*10)+p)%n])
         {
          q.push(((val*10)+p)%n);
          vis[((val*10)+p)%n]=1;
          pr[((val*10)+p)%n]=val;
          ans[((val*10)+p)%n]=min(ans[((val*10)+p)%n],p);
         }
        }

    }
    return -1;
}
void bulid(int s)
{
    if(s==-1)return;
    bulid(pr[s]);
    cout<<ans[s];
}

int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("tour.in","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
while(cin>>n)
{
cin>>m;
int x;
memset(ck,0,sizeof ck);
forr(i,1,m)
{
    cin>>x;
    ck[x]=1;
}
v.clear();
forr(i,0,9)
    if(!ck[i])v.push_back(i);
int e=bfs();
if(e==-1)
    cout<<"Case "<<++u<<": "<<"-1"<<endl;
else
{
    cout<<"Case "<<++u<<": ";
    bulid(e);
    cout<<endl;
}

}
return 0;
}
