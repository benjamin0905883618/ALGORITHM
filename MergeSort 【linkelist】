#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *prev,*next;
    Node(int d,Node *p,Node *n) : data(d),prev(p),next(n){}

    void insertBefore(int d){
        Node *temp = new Node(d,this->prev,this);
        temp->next->prev = temp;
        temp->prev->next = temp;
    }
    void remove(){
        this->next->prev = this->prev;
        this->prev->next = this->next;
        delete this;
    }
};

class List{
public:
    List(){
        head = new Node(0,NULL,NULL);
        tail = new Node(0,head,NULL);
        head->next = tail;
        s = 0;
    }
    bool empty(){return head->next == tail;}
    void push(int d){
        tail->insertBefore(d);
        s++;
    }
    int size(){return s;}
    int top(){
        if(!empty())
            return head->next->data;
        else
            return 100000;
    }
    void printlist(){
        for(Node *i = head->next;i != tail;i = i->next)
            cout << i->data << " ";
        cout << endl;
    }

    void pop(){
        if(!empty()){
            head->next->remove();
            s--;
        }
    }
    void clear(){
        while(!empty())
            pop();
    }
protected:
    Node *head,*tail;
    int s;
};

List Merge(List l,List r){
    List arr;
    while(!l.empty() || !r.empty()){
        int num = (l.top() < r.top())?l.top():r.top();
        //cout << l.top() << " " << r.top() << " " << num << endl;
        arr.push(num);
        if(num == l.top())
            l.pop();
        else if(num == r.top())
            r.pop();
    }
    //arr.printlist();
    return arr;
}
void MergeSort(List &arr){
    if(arr.size() == 1)
        return;
    int mid = arr.size()/2;
    //cout << arr.top() << " " << mid << endl;
    List l;
    for(int i = 0;i < mid;i++){
        if(arr.top() != 100000){
            l.push(arr.top());
            arr.pop();
        }
        //cout << arr.top() << endl;
    }
    MergeSort(arr);
    MergeSort(l);
    arr = Merge(l,arr);
}
int main(){
    int num;
    List arr;
    cin >> num;
    int n;
    for(int i = 0;i < num;i++){
        cin >> n;
        arr.push(n);
    }
    //cout << arr.size() << endl;
    MergeSort(arr);
    for(int i = 0;i < num;i++){
        cout << arr.top() << " ";
        arr.pop();
    }
    cout << endl;

}


