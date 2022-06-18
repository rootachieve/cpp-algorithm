#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 1000001
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int map[101][101];

int main() {
	int locX = 5000;
	int locY = 5000;
	int Count = 1;

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a+=5000;
	b+=5000;
	c+=5000;
	d+=5000;
	if(a<=locY&&locY<=c&&b<=locX&&locX<=d){
		map[locY-a][locX-b] = 1;
	}
	for (int i = 1; i <= 5000; i++) {
		locX++;
		++Count;
		if (a <= locY && locY <= c && b <= locX && locX <= d) {
			map[locY - a][locX - b] = Count;
		}
		for(int j = 1,  num = 2 * i - 1; j <= num; j++){
			--locY;
			++Count;
			if (a <= locY && locY <= c && b <= locX && locX <= d) {
				map[locY - a][locX - b] = Count;
			}
		}
		--locX;
		++Count;

		if (a <= locY && locY <= c && b <= locX && locX <= d) {
			map[locY - a][locX - b] = Count;
		}
		for (int j = 1,  num = 2 * i - 1; j <= num; j++) {
			--locX;
			++Count;
			if (a <= locY && locY <= c && b <= locX && locX <= d) {
				map[locY - a][locX - b] = Count;
			}
		}
		++locY;
		++Count;
		if (a <= locY && locY <= c && b <= locX && locX <= d) {
			map[locY - a][locX - b] = Count;
		}
		for (int j = 1,  num = 2 * i - 1; j <= num; j++) {
			++locY;
			++Count;
			if (a <= locY && locY <= c && b <= locX && locX <= d) {
				map[locY - a][locX - b] = Count;
			}
		}
		++locX;
		++Count;
		if (a <= locY && locY <= c && b <= locX && locX <= d) {
			map[locY - a][locX - b] = Count;
		}
		for (int j = 1, num = 2*i-1; j <= num; j++) {
			++locX;
			++Count;
			if (a <= locY && locY <= c && b <= locX && locX <= d) {
				map[locY - a][locX - b] = Count;
			}
		}
	}

	string temp;
	int Max = 0;
	for (int i = 0; i <= c-a; i++) {
		for (int j = 0; j <= d-b; j++) {
			Max = max(Max,map[i][j]);
		}
	}
	temp = to_string(Max);
	int l = temp.size();

	for (int i = 0; i <= c - a; i++) {
		for (int j = 0; j <= d - b; j++) {
			for (int k = l - to_string(map[i][j]).size(); k >= 1; k--) {
				printf(" ");
			}
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
}