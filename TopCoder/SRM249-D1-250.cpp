//https://apps.topcoder.com/forums/?module=Thread&threadID=846257&start=0
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

//const double PI  = acos(-1.0);
using namespace std;
//typedef pair<double,double>pdd;
typedef long long  ll;
//typedef pair<ll, ll>pii;
//typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//char rv[4]={'D','R','L','U'};
const double EPS = 1e-9;
const int N = 5e5 + 9;
int pro[15];
double mem[1<<14];
int n,m;
int ok(int msk,int c)
{
    int cnt=0;
    for(int i=0;i+c<=n;i++)
    {
        int ck=1;
        for(int j=i;j<i+c;j++)
        {
            if(msk&(1<<j))
            {
                ck=0;
                break;
            }
        }
        if(ck)cnt++;
    }
    return cnt;
}


double dp(int msk)
{
    double&ret=mem[msk];
    if(ret==ret)return ret;
    ret=0;
    for(int x=1;x<=m;x++)
    {
        int cnt =ok(msk,x);
        for(int i=0;i+x<=n;i++)
        {
            int ck=1;
            int cp=msk;
            for(int j=i;j<i+x;j++)
            {
                if(msk&(1<<j))
                {
                    ck=0;
                    break;
                }
                cp|=(1<<j);
            }
            if(ck)ret+=(1.0/cnt)*(pro[x]/100.0)*(x+dp(cp));
        }
    }
    return ret;
}
class TableSeating{
public:
    double getExpected(int numTables, vector <int> probs){
        memset(mem,-1, sizeof mem);
        n=numTables;
        m=probs.size();
        for(int i=0;i<m;i++)pro[i+1]=probs[i];
        return dp(0);
    }
};
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input





return 0;
}
