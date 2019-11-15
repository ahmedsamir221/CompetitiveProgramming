//https://github.com/Coder-Boy1/SPOJ/blob/master/SPOJ%20ADABLOOM
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>


/*
#define x real()
#define y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
*/

//#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
#define NOT(x) (1^x)

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const int N=5009*2,M=30000000;

const int N = 5e4 + 3, M = 5e4 + 3, E = 3e7 + 3;
int head[N], work[N], to[E], nxt[E], ne;
int n, m;
ll a[N];
void init() {
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}

void add_edge(int f, int t) {
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}

int rID[N], lID[M], dist[N];
bool dfs(int lf) {
    for (int &e = work[lf]; ~e; e = nxt[e]) {
        int rt = to[e];
        int nwLf = lID[rt];
        if (nwLf == -1 || dist[nwLf] == dist[lf] + 1 && dfs(nwLf)) {
            rID[lf] = rt;
            lID[rt] = lf;
            return true;
        }
    }
    return false;
}
int q[N], qsz;
bool bfs() {
    qsz = 0;
    for (int i = 0; i < n; ++i)
        if (rID[i] == -1)
            q[qsz++] = i, dist[i] = 0;
        else
            dist[i] = 1e9;
    bool kammel = true;
    int frnt = 0;
    while (frnt < qsz && kammel) {
        int s = qsz;
        while (frnt < s) {
            int lf = q[frnt++];
            for (int e = head[lf]; ~e; e = nxt[e]) {
                int rt = to[e];
                int nwLf = lID[rt];
                if (nwLf == -1) {
                    kammel = false;
                } else if (dist[nwLf] > dist[lf] + 1) {
                    dist[nwLf] = dist[lf] + 1;
                    q[qsz++] = nwLf;
                }
            }
        }
    }
    return !kammel;
}

int match() {
    memset(rID, -1, n * sizeof(rID[0]));
    memset(lID, -1, m * sizeof(lID[0]));
    int res = 0;
    while (bfs()) {
        memcpy(work, head, n * sizeof head[0]);
        for (int i = 0; i < n; ++i)
            if (rID[i] == -1 && dfs(i))
                ++res;
    }
    return res;
}


 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;
      int t,k;
      scanf("%d",&t);
      while(t--)
      {
          scanf("%d",&k);
          forr(i,0,k-1)scanf("%lld",&a[i]);
          n=k;
          m=k;
          init();

          forr(i,0,k-1)
          {
              forr(j,0,k-1)
              {
                  if(i==j)continue;
                  if((a[i]^a[j])>min(a[i],a[j])&&(a[i]^a[j])<max(a[i],a[j])){
                      add_edge( i, j);
                      add_edge( j ,i);
                      }
              }
          }
          printf("%d\n",match()/2);

      }


return 0;
}
