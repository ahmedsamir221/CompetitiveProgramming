/*
    we will represent each number in mask that tell us which digits that number consist of.
    then generate all set of digits and count number of numbers that have each set of them.
    if the set with odd number of digits we will add it's numbers of pairs
    else will subtract it's numbers of pairs
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
int n,c[1030];
ll ans,x;
void bk(int mask=0,int i=0,int v=0)
{
    if(i>9&&mask==0)return;
    if(i>9)
    {
        int cc=0;
        forr(j,0,1023)
        {
            if(!c[j])continue;
            int ck=1;
            forr(e,0,9)
            {
                if((mask&(1<<e))&&(j&(1<<e))==0)
                {
                    ck=0;
                    break;
                }
            }
            if(ck)cc+=c[j];
        }
        if(v%2)ans+=(ll)cc*((ll)cc-1)/2;
        else  ans-=(ll)cc*((ll)cc-1)/2;
        return;
    }
    bk(mask|(1<<i),i+1,v+1);
    bk(mask,i+1,v);
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
cin>>n;
forr(i,1,n)
{
    cin>>x;
    int mask=0;
    while(x)
    {
        int g=x%10;
        mask|=(1<<g);
        x/=10;
    }
    c[mask]++;
}
bk();
cout<<ans;
return 0;
}
