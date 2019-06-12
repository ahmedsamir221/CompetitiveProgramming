//https://codeforces.com/blog/entry/51163
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
int n,a[2][7007],k[2],ck[2][7007],c[2][7007],vis[2][7007];

int bfs()
{
   ck[0][n]=0;
   ck[1][n]=0;
   vis[0][n]=1;
   vis[1][n]=1;
   queue<pair<int,int>>q;
   q.push({0,n});
   q.push({1,n});
   while(q.size())
   {
       int i=q.front().F;
       int u=q.front().S;
       q.pop();
       forr(j,1,k[!i])
       {
           int v=u-a[!i][j];
           if(v<1)v+=n;
           if(vis[!i][v])continue;
           if(!ck[i][u])
           {
               ck[!i][v]=1;
               vis[!i][v]=1;
               q.push({!i,v});
           }
           else
           {
              c[!i][v]++;
              if(c[!i][v]==k[!i])ck[!i][v]=0,vis[!i][v]=1,q.push({!i,v});
           }
       }
   }
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

cin>>n;
cin>>k[0];
forr(i,1,k[0])cin>>a[0][i];
cin>>k[1];
forr(i,1,k[1])cin>>a[1][i];

memset(ck,-1,sizeof ck);
bfs();

forr(i,0,1)
{
    forr(j,1,n-1)
    {
        if(c[i][j]==k[i])cout<<"Lose ";
        else if(ck[i][j]==1)cout<<"Win ";
        else cout<<"Loop ";
    }
    cout<<endl;
}

return 0;
}
