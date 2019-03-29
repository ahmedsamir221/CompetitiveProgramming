/*
   we will binary search about the answer and it's check function will check if we have at least K stick with our mid
   after at most C cuts
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
//const int N=10020,M=200020;
//int n,m,c,k,x;
//vector<int>a;
//string s;
//char ch;
class CutSticks
{
public:
double maxKth(vector <int> sticks, int C, int K)
{
sort(sticks.rbegin(),sticks.rend());
double l=0.0,r=2e9,mid;
forr(i,1,100000)
{
   mid=(l+r)/2.0;
   ll g=0;
   ll h=C;
   for(auto p:sticks)
   {
       ll d=(ll)(p/mid+1e-10);
       ll f=min(d,h+1);
       g+=f;
       h-=max((ll)0,f-1);
   }
   if(g>=K)l=mid;
   else r=mid;
}
return l;
}
};
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
//input;

return 0;
}
