#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <cstring>
#define MOD 1000000
#define MODUL(x,y) (((y)%MOD) + ((x)%MOD))%MOD
#define MODULF(x,y) (((y)%MOD) * ((x)%MOD))%MOD
using namespace std;
char arr[5003];
long long dp[5003];
int main() {
	scanf("%s",&arr);
	int len = strlen(arr);
	dp[len] = 1;
	for (int i = len - 1; i >= 0; i--) {
		if ((arr[i] == '1')&&arr[i+1]!=NULL) {
			dp[i] = MODUL(dp[i+2],dp[i]);
		}
		else if ((arr[i] == '2') && (arr[i + 1] <= '6') && arr[i + 1] != NULL) {
			dp[i] = MODUL(dp[i + 2], dp[i]);
		}
		if(arr[i]!='0'){
			dp[i] = MODUL(dp[i + 1], dp[i]);
		}
	}

	printf("%lld",dp[0]%MOD);

}