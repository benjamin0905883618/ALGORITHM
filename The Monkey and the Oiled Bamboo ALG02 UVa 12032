#include<iostream>
using namespace std;
int t,T;
int num;
int *data;
void init(){
    cin >> T;
    t = 0;
}
bool input(){
    if(t++ == T)
        return false;
    cin >> num;
    data = new int [num+1];
    data[0] = 0;
    for(int i = 1;i <= num;i++)
        cin >> data[i];
    return true;
}
bool run(int n){
    for(int i = 1;i <= num;i++){
        if(data[i] - data[i-1] > n) return false;
        else if(data[i] - data[i-1] == n) n--;
    }
    return true;
}
int BinarySearch(int start,int terminal){
    if(terminal - start == 1)
        return terminal;
    int mid = (start + terminal) / 2;
    bool test = run(mid);
    //cout << test << endl;
    if(!test)
        return BinarySearch(mid,terminal);
    else if(test)
        return BinarySearch(start,mid);

}
int main(){
    init();
    while(input()){
        cout << "Case " << t << ": "<< BinarySearch(0,data[num]) << endl;
    }
}



