//https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/UVA/UVA_11361.txt
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N = 2e5 + 9;
ll p[20];
ll a,b,k,mem[12][2][2][102][102];
int dp(int g=10,int cka=0,int ckb=0,int r1=0,int r2=0)
{
    if(g==-1)
    {
        if(!r1&&!r2)return 1;
        return 0;
    }
    ll&ret=mem[g][cka][ckb][r1][r2];
    if(~ret)return ret;
    ret=0;
    ll A=(a/p[g])%10;
    ll B=(b/p[g])%10;
    for(int d=0;d<10;d++)
    {
        if(!cka && d<A)continue;
        if(!ckb && d>B)continue;
        ret+=dp(g-1,d>A?1:cka,d<B?1:ckb,(1LL*r1+d*p[g])%k,(r2+d)%k);
    }
    return ret;
}
 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input
    p[0]=1;
    for(int i=1;i<13;i++)p[i]=p[i-1]*1LL*10;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        if(k>100)
        {
            cout<<"0"<<endl;
            continue;
        }
        memset(mem,-1,sizeof mem);
        cout<<dp()<<endl;
    }




return 0;
}
