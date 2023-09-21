#include<bits/stdc++.h>
using namespace std;

const int N = 200001;

int _rank[N];
int par[N];

int find(int a){
	if(par[a] == -1) return a;

	return par[a] = find(par[a]);
}

int merge(int a , int b){

	a = find(a);
	b = find(b);

	if(_rank[a] < _rank[b]) swap(a , b);

	par[b] = a;
	_rank[a] += _rank[b];

	return _rank[a];
}

int main()
{
	int n , a , b , m;

	cin>>n>>m;
	for(int i=1;i<=n;i++) _rank[i] = 1 , par[i] = -1;

	int cc = n;
	int mx = 1;

	while(m--){
		cin>>a>>b;

		if(find(a) != find(b)) mx = max(mx , merge(a , b)) , cc--;

		cout<<cc<<" "<<mx<<endl;
	}
}
