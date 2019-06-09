/*
   we will preprocessing all possible masks of a row and save it's  answers and the mask of the next row of it .
   then use dp to get the answer .
*/
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
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=210,M=20500;
vector<pair<int,int>>e[(1<<10)+10];
int n,m,t,mem[42][(1<<10)+10];
char a[44][12];
void get(int j,int msk,int nxt,int c)
{
    if(j>=10)
    {
        e[msk].push_back({c,nxt});
        return ;
    }
    if(msk&(1<<j)) get(j+1,msk,nxt,c);
    get(j+2,msk,nxt,c+1);
    get(j+1,msk,nxt|(1<<j),c+1);
}
void go()
{
      forr(msk,0,(1<<10)-1)
          get(0,msk,0,0);
}
int dp(int i=1,int msk=0)
{
    if(i>n)return 0;
    int&ret=mem[i][msk];
    if(~ret)return ret;
    ret=1e9;
    forr(j,1,10)
    {
      if(j<=m&&a[i][j]=='o') msk|=(1<<(j-1));
      else if(j>m) msk|=(1<<(j-1));
    }
    for(auto p:e[msk])
        ret=min(ret,dp(i+1,p.S)+p.F);
    return ret;
}
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
input;
go();
cin>>t;
while(t--)
{
    cin>>n>>m;
    forr(i,1,n)
    forr(j,1,m)
    cin>>a[i][j];
    memset(mem,-1,sizeof mem);
    cout<<dp()<<endl;
}

return 0;
}
