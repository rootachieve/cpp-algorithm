#include <iostream>
#include<stdio.h>
using namespace std;
int a,b,coun;
int main(){
    cin>>a;
    for(int i = 1; i <= 5 ;i++){
        cin>>b;
        if(b==a){
            coun++;
            }
        }
    cout<<coun;
   }