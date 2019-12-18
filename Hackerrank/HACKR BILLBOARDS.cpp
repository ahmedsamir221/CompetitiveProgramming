//https://github.com/sggutier/CompetitiveProgramming/blob/master/HackerRank/billboards.cpp
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
int n,k,a[N];
ll sum;
 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input

        cin>>n>>k;
        forr(i,1,n)cin>>a[i],sum+=a[i];
        priority_queue<pii,vector<pii>,greater<pii>>q;
        q.push({0,0});
        forr(i,1,n)
        {
            while(i-q.top().S-1>k)q.pop();
            q.push({q.top().F+a[i],i});
        }
        while((n+1)-q.top().S-1>k)q.pop();
        cout<<sum-q.top().F<<endl;


return 0;
}
