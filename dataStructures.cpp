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

        void sortList() {
            Node *last = nullptr;
            Node *current = head;
            Node *next = current->next;
            Node *new_head = head;
            Node *min = head;
            Node *before_min = last;
            Node *after_min = next;
            Node *unsorted = head;
            Node *sorted = nullptr;
            
            while(true) {
                current = unsorted;
                while(current != nullptr) {
                    if(current->data <= min->data) {
                        before_min = last;
                        min = current;
                        after_min = next;
                    }
                    last = current;
                    current = current->next;
                    if(current != nullptr) {
                        next = current->next;
                    }
                }
                if(min == unsorted) {
                    unsorted = unsorted->next;
                }
                min->next = new_head;
                if(sorted == nullptr) {
                    sorted = min;
                }
                new_head = min;
                before_min->next = after_min;
                min = unsorted;
                if(min == nullptr) {
                    break;
                }

                next = unsorted->next;
                last = sorted;
            }
            head = new_head;
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
    list.append(-420);
    list.append(8086);
    list.printList();
    list.printAddress();
    list.reverseList();
    list.printList();
    list.sortList();
    list.printList();
}