#include <iostream>
using namespace std;

class CircularQueue{
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;
    
    public:
    CircularQueue(int size){
        capacity=size;
        arr=new int[size];
        front=0;
        rear=-1; //change
        count=0;
    }
    
    bool isEmpty(){
        return count==0;
    }
    
    bool isFull(){
        return count==capacity;
    }
    
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue is full\n";
            return;
        }
        rear=(rear+1)%capacity;
        arr[rear]=x;
        count++;
    }
    
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        int data=arr[front];
        front=(front+1)%capacity;
        count--;
        return data;
    }
    
    int frontElement(){
        if(isEmpty()){
            cout<<"Queue is emptyl\n";
            return -1;
        }
        return arr[front];
    }
    
    int size(){
        return count;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.enqueue(60);

    cout << q.frontElement() << endl; // 10
    q.dequeue();
    cout << q.frontElement() << endl; // 20
}
