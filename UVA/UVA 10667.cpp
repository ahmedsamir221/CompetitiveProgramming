/*
   we will start from each point as a left top of the rectangle and loop in rows and lower bound in columns
   then maximize the answer
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
int a[103][103];
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//input;
int t,n;
scanf("%d",&t);
while(t--)
{
    scanf("%d",&n);
    int b;
    scanf("%d",&b);
    int r1,r2,c1,c2;
    vector<int>s[103];
    memset(a,0,sizeof a);
    while(b--)
    {
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        forr(i,r1,r2)
            forr(j,c1,c2)
            {
             if(a[i][j]==0)
                s[i].push_back(j),a[i][j]=1;
            }
    }
    forr(i,1,n)
    s[i].push_back(n+1),sort(s[i].begin(),s[i].end());

    int ans=0;
    forr(i,1,n)
    forr(j,1,n)
    {
        int cc=1e9;
           forr(e,i,n)
           {
               if(a[e][j])break;
               auto it=lower_bound(s[e].begin(),s[e].end(),j);
               cc=min(cc,*it-j);
               ans=max(ans,(e-i+1)*cc);
           }
    }
    printf("%d\n",ans);

}

return 0;
}
