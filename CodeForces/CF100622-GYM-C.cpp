/*
    we will iterate in the columns from left to right and need to keep a set to tell us which
    circles pass through the current column then use line sweep in these circles to get
    the number of covered pixels .
*/
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
freopen("circles.in ","r",stdin);
freopen("circles.out","w",stdout);
//__builtin_popcount()
//input
        int w,h,n,x,y,r;
        scanf("%d %d %d",&w,&h,&n);
        vector<pair<pair<int,int>,pair<int,pair<int,int>>>>v;
        forr(i,1,n)
        {
            scanf("%d %d %d",&x,&y,&r);
            v.push_back({{max(0,x-r),0},{r,{x,y}}});
            v.push_back({{min(w-1,x+r),1},{r,{x,y}}});
        }
        sort(v.begin(),v.end());
        int l=0;
        multiset<pair<pair<int,int>,int>>s;
        ll ans=0;
        for(int i=0;i<w;i++)
        {
            while(l<n*2&&v[l].F.F==i&&v[l].F.S==0)
            {
                s.insert({{v[l].S.S.F,v[l].S.S.S},v[l].S.F});
                l++;
            }
            vector<pair<int,int>>q;
            for(auto p:s)
            {
                int x=p.F.F,y=p.F.S,r=p.S;
                int ab=abs(i-x);
                ll d=sqrt(1LL*r*r-1LL*ab*ab);
                int f=d;
                q.push_back({max(0,y-f),0});
                q.push_back({min(h-1,y+f),1});
            }
            sort(q.begin(),q.end());
            int m=q.size(),cnt=0;
            for(int j=0;j<m;j++)
            {
                if(q[j].S==0)cnt++;
                else cnt--;

                if(cnt==1&&q[j].S==0)ans++;
                else ans+=q[j].F-q[j-1].F;
            }

            while(l<n*2&&v[l].F.F==i&&v[l].F.S==1)
            {
                s.erase(s.find({{v[l].S.S.F,v[l].S.S.S},v[l].S.F}));
                l++;
            }
        }
        cout<<1LL*h*w-ans<<endl;

return 0;
}
