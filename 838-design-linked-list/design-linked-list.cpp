class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data=val;
            next=NULL;
        }
};
class MyLinkedList {
public:
    Node* head;
    MyLinkedList() {
        head=NULL;
    }
    
    int get(int index) {
        Node* temp = head;
        int i = 0;

        while (temp != nullptr) {
            if (i == index) return temp->data;
            temp = temp->next;
            i++;
        }

        return -1;
    }
    
    void addAtHead(int val) {
        Node* newNode= new Node(val);
        if(head==NULL){
            head=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    
    void addAtTail(int val) {
        Node* newNode= new Node(val);
        if(head==NULL){
            head=newNode;
            return;
        }else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        } 
        Node* newNode= new Node(val);
        Node* temp=head;
        int i=0;
        // stop at node BEFORE index
        while (temp != nullptr && i < index - 1) {
            temp = temp->next;
            i++;
        }
        if (temp == nullptr) return; // index > length → ignore
        newNode->next=temp->next;
        temp->next=newNode;
    }
    
    void deleteAtIndex(int index) {
        if(head==NULL)  return ;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp=head;
         int i = 0;

        // stop at node BEFORE index
        while (temp != nullptr && i < index - 1) {
            temp = temp->next;
            i++;
        }
        if (temp == nullptr || temp->next == nullptr) return; // index out of bounds
        // temp->next=temp->next->next;
        // // temp->next->next=NULL;
        // delete(temp->next);
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */