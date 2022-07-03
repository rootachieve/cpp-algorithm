#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<map>
#include <stack>
#define DIV 1000000007
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 500002
using namespace std;

int tree[800000];
int laze[800000];
int loc[100001];
int Count;
int n,m;
void init(int s, int e, int node) {
	if (s == e) {
		if(s<n){
			tree[node] = n-s;
		}
		return;
	}
	int mid = (s+e)/2;
	init(s,mid,node*2);
	init(mid+1,e,node*2+1);
	return;
}

void Add(int s, int e, int node, int l, int r,int data) {
	if (l > e || r < s) {
		return;
	}

	if (l <= s && e <= r) {
		
		if (s==e) {
			tree[node]+=data;
		}
		else {
			laze[node] += data;
		}
		return;
	}

	int mid = (s+e)/2;

	Add(s,mid,node*2,l,r,data);
	Add(mid + 1,e , node * 2+1, l, r, data);

}

int find(int s, int e, int node,int target) {
	if (s == e) {
		int temp = tree[node];
		tree[node] = 0;
		temp+=laze[node];
		laze[node]=0;
		return temp;
	}
	
	if (laze[node] != 0) {
		laze[node*2] +=laze[node];
		laze[node*2+1] +=laze[node];
		laze[node] = 0;
	}

	int mid = (s+e)/2;
	if (target <= mid) {
		return find(s,mid,node*2,target);
	}
	else {
		return find(mid+1,e, node * 2+1, target);
	}


}
int main() {
	int t;
	int a;
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d", &n, &m);
		Count = n;
		
		for (int i = 1; i <= (n + m) * 4; i++) {
			tree[i] = 0;
			laze[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			loc[i] = n-i+1;
		}
		init(1, n+m, 1);
		for (int i = 1; i <= m; i++) {
			scanf("%d",&a);
			printf("%d ",find(1, n + m,1,loc[a]));
			Add(1, n + m,1,loc[a]+1,Count,1);
			loc[a] = ++Count;
		}
		printf("\n");
	}
}