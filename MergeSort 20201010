#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next,*prev;
    Node(int d,Node *p,Node *n):data(d),prev(p),next(n){}

    void insertAfter(int datum){
        Node *temp = new Node(datum,this,this->next);
        temp->next->prev = temp;
        temp->prev->next = temp;
    }
    void insertBefore(int datum){
        Node *temp = new Node(datum,this->prev,this);
        temp->next->prev = temp;
        temp->prev->next = temp;
    }
    void remove(){
        this->prev->next = this->next;
        this->next->prev = this->prev;
        delete this;
    }
};

class List{
public:
    List(){
        head = new Node(0,NULL,NULL);
        tail = new Node(0,head,NULL);
        head->next = tail;
        _size_ = 0;
    }
    int size(){return _size_;}
    void push(int d){
        tail->insertBefore(d);
        _size_++;
    }
    int top(){return head->next->data;}
    void pop(){head->next->remove();}
    bool empty(){return (head->next == tail);}
    void clear(){
        while(!empty())
            pop();
    }

protected:
    Node *head,*tail;
    int _size_;
};
List Combine(List left,List right){
    List combine;
    while(!left.empty() && !right.empty()){
        if(left.top() < right.top()){
            combine.push(left.top());
            left.pop();
        }
        else
        {
            combine.push(right.top());
            right.pop();
        }

    }
    if(right.empty()){
        while(!left.empty()){
            combine.push(left.top());
            left.pop();
        }
    }
    else{
        while(!right.empty()){
            combine.push(right.top());
            right.pop();
        }
    }
    cout << "Combine fin!" << endl;
    return combine;

}

List Divide_and_Conquer(List l){
    if(l.size() == 1)
        return l;
    else{
        List left,right;
        int num = l.size() / 2;
        //cout << num << endl;
        for(int i = 0;i < num;i++){
            left.push(l.top());
            l.pop();
        }
        while(!l.empty()){
            right.push(l.top());
            l.pop();
        }
        cout << "Divide fin!" << endl;
        return Combine(Divide_and_Conquer(left),Divide_and_Conquer(right));
    }

}

int main(){
    List test;
    test.push(7);
    test.push(8);
    test.push(4);
    test.push(5);
    test.push(2);
    test.push(1);
    test.push(3);
    test.push(10);
    cout << "push fin!" << endl;
    //cout << test.size() << endl;
    List output = Divide_and_Conquer(test);
    for(int i = 0;i < 8;i++){
         cout << output.top() << " ";
         output.pop();
    }
    cout << endl;

}
