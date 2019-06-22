/*
   we will calculate number of state that it's sum >= X using dp then divide it by 6^n
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
const int N=100000,M=100000;
ll n,x,mem[26][160];

ll dp(int i,int sum)
{
    if(i>n)
    {
        if(sum>=x)return 1;
        else return 0;
    }
    ll&ret=mem[i][sum];
    if(~ret)return ret;
    ret=0;
    forr(j,1,6)
    ret+=dp(i+1,sum+j);
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
while(cin>>n>>x,n||x)
{
    memset(mem,-1,sizeof mem);
    ll p=dp(1,0);
    ll q=1;
    forr(i,1,n)q*=6;
    ll g=__gcd(p,q);
    p/=g;
    q/=g;

    if(p==0)cout<<"0"<<endl;
    else if(p==1&&q==1)cout<<"1"<<endl;
    else cout<<p<<"/"<<q<<endl;

}
return 0;
}
