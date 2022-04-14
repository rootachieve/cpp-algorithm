#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 5000002
using namespace std;
vector<int> v[101];
int base[12][12];
int number[12][12];
int d[101];
bool c[101];
char arr[12];
int n,m,t;
bool dfs(int node) {
	for (int i = 0; i < v[node].size(); i++) {
		int y = v[node][i];

		if (c[y]) {
			continue;
		}

		c[y] = true;

		if (d[y] == 0 || dfs(d[y])) {
			d[y] = node;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d",&t);
	while (t--) {
		int oddCount = 0;
		int evenCount = 0;
		int Count = 0;
		int answer = 0;
		for (int i = 1; i <= 100; i++) {
			v[i].clear();
			c[i] = false;
			d[i] = 0;
		}
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; i++) {
			scanf("%s",&arr);
			for (int j = 1; j <= m; j++) {
				if (arr[j - 1] == '.') {
					base[i][j] = 1;
					Count++;
				}
				else {
					base[i][j] = 0;
				}

				number[i][j] = 0;
			}
		}

		for(int j = 1;j<=m;j+=2){
			for(int i = 1;i<=n;i++){
				number[i][j] = ++oddCount;
			}
		}
		for (int j = 2; j <= m; j += 2) {
			for (int i = 1; i <= n; i++) {
				number[i][j] = ++evenCount;
			}
		}

		for (int j = 1; j <= m; j+=2) {
			for (int i = 1; i <= n; i++) {
				if (base[i][j] == 1) {
					if (j != 1) {
						if (base[i][j - 1] == 1) {

							v[number[i][j]].push_back(number[i][j - 1]);
						}

						if (i != n) {
							if (base[i + 1][j - 1] == 1) {

								v[number[i][j]].push_back(number[i + 1][j - 1]);
							}
						}

						if (i != 1) {
							if (base[i - 1][j - 1] == 1) {
	
								v[number[i][j]].push_back(number[i - 1][j - 1]);
							}
						}
					}

					if (j != m) {
						if (base[i][j + 1] == 1) {

							v[number[i][j]].push_back(number[i][j + 1]);
						}

						if (i != n) {
							if (base[i + 1][j + 1] == 1) {

								v[number[i][j]].push_back(number[i + 1][j + 1]);
							}
						}

						if (i != 1) {
							if (base[i - 1][j + 1] == 1) {

								v[number[i][j]].push_back(number[i - 1][j + 1]);
							}
						}
					}
				}
			}
		}

		for (int i = 1; i <= oddCount; i++) {
			fill(c,c+oddCount,false);
			if(dfs(i))answer++;
		}
		printf("%d\n",Count-answer);
	}
}
