/*
first we will save 4 array int row ,column and the two diagonals  to check if there an side with any black node
then iterate in all grade and at each node we will go throw all 8 direction and get all possible triangles from that node
and we will check if every triangle holds all condition to increase the answer

after that will be three type of triangles two of them will repeated from all its three nodes
so will divide the total answer of them by three
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
//typedef bitset<3> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
int n,m,a[1004][1004],ckrow[1004][1004],ckcol[1004][1004],ckrd[1004][1004],ckld[1004][1004],mx;
ll ans,ans2,ans3;
char x;
bool valid (int i,int j)
{
    if(i<1||i>n||j<1||j>m)return 0;
    return 1;
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
cin>>n>>m;
mx=max(n,m);
forr(i,1,n)
forr(j,1,m)
{
    cin>>x;
    a[i][j]=x-'0';
    ckrow[i][j]=a[i][j]+ckrow[i][j-1];
}
forr(j,1,m)
forr(i,1,n)
    ckcol[i][j]=a[i][j]+ckcol[i-1][j];

forr(j,1,m)
forr(i,1,n)
    ckrd[i+j][j]=a[i][j]+ckrd[i+j][j-1];

forr(i,1,n)
forr(j,1,m)
    ckld[j-i+mx][j]=a[i][j]+ckld[j-i+mx][j-1];

forr(i,1,n)
forr(j,1,m)
{
    if(a[i][j]==1)continue;
    pair<int,int> p1={i,j},p2={i,j},p3={i,j},p4={i,j},l={i,j},r={i,j},u={i,j},d={i,j};
    int ckp1=1,ckp2=1,ckp3=1,ckp4=1;
    int ckl=1,ckr=1,cku=1,ckd=1;
    forr(k,1,max(n,m))
    {
        p1.F--,p1.S++;
        p2.F--,p2.S--;
        p3.F++,p3.S--;
        p4.F++,p4.S++;
        l.S--;
        r.S++;
        u.F--;
        d.F++;
        if(valid(p1.F,p1.S)==0||a[p1.F][p1.S]==1)ckp1=0;
        if(valid(p2.F,p2.S)==0||a[p2.F][p2.S]==1)ckp2=0;
        if(valid(p3.F,p3.S)==0||a[p3.F][p3.S]==1)ckp3=0;
        if(valid(p4.F,p4.S)==0||a[p4.F][p4.S]==1)ckp4=0;
        if(valid(l.F,l.S)==0||a[l.F][l.S]==1)ckl=0;
        if(valid(r.F,r.S)==0||a[r.F][r.S]==1)ckr=0;
        if(valid(u.F,u.S)==0||a[u.F][u.S]==1)cku=0;
        if(valid(d.F,d.S)==0||a[d.F][d.S]==1)ckd=0;

        if(ckp1&&ckr&&ckcol[r.F][r.S]-ckcol[p1.F-1][p1.S]==0)ans++;
        if(ckr&&ckp4&&ckcol[p4.F][p4.S]-ckcol[r.F-1][r.S]==0)ans++;
        if(ckp4&&ckd&&ckrow[p4.F][p4.S]-ckrow[d.F][d.S-1]==0)ans++;
        if(ckd&&ckp3&&ckrow[d.F][d.S]-ckrow[p3.F][p3.S-1]==0)ans++;
        if(ckp3&&ckl&&ckcol[p3.F][p3.S]-ckcol[l.F-1][l.S]==0)ans++;
        if(ckl&&ckp2&&ckcol[l.F][l.S]-ckcol[p2.F-1][p2.S]==0)ans++;
        if(ckp2&&cku&&ckrow[u.F][u.S]-ckrow[p2.F][p2.S-1]==0)ans++;
        if(cku&&ckp1&&ckrow[p1.F][p1.S]-ckrow[u.F][u.S-1]==0)ans++;


        if(ckp1&&ckp4&&ckcol[p4.F][p4.S]-ckcol[p1.F-1][p1.S]==0)ans2++;
        if(ckp4&&ckp3&&ckrow[p4.F][p4.S]-ckrow[p3.F][p3.S-1]==0)ans2++;
        if(ckp3&&ckp2&&ckcol[p3.F][p3.S]-ckcol[p2.F-1][p2.S]==0)ans2++;
        if(ckp2&&ckp1&&ckrow[p1.F][p1.S]-ckrow[p2.F][p2.S-1]==0)ans2++;


        if(ckr&&ckd&&ckrd[r.F+r.S][r.S]-ckrd[d.F+d.S][d.S-1]==0)ans3++;
        if(ckd&&ckl&&ckld[d.S-d.F+mx][d.S]-ckld[l.S-l.F+mx][l.S-1]==0)ans3++;
        if(ckl&&cku&&ckrd[u.F+u.S][u.S]-ckrd[l.F+l.S][l.S-1]==0)ans3++;
        if(cku&&ckr&&ckld[r.S-r.F+mx][r.S]-ckld[u.S-u.F+mx][u.S-1]==0)ans3++;
    }
    //cout<<i<<"  "<<j<<" "<<ans<<endl;
}
cout<<(ans+ans3)/3+ans2;
return 0;
}
