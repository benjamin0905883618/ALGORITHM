#include<iostream>
using namespace std;

int Hanoi(int n){
    if(n == 1)
        return 1;
    else
        return 2*Hanoi(n-1) + Hanoi(1);
}

int main(){
    cout << Hanoi(7) << endl;
}
