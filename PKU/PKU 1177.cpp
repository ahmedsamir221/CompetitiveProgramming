//https://github.com/osamahatem/CompetitiveProgramming/blob/master/PKU/1177%20-%20Picture.cpp
#pragma GCC optimize("O3")
//#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>
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
int n,xmn[N],ymn[N],xmx[N],ymx[N];
int solvev()
{
    int ans=0;
    vector<pair<pair<int,int>,pair<int,int> > >v;
    forr(i,1,n)
    {
        v.push_back(make_pair(make_pair(xmn[i],0),make_pair(ymn[i],ymx[i])));
        v.push_back(make_pair(make_pair(xmx[i],1),make_pair(ymn[i],ymx[i])));
    }
    sort(v.begin(),v.end());
    multiset<pair<int,int> >s;
    for(int i=0;i<n*2;i++)
    {
        int x=0;
        if(i)x=v[i].F.F-v[i-1].F.F;
        int cnt=0,c=0;
        if((int)s.size()){
        multiset<pair<int,int> >::iterator it=s.begin();
        for(;it!=s.end();it++)
        {
            pair<int,int> p= *it;
            if(p.S==0)cnt++;
            else cnt--;
            if(cnt==1&&p.S==0)c++;
            else if(cnt==0&&p.S==1)c++;
        }}
        ans+=x*c;
        if(v[i].F.S==0)s.insert(make_pair(v[i].S.F,0)),s.insert(make_pair(v[i].S.S,1));
        else s.erase(s.find(make_pair(v[i].S.F,0))),s.erase(s.find(make_pair(v[i].S.S,1)));
    }
    return ans;
}
int solveh()
{
    int ans=0;
    vector<pair<pair<int,int>,pair<int,int> > >v;
    forr(i,1,n)
    {
        v.push_back(make_pair(make_pair(ymn[i],0),make_pair(xmn[i],xmx[i])));
        v.push_back(make_pair(make_pair(ymx[i],1),make_pair(xmn[i],xmx[i])));
    }
    sort(v.begin(),v.end());
    multiset<pair<int,int> >s;
    for(int i=0;i<n*2;i++)
    {
        int x=0;
        if(i)x=v[i].F.F-v[i-1].F.F;
        int cnt=0,c=0;
        if((int)s.size()){
        multiset<pair<int,int> >::iterator it=s.begin();
        for(;it!=s.end();it++)
        {
            pair<int,int> p= *it;
            if(p.S==0)cnt++;
            else cnt--;
            if(cnt==1&&p.S==0)c++;
            else if(cnt==0&&p.S==1)c++;
        }}
        ans+=x*c;
        if(v[i].F.S==0)s.insert(make_pair(v[i].S.F,0)),s.insert(make_pair(v[i].S.S,1));
        else s.erase(s.find(make_pair(v[i].S.F,0))),s.erase(s.find(make_pair(v[i].S.S,1)));
    }
    return ans;
}
 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input
        scanf("%d",&n);
        forr(i,1,n)scanf("%d %d %d %d",&xmn[i],&ymn[i],&xmx[i],&ymx[i]);
        int ans=solvev();
        ans+=solveh();
        printf("%d\n",ans);


return 0;
}
