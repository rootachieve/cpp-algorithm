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
#include <bitset>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int map[2002][2002];
bool visit[2002][2002];
int parent[100001];
int Rank[100001];

int base[2][4] = {{0,0,-1,1},{1,-1,0,0}};
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

	if (a == b) {
		return;
	}
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
queue<pair<int,int>>q;
queue <pair<int,pair<int, int>>>tempQ;
int main() {
	int n,m;
	int a,b;
	cin>>n>>m;
	int y, x, num, t;
	int nexY, nexX;
	int Cnt = m;
	for (int i = 1; i <= m; i++) {
		parent[i] = i;
		Rank[i] = 1;
		cin>>a>>b;
		map[b][a] = i;
		q.push({b,a});
	}
	int ans = 0;
	bool Find = false;
	while(1){
		while (!q.empty()) {
			y = q.front().first;
			x = q.front().second;
			num = map[y][x];
			q.pop();

			for (int i = 0; i < 4; i++) {
				nexY = y + base[0][i];
				nexX = x + base[1][i];

				if (nexY <= n && nexY >= 1 && nexX <= n && nexX >= 1) {
					if (map[nexY][nexX] == 0) {
						if(!visit[nexY][nexX]){
							visit[nexY][nexX] = true;
							tempQ.push({num,{nexY,nexX}});
						}
					}
					else {
						if (find(map[nexY][nexX]) != find(num)) {
							merge(map[nexY][nexX],num);
							Cnt--;
							if (Cnt == 1) {
								Find = true;
							}
						}

					}
				}
			}

			if (Find) {
				break;
			}
		}
		if(Find){
			break;
		}
		ans++;
		while (!tempQ.empty()) {
			y = tempQ.front().second.first;
			x = tempQ.front().second.second;
			num = find(tempQ.front().first);
			tempQ.pop();
			q.push({y,x});
			map[y][x] = num;
		}
	}

	cout<<ans;
}