//https://github.com/YazanZebak/CompetitiveProgramming/blob/master/Codeforces/CF102299-GYM-F.cpp
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
const int N = 2e5 + 9;

 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input

        ll a,b;
        cin>>a>>b;
        ll g=__gcd(a,b);
        b/=g;

        ll ans=1,j=0;
        for(ll i=2;i*i<=b;i++)
        {
            if(b%i==0)
            {
                ans*=i;
                while(b%i==0)b/=i;
            }
            j++;
            if(j>100000000)break;
        }
        ll sq=(ll)sqrt(b);
        if(sq*sq==b)ans*=sq;
        else ans*=b;
        cout<<max(1LL*2,ans)<<endl;




return 0;
}
