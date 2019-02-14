//https://ideone.com/Vyo2Z5
#include<stdio.h>
#include<vector>
#include<algorithm>
#include <iostream>
#include <cmath>
#include <complex>
#include<queue>
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
ll k,a[760][760];
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("CAMP.IN","r",stdin);
//freopen("CAMP.OUT","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
while(cin>>k)
{
    forr(i,1,k)
    {
        forr(j,1,k)cin>>a[i][j];
        sort(a[i]+1,a[i]+1+k);
    }
    vector<ll>v;
    forr(i,1,k)v.push_back(a[1][i]);

    forr(i,2,k)
    {
        priority_queue<ll>q;
        forr(j,1,k)
        {
            for(auto p:v)
            {
                if(q.size()<k)q.push(p+a[i][j]);
                else if(p+a[i][j]<q.top())
                {
                    q.pop();
                    q.push(p+a[i][j]);
                }
                else break;
            }
        }
        v.clear();
        while(q.size())v.push_back(q.top()),q.pop();
        reverse(v.begin(),v.end());
    }
    forr(i,0,k-2)cout<<v[i]<<" ";
    cout<<v[k-1]<<endl;
}
return 0;
}
