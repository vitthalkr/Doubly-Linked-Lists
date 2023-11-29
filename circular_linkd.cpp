#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    // constructor
    Node(int d)
    {
        this->data = d;
        Node* next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if(this->next!= NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for node with data " <<value<<endl;
    }
};

//get length
void get_length(Node* &tail)
{   
    Node* temp = tail->next;
    int cnt = 1;
    while(temp != tail)
    {
        temp = temp -> next;
        cnt++;
    }
    cout<<cnt;
    cout<<endl;
}

// insertion
void insert_node(Node* &tail, int element , int d)
{
    // assuming the element is present in the list
    if(tail == NULL)
    {
        Node* node = new Node(d);
        tail = node;
        node->next = node;
    }
    else{
        //non empty list
        Node* curr = tail;
        while(curr->data != element)
        {
            curr = curr->next;
        }
        // element found

        Node*temp = new Node(d);
        temp ->next = curr->next;
        curr->next = temp;
    }
}

// delete node

void delete_node(Node* &tail, int value)
{
    if(tail == NULL)
    {
        cout<<"List is already empty";
    }
    else{
        Node* prev = tail;
        Node* curr =  prev->next;

        while(curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev ->next = curr->next;
        curr->next = NULL;
        delete(curr);

    }
}

void print_list(Node* tail)
{
    Node*temp = tail;
    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while (tail!= temp);
    cout<<endl;
}

int main()
{
    Node* tail = NULL;
    // empty list insertion
    insert_node(tail, 5, 3);
    get_length(tail);
    print_list(tail);
    insert_node(tail, 3, 5);
    print_list(tail);
    insert_node(tail, 5, 7);
    print_list(tail);
    insert_node(tail, 7, 9);
    print_list(tail);
    get_length(tail);

    delete_node(tail, 9);
    print_list(tail);
    return 0;

}