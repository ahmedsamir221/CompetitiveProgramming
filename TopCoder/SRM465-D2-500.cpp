/*
   we just need to make the sides of two towers parallel to each others then try all possible lengths .
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
const int N=500005,M=1000000;
const double EPS= 1e-8;

double dis(int a,int b,int c,int d){
    return sqrt(pow(a-c,2)+pow(b-d,2));
}
class TurretPlacement{
public:
    long long count(vector <int> x, vector <int> y){
        int n=x.size();
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                 double d=dis(x[i],y[i],x[j],y[j]);
                 d*=2;
                 for(int s=1;s<=100000;s++)
                 {
                     if(s+1>(int)d)break;
                     ans+=(int)d-s;
                 }
            }
        }
        return ans;
    }
};
