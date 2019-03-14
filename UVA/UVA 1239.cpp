/*
   we will use dp to save in each segment number of changes we need to make it  palindrome .
   then get max segment that number of changes <= K .
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
int t,k,mem[1002][1002][2],n;
string s;
int dp(int l=0,int r=n-1,int ck=0)
{
    if(l==r)return 1;
    if(l>r)return 0;
    int&ret=mem[l][r][ck];
    if(~ret)return ret;
    ret=-1e6;
    if(ck==0)
    {
      ret=max(ret,dp(l+1,r,0));
      ret=max(ret,dp(l+1,r,1));
      ret=max(ret,dp(l,r-1,0));
      ret=max(ret,dp(l,r-1,1));
    }
    else
    {
    if(s[l]==s[r])
        ret=max(ret,dp(l+1,r-1,1)+2);
    else
        ret=max(ret,dp(l+1,r-1,1)+1);
    }
    return ret;
}
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
    cin>>s>>k;
    n=s.size();
    memset(mem,-1,sizeof mem);
    dp(0,n-1,0);
    dp(0,n-1,1);
    int ans=1;
    forr(l,0,n-1)
    forr(r,l,n-1)
    if(mem[l][r][1]!=-1&&mem[l][r][1]+k>=r-l+1)
            ans=max(ans,r-l+1);

    cout<<ans<<endl;

}
return 0;
}
