/*
    we will do prefix sum in our array then try to do all n cyclic shift and in each shift
    will use the segment tree to check if any number become less than zero by get the min element
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
//#define pi 3.141592654
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
int n,val[30000020],l,r,a[1000020];
int bulid(int s=1,int e=n,int p=1)
{
    if(s==e)return val[p]=a[s];
    int mid=(s+e)/2;
    return val[p]=min(bulid(s,mid,p*2),bulid(mid+1,e,p*2+1));
}

int get(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)return val[p];
    int mid=(s+e)/2;
    if(r<=mid)return get(s,mid,p*2);
    else if(l>mid)return get(mid+1,e,p*2+1);
    return min(get(s,mid,p*2),get(mid+1,e,p*2+1));
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//input;
while(1)
{
    scanf("%d",&n);
    if(!n)break;
    forr(i,1,n)scanf("%d",&a[i]),a[i]+=a[i-1];
    bulid();
    int ans=0;
    forr(i,1,n)
    {
        int ok=1,q,pre;
        l=i,r=n;
        if(l<=r)
        {
        q=get();
        pre=a[i-1];
        if(q-pre<0)ok=0;
        }
        l=1,r=i-1;
        if(l<=r)
        {
        pre=a[n]-a[i-1];
        q=get();
        if(q+pre<0)ok=0;
        }
        if(ok)ans++;
    }
    cout<<ans<<endl;
}

return 0;
}
