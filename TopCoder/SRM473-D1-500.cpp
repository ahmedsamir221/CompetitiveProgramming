//https://tasks.illustrativemathematics.org/content-standards/HSG/C/A/2/tasks/1091
/*
   there will be right triangle if the Hypotenuse passes with the center of the circle .
   so after get the red point we can get the answer by using prefix sum .
   using set data structure to get the red points will may get memory limit , so we can use BIT .
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>



#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=1000006,M=1000000;
const double eps= 1e-9,EPS= 1e-9;

int ck[N],sum[N],tree[N],n;
void up(int idx)
{
    for(;idx<=n;idx+=(idx&-idx))tree[idx]++;
}

int get(int idx)
{
    int ans=0;
    for(;idx;idx-=(idx&-idx))ans+=tree[idx];
    return ans;
}

int go(int d)
{
    if(get(d)-get(d-1)==0)return d-1;
    int l=d+1,r=n,mid;
    if(get(n)-get(d)==n-d)l=1,d=0;

    while(l<r)
    {
        mid=(l+r)/2;
        if(get(mid)-get(d)<mid-d)r=mid;
        else l=mid+1;
    }
    return l-1;
}
class RightTriangle{
public:
    long long triangleCount(int places, int points, int a, int b, int c){
        if(places%2)return 0;
        n=places;
        for(int i=0;i<points;i++)
        {
            int g=(ll)((ll)a*i*i+(ll)b*i+c)%places;
            int idx=go(g+1);
       //     cout<<idx<<endl;
            ck[idx]=1;
            up(idx+1);
        }
        ll ans=0;
        sum[0]=ck[0];
        for(int i=1;i<places;i++)sum[i]=sum[i-1]+ck[i];
        for(int i=0;i<places;i++)
        {
            int f=i,t=(i+places/2)%places;
            if(ck[f]&&ck[t])
            {
                if(f<t)ans+=sum[t]-sum[f]-1;
                else
                {
                    ans+=sum[places-1]-sum[f];
                    ans+=sum[t]-1;
                }
            }
        }
        return ans;
    }
};
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

RightTriangle k;
cout<<k.triangleCount(4,
4,
16,
24,
17);
return 0;
}
