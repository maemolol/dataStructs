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
        int len = 0;

        LinkedList() {
            this->head = nullptr;
        }

        void append(int data) {
            Node* newNode = new Node(data);
            if(head == nullptr) {
                head = newNode;
                len++;
                return;
            }
            Node* current = head;
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            len++;
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

class Stack: LinkedList {
    public:
        void push(int data) {
            Node* newNode = new Node(data);
            if(head == nullptr) {
                head = newNode;
                len++;
                return;
            }
            newNode->next = head;
            head = newNode;
            len++;
        }

        int pop() {
            int ret_value = head->data;
            //Node* newNode = head;
            head = head->next;
            //free(newNode);
            len--;
            return ret_value;
        }

        bool isEmpty() {
            return head == nullptr;
        }
        
        int size() {
            int count = 0;
            Node* current = head;
            while(current != nullptr) {
                count++;
                current = current->next;
            }
            return count;
        }

        int top() {
            int ret_value = head->data;
            return ret_value;
        }

        bool isValid(string data) {
            Stack validity;

            for (char bracket : data) {
                if (bracket == '(' || bracket == '[' || bracket == '{') {
                    validity.push(bracket);
                }
                else if (bracket == ')' || bracket == ']' || bracket == '}') {
                    if (validity.isEmpty()) {
                        return false;
                    }
                    char top = validity.top();
                    if ((bracket == ')' && top == '(') || (bracket == ']' && top == '[') || (bracket == '}' && top == '{')) {
                        validity.pop();
                    }
                    else {
                        return false;
                    }
                }
            }

            return validity.isEmpty();
        }
};

/* void bubbleSort(int arr[], int len) {
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
} */

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

    Stack sticc;
    sticc.push(1);
    sticc.push(404);
    sticc.push(80085);
    sticc.push(64);
    sticc.push(-1);
    if(sticc.isValid("{{[]}}") == true) {
        printf("Brackets are valid.\n");
    } else {
        printf("Brackets are invalid.\n");
    }
    printf("Top: %d\n", sticc.top());
    printf("Size: %d\n", sticc.size());
    printf("Pop: %d\n",sticc.pop());
    printf("Top: %d\n", sticc.top());
    printf("Size: %d\n", sticc.size());
}