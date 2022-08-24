#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <string>
#include <unordered_set>
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
int n,m;
int c[103][103];
int f[103][103];
int parent[103];

queue<int> temp;
int flow(int source, int sink) {
	int answer = 0;

	while (true) {
		for (int i = 1; i <= sink; i++) {
			parent[i] = -1;
		}
		queue<int> q;
		parent[source] = source;
		q.push(source);
		int node;
		while (!q.empty() && parent[sink] == -1) {
			node = q.front();
			q.pop();
			
			for (int i = 1; i <= sink; i++) {
				if (c[node][i] - f[node][i] > 0 && parent[i] == -1) {
					q.push(i);
					parent[i] = node;
				}
			}
		}

		if (parent[sink] == -1) {
			break;
		}

		for (int i = sink; i != source; i = parent[i]) {
			f[parent[i]][i] ++;
			f[i][parent[i]] --;
		}

		answer++;
	}
	return answer;
}

void find(int s, int e) {

	for (int i = 1; i <= n + m; i++) {
		parent[i] = -1;
	}
	parent[s] = s;
	temp.push(s);
	int node;
	while (!temp.empty()&&parent[e]==-1) {
		node = temp.front();
		temp.pop();
		if (node <= n) {
			for (int i = n+1; i <= n + m; i++) {
				if (node == s && i == e) {
					continue;
				}
				if (c[node][i] - f[node][i] > 0 && parent[i] == -1) {
					temp.push(i);
					parent[i] = node;
					if (i == e) {
						break;
					}
				}
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (c[node][i] - f[node][i] > 0 && parent[i] == -1) {
					temp.push(i);
					parent[i] = node;
				}
			}
		}
		
	}
	while (!temp.empty()) {
		temp.pop();
	}

	if (parent[e] == -1) {
		return;
	}
	else {
		f[s][e]--;
		f[e][s]++;
		c[s][e] = 0;

		for (int i = e; i != s; i = parent[i]) {
			f[parent[i]][i]++;
			f[i][parent[i]]--;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	int a;
	int asum = 0;
	int bsum = 0;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		asum+=a;
		for (int j = 1; j <= m; j++) {
			c[i][n+j] = 1;
		}
		c[n+m+1][i] = a;
	}
	for (int i = 1; i <= m; i++) {
		cin >>a;
		bsum+=a;
		c[n+i][n + m + 2] = a;
	}
	if (asum != bsum) {
		cout<<-1<<"\n";
	}
	else {
		if (flow(n + m + 1, n + m + 2) != bsum) {
			cout << -1 << "\n";
		}
		else {
			
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (f[i][n + j] == 1) {
						find(i, n + j);
					}
					else {
						c[i][n+j] = 0;
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					cout<<f[i][n+j];
				}
				cout<<"\n";
			}
		}
	}
}