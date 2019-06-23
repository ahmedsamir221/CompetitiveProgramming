
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
const int N=100000,M=100000;
int t,n;
double p;
double mem[55][27];
double dp(int i=1,int win=0)
{
    if(win==n)return 1;
    if((i-1)-win==n)return 0;
    double&ret=mem[i][win];
    if(ret==ret)return ret;
    ret=0;
    ret+=dp(i+1,win+1)*p;
    ret+=dp(i+1,win)*(1-p);
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
//priority_queue<ll,vector<ll>,greater<ll>>y;
input;

cin>>t;
while(t--)
{
    cin>>n>>p;
    memset(mem,-1,sizeof mem);
    cout<<fixed<<setprecision(2)<<dp()<<endl;
}
return 0;
}
