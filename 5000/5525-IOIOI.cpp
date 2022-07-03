#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
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
int Count = 1;
char base[2000005];
char in[2000005];
int N,M;
int ans = 0;

int main() {
	scanf("%d", &N);
	base[0] = 'I';
	base[1] = 'O';
	base[2] = 'I';
	for (int i = 2; i <= N; i++) {
		base[2 * i - 1] = 'O';
		base[2 * i] = 'I';
	}
	scanf("%d", &M);
	scanf("%s", &in);
	bool y = false;
	for (int i = 0; in[i] != NULL;i++) {
		if (y) {
			if (in[i] == 'O' && in[i + 1] == 'I') {
				ans++;
				i++;
			}
			else {
				y = false;
				i--;
			}
		}
		else {
			int j;
			bool err = false;
			for (j = 0; base[j] != NULL; j++) {
				if (in[i + j] == NULL ||base[j] != in[i + j]) {
					err = true;
					break;
				}
			}

			if (err) {
				i +=j;
				if (j != 0) {
				 i--;
				}
			}
			else {
				i+=j-1;
				y = true;
				ans++;
			}
		}
		
	}
    printf("%d",ans);
}