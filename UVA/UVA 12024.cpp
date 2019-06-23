
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
ll mem[13][(1<<12)+5];
ll dp(int i=0,int m=0)
{
    if(i==n)return 1;
    ll&ret=mem[i][m];
    if(~ret)return ret;
    ret=0;
    for(int j=0;j<n;j++)
    {
        if(i==j)continue;
        if((m&(1<<j))==0)
        ret+=dp(i+1,m|(1<<j));
    }
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
    cin>>n;
    memset(mem,-1,sizeof mem);
    ll p=dp();
    ll q=1;
    forr(i,1,n)q*=(ll)i;

    cout<<p<<"/"<<q<<endl;
}
return 0;
}
