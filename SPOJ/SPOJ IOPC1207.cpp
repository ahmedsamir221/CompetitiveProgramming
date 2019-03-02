/*
   we will use segment tree for every dimension to get the number of red plants in certain segment in that dimension
   to check if the the plant is red it must be red in only on dimension or in all three dimension other
   will be green .
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
int t,x,y,z,q,val[3][3000000],laz[3][3000000],typ,l,r;
int up(int s,int e,int p)
{
    if(s>=l&&e<=r)
    {
        laz[typ][p]=!laz[typ][p];
        return val[typ][p]=(e-s+1)-val[typ][p];
    }
    int mid=(s+e)/2;
    if(laz[typ][p])
    {
        laz[typ][p*2]=!laz[typ][p*2];
        laz[typ][p*2+1]=!laz[typ][p*2+1];
        laz[typ][p]=0;
        val[typ][p*2]=(mid-s+1)-val[typ][p*2];
        val[typ][p*2+1]=(e-mid)-val[typ][p*2+1];
    }

    if(r<=mid)return val[typ][p]=up(s,mid,p*2)+val[typ][p*2+1];
    else if(l>mid)return val[typ][p]=val[typ][p*2]+up(mid+1,e,p*2+1);
    else return val[typ][p]=up(s,mid,p*2)+up(mid+1,e,p*2+1);
}

int query(int s,int e,int p)
{
    if(s>=l&&e<=r) return val[typ][p];
    int mid=(s+e)/2;
    if(laz[typ][p])
    {
        laz[typ][p*2]=!laz[typ][p*2];
        laz[typ][p*2+1]=!laz[typ][p*2+1];
        laz[typ][p]=0;
        val[typ][p*2]=(mid-s+1)-val[typ][p*2];
        val[typ][p*2+1]=(e-mid)-val[typ][p*2+1];
    }
    if(r<=mid)return query(s,mid,p*2);
    else if(l>mid)return query(mid+1,e,p*2+1);
    else return query(s,mid,p*2)+query(mid+1,e,p*2+1);
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
    cin>>x>>y>>z>>q;
    while(q--)
    {
        cin>>typ;
        if(typ<3)
        {
            cin>>l>>r;
            l++,r++;
            if(typ==0)up(1,x,1);
            else if(typ==1)up(1,y,1);
            else up(1,z,1);
        }
        else
        {
            ll ans=0;
            int x1,y1,z1,x2,y2,z2;
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            x1++,y1++,z1++,x2++,y2++,z2++;
            int xsize=(x2-x1+1);
            int ysize=(y2-y1+1);
            int zsize=(z2-z1+1);

            l=x1,r=x2,typ=0;
            int qx=query(1,x,1);
            l=y1,r=y2,typ=1;
            int qy=query(1,y,1);
            l=z1,r=z2,typ=2;
            int qz=query(1,z,1);

            ans+=(ll)qx*(ll)ysize*(ll)zsize-(ll)qx*(ll)qy*(ll)zsize-(ll)qx*(ll)qz*(ll)ysize+(ll)qx*(ll)qy*(ll)qz;
            ans+=(ll)qy*(ll)xsize*(ll)zsize-(ll)qx*(ll)qy*(ll)zsize-(ll)qy*(ll)qz*(ll)xsize+(ll)qx*(ll)qy*(ll)qz;
            ans+=(ll)qz*(ll)xsize*(ll)ysize-(ll)qx*(ll)qz*(ll)ysize-(ll)qy*(ll)qz*(ll)xsize+(ll)qx*(ll)qy*(ll)qz;

            ans+=(ll)qx*(ll)qy*(ll)qz;

            cout<<ans<<endl;
        }
    }
    memset(val,0,sizeof val);
    memset(laz,0,sizeof laz);

}
return 0;
}
