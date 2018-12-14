/*
   first we will sort the balloons according to the sum of limit ans duration
   then using greegy to get max number of balloons
*/
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
ll n,id[300030];
pii a[300030];

bool com(int i,int j)
{
    if(a[i].F+a[i].S<a[j].F+a[j].S)return 1;
    return 0;
}

int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("tour.in","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n;
forr(i,0,n-1)
    cin>>a[i].F>>a[i].S,id[i]=i;

sort(id,id+n,com);

ll cur=0,ans=0;
priority_queue<ll>q;
forr(j,0,n-1)
{
    int i=id[j];
    if(a[i].F>=cur)
    {
        cur+=a[i].S;
        q.push(a[i].S);
        ans++;
    }
    else
    {
        if(q.top()>a[i].S)
        {
            cur-=q.top();
            q.pop();
            cur+=a[i].S;
            q.push(a[i].S);
        }
    }
}
cout<<ans;
return 0;
}
