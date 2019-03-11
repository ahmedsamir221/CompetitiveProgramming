/*
   we will use dp our state will be number of used cards  for each number from 1 to 6
   then try all possible moves to detect the winner.
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
int mem[5][5][5][5][5][5][2];
string s;
int dp(int n1,int n2,int n3,int n4,int n5,int n6,int t)
{
    int&ret=mem[n1][n2][n3][n4][n5][n6][t];
    if(~ret)return ret;
    int sum=n1*1+n2*2+n3*3+n4*4+n5*5+n6*6;
    ret=1;
    if(n1<4&&sum+1<=31)ret&=dp(n1+1,n2,n3,n4,n5,n6,!t);
    if(n2<4&&sum+2<=31)ret&=dp(n1,n2+1,n3,n4,n5,n6,!t);
    if(n3<4&&sum+3<=31)ret&=dp(n1,n2,n3+1,n4,n5,n6,!t);
    if(n4<4&&sum+4<=31)ret&=dp(n1,n2,n3,n4+1,n5,n6,!t);
    if(n5<4&&sum+5<=31)ret&=dp(n1,n2,n3,n4,n5+1,n6,!t);
    if(n6<4&&sum+6<=31)ret&=dp(n1,n2,n3,n4,n5,n6+1,!t);

    return ret=!ret;
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
memset(mem,-1,sizeof mem);
dp(0,0,0,0,0,0,0);
while(cin>>s)
{
    int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0;
    int n=s.size(),t=1;
    forr(i,0,n-1)
    {
        if(s[i]-'0'==1)n1++;
        if(s[i]-'0'==2)n2++;
        if(s[i]-'0'==3)n3++;
        if(s[i]-'0'==4)n4++;
        if(s[i]-'0'==5)n5++;
        if(s[i]-'0'==6)n6++;
    }
    if(n%2==0)t=0;
    if(t==0)
    {
        if(mem[n1][n2][n3][n4][n5][n6][t])cout<<s<<" "<<"A"<<endl;
        else cout<<s<<" "<<"B"<<endl;
    }
    else
    {
        if(mem[n1][n2][n3][n4][n5][n6][t])cout<<s<<" "<<"B"<<endl;
        else cout<<s<<" "<<"A"<<endl;
    }
}
return 0;
}
