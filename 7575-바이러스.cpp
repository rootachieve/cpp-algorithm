#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <math.h>

#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
int pi[1001][1001];
int n, k;
int len[202];
int in[202][1002];
void kmp(int a) {
	int i = -1;
	int j = 0;
	pi[a][j] = -1;
	while (j < k) {
		if (i == -1 || in[0][a + j] == in[0][i]) {
			pi[a][++j] = ++i;
		}
		else {
			i = pi[a][i];
		}
	}
}

int main() {
	scanf("%d%d", &n, &k);
	int Min = 1001;
	int l, a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &l);
		len[i * 2] = l;
		len[i * 2 + 1] = l;
		Min = min(Min,l);
		for (int j = 0; j < l; j++) {
			scanf("%d", &a);
			in[i * 2][j] = a;
			in[i * 2 + 1][l - 1 - j] = a;
		}
	}


	if (Min < k) {
		printf("NO");
	}else{
		for (int i = 0; in[0][i + k - 1] != 0; i++) {
			kmp(i);
		}
		bool ansFind = false;

		for (int i = 0; pi[i][0] == -1; i++) {
			bool err = false;
			for (int j = 2; j <= 2 * n; j++) {
				int g = 0;
				int h = 0;

				bool Find = false;
				while (g < len[j]) {
					if (h == -1 || in[j][g] == in[0][i + h]) {
						g++;
						h++;
					}
					else {
						h = pi[i][h];
					}

					if (h == k) {
						Find = true;
						if (j % 2 == 0) {
							j++;
						}
						break;
					}
				}
				if (!Find && j % 2 == 1) {
					err = true;
					break;
				}
			}

			if (!err) {
				printf("YES");
				ansFind = true;
				break;
			}
		}
		
		if (!ansFind) {
			printf("NO");
		}
	}
}
