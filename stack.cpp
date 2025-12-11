// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Stack{
    int arr[100];
    int top;
    public:
    Stack(){
        top=-1;
    }
    void push(int x){
        if(top==100)    return ;
        top++;
        arr[top]=x;
    }
    int pop(){
        if(top==-1) return -1;
        int data=arr[top];
        top--;
        return data;
    }
    bool isEmpty() {
        return top == -1;
    }
    int isTop(){
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.pop();
    cout<<s.isTop()<<endl;
    return 0;
}
