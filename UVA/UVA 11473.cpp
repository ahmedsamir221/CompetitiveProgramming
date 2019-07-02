/*
    our step = total distance of the road / (number of trees - 1)
    so we can start from the first point with our step
*/
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep ,cos
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel , sin
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=100000,M=100000;
const double EPS= 1e-8;
int n,t,c,cas;
double x[110],y[110];

double dis(double a,double  b,double  c,double  d)
{
    return sqrt(pow(a-c,2)+pow(b-d,2));
}
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("ahmed.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
//priority_queue<ll,vector<ll>,greater<ll>>y;
input;

cin>>t;
while(t--)
{
    cin>>n>>c;
    double r=0;
    forr(i,1,n)
    {
        cin>>x[i]>>y[i];
        if(i>1)
            r+=dis(x[i],y[i],x[i-1],y[i-1]);
    }
    double d=r/(c-1);
    cout<<"Road #"<<++cas<<":"<<endl;
    cout<<fixed<<setprecision(2);
    cout<<x[1]<<" "<<y[1]<<endl;
    int i=2;
    double k=d;
    point a(x[1],y[1]);
    int f=c-1;
    while(f)
    {
        double g=dis(a.X,a.Y,x[i],y[i]);
        if(g>=k)
        {
            point b(x[i],y[i]);
            point c=b-a;
            c*=k/g;
            c+=a;
            a=c;
            cout<<c.X<<" "<<c.Y<<endl;
            f--;
            k=d;
        }
        else
        {
            k-=g;
            a={x[i],y[i]};
            i++;
        }
    }
    cout<<endl;
}


return 0;
}
