/*
    to get the median we will use two priority queue , one with max heap and the other with min heap .
    each time we calculate the value of F[i] will push it in one of them in such way to keep the difference
    between the size of them at most 1 and also all values of first one less than all values of the second .
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
int t;
ll a,b,c,n,m=1e9+7;
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
cin>>t;
while(t--)
{
    cin>>a>>b>>c>>n;
    priority_queue<ll>x;
    priority_queue<ll,vector<ll>,greater<ll>>y;
    ll sum=1;
    x.push(1);
    for(ll i=2;i<=n;i++)
    {
         ll g=x.top();
         ll p=(a*g+b*i+c)%m;
         sum+=p;
         if(i%2==0)
         {
             if(x.top()>p)
             {
                 y.push(x.top());
                 x.pop();
                 x.push(p);
             }
             else
                y.push(p);
         }
         else
         {
             if(y.top()<p)
             {
                 x.push(y.top());
                 y.pop();
                 y.push(p);
             }
             else
                x.push(p);
         }
    }
    cout<<sum<<endl;
}



return 0;
}
