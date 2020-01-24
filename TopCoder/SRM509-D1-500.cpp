/*
    we need to update our operations then use dp to get the answer .

    1 --> we can change one character to another directly or by series of change operations , so
    we can run floyed to deal with that .
    2 --> we can add character directly or by add another character then change it to our character .

    then our dp will use two states , star and  end and try to consist a palindrome
    we have three operation .
    1 --> change  the star character then add or erase it .
    2 --> change  the end character then add or erase it .
    3 --> change  the star and the end characters to the same character .


*/
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
const double EPS = 1e-9;
const int N = 3e5 + 9;
ll n,ad[30],er[30],ch[30][30],mem[55][55];
string s;
ll dp(int l=0,int r=n-1)
{
    if(l>=r)return 0;
    ll&ret=mem[l][r];
    if(~ret)return ret;
    ret=1e14;
    int a=s[l]-'a',b=s[r]-'a';
    for(int i=0;i<26;i++)
    {
        ret=min(ret,dp(l+1,r)+ch[a][i]+min(ad[i],er[i]));
        ret=min(ret,dp(l,r-1)+ch[b][i]+min(ad[i],er[i]));
        ret=min(ret,dp(l+1,r-1)+ch[a][i]+ch[b][i]);
    }
    return ret;
}
class PalindromizationDiv1{
public:
    int getMinimumCost(string word, vector <string> operations)
    {
        memset(ch,'?',sizeof ch);
        memset(ad,'?',sizeof ad);
        memset(er,'?',sizeof er);
        forr(i,0,25)ch[i][i]=0;
        for(auto p:operations)
        {
            int sz=p.size();
            if(p[0]=='a')
            {
                ll x=0;
                for(int i=6;i<sz;i++)x*=10,x+=p[i]-'0';
                ad[p[4]-'a']=min(ad[p[4]-'a'],x);
            }
            else if(p[0]=='e')
            {
                ll x=0;
                for(int i=8;i<sz;i++)x*=10,x+=p[i]-'0';
                er[p[6]-'a']=min(er[p[6]-'a'],x);
            }
            else
            {
                ll x=0;
                for(int i=11;i<sz;i++)x*=10,x+=p[i]-'0';
                ch[p[7]-'a'][p[9]-'a']=min(ch[p[7]-'a'][p[9]-'a'],x);

            }
        }
        forr(k,0,25)forr(i,0,25)forr(j,0,25)ch[i][j]=min(ch[i][j],ch[i][k]+ch[k][j]);
        forr(i,0,25)forr(j,0,25)ad[i]=min(ad[i],ad[j]+ch[j][i]);
        s=word;
        n=s.size();
        memset(mem,-1,sizeof mem);
        ll ans=dp();
        if(ans>=1e9)return -1;
        else return (int)ans;
    }
};

 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input


return 0;
}
