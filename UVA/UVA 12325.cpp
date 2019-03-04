/*
   we will search about the number of items  of the treasure  with higher (value/size) .
   we will reduce our search space by using ternary search until 100000 items
   then use brute force to get the answer

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

ll n,s1,s2,v1,v2;

ll f(ll x)
{
    return x*v1+((n-x*s1)/s2)*v2;
}

ll get(ll left ,ll right) {
	while (right-left >100000) {
		ll g = left + (right - left) / 3, h = left + 2 * (right - left) / 3;

		if (f(g) > f(h))
			right = h;
		else
			left = g;
	}

	ll ans = 0;
	for (ll i = left; i <= right; ++i)
			ans = max(ans,f(i));

	return ans;
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
int t,u=0;
cin>>t;
while(t--)
{
cin>>n>>s1>>v1>>s2>>v2;
if(v2*s1>v1*s2)swap(s1,s2),swap(v1,v2);

ll ans=get(0,n/s1);
cout<<"Case #"<<++u<<": "<<ans<<endl;
}
return 0;
}
