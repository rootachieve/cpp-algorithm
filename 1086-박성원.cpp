#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#define MOD(x,y,z) (((x)%z)+((y)%z))%z
#define MODF(x,y,z) (((x)%z)*((y)%z))%z
using namespace std;

long long bits[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384, 32768};
long long check[2][16];
long long DP[1<<16][100];
queue<pair<long long,long long>> q;
int n;
char temp[16][52];
long long k;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b,a%b);
	}
}
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%s",&temp[i]);
	}
	scanf("%lld",&k);
	for (int i = 0; i < n; i++) {
		int sum = 0;
		int Count  = 1;
		for (int j = 0; temp[i][j] != NULL; j++) {
			Count = ((Count%k)*(10%k))%k;
			sum = MOD((sum*10),(temp[i][j]-48),k);
		}
		check[0][i] = Count%k;
		check[1][i] = sum%k;
		DP[bits[i]][sum%k] = 1;
		q.push({bits[i],sum % k});
	}
	printf("");
	while (!q.empty()) {
		long long value = q.front().second;
		long long loc = q.front().first;
		long long temp2=0;
		q.pop();
		for (int i = 0; i < n; i++) {
			if ((loc & bits[i]) == 0) {
				temp2 = ((((value%k)*(check[0][i])) % k) + ((check[1][i]) % k)) % k;
				if (DP[(loc | bits[i])][temp2] == 0LL) {
					q.push({(loc| bits[i]),temp2 });
				}
				DP[(loc | bits[i])][temp2] += DP[loc][value];
			}
		}
	}
	long long bot = 0;
	for (int i = 0; i <k; i++) {
		bot+=DP[bits[n - 1] * 2 - 1][i];
	}
	long long top = DP[bits[n - 1] * 2 - 1][0];
	if (top == 0) {
		printf("0/1");
	}
	else if (bot == top) {
		printf("1/1");
	}
	else {
		long long d = gcd(bot, top);
		printf("%lld/%lld",top/d,bot/d);
	}

}