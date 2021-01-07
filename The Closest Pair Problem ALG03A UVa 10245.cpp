#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

struct point{
    double x;
    double y;
};
 bool cmp(point a,point b){
    return a.x < b.x;
 }
 double Distance(point a,point b){
    return (double) sqrt(pow(a.x - b.x , 2) + pow(a.y - b.y , 2));
 }
 double combine(point a[],int low,int mid,int high,double min_left,double min_right){
    double d = (min_left < min_right)?min_left : min_right;
    double line = (double)(a[mid].x+a[mid+1].x)*0.5;
    double min_D = d;
    for(int i = mid+1;a[i].x < line+d && i <= high;i++){
        for(int j = mid;a[j].x > line-d && j >= low;j--){
            double temp = Distance(a[i],a[j]);
            if(temp < min_D) min_D = temp;

        }
    }
    return min_D;
 }
 double divide(point a[],int low,int high){
    if(low >= high) return 99999;

    int mid = (low + high) / 2;
    double min_left = divide(a,low,mid);
    double min_right = divide(a,mid+1,high);
    return combine(a,low,mid,high,min_left,min_right);
 }
 int main(){
    int n;
    point a[10001];
    while(cin >> n){
        if(n == 0)
            break;
        for(int i = 0;i < n;i++)
            cin >> a[i].x >> a[i].y;
        sort(a,a+n,cmp);
        double dis = divide(a,0,n-1);
        if(dis >= 10000.0) cout << "INFINITY" << endl;
        else cout << fixed << setprecision(4) << dis << endl;
    }
 }
