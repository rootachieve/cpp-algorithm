#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<map>
#include <stack>
#define MOD(x,y,z) (((x)%z)+((y)%z))%z
#define MODF(x,y,z) (((x)%z)*((y)%z))%z
using namespace std;
vector<int> v[2002];
int n,m;
int id = 0;
int nodeId[2002];
vector<vector<int>> SCC;
bool fin[2002];
stack<int> s;
int dfs(int node) {
	nodeId[node] = ++id;
	int Min = nodeId[node];
	s.push(node);
	for (int i = 0; i < v[node].size(); i++) {
		if (nodeId[v[node][i]]==0) {
			Min = min(Min,dfs(v[node][i]));
		}
		else if (!fin[v[node][i]]) {
			Min = min(Min,nodeId[v[node][i]]);
		}
	}

	if (Min == nodeId[node]) {
		vector<int> scc;
		while(1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			fin[t] = true;
			if (t == node) {
				break;
			}
		}

		sort(scc.begin(),scc.end());
		SCC.push_back(scc);
	}
	return Min;
}
int main() {
	int a,b;
	int t1,t2,t3,t4;//t1 t3 : false t2,t4 = true;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= 2*n; i++) {
			v[i].clear();
			nodeId[i] = 0;
			fin[i] = false;
		}
		id = 0;
		SCC.clear();

		v[1].push_back(2);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d",&a,&b);
			t1 = abs(a)*2-1;//not
			t2 = abs(a)*2;
			t3 = abs(b)*2-1;//not
			t4 = abs(b)*2;
			if (a > 0 && b > 0) {
				v[t1].push_back(t4);
				v[t3].push_back(t2);
			}
			else if (a > 0 && b < 0) {
				v[t1].push_back(t3);
				v[t4].push_back(t2);
			}
			else if (a < 0 && b >0) {
				v[t3].push_back(t1);
				v[t2].push_back(t4);
			}
			else {
				v[t2].push_back(t3);
				v[t4].push_back(t1);
			}
		}

		for (int i = 1; i <= 2 * n; i++) {
			if (nodeId[i] == 0) {
				dfs(i);
			}
		}
		bool err =false;
		int c,d;
		for (int i = 0; i < SCC.size(); i++) {
			for (int j = 0; j < SCC[i].size() - 1; j++){
				c = (SCC[i][j] %2 == 0 ? SCC[i][j]/2 : (SCC[i][j]+1)/2);
				d = (SCC[i][j+1]%2==0 ? SCC[i][j+1] / 2 : (SCC[i][j+1] + 1) / 2);
				if (c == d) {
					err = true;
					break;
				}
			}
			if (err) {
				break;
			}
		}

		if (err) {
			printf("no\n");
		}
		else {
			printf("yes\n");
		}
	};
}