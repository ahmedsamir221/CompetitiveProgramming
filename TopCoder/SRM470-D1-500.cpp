//https://apps.topcoder.com/wiki/display/tc/SRM+470
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

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=100006,M=1000000;
const double EPS= 1e-9;
int to[20000],f[20000],ck[20000];
class DrawingLines{
public:
    double countLineCrossings(int n, vector <int> a, vector <int> b){
        int m=n-a.size();
        fill(f+1,f+10020,1);
        for(int i=0;i<a.size();i++)
        {
            to[a[i]]=b[i];
            ck[a[i]]=1;
            f[b[i]]=0;
        }
        for(int i=1;i<=n;i++)f[i]+=f[i-1];
        double ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(ck[i]&&ck[j])
                {
                    if(to[i]>to[j])ans++;
                }
                else if(ck[i])
                {
                    ans+=f[to[i]-1]*1.0/m;
                }
                else if(ck[j])
                {
                    ans+=(m-f[to[j]])*1.0/m;
                }
                else ans+=0.5;
            }
        }
        return ans;
    }

};
