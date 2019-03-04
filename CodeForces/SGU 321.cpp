/*
   we need for every node to know which node in it's sub tree need max change from "almost protected" to "protected"
   to hold the requirements and we can do that by DFS.
   then start from node 1 and check if there channel need to change, will change it and update
   the require of nodes connected to it.
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
int n,zero[200020],one[200020],c[200020];
vector<pair<pair<int,int>,int>>a[200020];
vector<int>ans;
void dfs(int i)
{
    for(auto p:a[i])
    {
        if(p.F.S)one[p.F.F]=one[i]+1,zero[p.F.F]=zero[i];
        else zero[p.F.F]=zero[i]+1,one[p.F.F]=one[i];
        dfs(p.F.F);
    }
}

void dfs2(int i)
{
    for(auto p:a[i])
    {
        dfs2(p.F.F);
        if(zero[p.F.F]-one[p.F.F]>zero[i]-one[i])zero[i]=zero[p.F.F],one[i]=one[p.F.F];
    }
}


void get(int i)
{
    if(one[i]>=zero[i])return;
    for(auto p:a[i])
    {
         zero[p.F.F]-=c[i];
         one[p.F.F]+=c[i];
         c[p.F.F]=c[i];
        if(p.F.S==0&&zero[p.F.F]>one[p.F.F])
        {
            zero[p.F.F]--;
            one[p.F.F]++;
            c[p.F.F]++;
            ans.push_back(p.S);
        }
        get(p.F.F);
    }
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n;
cin.ignore();
int u,v,ck;
string t,s;
forr(i,1,n-1)
{
    getline(cin,s);
    stringstream f;
    f<<s;
    f>>u>>v>>t;
    if(t=="protected")ck=1;
    else ck=0;
    a[v].push_back({{u,ck},i});
}
dfs(1);
dfs2(1);
get(1);
sort(ans.begin(),ans.end());
cout<<(int)ans.size()<<endl;
for(auto p:ans)cout<<p<<" ";
return 0;
}
