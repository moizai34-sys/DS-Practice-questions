#include<iostream>
using namespace std;


// ==================== NODE CLASS ====================

class Node
{
public:
    int key;
    int data;
    Node* next;

    // Default constructor
    Node(): key(0), data(0), next(NULL) {}

    // Parameterized constructor
    Node(int k, int d): key(k), data(d), next(NULL) {}
};


// ==================== CIRCULAR LINKED LIST ====================

class CircularLL
{
public:
    Node* Head;


    // Constructor: Creates the first node
    CircularLL(int k, int d)
    {
        Head = new Node(k, d);

        // Since there is only one node,
        // it points back to itself
        Head->next = Head;
    }


    // --------------------------------------------------
    // INSERT AT END
    // --------------------------------------------------

    // Inserts a new node at the end of the circular list
    void insertatEnd(int k, int d)
    {
        Node* end = new Node(k, d);

        Node* temp = Head;

        // Find the last node
        while(temp->next != Head)
        {
            temp = temp->next;
        }

        // Last node points to new node
        temp->next = end;

        // New node points back to Head
        end->next = Head;
    }


    // --------------------------------------------------
    // INSERT AT BEGINNING
    // --------------------------------------------------

    // Inserts a new node at the beginning of the list
    void insertatFirst(int k, int d)
    {
        Node* newnode = new Node(k, d);

        Node* temp = Head;

        // Find the last node
        while(temp->next != Head)
        {
            temp = temp->next;
        }

        // New node points to current Head
        newnode->next = Head;

        // Last node points to new Head
        temp->next = newnode;

        // Update Head
        Head = newnode;
    }


    // --------------------------------------------------
    // INSERT IN MIDDLE
    // --------------------------------------------------

    // Inserts a new node according to key order
    void insertatmid(int key, int d)
    {
        Node* current = Head;

        do
        {
            // Check if key already exists
            if(current->key == key)
            {
                cout << "Node already exists. "
                     << "Select a different key." << endl;
                return;
            }

            // Check if new key belongs between
            // current node and next node
            if((current->key < key) &&
               (current->next->key > key))
            {
                Node* newnode = new Node(key, d);

                newnode->next = current->next;
                current->next = newnode;

                return;
            }

            current = current->next;

        } while(current != Head);

        cout << "Suitable position not found." << endl;
    }


    // --------------------------------------------------
    // DELETE FROM BEGINNING
    // --------------------------------------------------

    // Deletes the first node of the circular linked list
    void deleteFromBeginning()
    {
        // If list is empty
        if(Head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        // If only one node exists
        if(Head->next == Head)
        {
            delete Head;
            Head = NULL;
            return;
        }

        Node* last = Head;

        // Find the last node
        while(last->next != Head)
        {
            last = last->next;
        }

        Node* temp = Head;

        // Move Head to next node
        Head = Head->next;

        // Last node points to new Head
        last->next = Head;

        delete temp;
    }


    // --------------------------------------------------
    // DELETE FROM END
    // --------------------------------------------------

    // Deletes the last node of the circular linked list
    void deleteFromEnd()
    {
        // If list is empty
        if(Head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        // If only one node exists
        if(Head->next == Head)
        {
            delete Head;
            Head = NULL;
            return;
        }

        Node* temp = Head;

        // Find second-last node
        while(temp->next->next != Head)
        {
            temp = temp->next;
        }

        // temp is second-last node
        Node* last = temp->next;

        // Second-last now points to Head
        temp->next = Head;

        delete last;
    }


    // --------------------------------------------------
    // DELETE IN BETWEEN / BY KEY
    // --------------------------------------------------

    // Deletes the node having the given key
    void deleteNode(int key)
    {
        // If list is empty
        if(Head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        // If Head contains the key
        if(Head->key == key)
        {
            deleteFromBeginning();
            return;
        }

        Node* current = Head;

        // Find the node before the node to delete
        while(current->next != Head)
        {
            if(current->next->key == key)
            {
                Node* temp = current->next;

                current->next = temp->next;

                delete temp;

                cout << "Node deleted successfully." << endl;
                return;
            }

            current = current->next;
        }

        cout << "Key not found." << endl;
    }


    // --------------------------------------------------
    // SEARCH
    // --------------------------------------------------

    // Searches for a node using its key
    void search(int key)
    {
        // If list is empty
        if(Head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = Head;

        do
        {
            if(current->key == key)
            {
                cout << "Key " << key
                     << " found." << endl;

                cout << "Data = "
                     << current->data << endl;

                return;
            }

            current = current->next;

        } while(current != Head);

        cout << "Key " << key
             << " not found." << endl;
    }


    // --------------------------------------------------
    // PRINT
    // --------------------------------------------------

    // Displays all nodes of the circular linked list
    void printLL()
    {
        if(Head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* print = Head;

        do
        {
            cout << print->data << "->";
            print = print->next;

        } while(print != Head);

        cout << "(Back to Head)" << endl;
    }
};


// ==================== MAIN ====================

int main()
{
    CircularLL L1(6,6);


    // --------------------------------------------------
    // INSERTING AT END
    // --------------------------------------------------

    cout << "Inserting at End" << endl;

    L1.insertatEnd(7,7);
    L1.insertatEnd(8,8);
    L1.insertatEnd(9,9);

    L1.printLL();


    // --------------------------------------------------
    // INSERTING AT FRONT
    // --------------------------------------------------

    cout << "\nInserting at Front" << endl;

    L1.insertatFirst(0,0);
    L1.insertatFirst(1,1);

    L1.printLL();


    // --------------------------------------------------
    // INSERTING IN MIDDLE
    // --------------------------------------------------

    cout << "\nInserting in Middle" << endl;

    L1.insertatmid(2,3);

    L1.printLL();


    // --------------------------------------------------
    // SEARCH
    // --------------------------------------------------

    cout << "\nSearching for key 8" << endl;

    L1.search(8);


    // --------------------------------------------------
    // DELETE FROM BEGINNING
    // --------------------------------------------------

    cout << "\nDeleting from Beginning" << endl;

    L1.deleteFromBeginning();

    L1.printLL();


    // --------------------------------------------------
    // DELETE FROM END
    // --------------------------------------------------

    cout << "\nDeleting from End" << endl;

    L1.deleteFromEnd();

    L1.printLL();


    // --------------------------------------------------
    // DELETE NODE BY KEY
    // --------------------------------------------------

    cout << "\nDeleting node with key 2" << endl;

    L1.deleteNode(2);

    L1.printLL();


    return 0;
}
