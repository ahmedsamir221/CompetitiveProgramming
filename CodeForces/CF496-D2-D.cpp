//https://codeforces.com/blog/entry/15208
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
int n,a[100010],b[100010],x;
vector<pair<int,int>>ans;
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
input;
cin>>n;
forr(i,1,n)
{
    cin>>x;
    if(x==1)a[i]=1;
    else b[i]=1;
    a[i]+=a[i-1];
    b[i]+=b[i-1];
}

forr(t,1,n)
{
   int ca=0,cb=0;
   int i=0,ck;
   while(i<n)
   {
      auto A=lower_bound(a+1,a+1+n,a[i]+t);
      auto B=lower_bound(b+1,b+1+n,b[i]+t);
      int idxa=A-a;
      int idxb=B-b;
      if(idxa<idxb)i=idxa,ca++,ck=1;
      else i=idxb,cb++,ck=-1;
      if(i==n&&((ca>cb&&ck==1)||(cb>ca&&ck==-1)))ans.push_back({max(ca,cb),t});
   }
}

sort(ans.begin(),ans.end());
cout<<(int)ans.size()<<endl;
for(auto p:ans)cout<<p.F<<" "<<p.S<<endl;

return 0;
}
