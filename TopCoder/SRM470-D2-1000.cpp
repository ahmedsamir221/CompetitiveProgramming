/*
    we will consider each cell in the grid as a node in a graph and each absolute value between any two adjacent cell
    as edge ;
    then get the cost of max spanning tree ,it will be the answer ;  
*/
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
int x[8]={1,0,0,-1,-1,-1,1,1};
int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=10001000,M=101000;
int n,m;
char a[55][55];
bool valid(int i,int j)
{
    if(i<1||i>n||j<1||j>m)return 0;
    else return 1;
}
vector<pair<int,pair<int,int>>>k;

int p[100010],ran[100010];


int findset(int f)
{
    if(p[f]==f)
        return f;
    else
        return p[f]=findset(p[f]);
}
void conect(int x,int y)
{
    x=findset(x);
    y=findset(y);
    if(ran[x]>ran[y])swap(x,y);
    p[x]=y;
    if(ran[x]==ran[y])
        ran[y]++;
}
bool isconect(int x,int y)
{
    if(findset(x)==findset(y))
        return 1;
    else
        return 0;
}

class ActivateGame{
public:
int findMaxScore(vector <string> grid)
{
n=grid.size();
m=grid[0].size();
forr(i,1,n)
forr(j,1,m)
a[i][j]=grid[i-1][j-1];


forr(i,1,n)
forr(j,1,m)
{
    for(int e=0;e<4;e++)
    {
        int u=i+x[e];
        int v=j+y[e];
        if(valid(u,v))
        {
            int d1,d2;
            if(a[i][j]>='0'&&a[i][j]<='9')d1=a[i][j]-'0';
            else if(a[i][j]>='a'&&a[i][j]<='z')d1=a[i][j]-'a'+10;
            else d1=a[i][j]-'A'+36;

            if(a[u][v]>='0'&&a[u][v]<='9')d2=a[u][v]-'0';
            else if(a[u][v]>='a'&&a[u][v]<='z')d2=a[u][v]-'a'+10;
            else d2=a[u][v]-'A'+36;
            k.push_back({abs(d1-d2),{(u-1)*m+v,(i-1)*m+j}});
        }
    }
}
sort(k.rbegin(),k.rend());
int ans=0;
forr(i,1,n*m)p[i]=i;
for(int i=0;i<k.size();i++)
{
    int u=k[i].S.F;
    int v=k[i].S.S;
    if(isconect(u,v))continue;
    ans+=k[i].F;
    conect(u,v);
}

return ans;   
}
};
