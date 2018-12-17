/*
  we will simulate the process on first K number and will remove the number we appended in array b
  from the first K number and check if the remaining numbers sorted in decreasing order
  if that there will be an answer and will be:
  begin from 1 to N  we will tack every segment that not in first K number and reverse it
  then print it .

  other wise the answer is -1
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
#define Z size()
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
int n,k,a[200005],ck[200005],h=1;
vector<int>v;
stack<int>s;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("trip.in","r",stdin);
//freopen("trip.out","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>k;
forr(i,1,k)
{
    cin>>a[i];
    ck[a[i]]=1;
   v.push_back(a[i]);
}
reverse(v.begin(),v.end());
int cur=1;
while(v.Z||s.Z)
{
    if(s.Z&&s.top()==cur)
    {
        s.pop();
        cur++;
    }
    else
    {
        if(v.Z==0)break;
        s.push(v[v.Z-1]);
        v.pop_back();
    }
}
int pr=0;
forr(i,1,k)
{
  if(a[i]<cur)continue;
  if(pr!=0&&a[i]>pr)h=0;
  pr=a[i];
}

if(h)
{

    forr(i,1,k)
      cout<<a[i]<<" ";

    vector<int>x;
    ck[n+1]=1;
    forr(i,1,n+1)
    {
        if(ck[i]==0)x.push_back(i);
        else
        {
            reverse(x.begin(),x.end());
            for(auto p:x)
                cout<<p<<" ";
            x.clear();
        }
    }

}
else
    cout<<"-1";
return 0;
}
