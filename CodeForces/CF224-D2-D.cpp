/*
   we will get the first subsequence of string s that match string t from the begin of string s .
   then get the first subsequence of string s that match string t from the end of string s .
   for each letter in string s we will try to match it with the nearest letter from the left  subsequence
   that come before it then check if we can get the remaining string from the right subsequence .
*/
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
int n,m,l[300000],r[300000],ck[300000];
string s,t;
vector<int>L[30],R[30];
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
input;
cin>>s>>t;
n=s.size(),m=t.size();

int j=m-1,i=n-1;
while(j>-1&&i>-1)
{
    r[i]=r[i+1];
    if(s[i]==t[j])r[i]++,j--;
    i--;
}

if(j>-1)
{
    cout<<"No";
    return 0;
}
else
{
    for(;i>-1;i--)r[i]=r[i+1];
}
i=0,j=0;
while(i<n&&j<m)
{
   if(i)l[i]=l[i-1];
   if(s[i]==t[j])l[i]++,j++;
   i++;
}
if(j<m)
{
    cout<<"No";
    return 0;
}
else
{
    for(;i<n;i++)l[i]=l[i-1];
}

j=0;
for(int i=0;i<n;i++)
{
    if(j<m&&s[i]==t[j])L[s[i]-'a'].push_back(i),ck[i]=1,j++;
    else
    {
        if(L[s[i]-'a'].size())
        {
            int g=L[s[i]-'a'][L[s[i]-'a'].size()-1];
            if(l[g]+r[i]>=m)ck[i]=1;
        }
    }
}

int ans=0;
for(int i=0;i<n;i++)ans+=ck[i];

if(ans==n)cout<<"Yes";
else cout<<"No";


return 0;
}
