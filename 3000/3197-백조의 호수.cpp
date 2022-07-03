#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
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

int parent[3000000];
int Rank[3000000];
struct loc {
	int x;
	int y;

	loc(int a, int b) {
		x = b;
		y = a;
	}
};
queue<loc> q;
int map[1502][1502];
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
	if(a==b) return;

	if (Rank[a] > Rank[b]) {
		parent[b] = a;
		Rank[a] += Rank[b];
	}
	else {
		parent[a] = b;
		Rank[b] += Rank[a];
	}
}
int X1,X2,Y1,Y2;
int dir[2][4] = {{0,0,-1,1},{-1,1,0,0}};
int n,m;
void check(int y, int x,int value) {
	for (int i = 0; i <= 3; i++) {
		if (map[y + dir[0][i]][x + dir[1][i]]!=0 && map[y + dir[0][i]][x + dir[1][i]] <= value) {
			merge((y-1)*m+x, (y + dir[0][i]-1)*m + x + dir[1][i]);
		}
	}
}

bool isMeet() {
	return find((Y1 - 1) * m + X1) == find((Y2 - 1) * m + X2);
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n*m; i++) {
		parent[i] = i;
		Rank[i] = 1;
	}
	string temp;
	bool f = false;
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		for (int j = 1; j <= m; j++) {
			if (temp[j - 1] == '.') {
				map[i][j] = 1;
				q.push(loc(i,j));
			}
			else if (temp[j - 1] == 'L') {
				map[i][j] = 1;
				q.push(loc(i, j));
				if (f) {
					X2 = j;
					Y2 = i;
				}
				else {
					f = true;
					X1 = j;
					Y1 = i;
				}
			}
		}
	}
	if (isMeet()) {
		printf("0");
	}else{
		int y,x;
		while (!q.empty()) {
			y = q.front().y;
			x = q.front().x;
			check(y,x,map[y][x]);
			if (isMeet()) {
				break;
			}
			q.pop();
			for (int i = 0; i <= 3; i++) {
				if (map[y + dir[0][i]][x + dir[1][i]] == 0&& y + dir[0][i]>0&& y + dir[0][i]<=n&& x + dir[1][i]<=m&& x + dir[1][i]>0) {
					map[y + dir[0][i]][x + dir[1][i]] = map[y][x]+1;
					q.push(loc(y + dir[0][i], x + dir[1][i]));
				}
			}
		}

		printf("%d",map[y][x]-1);
	}
}