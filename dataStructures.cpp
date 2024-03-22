#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList {
    public:
        Node* head;

        LinkedList() {
            this->head = nullptr;
        }

        void append(int data) {
            Node* newNode = new Node(data);
            if(head == nullptr) {
                head = newNode;
                return;
            }
            Node* current = head;
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        void printList() {
            Node* current = head;
            while(current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        void printAddress() {
            Node* current = head;
            while(current != nullptr) {
                cout << current << " ";
                current = current->next;
            }
            cout << endl;
        }

        void reverseList() {
            Node* last = nullptr;
            Node* current = head;
            Node* next = nullptr;
            while(current != nullptr) {
                next = current->next;
                current->next = last;
                last = current;
                current = next;
            }
            head = last;
        }
};

void bubbleSort(int arr[], int len) {
    int temp;
    for(int i = 0; i < len; i++) {
        for(int j = 1; j < len; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    LinkedList list;
    list.append(1);
    list.append(420);
    list.append(8086);
    list.printList();
    list.printAddress();
    list.reverseList();
    list.printList();
}