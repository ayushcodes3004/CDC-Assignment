#include <iostream>
using namespace std;

class Queue{
    int* arr;
    int capacity;
    int front;
    int rear;
    public:
    Queue(int size){
        capacity=size;
        arr=new int[size];
        front=0;
        rear=0;
    }
    
    bool isEmpty(){
        return front==rear;
    }
    
    bool isFull(){
        return rear==capacity;
    }
    
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue is full\n";
            return;
        }
        arr[rear++]=x;
    }
    
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        int data=arr[front++];
        return data;
    }
    
    int frontElemnt(){
        if(isEmpty()){
            cout<<"Queue is emptyl\n";
            return -1;
        }
        return arr[front];
    }
    
    int size(){
        return rear-front;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.frontElemnt() << endl;
    q.dequeue();

    cout << q.frontElemnt() << endl; 

    return 0;
}
