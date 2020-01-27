//https://github.com/osamahatem/CompetitiveProgramming/blob/master/SPOJ/SHORTCUT.cpp
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
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
const double EPS = 1e-9;
const int N = 5e5 + 9;
int t,n;
char f[N];
map<int,set<pair<int,int>>>X,Y;
set<pair<pair<int,int>,pair<int,char>>>ans;
void go(int x,int y,int c)
{
               auto it=X[x].lower_bound({y,c});
               it++;
               if(it!=X[x].end())
               {
                   auto k=*it;
                   if(k.S!=c-1)ans.insert({{k.F-y,k.S},{-c,'S'}});
               }
               it--;
               if(it!=X[x].begin())
               {
                   it--;
                   auto k=*it;
                   if(k.S!=c-1)ans.insert({{y-k.F,k.S},{-c,'N'}});
               }
               it=Y[y].lower_bound({x,c});
               it++;
               if(it!=Y[y].end())
               {
                   auto k=*it;
                   if(k.S!=c-1)ans.insert({{k.F-x,k.S},{-c,'W'}});
               }
               it--;
               if(it!=Y[y].begin())
               {
                   it--;
                   auto k=*it;
                   if(k.S!=c-1)ans.insert({{x-k.F,k.S},{-c,'E'}});
               }
}
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
    cin>>t;
    while(t--)
    {
       cin>>n;
       string s;
       cin>>s;
       X.clear();Y.clear(),ans.clear();
       int x=0,y=0,c=0;
       X[0].insert({0,0});
       Y[0].insert({0,0});
       for(int i=0;i<n;i++)
       {
           c++;
           if(s[i]=='N')y++;
           else if(s[i]=='S')y--;
           else if(s[i]=='W')x--;
           else x++;
           X[x].insert({y,c});
           Y[y].insert({x,c});
           go(x,y,c);
           while((int)ans.size()>1)ans.erase(--ans.end());
       }
       auto p=*ans.begin();
       cout<<p.F.F<<" "<<p.F.S<<" "<<-p.S.F<<" "<<p.S.S<<endl;

    }



return 0;
}
