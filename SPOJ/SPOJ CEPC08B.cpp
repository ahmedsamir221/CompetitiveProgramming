//https://github.com/MohamedNabil97/CompetitiveProgramming/blob/master/SPOJ/CEPC08B.cpp
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
const int N = 1e6 + 9;

int n,q,lft[N],rt[N];

 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input
        int t;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d %d",&n,&q);
            vector<pair<int,int> >v;
            int x;
            forr(i,1,n)
            {
                scanf("%d",&x);
                v.push_back(make_pair(x,i));

                if(i>1)lft[i]=1;
                else lft[i]=0;

                if(i<n)rt[i]=1;
                else rt[i]=0;

            }
            sort(v.begin(),v.end());
            int l=0,ans=1;
            while(q--)
            {
                scanf("%d",&x);
                while(l<n)
                {
                    pair<int,int> p=v[l];
                    if(p.F<=x)
                    {
                        if(lft[p.S]==0&&rt[p.S]==0)ans--;
                        else if(lft[p.S]==1&&rt[p.S]==1)ans++;
                        lft[p.S+1]=0;
                        rt[p.S-1]=0;
                        l++;
                    }
                    else break;
                }
                if(q==0)printf("%d\n",ans);
                else printf("%d ",ans);
            }
        }

return 0;
}
