#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

struct info {
	int y;
	int x;

	info(int a, int b) {
		y =a;
		x = b;
	}
};
int map[52][52];
int visit[52][52];

int c[2][4] = {{1, -1 , 0, 0},{0,0,1,-1}};
int main() {
	int t;
	cin>>t;
	queue<info> q;
	while (t--) {
		int ans = 0;
		int n, m, k;
		cin>>n>>m>>k;
		
		int a,b;
		for (int i = 1; i <= k; i++) {
			cin>>a>>b;
			map[a+1][b+1] = 1;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 1&&visit[i][j] == 0) {
					visit[i][j] = 1;
					q.push(info(i,j));
					ans++;
					while (!q.empty()) {
						info f = q.front();
						q.pop();

						for(int i = 0 ;i<4;i++){
							if (map[f.y + c[0][i]][f.x + c[1][i]]== 1 && visit[f.y + c[0][i]][f.x + c[1][i]] == 0) {

								visit[f.y + c[0][i]][f.x + c[1][i]] = 1;

								q.push(info(f.y + c[0][i],f.x + c[1][i]));
							}
						}
					}
				}

				visit[i][j] = 0;
				map[i][j] = 0;
			}
		}

		printf("%d\n",ans);
	}
}