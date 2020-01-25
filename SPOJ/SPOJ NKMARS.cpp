/*
    we will use line sweep in x-axis and segment tree with lazy in y-axis
    time --> n*log(n)
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
const int N = 3e4 + 9;
pair<int,int>val[N*20];
int laz[N*20];

void bulid(int s=1,int e=30000,int p=1)
{
    if(s==e)
    {
        val[p]={0,1};
        return;
    }
    int mid=(s+e)/2;
    bulid(s,mid,p*2);
    bulid(mid+1,e,p*2+1);
    val[p].S=val[p*2].S+val[p*2+1].S;
}
void lazy(int p)
{
    val[p*2].F+=laz[p];
    val[p*2+1].F+=laz[p];
    laz[p*2]+=laz[p];
    laz[p*2+1]+=laz[p];
    laz[p]=0;
}

void up(int s,int e ,int p ,int l,int r,int v)
{
    if(e<l||s>r)return;
    if(s>=l&&e<=r)
    {
        val[p].F+=v;
        laz[p]+=v;
        return;
    }
    if(laz[p])lazy(p);
    int mid=(s+e)/2;
    up(s,mid,p*2,l,r,v);
    up(mid+1,e,p*2+1,l,r,v);
    if(val[p*2].F==val[p*2+1].F)val[p].F=val[p*2].F,val[p].S=val[p*2].S+val[p*2+1].S;
    else if(val[p*2].F<val[p*2+1].F)val[p]=val[p*2];
    else val[p]=val[p*2+1];

}

 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input
        bulid();
        int n;
        cin>>n;
        int xs,ys,xe,ye;
        vector<pair<pair<int,int>,pair<int,int>>>v;
        forr(i,1,n)
        {
            cin>>xs>>ys>>xe>>ye;
            ys++;
            v.push_back({{xs,0},{ys,ye}});
            v.push_back({{xe,1},{ys,ye}});
        }
        sort(v.begin(),v.end());
        int m=v.size(),ans=0;
        for(int i=0;i<m;i++)
        {
            int x=0;
            if(i)x=v[i].F.F-v[i-1].F.F;
            auto k=val[1];
            int y=0;
            if(k.F > 0) y=30000;
            else y=30000-k.S;
            ans+=x*y;
            if(v[i].F.S==0)up(1,30000,1,v[i].S.F,v[i].S.S,1);
            else up(1,30000,1,v[i].S.F,v[i].S.S,-1);
        }
        cout<<ans<<endl;


return 0;
}
