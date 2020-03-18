//https://codeforces.com/blog/entry/3462
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

//const double PI  = acos(-1.0);
using namespace std;
//typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//char rv[4]={'D','R','L','U'};
const double EPS = 1e-9;
const int N = 5e5 + 9;
int n,m,val[N];
double pro[N];
vector<pair<pair<int,int>,pair<int,int>>>a,b;
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
        cin>>n>>m;
        int p,h,l,r;
        forr(i,1,n)
        {
            cin>>p>>h>>l>>r;
            a.push_back({{p,1},{h,100-r}});
            b.push_back({{p,0},{h,100-l}});
        }
        forr(i,1,m)
        {
            cin>>p>>val[i];
            a.push_back({{p,0},{i,0}});
            b.push_back({{p,1},{i,0}});
        }
        sort(a.begin(),a.end());
        multiset<pair<int,int>>s;
        for(int i=0;i<n+m;i++)
        {
            auto x = a[i];
            if(x.F.S==0)
            {
                while((int)s.size())
                {
                    auto v =*s.begin();
                    if(v.F<x.F.F) s.erase(s.begin());
                    else break;
                }
                if((int)s.size()>=100)pro[x.S.F]=0.0;
                else{
                    double temp=1.0;
                    for(auto p:s)temp*=p.S/100.0;
                    pro[x.S.F]=temp;
                }
            }
            else if(x.S.S!=100)s.insert({x.F.F+x.S.F,x.S.S});
        }

        sort(b.begin(),b.end());
        priority_queue<pair<int,int>>q;
        for(int i=n+m-1;i>-1;i--)
        {
            auto x = b[i];
            if(x.F.S==1)
            {
                while((int)q.size())
                {
                    auto v =q.top();
                    if(v.F>x.F.F)q.pop();
                    else break;
                }
                if((int)q.size()>=100)pro[x.S.F]=0.0;
                else{
                    double temp=1.0;
                    priority_queue<pair<int,int>>qt;
                    while((int)q.size())temp*=q.top().S/100.0,qt.push(q.top()),q.pop();
                    pro[x.S.F]*=temp;
                    q=qt;
                }
            }
            else if(x.S.S!=100)q.push({x.F.F-x.S.F,x.S.S});
        }
        double ans=0;
        forr(i,1,m)ans+=pro[i]*(double)val[i];

        cout<<fixed<<setprecision(9)<<ans<<endl;

return 0;
}
