/*
   we need to backtracking to get all masks that tell us which rumors will separated first for each rabbit
   then simulate the normal process in each mask and minimize the answer
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
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=250,M=400000;
pair<int,int> c[20],s[20];
int b[20],cc[20],t[20];
int ansfar=1e9;

void bk(int cur,int n,vector <string> &a)
{
    if(cur==n)
    {
        int g=2*n+3;
        int ans=0;
        for(int i=0;i<n;i++)
            c[i]=s[i],cc[i]=0,b[i]=t[i];
        while(g--)
        {
        vector<pair<int,int>>v;
        ans++;
        for(int i=0;i<n;i++)
        {
            if(cc[i]==2)continue;
            int ff=0;
            for(int j=0;j<n;j++)
                if(a[i][j]=='Y')
                {
                    if(c[i].F==1&&b[i]==0)v.push_back({j,0}),ff=1;
                    if(c[i].S==1&&b[i]==1)v.push_back({j,1}),ff=-1;
                }
            if(ff==1) b[i]=1,cc[i]++;
            else if(ff==-1) b[i]=0,cc[i]++;
        }
        for(auto p:v)
        if(p.S==0)c[p.F].F=1;
        else c[p.F].S=1;

        int ck=1;
        for(int i=0;i<n;i++)
          if(c[i].F==0||c[i].S==0)ck=0;
        if(ck)break;
        }
        if(ans<2*(int)n+3)ansfar=min(ans,ansfar);
        return ;
    }
    bk(cur+1,n,a);
    t[cur]=1;
    bk(cur+1,n,a);
    t[cur]=0;
}
class Rumor{
public:
    int getMinimum(string knowledge, vector <string> graph){
        int k=0;
        for(int i=0;i<(int)knowledge.size();i++)
         if(knowledge[i]=='Y')s[i].F=1,s[i].S=1,k++;

        if(k==(int)knowledge.size())return 0;

        bk(0,(int)knowledge.size(),graph);
        if(ansfar==1e9)return -1;
        else return ansfar;
    }
};
