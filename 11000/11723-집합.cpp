#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_map>
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

bool s[21];
char in[7];
int n;
int main() {
	int num;
	scanf("%d",&n);

	while (n--) {
		scanf("%s",&in);
		switch (in[0]) {
			case 'a':
				if (in[1] == 'd') {
					scanf("%d",&num);
					s[num] = true;
				}
				else {
					for (int i = 1; i <= 20; i++) {
						s[i] = true;
					}
				}
			break;
			case 'r':
				scanf("%d",&num);
				s[num] = false;
			break;

			case 'c':
				scanf("%d",&num);
				s[num] ? printf("1\n") : printf("0\n");
			break;

			case 't':
				scanf("%d",&num);
				s[num] ? s[num] = false : s[num] = true;
			break;

			case 'e':
				for (int i = 1; i <= 20; i++) {
					s[i] = false;
				}
			break;

		}
	}
}