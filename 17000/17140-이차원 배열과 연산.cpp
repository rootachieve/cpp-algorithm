#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <map>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
int arr[101][101];
map<int,int> m;
priority_queue<pair<int,int>> q;
int main() {
	int r,c,num;

	cin >> r >> c >> num;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin>>arr[i][j];
		}
	}

	int rMax = 3;
	int cMax = 3;
	int t = 0;
	while (t <= 100 && arr[r][c] != num) {
		t++;
		if (rMax >= cMax) {

			int Max = 0;
			for (int j = 1; j <= rMax; j++) {
				m.clear();
				for (int i = 1; i <= cMax; i++) {
					m[arr[j][i]]++;
				}
				int nowRMax = 0;
				
				for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
					q.push({-iter->second,-iter->first});
				}
				int index = 1;
				while (!q.empty()) {
					int Cnt = -q.top().first;
					int num = -q.top().second;
					q.pop();
					if (num != 0) {
						if (index <= 98) {
							arr[j][index++] = num;
							arr[j][index++] = Cnt;
						}
					}
					
				}

				for (int i = index; i <= cMax; i++) {
					arr[j][i] = 0;
				}

				Max = max(index-1,Max);
			}

			cMax = Max;
			
		}
		else {
			int Max = 0;
			for (int j = 1; j <= cMax; j++) {
				m.clear();
				for (int i = 1; i <= rMax; i++) {
					m[arr[i][j]]++;
				}

				for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
					q.push({ -iter->second,-iter->first });
				}
				int index = 1;
				while (!q.empty()) {
					int Cnt = -q.top().first;
					int num = -q.top().second;
					q.pop();
					if (num != 0) {
						if (index <= 98) {
							arr[index++][j] = num;
							arr[index++][j] = Cnt;
						}
					}

				}

				for (int i = index; i <= rMax; i++) {
					arr[i][j] = 0;
				}

				Max = max(index - 1, Max);
			}

			rMax = Max;

		}
	}

	if (t <= 100) {
		cout<<t;
	}
	else {
		cout<<-1;
	}
}