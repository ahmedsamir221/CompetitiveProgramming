/*
   if the length of given number == X , there always answer of '9' X times , so the answer will be with length = the given length .
   we will get all combinatorics of the ten digits  that it's length divide our length ,then by binary search we will get the min
   number of each combination that >= given number ,and minimize our so far answer .      
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
const int N=10001000,M=101000;


int c[10],t,sz;
string num,ans;
void bk(int i=0,int cnt=0)
{
    if(i>9&&cnt==0) return;
    if(i>9&&sz%cnt) return;
    if(i>9)
    {
        int time=sz/cnt;
        multiset<int>s;
        forr(j,0,9)
            if(c[j])
                forr(e,1,time) s.insert(j);
        int ck=0,cc=0;
        string f;
        for(auto p: num)
        {
            cc++;
            auto it= s.lower_bound(p-'0');
            if(it==s.end())
            {
                while(f.size())
                {
                    auto g=f[f.size()-1];
                    f.pop_back();
                    s.insert(g-'0');
                    auto itt= s.upper_bound(g-'0');
                    if(itt==s.end())continue;
                    s.erase(itt);
                    f.push_back(*itt+'0');
                    while(s.size())f.push_back(*s.begin()+'0'),s.erase(s.begin());
                    ck=1;
                    break;
                }
                break;
            }
            else if(*it==p-'0')
            {
                s.erase(it);
                f.push_back(*it+'0');
                if(cc==sz)ck=1;
            }
            else
            {
                s.erase(it);
                f.push_back(*it+'0');
                while(s.size())f.push_back(*s.begin()+'0'),s.erase(s.begin());
                ck=1;
                break;
            }
        }
        if(ck)ans=min(ans,f);
        return ;
    }
    c[i]=1;
    bk(i+1,cnt+1);
    c[i]=0;
    bk(i+1,cnt);

}

class EquiDigitNumbers{
public:
    long long findNext(string n)
    {
        num=n;
        sz=num.size();
        forr(i,1,sz)ans.push_back('9');
        bk();
        ll k=0;
        for(auto p: ans)
            k*=10,k+=p-'0';
        return k;
    }
};
