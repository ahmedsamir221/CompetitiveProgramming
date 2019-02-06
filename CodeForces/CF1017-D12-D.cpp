/*
   we will get all strings with length n and calculate the answer of them with 
   the M strings that will be at most 1<<n different string 
   and answer the query in O(1)
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
int n,m,q,w[15],k;
char s[17];
int c[5000];
int ck[5000][110];
void bk()
{
    forr(i,0,(1<<n)-1)
    forr(j,0,(1<<n)-1)
    {
        if(c[j])
        {
            int a=i,b=j,cost=0;
            forr(e,0,n-1)
            {
                if(a%2==b%2)cost+=w[e];
                a/=2;
                b/=2;
            }
            if(cost<=100)
            ck[i][cost]+=c[j];
        }
    }

}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("CAMP.IN","r",stdin);
//freopen("CAMP.OUT","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//input;
scanf("%d%d%d",&n,&m,&q);
forr(i,0,n-1)
scanf("%d",&w[i]);

forr(i,1,m)
{
     scanf("%s",&s);
    int num=0,d=1;
        forr(j,0,n-1)num+=d*(s[j]-'0'),d*=2;
    c[num]++;
}
bk();

forr(i,0,(1<<n)-1)
    forr(j,1,100)
        ck[i][j]+=ck[i][j-1];



while(q--)
{
    scanf("%s", &s);
    scanf("%d", &k);
    int num=0,d=1;
        forr(j,0,n-1)num+=d*(s[j]-'0'),d*=2;
    printf("%d\n",ck[num][k]);
}
return 0;
}
