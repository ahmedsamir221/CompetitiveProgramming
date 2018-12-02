
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
int t,pr[10010];
string s;
vector<int>a[10010];
vector<char>ans;
void bfs(int i)
{
   queue<int>q;
   q.push(i);
   while((int)q.size())
   {
       int u=q.front();
       ans.push_back(s[u]);
       q.pop();
       for(auto p:a[u])
           q.push(p);
   }
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
cin>>t;
while(t--)
{
    cin>>s;
    stack<int>k;
    forr(i,0,(int)s.size()-1)
    {
        pr[i]=i;
        a[i].clear();
        if(s[i]>='A'&&s[i]<='Z')
        {
            int x=k.top();
            k.pop();
            int y=k.top();
            k.pop();
            a[i].push_back(y);
            a[i].push_back(x);
            pr[x]=i;
            pr[y]=i;
            k.push(i);
        }
        else
        {
           k.push(i);
        }
    }
    ans.clear();
    forr(i,0,(int)s.size()-1)
    {
        if(pr[i]==i)
        {
            bfs(i);
            break;
        }
    }
    for(int i=(int)ans.size()-1;i>=0;i--)
    cout<<ans[i];
    cout<<endl;
}
return 0;
}
