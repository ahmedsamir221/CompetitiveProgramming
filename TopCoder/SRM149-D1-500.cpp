/*
   we will use dp , our state will be the remaining message and each time we will try to split the message
   and recurs to  the remaining message
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
map<string,int>ck;
string s;
int mem[55];
int dp(int l,int r,string &a)
{
    if(l>r)return 1;
    int&ret=mem[l];
    if(~ret)return ret;
    ret=0;
    forr(i,l,r)
    {
        if(ck.count(a.substr(l,i-l+1)))ret+=dp(i+1,r,a);
    }
    return ret=min(ret,100000);
}

void bulid(int l,int r,string &a)
{
    if(l>r)return ;
    forr(i,l,r)
    {
        if(ck.count(a.substr(l,i-l+1))&&dp(i+1,r,a))
        {
            forr(j,l,i)s.push_back(a[j]);
            if(i!=r)s.push_back(' ');
            bulid(i+1,r,a);
            break;
        }
    }
}

class MessageMess{
public:
    string restore(vector <string> dictionary, string message)
    {
      for(auto p:dictionary)ck[p]=1;
      memset(mem,-1,sizeof mem);
      int ans = dp(0,(int)message.size()-1,message);
      if(ans==0)return "IMPOSSIBLE!";
      else if(ans>1)return "AMBIGUOUS!";
      else
      {
          bulid(0,(int)message.size()-1,message);
          return s;
      }
    }
};
