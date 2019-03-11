/*
   we will use dp with mask to all grid and try all possible moves to win
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
vector<vector<int>>t;
map<pair<vector<vector<int>>,int>,int>mem;
int ans,x,y;
int dp(vector<vector<int>> a,int turn ,int c)
{

    forr(i,0,3)if(abs(a[i][0]+a[i][1]+a[i][2]+a[i][3])==4)return 0;
    forr(i,0,3)if(abs(a[0][i]+a[1][i]+a[2][i]+a[3][i])==4)return 0;
    if(abs(a[0][0]+a[1][1]+a[2][2]+a[3][3])==4)return 0;
    if(abs(a[0][3]+a[1][2]+a[2][1]+a[3][0])==4)return 0;

    if(mem.count({a,turn}))return mem[{a,turn}];

    int ck[3]={0,0,0};
    int g=1;
    forr(i,0,3)
    forr(j,0,3)
    {
        if(a[i][j]==0)
        {
            g=0;
            a[i][j]=turn;
            int m=dp(a,-turn,c+1);
            if(c==1&&m==0&&x==-1)x=i,y=j;
            ck[m]=1;
            a[i][j]=0;
        }
    }
    if(c==1&&ck[0])ans=1;
    if(g)return mem[{a,turn}]=2;
    if(ck[0])return mem[{a,turn}]=1;
    else if(ck[2])return mem[{a,turn}]=2;
    else if(ck[1])return mem[{a,turn}]=0;
    else return mem[{a,turn}]=2;

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
t.resize(4);
char d;
while(1)
{
  cin>>d;
  if(d=='$')break;

  forr(i,0,3)t[i].clear();

  forr(i,0,3)
  forr(j,0,3)
  {
      cin>>d;
      if(d=='x')t[i].push_back(1);
      else if(d=='o')t[i].push_back(-1);
      else t[i].push_back(0);
  }
  x=-1;
  ans=0;
  mem.clear();
  dp(t,1,1);
  if(ans)cout<<"("<<x<<","<<y<<")"<<endl;
  else cout<<"#####"<<endl;

}
return 0;
}
