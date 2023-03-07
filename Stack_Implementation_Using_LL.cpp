// Stack_Implementation_Using_LL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Stack {

    struct Node {
        int data;
        Node* next;
        Node(int d) {
            data = d;
            next = NULL;
        }
    };
    Node* head;
    int size;


public:
    Stack() {
        head = NULL;
        size = 0;
    }

    bool empty()
    {
        return head == NULL;
    }

    void push(int data)
    {
        Node* newHead = new Node(data);
        if (empty()) 
        {
            head = newHead;
        }
        else
        {
            newHead->next = head;
            head = newHead;

        }
        size += 1;
    }

    void pop()
    {
        if (empty()) {
            cout << "Stack is underflow."<<endl;
            return;
        }
        else
        {
            //this below operation is almost like the SWAPPING THE TWO NUMBER.
            Node* toDelete = head; //this is a temporary node for storing the head.
            head = head->next;
            free(toDelete); //we have free the data in order to remove it from the memory,if not,it'll stay there and use the memory for no reason.
            size -= 1;
        }
    }

    int top()
    {
        if (empty())
        {
            cout << "The Stack is empty." << endl;
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    int getSize()
    {
        return size;
    }

    void print()
    {
        if (empty())
        {
            cout << "The Stack is empty";
        }
        else
        {
            Node* current = head;
            cout << "Top to bottom" << endl;
            while (current  != NULL) {
                cout << current->data << ' ';
                current = current->next;
            }
            cout << endl;
        }
    }

};

int main()
{
    Stack stack=Stack();
    stack.top();
    stack.push(20);
    stack.push(23);

    stack.print();
    return 0;
}
