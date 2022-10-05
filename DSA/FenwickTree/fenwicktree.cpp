// problem Link :- https://cses.fi/problemset/task/1648/
#include<bits/stdc++.h>
using namespace std;


struct FenwickTree{
	int siz;
	vector<long long>tr;

	void init(int n){
		siz = n;
		tr.assign(siz, 0ll);
	}

	void update(int idx, int val){
		while(idx <= siz){
			tr[idx] += val;
			idx += (idx&-idx);
		}
	}

	long long query(int idx){
		long long ans=0;
		while(idx > 0){
			ans += tr[idx];
			idx -= (idx&-idx);
		}
		return ans;
	}
	long long query(int l, int r){
		return query(r)-query(l-1);
	}
};


int32_t main(){
	int n,q; cin>>n>>q;
	vector<int>v(n+1);
	FenwickTree tr;
	tr.init(n);
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		tr.update(i, x-v[i]);
		v[i]=x;
	}
	while(q--){
		int type; cin>>type;
		if(type == 1){
			int idx, val; cin>>idx>>val;
			tr.update(idx, val-v[idx]);
			v[idx] = val;
		}
		else{
			int l, r; cin>>l>>r;
			cout<<tr.query(l,r)<<endl;
		}
	}
}
