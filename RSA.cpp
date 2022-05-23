#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    if(y==0)
    return x;

    return gcd(y,x%y);
}

int main(){
    int p=3;
    int q=7;
    int n=p*q;
    int phi=(p-1)*(q-1);
    int e=2;
    while(e<phi){
        if(gcd(e,phi)==1){
            break;
        }
        else
            e++;
    }
    cout<<phi<<" ";
    cout<<e<<" ";
    //int d=(1%phi)/e;
    int k=2;
    double d=(k*phi + 1) / e;
    cout<<d<<" ";
    int mssg=12;
    int E=pow(mssg,e);
    double encrypt=fmod(E,n);
    int D=pow(encrypt,d);
    double decrypt=fmod(D,n);
    cout<<encrypt<<" ";
    cout<<decrypt<<" ";
    return 0;
}