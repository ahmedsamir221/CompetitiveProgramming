//https://github.com/aboodJAD/CompetitiveProgramming/blob/master/UVA/UVA%2010750.cpp
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
pair<int,int> a[N];

double dis(int a,int b,int c,int d)
{
    double x=a-c;
    x*=x;
    double y=b-d;
    y*=y;
    return sqrt(x+y);
}
 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            forr(i,1,n) cin>>a[i].F>>a[i].S;
            sort(a+1,a+1+n);
            int l=1;
            double d=1e8;
            pair<int,int>x,y;
            multiset<pair<int,int>>s;
            forr(i,1,n)
            {
                while(l<i && (a[i].F-a[l].F)*1.0 > d)s.erase(s.lower_bound({a[l].S,a[l].F})),l++;
                multiset<pair<int,int>>::iterator st=s.lower_bound({a[i].S-d,-1e9});
                multiset<pair<int,int>>::iterator en=s.upper_bound({a[i].S+d,-1e9});
                auto k=*en;
                for(;st!=en;st++)
                {
                    auto p=*st;
                    if(dis(a[i].F,a[i].S,p.S,p.F)<d)
                    {
                        d=dis(a[i].F,a[i].S,p.S,p.F);
                        x=a[i];
                        y={p.S,p.F};
                    }
                }
                s.insert({a[i].S,a[i].F});
            }
            cout<<fixed<<setprecision(3);
            cout<<(x.F+y.F)/2.0<<" "<<(x.S+y.S)/2.0<<endl;
            if(t)cout<<endl;
        }








return 0;
}
