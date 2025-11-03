#include <iostream>
using namespace std;

// Node class for circular singly linked list
class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Singly Linked List class
class CircularLinkedList {
private:
    Node* tail;  // Points to the last node (tail->next points to head)
    int size;

public:
    // Constructor
    CircularLinkedList() {
        tail = nullptr;
        size = 0;
    }
    
    // Destructor
    ~CircularLinkedList() {
        clear();
    }
    
    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        
        if (tail == nullptr) {
            // First node - points to itself
            tail = newNode;
            newNode->next = newNode;
        } else {
            // Insert at beginning (after tail)
            newNode->next = tail->next;
        }
        size++;
    }
    
    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (tail == nullptr) {
            // First node - points to itself
            tail = newNode;
            newNode->next = newNode;
        } else {
            // Insert after tail and update tail
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    // Insert at specific position (0-based indexing)
    void insertAtPosition(int position, int value) {
        if (position < 0 || position > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        
        if (position == size) {
            insertAtEnd(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* current = tail->next;  // Start from head
        
        // Traverse to position-1
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
    
    // Delete from beginning
    void deleteFromBeginning() {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node* head = tail->next;
        
        if (head == tail) {
            // Only one node
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
        size--;
    }
    
    // Delete from end
    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        if (tail->next == tail) {
            // Only one node
            delete tail;
            tail = nullptr;
        } else {
            // Find the second last node
            Node* current = tail->next;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = tail->next;
            delete tail;
            tail = current;
        }
        size--;
    }
    
    // Delete by value
    void deleteByValue(int value) {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node* head = tail->next;
        
        // If head node contains the value
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        
        Node* current = head;
        while (current->next != head && current->next->data != value) {
            current = current->next;
        }
        
        if (current->next == head) {
            cout << "Value " << value << " not found!" << endl;
            return;
        }
        
        Node* nodeToDelete = current->next;
        if (nodeToDelete == tail) {
            tail = current;
        }
        current->next = nodeToDelete->next;
        delete nodeToDelete;
        size--;
    }
    
    // Search for a value
    bool search(int value) {
        if (tail == nullptr) return false;
        
        Node* current = tail->next;  // Start from head
        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != tail->next);
        
        return false;
    }
    
    // Display the list
    void display() {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node* current = tail->next;  // Start from head
        cout << "Circular List: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != tail->next);
        cout << "(size: " << size << ")" << endl;
    }
    
    // Get size
    int getSize() {
        return size;
    }
    
    // Check if empty
    bool isEmpty() {
        return tail == nullptr;
    }
    
    // Clear the entire list
    void clear() {
        if (tail == nullptr) return;
        
        Node* current = tail->next;
        Node* next;
        
        do {
            next = current->next;
            delete current;
            current = next;
        } while (current != tail->next);
        
        tail = nullptr;
        size = 0;
    }
};

// Demo function
int main() {
    CircularLinkedList cll;
    
    cout << "=== Circular Singly Linked List Demo ===" << endl;
    
    // Insert operations
    cout << "\n1. Inserting elements:" << endl;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.display();
    
    cll.insertAtBeginning(5);
    cll.display();
    
    cll.insertAtPosition(2, 15);
    cll.display();
    
    // Search operations
    cout << "\n2. Search operations:" << endl;
    cout << "Searching for 15: " << (cll.search(15) ? "Found" : "Not found") << endl;
    cout << "Searching for 100: " << (cll.search(100) ? "Found" : "Not found") << endl;
    
    // Delete operations
    cout << "\n3. Delete operations:" << endl;
    cll.deleteFromBeginning();
    cll.display();
    
    cll.deleteFromEnd();
    cll.display();
    
    cll.deleteByValue(15);
    cll.display();
    
    // Size and empty check
    cout << "\n4. List info:" << endl;
    cout << "Size: " << cll.getSize() << endl;
    cout << "Is empty: " << (cll.isEmpty() ? "Yes" : "No") << endl;
    
    // Clear list
    cout << "\n5. Clearing list:" << endl;
    cll.clear();
    cll.display();
    cout << "Is empty: " << (cll.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}
