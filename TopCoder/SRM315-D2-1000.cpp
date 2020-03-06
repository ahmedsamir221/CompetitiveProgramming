//https://github.com/shashank0107/CompetitiveProgramming/blob/master/Topcoder/SRM315-D2-1000.cpp
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
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
char rv[4]={'D','R','L','U'};
const double EPS = 1e-9;
const int N = 6e5 + 9;
int tree[N],mx=1<<19;
void up(int idx,int v)
{
    for(;idx<=mx;idx+=idx&-idx)tree[idx]+=v;
}

int get(int idx)
{
    if(idx<=0)return 0;
    int res=0;
    for(;idx;idx-=idx&-idx)res+=tree[idx];
    return res;
}

int kth(int k)
{
    int l=1,r=mx,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(tree[mid]<k)l=mid+1,k-=tree[mid];
        else r=mid;
    }
    if(l==mx)return -1;
    return l;
}

class KidsGame{
public:
    int kthKid(int n, int m, int k)
    {
        forr(i,1,n)up(i,1);
        int rm=0,ans=0,lst=0;
        while(1)
        {
            vector<int>v;
            lst=0;
            forr(i,1,1000000)
            {
                int cur=m*i-rm;
                int x=kth(cur);

                if(x!=-1)v.push_back(x),lst=x;
                else
                {
                    if((int)v.size()==0)rm+=get(mx)-get(lst);
                    else rm=get(mx)-get(lst);
                    break;
                }
            }
            for(auto p:v)
            {
                ans++;
                if(p==k)return ans;
                up(p,-1);
            }
        }
    }
};
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
   KidsGame x ;
   cout<<x.kthKid(99,100,99)<<endl;


return 0;
}
