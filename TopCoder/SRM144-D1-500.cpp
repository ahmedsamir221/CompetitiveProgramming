/*
   there are 4 cases   
   1 - sorted + unique --> we can do it easy with dp;
   2 - sorted + repeat --> and also we can do it easy with dp;
   1 - unsorted + unique --> choices permutation blanks;
   2 - sorted + repeat --> choices power blanks;
      
*/
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
//#define pi 3.141592654
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
const int N=2800000,M=20000000;
ll n,m,mem[10][110];

ll dp(int i,int p,int s,int r)
{
    if(i>n)return 1;
    ll&ret=mem[i][p];
    if(~ret)return ret;
    ret=0;
    int j=1;
    if(s)j=p;
    if(r)j++;
    if(!j)j++;
    for(;j<=m;j++)
        ret+=dp(i+1,j,s,r);
    return ret;
}


class Lottery{
public:
    vector <string> sortByOdds(vector <string> rules)
    {
         vector <pair<ll,string> > ans;
         for(auto p: rules)
         {
             string a,b;
             int ck=0,sor,r;
             char v;
             memset(mem,-1,sizeof mem);
             for(int i=0;i<p.size();i++)
             {
                 if(p[i]==':')
                 {
                     ck=1;
                     continue;
                 }
                 if(ck)b.push_back(p[i]);
                 else a.push_back(p[i]);
             }
             stringstream f;
             f<<b;
             f>>m>>n;
             f>>v;
             if(v=='T')sor=1;
             else sor=0;
             f>>v;
             if(v=='T')r=1;
             else r=0;
             ll k=1;
             if(r)
             {
                for(ll i=m,j=1;j<=n;j++,i--)k*=i;
                if(sor)ans.push_back({dp(1,0,sor,r),a});
                else  ans.push_back({k,a});
             }
             else
             {
                for(ll j=1;j<=n;j++)k*=m;
                if(sor)ans.push_back({dp(1,0,sor,r),a});
                else  ans.push_back({k,a});
             }

         }
         sort(ans.begin(),ans.end());
         vector<string>h;
         for(auto p:ans)h.push_back(p.S);
         return h;
    }
};
