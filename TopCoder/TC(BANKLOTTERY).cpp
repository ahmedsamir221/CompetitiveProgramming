/*
    we will use normal dp (win or lose) , and our state will be the number of times i won till now
    and the index of current week .
    from that state we can know our balance and total balance to get our probability .
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
int blance,pls,sz,tot,n;
double mem[1009][1009];
double dp(int cnt ,int i)
{
    if(i>n)return blance;
    double&ret=mem[cnt][i];
    if(ret == ret)return ret;
    double p = (pls*cnt+blance)*1.0/(tot + pls * (i-1));
    ret = p*(pls+dp(cnt+1,i+1));
    ret += (1.0-p)*dp(cnt,i+1);
    return ret;
}
class BankLottery{
public:
    double expectedAmount(vector <int> accountBalance, int weeklyJackpot, int weekCount){
        memset(mem,-1,sizeof mem);
        for(auto p:accountBalance)tot+=p;
        blance = accountBalance[0];
        pls = weeklyJackpot;
        n=weekCount;
        return dp(0,1);
    }
};
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
    BankLottery x ;
    cout<<fixed<<setprecision(9)<<x.expectedAmount({2,2,2},1,2);



return 0;
}
