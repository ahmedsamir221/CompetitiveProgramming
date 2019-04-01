
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
#define var(x) ((x)<<1)
#define nvar(x) ((x)^1)
const int N=300,M=8*300;
int n,m,a[N][N];
void init()
{
    memset(a,0,sizeof a);
}


int get(int x)
{
    int u=var(x);
    int v=nvar(u);
    if(a[u][v]==1&&a[v][u]==1)return 1;
    else return 0;
}

 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
input;
int t,q,s1,s2,v1,v2;
cin>>t;
while(t--)
{
    cin>>n>>m>>q;
    init();
    forr(i,1,q)
    {
        cin>>s1>>v1>>s2>>v2;
        v1--,v2--,s1--,s2--;
        v1+=n;
        v2+=n;
        s1=var(s1);int ns1=nvar(s1);
        s2=var(s2);int ns2=nvar(s2);
        v1=var(v1);int nv1=nvar(v1);
        v2=var(v2);int nv2=nvar(v2);

        if(v1>v2)swap(s1,ns1),swap(s2,ns2);
        if(s1<s2)swap(v1,nv1),swap(v2,nv2);



        if(s1 == s2) {
            a[ns1][s2]=1;
            continue;
        }
        if(v1 == v2) {
            a[nv1][v2]=1;
            continue;
        }
        a[ns1][s2]=1;
        a[ns2][s1]=1;
        a[nv1][v2]=1;
        a[nv2][v1]=1;
        a[ns2][v2]=1;
        a[nv2][s2]=1;
        a[ns1][v1]=1;
        a[nv1][s1]=1;
    }

    forr(k,0,(n+m)*2-1)
    forr(i,0,(n+m)*2-1)
    forr(j,0,(n+m)*2-1)
    a[i][j]|=(a[i][k]&a[k][j]);



    int ans=1;
    forr(i,0,n+m-1)
    if(get(i))ans=0;

    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
return 0;
}
