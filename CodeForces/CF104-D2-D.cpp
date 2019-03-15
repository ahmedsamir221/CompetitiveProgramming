//http://codeforces.com/blog/entry/2426
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
ll n,k,q,x;

int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>k>>q;

while(q--)
{
    cin>>x;

    if(k==1)
    {
        if(x!=n)cout<<".";
        else cout<<"X";
        continue;
    }
    ll f=n-k;
    if(f<=k)
    {
        if(x<=f*2)
        {
            if(x%2)cout<<".";
            else cout<<"X";
        }
        else cout<<"X";
    }
    else
    {
        if(n%2==0)
        {
            if(x<=n-k*2)cout<<".";
            else
            {
                if(x%2)cout<<".";
                else cout<<"X";
            }
        }
        else
        {
            if(x<=n-k*2)cout<<".";
            else if(x-(n-k*2)==1||x-(n-k*2)==2)cout<<".";
            else if(x==n||x==n-1)cout<<"X";
            else
            {
                if(x%2)cout<<".";
                else cout<<"X";
            }

        }
    }
}
return 0;
}
