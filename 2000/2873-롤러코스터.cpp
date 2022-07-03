#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <vector>
#define MOD 1000000
#define MODUL(x,y) (((y)%MOD) + ((x)%MOD))%MOD
#define MODULF(x,y) (((y)%MOD) * ((x)%MOD))%MOD
using namespace std;

int r,c;
int map[1001][1001];
int sum;
int main() {
	scanf("%d%d",&r,&c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d",&map[i][j]);
			sum+=map[i][j];
		}
	}

	if (r % 2 == 1) {
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j < c; j++) {
				if (i % 2 == 1) {
					printf("R");
				}
				else {
					printf("L");
				}
			}
			if(i<r){
				printf("D");
			}
		}
	}
	else if (c % 2 == 1) {
		for (int i = 1; i <= c; i++) {
			for (int j = 1; j < r; j++) {
				if (i % 2 == 1) {
					printf("D");
				}
				else {
					printf("U");
				}
			}
			if (i < c) {
				printf("R");
			}
		}
	}
	else {
		pair<int,int> loc;
		int minvalue = 1001;
		string temp1 ="";
		string temp2="";

		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j < c; j++) {
				if (i % 2 == 1) {
					temp1+="R";
				}
				else {
					temp1 += "L";
				}
			}
			if (i <= r) {
				temp1 += "D";
			}
		}

		for (int i = 1; i <= 2; i++) {
			if (i <= r) {
				temp2 += "D";
			}
			for (int j = 1; j < c; j++) {
				if (i % 2 == 1) {
					temp2 += "L";
				}
				else {
					temp2 += "R";
				}
			}
			
		}


		string s = "";
		string e = "";
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if ((i + j) % 2 == 1) {
					if (minvalue > map[i][j]) {
						minvalue = map[i][j];
						loc = { i,j };
					}
				}
			}
		}
		int rc = r/2;
		int notvisitR = (loc.first-1)/2+1;
		for (int i = 1; i < notvisitR;i++) {
			s+=temp1;
		}
		for (int i = notvisitR + 1;i <=rc; i++) {
			e = temp2+e;
		}
		int Count = 1;
		for (int i = 1; i <= c; i++) {
			if (i == c && i == loc.second) {
				break;
			}
			if (i == loc.second) {
				s += "R";
			}else{
				if (Count % 2 == 1) {
					s+="D";
				}
				else {
					s += "U";
				}
				if (i < c) {
					s += "R";
				}
				Count++;
			}
		}
		s+=e;
		printf("%s",s.c_str());
		
	}
}