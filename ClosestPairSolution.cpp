#include <iostream>
#include <math.h>
using namespace std;

struct point{
    float x,y;
    point* next,*prev;
    point(float x,float y,point *p,point *n):x(x),y(y),prev(p),next(n){}

    void insertAfter(float x,float y){
        point *temp = new point(x,y,this,this->next);
        temp->next->prev = temp;
        temp->prev->next = temp;
    }
    void insertBefore(float x,float y){
        point *temp = new point(x,y,this->prev,this);
        temp->prev->next = temp;
        temp->next->prev = temp;

    }
    void remove(){
        this->prev->next = this->next;
        this->next->prev = this->prev;
        delete this;
    }
};
class pointlist{
public:
    pointlist(){
        head = new point(-1,-1,NULL,NULL);
        tail = new point(-10,-10,head,NULL);
        head->next = tail;
        top = 0;
    }
    int size(){return top;}
    void push(float x,float y){
        point *cursor = tail->prev;
        while(x <= cursor->x && cursor != head){
            cursor = cursor->prev;
        }
        cursor->insertAfter(x,y);
        top++;
    }
    void pop(){
        head->next->remove();
        top--;
    }
    float top_x(){return head->next->x;}
    float top_y(){return head->next->y;}
    point* r_head(){return head;}
    point* r_tail() {return tail;}
    void clear(){
        while(head->next != tail)
            pop();
    }
protected:
    point *head,*tail;
    int top;
};

float min(float a,float b){
    return (a < b) ? a : b;
}
float distance(point *a,point *b){
    float x_pow = (a->x - b->x) * (a->x - b->x);
    float y_pow = (a->y - b->y) * (a->y - b->y);
    return sqrt(x_pow + y_pow);
}
float Closest_Pair(pointlist l){
    if(l.size() <= 3){
        if(l.size() == 2)
            return distance(l.r_head()->next,l.r_head()->next->next);
        float fe = distance(l.r_head()->next,l.r_tail()->prev);
        float fm = distance(l.r_head()->next,l.r_head()->next->next);
        float me = distance(l.r_tail()->prev,l.r_tail()->prev->prev);
        return min(me,min(fe,fm));
    }
    pointlist left_side;
    //cout << left_side.size() << endl;
    int list_size = l.size();
    for(int i = 0;i < list_size/2;i++){
        left_side.push(l.top_x(),l.top_y());
        l.pop();
    }
    float left_min = Closest_Pair(left_side);
    float right_min = Closest_Pair(l);
    float delta = min(left_min,right_min);
    float left_max_x = left_side.r_tail()->prev->x;
    float right_min_x= l.r_head()->next->x;
    float mid_vertical = (left_max_x + right_min_x) / 2;
    pointlist middle;
    point* cursor = left_side.r_tail()->prev;
    while(mid_vertical - cursor-> x < delta && cursor != left_side.r_head()){
        middle.push(cursor->x,cursor->y);
        cursor = cursor->prev;
    }
    cursor = l.r_head()->next;
    while(cursor-> x - mid_vertical < delta && cursor != l.r_tail()){
        middle.push(cursor->x,cursor->y);
        cursor = cursor->next;
    }
    for(point* i = middle.r_head()->next;i != middle.r_tail();i = i->next){
        for(point* j = i->next;j != middle.r_tail();j = j->next){
            delta = (distance(i,j) < delta) ? distance(i,j) : delta;
        }
    }

    return delta;
}

int main(){
    int number;
    while(cin >> number){
        pointlist l;
        if(number == 0)
            break;
        for(int i = 0;i < number;i++){
            float x,y;
            cin >> x >> y;
            l.push(x,y);
        }
        float d = Closest_Pair(l);
        if(d >= 10000)
            cout << "INFINITY" << endl;
        else
            cout << d << endl;
        l.clear();
    }
}
