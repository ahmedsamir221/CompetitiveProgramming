/*
    we will use normal dp , our state will be the permutation vector and then try all possible swaps .
*/
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
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
//char rv[4]={'D','R','L','U'};
const double EPS = 1e-9;
const int N = 5e5 + 9;

int n;
map<vector<int>,double>mem;
bool ok(vector<int> &a)
{
    for(int i=1;i<n;i++)if(a[i]<a[i-1])return 0;
    return 1;
}
double dp(vector<int>a)
{
    if(ok(a))return 0;
    if(mem.count(a))return mem[a];
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i] > a[j])cnt++;
    double p = 1.0/cnt;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i] > a[j]){
                vector<int>b=a;
                swap(b[i],b[j]);
                mem[a]+=p*(1.0+dp(b));
            }
        }
    }

    return mem[a];
}

class RandomSort{
public:
    double getExpected(vector <int> permutation){
        n=permutation.size();
        return dp(permutation);
    }
};

 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input



return 0;
}
