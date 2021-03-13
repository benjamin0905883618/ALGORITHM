//Maxtrix-Chain Multiplication

#include <iostream>
#define INFINITE 999999999
using namespace std;

int **M;
int *length;
int n;

bool init(){
    cin >> n;
    if(n == 0)
        return false;
    M = new int* [n];
    for(int i = 0;i < n;i++){
        M[i] = new int [n];
        for(int j = 0;j < n;j++){
            M[i][j] = 0;
        }
    }
    length = new int [n + 1];
}
bool input(){
    int width,height;
    cin >> width >> height;
    length[0] = width;
    length[1] = height;
    for(int i = 1;i < n;i++){
        cin >> width >> height;
        if(length[i] != width)
            return false;
        length[i+1] = height;
    }
    return true;
}
int DP(){
    for(int j = 1;j < n;j++){
        for(int i = 0;i < n-1;i++){
            int left = M[i][j + i - 1] + length[i] * length[j + i] * length[j + i + 1];
            int bottom = M[i + 1][j + i] + length[i] * length[i+1] * length[j + i + 1];
            M[i][j + i] = (left < bottom) ? left:bottom;
        }
    }
    return M[0][n-1];
}



int main(){
    //有n個Matrix
    //假設已經排列好(可得出解)，只是需要利用DP找出optimal
    while(init()){
        if(input() == false){
            cout << "the wrong matrix size" << endl;
            break;
        }
        int optimal_solution = DP();
        //測試兩個陣列是否丟錯
        /*for(int i = 0;i < n+1;i++)
            cout << length[i];
        cout << endl;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
        */
        cout << optimal_solution << endl;
    }



}
