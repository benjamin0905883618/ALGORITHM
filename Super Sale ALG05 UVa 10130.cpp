#include<iostream>
using namespace std;
int T,t;

struct cargo{
    int profit;
    int weight;
};
void init(){
    cin >> T;
    t = 0;
}

cargo c[1000];
int dp[1001][31] = {-1};
int num;
bool input(){
    if(t++ == T)
        return false;
    cin >> num;
    for(int i = 0;i < num;i++)
        cin >> c[i].profit >> c[i].weight;
    for(int i = 0;i < num;i++)
        for(int j = 0;j < 31;j++)
            dp[i][j] = -1;
    return true;
}

int run(int n,int w){
    if(n < 0)
        return 0;
    if(dp[n][w] >= 0)
        return dp[n][w];
    dp[n][w] = run(n-1,w);
    //cout << dp[n][w] << endl;
    if(w >= c[n].weight && dp[n][w] < c[n].profit + run(n - 1,w - c[n].weight))
        dp[n][w] = c[n].profit + run(n - 1 ,w - c[n].weight);
    return dp[n][w];
}

int buy(){
    //cout << dp[1000][30];
    int customer;
    cin >> customer;
    int sum = 0;
    int power;
    for(int i = 0;i < customer;i++){
        cin >> power;
        //cout << num << endl;
        sum += run(num-1,power);
    }
    return sum;
}

int main(){
    init();
    while(input()){
        cout << buy() << endl;
    }
}
