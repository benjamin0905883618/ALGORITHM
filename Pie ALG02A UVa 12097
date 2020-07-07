#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
#define PI  3.14159265358979323846

int t,T;
int num,people;
double *data;
void init(){
    cin >> T;
    t = 0;
}
bool input(){
    if(t++ == T)
        return false;
    cin >> num >> people;
    data = new double [num];
    for(int i = 0;i < num;i++){
        cin >> data[i];
        data[i] = data[i] * data[i] * PI;
    }


    return true;
}
bool run(double n){
    int sum = 0;
    for(int i = 0;i < num;i++){
        sum += data[i] / n;
    }
    if(sum >= people + 1)
        return true;
    return false;
}
double BinarySearch(double start,double terminal){
    if(terminal - start < 0.0001)
        return start;
    double mid = (start + terminal) / 2;
    bool test = run(mid);
    //cout << test << endl;
    if(!test)
        return BinarySearch(start,mid);
    else if(test)
        return BinarySearch(mid,terminal);

}
int main(){
    init();
    while(input()){
        sort(data,data+num);
        cout << fixed << setprecision(4) << BinarySearch(0,data[num-1]) << endl;
    }
}



