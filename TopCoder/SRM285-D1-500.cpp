/*
   we have 4*N point which the robot can exit from "the borders of the grid" , so we can check from 1 to 50000 
   step if the robot will leave the grid from one of 4*N point and count this cells , the remaining cells will
   complete the 50000 step .
    
*/
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
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

const int N=50000,M=1000000;
const double EPS= 1e-9;
int a[50505],b[50505],ck[1005][1005];
string s;
class RobotTesting{
public:
      double estimateCommands(int N, string program){
          while(s.size()<50000)s+=program;
          int x=0,y=0,i=0;
          for(auto p:s)
          {
              if(p=='U')x--;
              else if(p=='D')x++;
              else if(p=='L')y--;
              else y++;
              i++;
              a[i]=x,b[i]=y;
          }
          ll ans=0;
          forr(i,1,50000)
          {
              forr(j,1,N)
              {
                  int u=0,v=j;
                  u+=-1*a[i],v+=-1*b[i];
                  if(u>=1&&u<=N&&v>=1&&v<=N&&!ck[u][v])
                  {
                      ck[u][v]=1;
                      ans+=i;
                  }
              }
              forr(j,1,N)
              {
                  int u=N+1,v=j;
                  u+=-1*a[i],v+=-1*b[i];
                  if(u>=1&&u<=N&&v>=1&&v<=N&&!ck[u][v])
                  {
                      ck[u][v]=1;
                      ans+=i;
                  }
              }
              forr(j,1,N)
              {
                  int u=j,v=0;
                  u+=-1*a[i],v+=-1*b[i];
                  if(u>=1&&u<=N&&v>=1&&v<=N&&!ck[u][v])
                  {
                      ck[u][v]=1;
                      ans+=i;
                  }
              }
              forr(j,1,N)
              {
                  int u=j,v=N+1;
                  u+=-1*a[i],v+=-1*b[i];
                  if(u>=1&&u<=N&&v>=1&&v<=N&&!ck[u][v])
                  {
                      ck[u][v]=1;
                      ans+=i;
                  }
              }
          }
          forr(i,1,N)forr(j,1,N)if(!ck[i][j])ans+=50000;
         // cout<<ans<<endl;
          return ans*1.0/(N*N);
      }
};
