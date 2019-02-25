/*
  to solve that problem we need to know for each bracket it's width ,height and it,s degree
  the outer bracket is degree 1 , bracket inside  it is degree 2 and so on ...........
  if the bracket with odd degree we will add it,s area
  else we will subtract it,s area
  we can do that easy with stack
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
int t;
string s;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>t;
while(t--)
{
    cin>>s;
    stack<pair<pair<int,int>,int>>v;
    ll ans=0;
    for(auto p:s)
    {
        int w,h,d;
        if(p=='(')
        {
            if(v.size()==0)d=1;
            else d=v.top().S+1;
            v.push({{0,1},d});
        }
        else
        {
            auto g=v.top();
            w=g.F.F+1;
            h=g.F.S;
            d=g.S;
            v.pop();
            if(d%2==1)ans+=(ll)w*(ll)h;
            else ans-=(ll)w*(ll)h;

            if(v.size())
            {
            v.top().F.F+=w+1;
            v.top().F.S=max(v.top().F.S,h+1);
            }
        }
    }
    cout<<ans<<endl;
}
return 0;
}
