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
int n;
vector<pair<int,int>> v[102];
bool visit[102];
vector<pair<int,int>> in;

void BFS() {
	queue<int> q;

	q.push(0);
	visit[0] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (int i = 0; i < v[front].size(); i++) {
			if (!visit[v[front][i].first]&&v[front][i].second <= 1000) {
				q.push(v[front][i].first);
				visit[v[front][i].first] = true;
			}
		}
	}
}
int main() {
	int t;
	int a,b;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		in.clear();
		for (int i = 0; i <= n + 1; i++) {
			v[i].clear();
			visit[i] = false;
			scanf("%d%d",&a,&b);
			in.push_back({a,b});
			for (int j = 0; j < i; j++) {
				int temp = abs(in[j].first-a) + abs(in[j].second - b);
				v[j].push_back({i,temp});
				v[i].push_back({j,temp});
			}
		}

		BFS();
		if (visit[n + 1]) {
			printf("happy\n");
		}
		else {
			printf("sad\n");
		}

	}
}