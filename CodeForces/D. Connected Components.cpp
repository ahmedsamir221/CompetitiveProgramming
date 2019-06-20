//https://codeforces.com/blog/entry/7371
#include<queue>
#include<map>
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
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=100000,M=100000;
int n,m,p[2][10004][505],x[10004],y[10004],k[505];

int findset(int t,int i,int f)
{
    if(p[t][i][f]==f)
        return f;
    else
        return p[t][i][f]=findset(t,i,p[t][i][f]);
}
void conect(int t,int i,int x,int y)
{
    x=findset(t,i,x);
    y=findset(t,i,y);
    if(x>y)swap(x,y);
    p[t][i][y]=x;
}
bool isconect(int t,int i,int x,int y)
{
    if(findset(t,i,x)==findset(t,i,y))
        return 1;
    else
        return 0;
}
/////////////////////
int findsetk(int f)
{
    if(k[f]==f)
        return f;
    else
        return k[f]=findsetk(k[f]);
}
void conectk(int x,int y)
{
    x=findsetk(x);
    y=findsetk(y);
    if(x>y)swap(x,y);
    k[y]=x;
}
bool isconectk(int x,int y)
{
    if(findsetk(x)==findsetk(y))
        return 1;
    else
        return 0;
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
//priority_queue<ll,vector<ll>,greater<ll>>y;
input;
cin>>n>>m;
forr(i,1,m)cin>>x[i]>>y[i];

forr(i,1,m)
{
    if(i==1) forr(j,1,n)p[0][i][j]=j;
    else forr(j,1,n)p[0][i][j]=p[0][i-1][j];

    if(isconect(0,i,x[i],y[i])==0)conect(0,i,x[i],y[i]);
}

for(int i=m;i>=1;i--)
{
    if(i==m) forr(j,1,n)p[1][i][j]=j;
    else forr(j,1,n)p[1][i][j]=p[1][i+1][j];

    if(isconect(1,i,x[i],y[i])==0)conect(1,i,x[i],y[i]);
}

int q,l,r;
cin>>q;
while(q--)
{
    cin>>l>>r;
    int ans=n;
    forr(i,1,n)k[i]=i;

    forr(i,1,n)
    {
        if(l>1)
        {
            int a=findset(0,l-1,i);
            if(isconectk(i,a)==0)conectk(i,a),ans--;
        }
        if(r<m)
        {
            int a=findset(1,r+1,i);
            if(isconectk(i,a)==0)conectk(i,a),ans--;
        }
    }

    cout<<ans<<endl;
}
return 0;
}
