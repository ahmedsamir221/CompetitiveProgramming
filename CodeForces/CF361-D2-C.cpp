/*
   we will try to gave every element in the array the max value that can satisfy all the operation.
   then simulate to check if that array meet the all condition.
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
int n,m,t[5005],l[5005],r[5005],d[5005],arr[5005],ans[5005];
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;

cin>>n>>m;
forr(i,1,m)
    cin>>t[i]>>l[i]>>r[i]>>d[i];

forr(i,1,n)
{
    ll num=1e8;
    for(int j=m;j>=1;j--)
    {
        if(i>=l[j]&&i<=r[j])
        {
        if(t[j]==1)
        {
            if(num!=1e8)num-=d[j];
        }
        else
        {
            if(num>d[j])num=d[j];
        }
        }
    }
    arr[i]=num;
    ans[i]=num;
}
int ck=1;

forr(i,1,m)
{
   if(t[i]==1)
   {
       forr(j,l[i],r[i])arr[j]+=d[i];
   }
   else
   {
       int mx=-2e9;
       forr(j,l[i],r[i])mx=max(mx,arr[j]);
       if(mx!=d[i])
       {
           ck=0;
           break;
       }
   }
}
if(ck)
{
    cout<<"YES"<<endl;
    forr(i,1,n)cout<<ans[i]<<" ";
}
else
    cout<<"NO";



return 0;
}
