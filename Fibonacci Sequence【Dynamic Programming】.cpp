#include<iostream>
using namespace std;

int fibonacci_sequence[10000] = {0};

int Fib(int n){
    if(fibonacci_sequence[n] == 0){
        fibonacci_sequence[n] = Fib(n-1) + Fib(n-2);
        return fibonacci_sequence[n];

    }
    else
        return fibonacci_sequence[n];

}

int main(){
    fibonacci_sequence[0] = 1;
    fibonacci_sequence[1] = 1;
    cout << Fib(9) << endl;
}
