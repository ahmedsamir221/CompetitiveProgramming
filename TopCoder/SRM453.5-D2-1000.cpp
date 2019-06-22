/*
   we will use two dp one to get max product if the number of negative number in our dp is even ,
   the other to git min product if the number of negative number in our dp is odd
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
ll mem[52][52][12][12],mom[52][52][12][12],n,cc;
ll a[55];
ll dpmax(int i,int p,int k,int c,int d)
{
    if(k==0)
    {
        if(c==0)return 1;
        else return -2;
    }
    if(c<0)return -2;
    if(i>n)return -2;
    ll&ret=mem[i][p][k][c];
    if(~ret)return ret;
    ret=dpmax(i+1,p,k,c,d);
    if(p==-1||i-p<=d)
    ret=max(ret,dpmax(i+1,i,k-1,(a[i]<0)?c-1:c,d)*abs(a[i]));
    return ret;
}


ll dpmin(int i,int p,int k,int c,int d)
{
    if(k==0)
    {
        if(c==0)return 1;
        else return 1e18;
    }
    if(c<0) return 1e18;
    if(i>n)return 1e18;
    ll&ret=mom[i][p][k][c];
    if(ret!=-1)return ret;
    ret=1e18;
    ll g=dpmin(i+1,p,k,c,d);
    if(g!=1e18)ret=min(ret,g);

    if(p==-1||i-p<=d)
    {
        g=dpmin(i+1,i,k-1,(a[i]<0)?c-1:c,d);
        if(g!=1e18)ret=min(ret,g*abs(a[i]));
    }
    return ret;
}

class TheProduct
{
public:
    long long maxProduct(vector <int> numbers, int k, int maxDist)
    {
        n=(int)numbers.size();
        forr(i,1,n)a[i]=numbers[i-1];
        memset(mem,-1,sizeof mem);
        memset(mom,-1,sizeof mom);
        ll ans=-1e18;
        forr(i,0,k)
        {
            if(i%2==0)
            {
                ll g=dpmax(1,-1,k,i,maxDist);
                if(g>=0) ans=max(ans,g);
            }
            else
            {
                ll g=dpmin(1,-1,k,i,maxDist);
                if(g<1e18) ans=max(ans,-g);
            }
        }
        return ans;
    }
};
