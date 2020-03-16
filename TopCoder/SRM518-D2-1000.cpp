/*
    we will use dp , and our state will be the number of heads and the index of current element in the array .
    each time we will try all possible combination to convert head to tail or tail to head
*/
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


int MAXN = 1010;
double comb[1020][1020] ;

int n,sz,c[55];
double mem[1009][55];
double dp(int h ,int i)
{
    if(i==sz)return h;
    double&ret=mem[h][i];
    if(ret == ret)return ret;
    int t = n - h;
    ret=0;
    double tot = comb[n][c[i]];
    forr(j,0,c[i])
    {
        double x=0,y=0,cnt=0;
        if(t>=j)x = comb[t][j],cnt++;
        if(h>=c[i]-j)y = comb[h][c[i]-j],cnt++;

        if(cnt<2)continue;

        int nh =  h + j - (c[i]-j);
        ret+= (x*y/tot)*dp(nh,i+1);
    }

    return ret;
}

class CoinReversing{
public:
    double expectedHeads(int N, vector <int> a){
        n=N;
        sz=a.size();
        for(int i=0;i<sz;i++)c[i]=a[i];
        comb[0][0] = 1;
        for (int i = 1; i < MAXN; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
        }
        }
        memset(mem,-1,sizeof mem);
        return dp(n,0);
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
