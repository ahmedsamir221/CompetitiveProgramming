//https://apps.topcoder.com/wiki/display/tc/SRM+577
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>



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

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=100006,M=1000000;
const double eps= 1e-9,EPS= 1e-9;

class EllysRoomAssignmentsDiv1{
public:
    double getAverage(vector <string> ratings){
        vector<int>v;
        string s;
        int x;
        for(auto p:ratings)s+=p;
        stringstream f;
        f<<s;
        while(f>>x)v.push_back(x);

       int n=v.size();
       int r=(n+19)/20,c=n/r,e=0;
       int k=v[0];
       sort(v.rbegin(),v.rend());
       int row,col;
       for(int i=0;i<v.size();i++)
       {
           if(v[i]==k)
           {
               row=i/r+1;
               col=i%r+1;
               break;
           }
       }
       double ans=0;
       forr(i,1,c)
       {
           if(i==row)
           {
               ans+=k;
               e+=r;
               continue;
           }
           double sum=0;
           forr(j,1,r)
           sum+=v[e++];
           ans+=sum/r;
       }

       if(n%r)
       {
           if(row>c)
           {
                ans+=k,ans/=c+1;
                return ans;
           }
           else
           {
               int w=n%r;
               double sum=0;
               for(int i=0,j=v.size()-1;i<w;i++,j--)sum+=v[j];
               double ans1=ans+sum/w;
               ans1/=c+1;
               ans1*=w*1.0/r;
               double ans2=ans/c*(1-w*1.0/r);
               return ans1+ans2;

           }
       }
       else return ans/c;

    }
};
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

vector<string>v={"2367 1395 1639 1842 1426 2393 2348 1571 2077 12", "2", "2 1966 1495 13",
 "09 1251 3039 1566 1989 2083 1819 1875 ", "1579 2206 1503 1461 2262 2116 1429 2150 1834 2097 ",
 "2093 1518 1923 1796 1669 2342 1826 2374 1635 1683 ", "1656 2190 1632 1946 1207 1293 2029 2243 2252 1559 ",
 "2366 1590 1563 2319 1391 1255 1727 1565 1911 1679 ", "1282 2358 1682 2148 3555 2362 1208 2044 1949 1980 ",
 "1983 2215 2184 1545 1665 2146 1272 2110 1889 1829 ", "1808 2065 1987 1297 2216 1609 1318 1816 1444 20", "00 1404"};

EllysRoomAssignmentsDiv1 kk ;
cout<<fixed<<setprecision(4)<<kk.getAverage(v);

return 0;
}
