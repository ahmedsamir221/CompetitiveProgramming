/*
   we can represent the student as a nodes in graph and  between any two troublemaker there are an edge .
   every time we will take the node with max degree and move it to the second class then will decrease all it's
   neighbours degree by one .
   we will do that until we have half of students in second class or all the degrees of all remaining students = 0  .
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
int n,m,u,v,d[110],cas;
vector<int>a[110];
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
//input;
int t;
cin>>t;
while(t--)
{
    cin>>n>>m;
    forr(i,1,n)
    {
        a[i].clear();
        d[i]=0;
    }
    forr(i,1,m)
    {
        cin>>u>>v;
        d[u]++;
        d[v]++;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    set<pair<int,int>>s;
    vector<int>ans;
    forr(i,1,n)
        s.insert({-d[i],i});
    forr(i,1,n/2)
    {
        if(s.size()==0)break;
        auto p=*s.begin();
        d[p.S]=0;
        s.erase(s.begin());
        ans.push_back(p.S);
        for(auto k:a[p.S])
        {
            if(!d[k])continue;
            auto it=s.lower_bound({-d[k],k});
            s.erase(it);
            d[k]--;
            if(d[k]) s.insert({-d[k],k});
        }
    }
    printf("Case #%d: %d\n",++cas,(int)ans.size());
    for(int i=0;i<(int)ans.size()-1;i++)cout<<ans[i]<<" ";
    cout<<ans[(int)ans.size()-1]<<endl;
}


return 0;
}
