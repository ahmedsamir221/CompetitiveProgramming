/*
    we will use  the normal trie in insert and search
*/
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

const int N=100006,M=1000000;
const double EPS= 1e-9;

int n,m,node[500000][27],ck[500000],e,cc;
string s,f;
void ins(int u,int i,int sz)
{
    if(i==sz)
    {
        ck[u]=1;
        return ;
    }
    if(!node[u][s[i]-'a'])node[u][s[i]-'a']=++e;
    ins(node[u][s[i]-'a'],i+1,sz);
}

void get(int u,int i,int sz,int key)
{
    if(i==sz)key=1;
    if(i>sz&&ck[u])
    {
        cout<<f<<endl;
        cc=1;
    }
    if(key==0)
    {
      f.push_back(s[i]);
      if(node[u][s[i]-'a'])get(node[u][s[i]-'a'],i+1,sz,0);
    }
    else
    {
        for(int j=0;j<26;j++)
        {
             if(node[u][j])
             {
                 f.push_back(j+'a');
                 get(node[u][j],i+1,sz,key);
                 f.pop_back();
             }
        }
    }
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
int cas=0;
cin>>n;
forr(i,1,n)
{
    cin>>s;
    ins(0,0,s.size());
}
cin>>m;
forr(i,1,m)
{
    cin>>s;
    cout<<"Case #"<<++cas<<":"<<endl;
    f.clear();
    cc=0;
    get(0,0,s.size(),0);
    if(cc==0)cout<<"No match."<<endl;
}
return 0;
}
