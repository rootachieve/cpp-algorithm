#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include<cmath>
#include<cstring>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 2000000001;
#define RESET 0
using namespace std;
int n,q;
int pInfo[200002];
int parent[200002];
int Rank[200002];
int find(int x) {
	if (parent[x] == x) {
		return x;
	}

	int y = find(parent[x]);
	parent[x] = y;
	return y;
}

void merge(int x, int y) {
	int a = find(x);
	int b = find(y);

	if (Rank[a] > Rank[b]) {
		parent[b] = a;
		Rank[a] += Rank[b];
		Rank[b] = 0;
	}
	else {
		parent[a] = b;
		Rank[b] += Rank[a];
		Rank[a] = 0;
	}
}
struct query {
	int type;
	int node1;
	int node2;

	query(int a, int b, int c) {
		type = a;
		node1 = b;
		node2 = c;
	}
};
vector<query> v;


int main() {
	scanf("%d%d",&n,&q);
	int num;
	int a,b;
	for (int i = 2; i <= n; i++) {
		scanf("%d",&pInfo[i]);
		parent[i] = i;
		Rank[i] = 1;
	}
	parent[1] = 1;
	Rank[1] = 1;

	for (int i = 1; i < q + n; i++) {
		scanf("%d",&num);
		if (num == 0) {
			scanf("%d",&a);
			v.push_back(query(num,a,0));
		}
		else {
			scanf("%d%d",&a,&b);
			v.push_back(query(num,a,b));
		}
	}
	stack<int> ans;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i].type == 0) {
			if (find(v[i].node1) != find(pInfo[v[i].node1])) {
				merge(v[i].node1, pInfo[v[i].node1]);
			}
		}
		else {
			if (find(v[i].node1) != find(v[i].node2)) {
				ans.push(0);
			}
			else {
				ans.push(1);
			}
		}
	}

	while (!ans.empty()) {
		if (ans.top() == 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		ans.pop();
	}
}