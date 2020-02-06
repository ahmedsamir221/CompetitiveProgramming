//https://github.com/3agwa/CompetitiveProgramming/blob/master/PKU/PKU%203744.cpp
#pragma GCC optimize("O3")
//#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
//#define input ios_base::sync_with_stdio(0);cin.tie(0);

//const double PI  = acos(-1.0);
using namespace std;
//typedef pair<double,double>pdd;
typedef long long  ll;
//typedef pair<ll, ll>pii;
//typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const double EPS = 1e-9;
const int N = 5e2 + 9;
int n,a[15],mx;
double p,mem[2009];
map<int,int>m;
double dp(int i=1)
{
    if(m.count(i))return 0;
    if(i>mx)return 1;
    double&ret=mem[i];
    if(ret==ret)return ret;
    return ret=dp(i+1)*p+dp(i+2)*(1.0-p);
}
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
//input
        while(cin>>n>>p)
        {
            forr(i,1,n)cin>>a[i];
            sort(a+1,a+1+n);
            int c=0;
            m.clear();
            forr(i,1,n)
            {
                a[i]-=c;
                if(a[i]-a[i-1]>100)c+=a[i]-a[i-1]-100,a[i]-=a[i]-a[i-1]-100;
                m[a[i]]=1;
            }
            mx=a[n];
            memset(mem,-1,sizeof mem);
            double ans=dp();
            cout<<fixed<<setprecision(7)<<ans<<endl;
        }

return 0;
}
