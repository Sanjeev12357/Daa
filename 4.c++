#include <iostream>

class DoublyLinkedList {
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    
public:
    DoublyLinkedList() : head(nullptr) {}

    // Insert at the end of the doubly linked list
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        std::cout << value << " inserted at the end (Doubly Linked List).\n";
    }

    // Delete the last node of the doubly linked list
    void deleteEnd() {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->prev->next = nullptr;
            delete temp;
        }
        std::cout << "Deleted last element from Doubly Linked List.\n";
    }

    // Display doubly linked list
    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

class CircularLinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Insert at the end of the circular linked list
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        std::cout << value << " inserted at the end (Circular Linked List).\n";
    }

    // Delete the last node of the circular linked list
    void deleteEnd() {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
        std::cout << "Deleted last element from Circular Linked List.\n";
    }

    // Display circular linked list
    void display() {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << "\n";
    }
};

int main() {
    // Doubly Linked List operations
    DoublyLinkedList dll;
    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);
    dll.display();
    dll.deleteEnd();
    dll.display();

    // Circular Linked List operations
    CircularLinkedList cll;
    cll.insertEnd(1);
    cll.insertEnd(2);
    cll.insertEnd(3);
    cll.display();
    cll.deleteEnd();
    cll.display();

    return 0;
}
