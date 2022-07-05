#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int tree[4000001];
int base[1000001];
void init(int s, int e, int node) {
	if (s == e) {
		tree[node] =base[s];
		return;
	}

	int m = (s+e)/2;

	init(s,m,node*2);
	init(m+1,e,node*2+1);
	tree[node] = max(tree[node*2],tree[node*2+1]);
}


int check(int s, int e,int l,int r, int node) {
	

	if (e < l || r < s) {
		return 0;
	}

	if (l <= s && e <= r) {
		return tree[node];
	}

	int m = (s+e)/2;
	
	return max(check(s,m,l,r,node*2),check(m+1,e,l,r,node*2+1));
}
int main() {
	int n,m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		cin>>base[i];
	}

	init(1,n,1);
	int end = n-(2*(m-1));
	for (int i = 1; i <= end; i++) {
		printf("%d ",check(1,n,i,2*(m-1)+i,1));
	}
}