#include<bits/stdc++.h>
using namespace std;string t;main(){getline(cin,t);puts(t==string(t.rbegin(),t.rend())?"palindrom":"!= palindrom");int n,a[(cin>>n,n)];for(int&v:a)cin>>v;sort(a,a+n);for(int v:a)cout<<v<<' ';}
