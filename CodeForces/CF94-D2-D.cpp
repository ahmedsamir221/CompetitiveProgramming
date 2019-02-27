//http://codeforces.com/blog/entry/2208
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
int n,m,w,c;
vector<pair<int,int>>ans[55];
priority_queue<pair<pair<int,int>,int>>q;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>w>>m;
w*=m;
int need=(n*w)/m;
forr(i,1,n)q.push({{i,w},0});

forr(i,1,m)
{
    int need=(n*w)/m;
    while(need)
    {
        if(q.size()==0)
        {
            cout<<"NO";
                return 0;
        }
        auto t=q.top();
        q.pop();
        int g=min(need,t.F.S);
        need-=g;
        ans[i].push_back({t.F.F,g});
        if(t.F.S-g>0&&t.S==0)q.push({{t.F.F,t.F.S-g},1});
    }
}

cout<<"YES"<<endl;
forr(i,1,m)
{
    for(auto p:ans[i])
        cout<<p.F<<" "<<fixed<<setprecision(9)<<p.S*1.0/m<<" ";
    cout<<endl;
}

return 0;
}
