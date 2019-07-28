//https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/LiveArchive/LIVEARCHIVE_4008.txt
#pragma GCC optimize("O3")
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
int n,c[30],a[1000007];
string s;


 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

while(cin>>s)
{
    int n=s.size();
    memset(c,0,sizeof c);
    for(int i=0;i<n;i++)
        c[s[i]-'a']++;

    memset(a,0,(n+2)*sizeof a[0]);
    for(int i=1;i<=n;i++)
    {
        int g=i;
        for(int j=2;j*j<=g;j++)
        {
            while(g%j==0)
            {
                a[j]++;
                g/=j;
            }
        }
        a[g]++;
    }

    for(int e=0;e<26;e++)
    {
        if(c[e])
        {
         for(int i=1;i<=c[e];i++)
           {
             int g=i;
             for(int j=2;j*j<=g;j++)
             {
                while(g%j==0)
                {
                  a[j]--;
                  g/=j;
                }
             }
             a[g]--;
          }
        }
    }
    int k=min(a[2],a[5]);
    a[2]-=k;
    a[5]-=k;
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<a[i];j++)
        {
            ans*=i;
            ans%=10;
        }
    }
    cout<<ans<<endl;
}

return 0;
}
