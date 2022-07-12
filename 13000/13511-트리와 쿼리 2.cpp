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
#include <map>
#define ll long long
#define MAX 1000001
#define MOD 100999
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
struct Info {
	int p;
	ll cost;

	Info() {
		p = 0;
		cost = 0;
	}

	Info(int a, ll b) {
		p = a;
		cost = b;
	}
};
vector<pair<int,int>> v[100001];
int depth[100001];
bool visit[100001];
Info table[18][100001];



void dfs(int node) {
	visit[node] = true;

	for (int i = 0; i < v[node].size(); i++) {
		if (!visit[v[node][i].first]) {
			table[0][v[node][i].first] = Info(node,v[node][i].second);
			depth[v[node][i].first] = depth[node] + 1;
			dfs(v[node][i].first);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int a,b,c;
	for (int i = 1; i < n; i++) {
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}

	dfs(1);

	for (int i = 1; i <= 17; i++) {
		for (int j = 1; j <= n; j++) {
			table[i][j].p = table[i-1][table[i-1][j].p].p;
			table[i][j].cost = table[i - 1][table[i - 1][j].p].cost + table[i - 1][j].cost;
		}
	}

	int k;
	int g,h;
	int count,diff;
	int l,r;
	int num = 0;
	ll sum;
	cin>>k;
	for (int i = 1; i <= k; i++) {
		cin>>a;
		if (a == 1) {
			cin>>a>>b;
			count = 0;
			sum = 0;
			g = a;
			h = b;
			if (depth[g] > depth[h]) {
				diff = depth[g] - depth[h];
				while (diff > 0) {
					if ((diff & 1) == 1) {
						sum += table[count][g].cost;
						g = table[count][g].p;
					}
					diff = diff >> 1;
					count++;
				}


			}
			else {
				diff = depth[h] - depth[g];
				while (diff > 0) {
					if ((diff & 1) == 1) {
						sum += table[count][h].cost;
						h = table[count][h].p;
					}
					diff = diff >> 1;
					count++;
				}

			}

			if (g != h) {
				for (int j = 17; j >= 0; j--) {
					if (table[j][g].p != table[j][h].p) {
						sum += table[j][g].cost;
						sum += table[j][h].cost;
						g = table[j][g].p;
						h = table[j][h].p;
					}
				}
				sum += table[0][g].cost;
				sum += table[0][h].cost;
				g = table[0][g].p;
				h = table[0][h].p;
			}

			cout << sum << "\n";
		}
		else {
			cin>>a>>b>>c;
			count = 0;
			sum = 0;
			g = a;
			h = b;
			l = 0;
			r = 0;

			num = 1;
			if (depth[g] > depth[h]) {
				diff = depth[g] - depth[h];
				while (diff > 0) {
					if ((diff & 1) == 1) {
						g = table[count][g].p;
						l += num;
					}
					diff = diff >> 1;
					num*=2;
					count++;
				}


			}
			else {
				diff = depth[h] - depth[g];
				while (diff > 0) {
					if ((diff & 1) == 1) {
						h = table[count][h].p;
						r+=num;
					}
					diff = diff >> 1;
					num*=2;
					count++;
				}

			}
			num = pow(2,17);
			if (g != h) {
				for (int j = 17; j >= 0; j--) {
					if (table[j][g].p != table[j][h].p) {
						l += num;
						r += num;
						g = table[j][g].p;
						h = table[j][h].p;
					}
					num/=2;
				}
				l ++;
				r ++;
				g = table[0][g].p;
				h = table[0][h].p;
			}

			if (l >= c-1) {
				c--;
				g = a;
				num = 1;
				count = 0;
				while (c > 0) {
					if ((c & 1) == 1) {
						g = table[count][g].p;
					}
					c=c>>1;
					count++;
				}

				cout<<g<<"\n";
			}
			else {
				c-=l;
				c--;
				r-=c;

				h = b;
				num = 1;
				count = 0;
				while (r > 0) {
					if ((r & 1) == 1) {
						h = table[count][h].p;
					}
					r = r >> 1;
					count++;
				}

				cout << h << "\n";
			}

		}
	}
}