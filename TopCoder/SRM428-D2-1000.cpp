/*
  we can reduce our search space by compare the number of permutation  of sub string X with K . if it >= K
  then subtract number of permutation of sub string (x-1) and so on
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
#define var(x) ((x)<<1)
#define nvar(x) ((x)^1)
const int N=2e5+5,M=6e5+5;
string ans;

void get(int n,int m,int k)
{
   // cout<<n<<" "<<m<<" "<<k<<endl;
    if(n==0&&m==0)return;
    if(n==0)
    {
        ans.push_back('z');
        get(n,m-1,k);
        return;
    }
    if(m==0)
    {
        ans.push_back('a');
        get(n-1,m,k);
        return;
    }
    if(k==1)
    {
        ans.push_back('a');
        get(n-1,m,k);
        return;
    }
    ll prv=1,cur=1;
    for(ll i=1;i<=n;i++)
    {
        cur*=(m+i);
        cur/=i;
        if(k<=cur)
        {
            forr(j,1,n-i)
            ans.push_back('a');
            ans.push_back('z');
            get(i,m-1,k-prv);
            return;
        }
        prv=cur;
    }
}

class TheDictionary{
public:
    string find(int n, int m, int k){
        ll g=1;
        for(ll i=1;i<=n;i++)
        {
            g*=(m+i);
            g/=i;
            if(k<=g)
            {
              get(n,m,k);
              return ans;
            }
        }
        return "";

    }
};
