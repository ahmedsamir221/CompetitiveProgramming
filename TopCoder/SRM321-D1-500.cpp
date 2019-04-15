/*
   first we need to sort all element in non decreasing order then
   if there is  x , y , z  where x < y < z  and x+1=y -->> we will put one element of Z between all x elements and y elements
   except if z is the max element we all all element of z between x and y  ; 
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


map<int,int>m;
set<int>s,v;
int mx,n,x;
vector<int>ans;


class WeirdSort{
public:
vector <int> sortArray(vector <int> data)
{
forr(i,0,data.size()-1)
{
   x=data[i];
   mx=max(mx,x);
   m[x]++;
   s.insert(x);
   v.insert(x);
}

for(auto p:v)
{
    if(m[p]==0)continue;
    if(ans.size()&&ans[ans.size()-1]==p-1)
    {
        auto it=s.upper_bound(p);
        if(it!=s.end())
        {
        ans.push_back(*it);
        m[*it]--;
        if(m[*it]==0)s.erase(it);
        }
    }
    auto u=s.lower_bound(p+1);
    if(u!=s.end()&&*u==p+1)
    {
        if(p+1==mx)
        {
            forr(i,1,m[p+1])ans.push_back(p+1);
            forr(i,1,m[p])ans.push_back(p);
            break;
        }
        else
        {
            forr(i,1,m[p])ans.push_back(p);
        }
    }
    else
    {
        forr(i,1,m[p])ans.push_back(p);
    }
    s.erase(p);
}
return ans;
}
};
