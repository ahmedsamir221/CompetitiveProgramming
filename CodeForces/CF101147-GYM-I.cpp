//https://github.com/aboodJAD/CompetitiveProgramming/blob/master/CodeForces/CF101147-GYM-I.cpp
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
const int N = 5e3 + 9;
 int main()
{
freopen("walk.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,R;
            scanf("%d %d",&n,&R);
            int x,y,r;
            vector<pair<pair<double,int>,int>>v;
            forr(i,1,n)
            {
                scanf("%d %d %d",&x,&y,&r);
                if(r<=R)
                {
                   ll k=1LL*(R-r)*(R-r)-1LL*y*y;
                   if(k>=0)
                   {
                       double f=sqrt(k);
                       v.push_back({{1.0*x-f,0},r});
                       v.push_back({{1.0*x+f,1},r});
                   }
                }
            }
            sort(v.begin(),v.end());
            int m=v.size();
            ll ans=0,sum=0;
            for(int i=0;i<m;i++)
            {
                if(v[i].F.S==0)sum+=v[i].S;
                else sum-=v[i].S;
                ans=max(ans,sum);
            }
            printf("%lld\n",ans);
        }

return 0;
}
