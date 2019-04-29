/*
  we will ternary search  about the time each group use the bus , which number of groups = (n+k-1)/k .
  and it's function will return the required time for all groups .
*/
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
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=10001000,M=101000;

ll n,d,v1,v2,k;

double ok(double x)
{
    ll g=(n+k-1)/k;
    double s = x*v2-x*v1;
    double l=0.0,r = 1e9;
    double mid;
    forr(i,1,1000)
    {
        mid=(l+r)/2;
        if(mid*v1+mid*v2<s)l=mid;
        else r=mid;
    }
    return max(x+(d-x*v2)*1.0/v1,g*x+(g-1)*l);
}


pair<double, double> ternaryReal() {
	double left = 0.0, right = 1e9;
	forr(i,1,1000)
	{
		double g = left + (right - left) / 3, h = left + 2 * (right - left) / 3;

		if (ok(g) < ok(h))
			right = h;
		else
			left = g;
	}

	return make_pair(left, ok(left));
}
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
input;

cin>>n>>d>>v1>>v2>>k;
auto ans=ternaryReal();
cout<<fixed<<setprecision(9)<<ans.S<<endl;

return 0;
}
