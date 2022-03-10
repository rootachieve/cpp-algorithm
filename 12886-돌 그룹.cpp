#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int dp[501][501][501];
typedef struct stone{
	
	int ar[3];
	stone(int A,int B,int C){
		ar[0] = A;
		ar[1] = B;
		ar[2] = C;
		sort(ar,ar+3);
	}
};
queue<stone> q;
int main() {
	int arr[3];
	scanf("%d%d%d",&arr[0],&arr[1],&arr[2]);
	sort(arr,arr+3);
	dp[arr[0]][arr[1]][arr[2]] = 1;
	bool Find = false;
	q.push(stone(arr[0],arr[1],arr[2]));
	while (!q.empty()) {
			
		arr[0] = q.front().ar[0];
		arr[1] = q.front().ar[1];
		arr[2] = q.front().ar[2];
		q.pop();
		if (arr[0] == arr[1] && arr[1] == arr[2]) {
			Find = true;
			break;
		}
		if (arr[0] != arr[1]) {
			stone s = stone(arr[0]+arr[0],arr[1]-arr[0],arr[2]);
			if (dp[s.ar[0]][s.ar[1]][s.ar[2]] == 0) {
				dp[s.ar[0]][s.ar[1]][s.ar[2]] = 1;
				q.push(s);
			}
		}

		if (arr[0] != arr[2]) {
			stone s = stone(arr[0] + arr[0], arr[1], arr[2] - arr[0]);
			if (dp[s.ar[0]][s.ar[1]][s.ar[2]] == 0) {
				dp[s.ar[0]][s.ar[1]][s.ar[2]] = 1;
				q.push(s);
			}
		}

		if (arr[1] != arr[2]) {
			stone s = stone(arr[0], arr[1] + arr[1], arr[2] - arr[1]);
			if (dp[s.ar[0]][s.ar[1]][s.ar[2]] == 0) {
				dp[s.ar[0]][s.ar[1]][s.ar[2]] = 1;
				q.push(s);
			}
		}
	
	}
	if (Find) {
		printf("1");
	}
	else {
		printf("0");
	}
}