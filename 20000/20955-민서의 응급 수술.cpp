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
int parent[100001];
int Rank[100001];
int n,m;
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

	if(Rank[a]>Rank[b]){
		parent[b] = a;
		Rank[a]+=Rank[b];
		Rank[b] = 0;
	}
	else {
		parent[a] = b;
		Rank[b] += Rank[a];
		Rank[a] = 0;
	}
}

int main() {
	int a,b;
	int ans = 0;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		Rank[i] = 1;
	}
	for(int i = 1;i<=m;i++){
		scanf("%d%d", &a, &b);
		if (find(a) == find(b)) {
			ans++;
		}
		else {
			merge(a,b);
		}
	}
	
	int Count = 0;
	for (int i = 1; i <= n; i++) {
		if (Rank[i] > 0) {
			Count++;
		}
	}
	ans+=max(0,Count-1);
	printf("%d",ans);
}