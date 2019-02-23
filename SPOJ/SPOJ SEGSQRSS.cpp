/*
   if the problem was with normal sum we could use normal segment tree with lazy
   the hint is use that equation (cur+x)^2 =  cur^2+x^2+2*cur*x in increment query along the size of that segment
   that we have cur^2 in current square sum and easy to count x^2*size and use another segment tree to get the normal sum
   of the segment to calculate the cur

*/
#include <iostream>
#include<vector>
#include<algorithm>
//#include <cmath>
//#include <complex>
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
//#define x real()
//#define y imag()
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
int n,a[100020],l,r,t,q,typ,x,u;
ll sum[6000020],se[6000020],inc[6000020];

ll bulid(int s=1,int e=n,int p=1)
{
    if(s==e)
    {
        inc[p]=0;
        se[p]=2000;
        return sum[p]=a[s];
    }
    int mid=(s+e)/2;
    inc[p]=0;
    se[p]=2000;
    return sum[p]=bulid(s,mid,p*2)+bulid(mid+1,e,p*2+1);
}
ll up(int s=1,int e=n,int p=1)
{
     if(s>=l&&e<=r)
     {
         if(typ==0)
         {
         inc[p]=0;
         se[p]=x;
         return sum[p]=(ll)x*(ll)(e-s+1);
         }
         else
         {
             inc[p]+=(ll)x;
             return sum[p]+=(ll)x*(ll)(e-s+1);
         }
     }
    int mid=(s+e)/2;
    if(se[p]<2000)
    {
        inc[p*2]=0;
        inc[p*2+1]=0;
        sum[p*2]=(ll)se[p]*(ll)(mid-s+1);
        sum[p*2+1]=(ll)se[p]*(ll)(e-mid);
        se[p*2]=se[p];
        se[p*2+1]=se[p];
        se[p]=2000;
    }
    if(inc[p])
    {
        sum[p*2]+=(ll)inc[p]*(ll)(mid-s+1);
        sum[p*2+1]+=(ll)inc[p]*(ll)(e-mid);
        inc[p*2]+=inc[p];
        inc[p*2+1]+=inc[p];
        inc[p]=0;
    }
    if(r<=mid) return sum[p]=up(s,mid,p*2)+sum[p*2+1];
    else if(l>mid) return sum[p]=sum[p*2]+up(mid+1,e,p*2+1);
    else return sum[p]=up(s,mid,p*2)+up(mid+1,e,p*2+1);

}
ll get(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)return sum[p];
    int mid=(s+e)/2;
    if(se[p]<2000)
    {
        inc[p*2]=0;
        inc[p*2+1]=0;
        sum[p*2]=(ll)se[p]*(ll)(mid-s+1);
        sum[p*2+1]=(ll)se[p]*(ll)(e-mid);
        se[p*2]=se[p];
        se[p*2+1]=se[p];
        se[p]=2000;
    }
    if(inc[p])
    {
        sum[p*2]+=(ll)inc[p]*(ll)(mid-s+1);
        sum[p*2+1]+=(ll)inc[p]*(ll)(e-mid);
        inc[p*2]+=inc[p];
        inc[p*2+1]+=inc[p];
        inc[p]=0;
    }
    if(r<=mid)
    {
        ll cl=get(s,mid,p*2);
        sum[p]=sum[p*2]+sum[p*2+1];
        return cl;
    }
    else if(l>mid)
    {
        ll cr=get(mid+1,e,p*2+1);
        sum[p]=sum[p*2]+sum[p*2+1];
        return cr;
    }
    else
    {
        ll cl=get(s,mid,p*2);
        ll cr=get(mid+1,e,p*2+1);
        sum[p]=sum[p*2]+sum[p*2+1];
        return cl+cr;
    }
}
//////////////////////////////////////////////////////////////////


ll sum2[6000020],se2[6000020],inc2[6000020];

ll bulid2(int s=1,int e=n,int p=1)
{
    if(s==e)
    {
        inc2[p]=0;
        se2[p]=2000;
        return sum2[p]=(ll)a[s]*(ll)a[s];
    }
    int mid=(s+e)/2;
    inc2[p]=0;
    se2[p]=2000;
    return sum2[p]=bulid2(s,mid,p*2)+bulid2(mid+1,e,p*2+1);
}
ll up2(int s=1,int e=n,int p=1)
{
     if(s>=l&&e<=r)
     {
         if(typ==0)
         {
         inc2[p]=0;
         se2[p]=x;
         return sum2[p]=(ll)x*(ll)x*(ll)(e-s+1);
         }
         else
         {
             inc2[p]+=(ll)x;
             l=s,r=e;
             return sum2[p]+=2*(ll)x*get()+(ll)(e-s+1)*(ll)x*(ll)x;
         }
     }
    int mid=(s+e)/2;
    if(se2[p]<2000)
    {
        inc2[p*2]=0;
        inc2[p*2+1]=0;
        sum2[p*2]=(ll)se2[p]*(ll)se2[p]*(ll)(mid-s+1);
        sum2[p*2+1]=(ll)se2[p]*(ll)se2[p]*(ll)(e-mid);
        se2[p*2]=se2[p];
        se2[p*2+1]=se2[p];
        se2[p]=2000;
    }
    if(inc2[p])
    {
        l=s,r=mid;
        sum2[p*2]+=2*(ll)inc2[p]*get()+(ll)(mid-s+1)*(ll)inc2[p]*(ll)inc2[p];
        l=mid+1,r=e;
        sum[p*2+1]+=2*(ll)inc2[p]*get()+(ll)(e-mid)*(ll)inc2[p]*(ll)inc2[p];
        inc2[p*2]+=inc2[p];
        inc2[p*2+1]+=inc2[p];
        inc2[p]=0;
    }
    if(r<=mid) return sum2[p]=up2(s,mid,p*2)+sum2[p*2+1];
    else if(l>mid) return sum2[p]=sum2[p*2]+up2(mid+1,e,p*2+1);
    else return sum2[p]=up2(s,mid,p*2)+up2(mid+1,e,p*2+1);

}
ll get2(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)return sum2[p];
    int mid=(s+e)/2;
    if(se2[p]<2000)
    {
        inc2[p*2]=0;
        inc2[p*2+1]=0;
        sum2[p*2]=(ll)se2[p]*(ll)se2[p]*(ll)(mid-s+1);
        sum2[p*2+1]=(ll)se2[p]*(ll)se2[p]*(ll)(e-mid);
        se2[p*2]=se2[p];
        se2[p*2+1]=se2[p];
        se2[p]=2000;
    }
    if(inc2[p])
    {
        l=s,r=mid;
        sum2[p*2]+=2*(ll)inc2[p]*get()+(ll)(mid-s+1)*(ll)inc2[p]*(ll)inc2[p];
        l=mid+1,r=e;
        sum[p*2+1]+=2*(ll)inc2[p]*get()+(ll)(e-mid)*(ll)inc2[p]*(ll)inc2[p];
        inc2[p*2]+=inc2[p];
        inc2[p*2+1]+=inc2[p];
        inc2[p]=0;
    }
    if(r<=mid)
    {
        ll cl=get2(s,mid,p*2);
        sum2[p]=sum2[p*2]+sum2[p*2+1];
        return cl;
    }
    else if(l>mid)
    {
        ll cr=get2(mid+1,e,p*2+1);
        sum2[p]=sum2[p*2]+sum2[p*2+1];
        return cr;
    }
    else
    {
        ll cl=get2(s,mid,p*2);
        ll cr=get2(mid+1,e,p*2+1);
        sum2[p]=sum2[p*2]+sum2[p*2+1];
        return cl+cr;
    }
}

int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>t;
while(t--)
{
    cin>>n>>q;
    forr(i,1,n)cin>>a[i];
    bulid();
    bulid2();
    cout<<"Case "<<++u<<":"<<endl;
    while(q--)
    {
        cin>>typ>>l>>r;
        if(typ==2)
        {
            cout<<get2()<<endl;
        }
        else
        {
            cin>>x;
            up2();
            up();
        }
    }
}
return 0;
}
