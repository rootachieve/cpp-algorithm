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
#include <bitset>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
set<int> s;
priority_queue<pair<int,pair<int,int>>> q;
int map[52][52];
int visit[52][52];
int check[52][52];
int Sy,Sx;
int base[2][8] = {{0,-1,-1,-1,0,1,1,1},{-1,-1,0,1,1,1,0,-1}};
vector<pair<int,int>> loc;
int main() {
	int n;
	cin>>n;
	string in;
	for (int i = 1; i <= n; i++) {
		cin>>in;
		for (int j = 1; j <= n; j++) {
			check[i][j] = 1e9;
			if (in[j - 1] == 'P') {
				Sy  = i;
				Sx = j;
			}
			else if (in[j - 1] == 'K') {
				loc.push_back({i,j});
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		
		for (int j = 1; j <= n; j++) {
			cin>>map[i][j];
			if (s.find(-map[i][j]) == s.end()) {
				s.insert(-map[i][j]);
			}
		}
	}
	int ans = 1e9;
	int Min = map[Sy][Sx];
	set<int>::iterator iter = s.begin();
	for (int i = 0; i < loc.size(); i++) {
		Min = min(Min,map[loc[i].first][loc[i].second]);
	}
	int y,x,ty,tx,v;
	for(;*iter!=-Min;iter++);
	for (; iter!=s.end(); iter++) {
		int h = -*iter;
		check[Sy][Sx] = h;
		visit[Sy][Sx] = map[Sy][Sx];
		q.push({-map[Sy][Sx],{Sy,Sx}});
		while (!q.empty()) {
			y = q.top().second.first;
			x = q.top().second.second;
			v = -q.top().first;
			q.pop();
			
			if (visit[y][x] < v) {
				continue;
			}
			for (int i = 0; i < 8; i++) {
				ty = y+base[0][i];
				tx = x+base[1][i];
				if(ty<=n&&ty>=1&&tx<=n&&tx>=1&&map[ty][tx]>=h){
					if (check[ty][tx] >h || visit[ty][tx] > visit[y][x]) {
						check[ty][tx] = h;
						visit[ty][tx] = max(visit[y][x],map[ty][tx]);
						q.push({-visit[ty][tx],{ty,tx}});
					}
				}
			}
		}
		int Max = 0;
		bool err = false;
		for (int i = 0; i < loc.size(); i++) {
			if (check[loc[i].first][loc[i].second] > h) {
				err = true;
				break;
			}
			else {
				Max = max(Max, visit[loc[i].first][loc[i].second]);
			}
		}

		if (!err) {
			ans = min(ans,Max - h);
		}
	}
	

	cout<<ans;
}