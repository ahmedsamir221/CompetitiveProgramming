/*
   we can use dp to get the the answer our state will be the time , row and column .
   each time we will move to adjacent cell or stay in the same cell if it available in (time+1) .
   then check our dp table ,if a cell is used at time x it will have value = 1 :
      1 -->  if at all times no cells used , The robber has escaped.
      2 -->  if at time x just one cell used it will be the answer at the time .
      3 -->  if at all times  number of used cells > 1 , Nothing known.

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
int x[8]={1,0,0,-1,-1,-1,1,1};
int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
int n,m,t,g,c1,c2,r1,r2,q,a[102][102][102],mem[102][102][102],cas;

bool valid(int i,int j)
{
    if(i<1||i>n||j<1||j>m)return 0;
    return 1;
}
int dp(int k,int i,int j)
{
    if(a[k][i][j])return 0;
    if(k>t)return 1;
    int&ret=mem[k][i][j];
    if(~ret)return ret;
    ret=0;
    for(int e=0;e<4;e++)
    {
        int u=i+x[e];
        int v=j+y[e];
        if(valid(u,v))
        ret=max(ret,dp(k+1,u,v));
    }
    ret=max(ret,dp(k+1,i,j));
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
//input;

while(cin>>m>>n>>t,n||m||t)
{
    memset(a,0,sizeof a);
    cin>>q;
    forr(e,1,q)
    {
        cin>>g>>c1>>r1>>c2>>r2;
        forr(i,r1,r2)
        forr(j,c1,c2)
        a[g][i][j]=1;
    }
    memset(mem,-1,sizeof mem);
    forr(i,1,n)
    forr(j,1,m)
    if(!a[1][i][j])
    dp(1,i,j);

    printf("Robbery #%d:\n",++cas);
    int f=0,ff=0;
    forr(k,1,t)
    {
    int ck=0,I,J;
    forr(i,1,n)
    forr(j,1,m)
        if(mem[k][i][j]==1)ck++,I=i,J=j;
    if(ck==1)
    {
        ff=1;
        printf("Time step %d: The robber has been at %d,%d.\n",k,J,I);
    }
    if(ck>0)f=1;
    }
    if(!f)
        printf("The robber has escaped.\n");
    else if(!ff)
        printf("Nothing known.\n");
    printf("\n");
}

return 0;
}
