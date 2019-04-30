/*
   we will check all number of exchanges begin from two , and each time will run dp to get max value according
   to number of exchanges ,then check if   (ans - 1.0) > 0.01
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
const int N=10001000,M=101000;

int n;
double a[33][33],mem[22][22][22];
double dp(int i ,int k,int e)
{
    if(!k)
    {
        if(i==e)return 1;
        else return 0;
    }
    double&ret=mem[i][k][e];
    if(ret==ret)return ret;
    ret=0;
    for(int j=0;j<n;j++)
        ret=max(ret,dp(j,k-1,e)*a[i][j]);
    return ret;
}

void bulid(int i ,int k,int e)
{
    if(!k)
    {
        cout<<e+1<<endl;
        return;
    }

    for(int j=0;j<n;j++)
    {
        if(dp(i,k,e)==dp(j,k-1,e)*a[i][j])
        {
            cout<<i+1<<" ";
            bulid(j,k-1,e);
            break;
        }
    }

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

while(cin>>n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                a[i][j]=1.0;
            else
                cin>>a[i][j];
        }
    }
    int ck=1;
    memset(mem,-1,sizeof mem);
    for(int i=2;i<=n;i++)
    {
      for(int j=0;j<n;j++)
      {
        double ans= dp(j,i,j);
        if(ans-1.0>.01)
        {
            bulid(j,i,j);
            ck=0;
            break;
        }
      }
      if(!ck)break;
    }
    if(ck)
        cout<<"no arbitrage sequence exists"<<endl;
}

return 0;
}
