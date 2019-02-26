/*
   we will use dp and try to add min number of brackets to make the sequence  regular
   our state will be the start and the end of the segment , each time will try to split the segment from
   all position and also try to match the start and the end brackets
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
int t,mem[105][105],ans[105],c;
string s,f;
int dp(int l=0,int r=(int)s.size()-1)
{
    if(l==r)return 1;
    if(l>r)return 0;
    int&ret=mem[l][r];
    if(~ret)return ret;
    ret=1e7;
    if((s[l]=='('&&s[r]==')')||(s[l]=='['&&s[r]==']'))ret=min(ret,dp(l+1,r-1));
    forr(j,l,r-1)
        ret=min(ret,dp(l,j)+dp(j+1,r));
    return ret;
}

void bulid(int l=0,int r=(int)s.size()-1)
{
    if(l==r)
    {
        ans[l]=1;
        return ;
    }
    if(l>r)return ;
    if(((s[l]=='('&&s[r]==')')||(s[l]=='['&&s[r]==']'))&&(dp(l,r)==dp(l+1,r-1)))
      bulid(l+1,r-1);
    else
    {
    forr(j,l,r-1)
    {
        if(dp(l,r)==dp(l,j)+dp(j+1,r))
        {
            bulid(l,j);
            bulid(j+1,r);
            break;
        }
    }
    }
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
cin.ignore();
while(t--)
{
    getline(cin,f);
    getline(cin,s);
    memset(mem,-1,sizeof mem);
    memset(ans,0,sizeof ans);
    dp();
    bulid();
    if(c++)cout<<endl;
    forr(i,0,(int)s.size()-1)
    {
        if(ans[i])
        {
            if(s[i]=='('||s[i]==')')cout<<"()";
            else cout<<"[]";
        }
        else cout<<s[i];
    }
    cout<<endl;
}
return 0;
}
