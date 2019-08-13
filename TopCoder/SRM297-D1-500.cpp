/*
   we have 2^4 way to put the forced field around the monster .
   so will try all possible position with all possible ways to put the forced field and minimize the answer . 
*/
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


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

int x[8]={1,0,0,-1,-1,-1,1,1};
int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=16,M=1000000;
const double EPS= 1e-9;
int n,m,k[4],ans=1e9,id,vis[50][50],ck;
char a[50][50];
bool valid(int u,int v,int i,int j)
{
    if(u<1||u>n||v<1||v>m)return 0;
    if(k[0]&&v<j)return 0;
    if(k[1]&&v>j)return 0;
    if(k[2]&&u<i)return 0;
    if(k[3]&&u>i)return 0;
    return 1;
}
void dfs(int i,int j,int si,int sj)
{
    vis[i][j]=id;
    if(i==1||i==n||j==1||j==m)
    {
        ck=0;
        return ;
    }
    if(!ck)return ;
    for(int e=0;e<4;e++)
    {
       int u=i+x[e];
       int v=j+y[e];
       if(valid(u,v,si,sj)&&vis[u][v]!=id&&a[u][v]!='#')dfs(u,v,si,sj);
    }
}
void bk(int t=0,int c=0)
{
    if(t==4)
    {
        forr(i,1,n)
        forr(j,1,m)
        {
            if(a[i][j]=='^')
            {
                id++;
                ck=1;
                dfs(i,j,i,j);
                if(ck) ans=min(ans,c);
            }
        }
        return;
    }
    k[t]=1;
    bk(t+1,c+1);
    k[t]=0;
    bk(t+1,c);
}

class CageTheMonster{
public:
    int capture(vector <string> labyrinth){
        n=labyrinth.size();
        m=labyrinth[0].size();
        forr(i,1,n)
        forr(j,1,m)
        a[i][j]=labyrinth[i-1][j-1];
        bk();
        if(ans==1e9)ans=-1;
        return ans;
    }
};
