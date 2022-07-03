#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#define MAX 1000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

bool map[10002][502];
int base[10002][502];
char temp[502];
int n,m;
stack<pair<int,int>> s;
int ans;
bool Find;
void dfs(int r,int c){
	if (c == m) {
		Find = true;
		ans++;
	}
	else {
		if (map[r - 1][c + 1] == 0 && base[r - 1][c + 1] == 1) {
			map[r-1][c+1] = 1;
			dfs(r-1,c+1);
			if (Find) {
				return;
			}
		}
		
		if (map[r][c + 1] == 0 && base[r][c + 1] == 1) {
			map[r][c+1] = 1;
			dfs(r, c + 1);
			if (Find) {
				return;
			}
		}
	
		if (map[r + 1][c + 1] == 0 && base[r + 1][c + 1] == 1) {
			map[r + 1][c+1] = 1;
			dfs(r + 1, c + 1);
			if (Find) {
				return;
			}
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &temp);
		for (int j = 1; j <= m; j++) {
			if (temp[j - 1] == '.') {
				base[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		Find = false;
		if (base[i][1] == 1) {
			dfs(i,1);
		}
	}
	printf("%d",ans);
}