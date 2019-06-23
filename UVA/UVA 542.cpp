/*
   we can with back tracking get all possible scenarios of who can win the champion ,
   for each team will collect it's probabilities
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
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=100000,M=100000;
int a[17][17];
string s[17];
vector<pair<int,double>>m;

vector<vector<pair<int,double>>>t;
double ans[17],tt;
void msk(vector<pair<int,double>> r,int d,int i)
{
    if(i==d)
    {
        t.push_back(m);
        return ;
    }
    m.push_back({r[i].F,r[i].S*r[i+1].S*a[r[i].F][r[i+1].F]/100.0});
    msk(r,d,i+2);
    m.pop_back();
    m.push_back({r[i+1].F,r[i].S*r[i+1].S*a[r[i+1].F][r[i].F]/100.0});
    msk(r,d,i+2);
    m.pop_back();
}
vector<vector<pair<int,double>>> go(vector<pair<int,double>> r,int d)
{
    t.clear();
    msk(r,d,0);
    return t;
}
void get(vector<pair<int,double>> r,int d)
{
    if(d==1)
    {
        ans[r[0].F]+=r[0].S;
        return;
    }
    vector<vector<pair<int,double>>> v =go(r,d);
    for(auto w:v)
       get(w,d/2);
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
//input;

for(int i=0;i<16;i++)
    cin>>s[i];
for(int i=0;i<16;i++)
    for(int j=0;j<16;j++)
        cin>>a[i][j];



vector<pair<int,double> >ff;
for(int i=0;i<16;i++) ff.push_back({i,1.0});

get(ff,16);

for(int i=0;i<16;i++)
{
   cout<<s[i];
   for(int j=0;j<=10-s[i].size();j++)cout<<" ";
   printf("p=%.2f%\n",ans[i]*100.00);
}

return 0;
}
