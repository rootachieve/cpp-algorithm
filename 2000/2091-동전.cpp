#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <string>
#include <unordered_set>
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

int main() {
	int num,a,b,c,d;
	cin>>num>>a>>b>>c>>d;
	int ans[4];
	int ansCnt = 0;
	int answer[4] = {0,0,0,0};
	for (int i = 0; i <= d; i++) {
		if (i * 25 <= num) {
			for (int j = 0; j <= c; j++) {
				if (j * 10 + i * 25 <= num) {
					ans[3] = i;
					ans[2] = j;
					int temp = num - j*10 - i*25;
					ans[1] = min(temp/5,b);
					temp-=ans[1]*5;
					ans[0] = min(temp,a);
					temp-=ans[0];

					if (temp > 0) {
						continue;
					}
					int temp2 = min((a - ans[0])/5,ans[1]);
					ans[1] -= temp2;
					ans[0] +=temp2*5;
					if (ans[1] + ans[2] + ans[3] + ans[0] > ansCnt) {
						ansCnt = ans[1] + ans[2] + ans[3] + ans[0];
						for(int k = 0;k<=3;k++){
							answer[k] = ans[k];
						}
					}
				}
				else {
					break;
				}
			}
		}
		else {
			break;
		}
	}

	printf("%d %d %d %d", answer[0], answer[1], answer[2], answer[3]);
}