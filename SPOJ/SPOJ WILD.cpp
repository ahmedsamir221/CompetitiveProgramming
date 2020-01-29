//https://github.com/osamahatem/CompetitiveProgramming/blob/master/SPOJ/WILD%20-%20set.cpp
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
int n,m;
pair<pair<int,int>,int>a[N];
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
        while(cin>>n>>m,n&&m)
        {
            forr(i,1,n)cin>>a[i].F.F>>a[i].F.S>>a[i].S;
            sort(a+1,a+1+n);
            set<pair<int,pair<int,int>>>s;
            s.insert({m,{1,m}});
            int idx=n;
            ll sum=m*m,ans=0;
            for(int i=m;i>0;i--)
            {
                while(idx>-1&&a[idx].F.F>=i)
                {
                    set<pair<int,pair<int,int>>>::iterator it=s.upper_bound({m-a[idx].S,{m,m}});
                    vector<set<pair<int,pair<int,int>>>::iterator>v;
                    while(it!=s.end())
                    {
                        auto p=*it;
                        int val=p.F,l=p.S.F,r=p.S.S;
                        if(l>a[idx].F.S)break;
                        else if(r<=a[idx].F.S)
                        {
                            sum-=1LL*val*(r-l+1);
                            sum+=1LL*(m-a[idx].S)*(r-l+1);
                            v.push_back(it);
                        }
                        else
                        {
                            sum-=1LL*val*(a[idx].F.S-l+1);
                            sum+=1LL*(m-a[idx].S)*(a[idx].F.S-l+1);
                            v.push_back(it);
                            break;
                        }
                        it++;
                    }
                    if((int)v.size())
                    {
                        auto st=*v[0],en=*v[(int)v.size()-1];
                        s.insert({m-a[idx].S,{st.S.F,a[idx].F.S}});
                        if(en.S.S>a[idx].F.S)s.insert({en.F,{a[idx].F.S+1,en.S.S}});
                        for(auto p:v)s.erase(p);
                    }

                    idx--;
                }
                ans+=sum;
            }
            cout<<ans<<endl;
        }



return 0;
}
