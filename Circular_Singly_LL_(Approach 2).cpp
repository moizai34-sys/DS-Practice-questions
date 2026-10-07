#include <iostream>

using namespace std;


// Node class for circular singly linked list
class Node
{
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) : data(data), next(NULL) {}
};


// Circular Singly Linked List class
class CircularSinglyLinkedList
{
private:
    Node* head;

public:

    // Constructor: Creates an empty circular linked list
    CircularSinglyLinkedList() : head(NULL) {}


    // Destructor: Deletes the complete circular linked list
    ~CircularSinglyLinkedList()
    {
        clear();
    }


    // --------------------------------------------------
    // INSERTION AT TAIL
    // --------------------------------------------------

    // Inserts a new node at the end of the circular linked list
    void InsertionAtTail(int data)
    {
        Node* newNode = new Node(data);

        // If list is empty
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        // Find last node
        while (temp->next != head)
        {
            temp = temp->next;
        }

        // Connect new node
        temp->next = newNode;
        newNode->next = head;
    }


    // --------------------------------------------------
    // INSERTION AT START
    // --------------------------------------------------

    // Inserts a new node at the beginning of the circular linked list
    void InsertionAtStart(int data)
    {
        Node* newNode = new Node(data);

        // If list is empty
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        // Find last node
        while (temp->next != head)
        {
            temp = temp->next;
        }

        // New node points to old head
        newNode->next = head;

        // Last node points to new head
        temp->next = newNode;

        // Update head
        head = newNode;
    }


    // --------------------------------------------------
    // INSERT AFTER POSITION
    // --------------------------------------------------

    // Inserts a new node after the specified 0-based position
    void InsertAfter(int position, int data)
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        // Move to required position
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;

            // We came back to head before reaching position
            if (temp == head)
            {
                cout << "Position out of bounds.\n";
                return;
            }
        }

        Node* newNode = new Node(data);

        newNode->next = temp->next;
        temp->next = newNode;
    }


    // --------------------------------------------------
    // SEARCH
    // --------------------------------------------------

    // Searches for a given key in the circular linked list
    bool SearchingForKey(int key) const
    {
        if (head == NULL)
        {
            return false;
        }

        Node* temp = head;

        do
        {
            if (temp->data == key)
            {
                return true;
            }

            temp = temp->next;

        } while (temp != head);

        return false;
    }


    // --------------------------------------------------
    // DISPLAY
    // --------------------------------------------------

    // Displays all nodes of the circular linked list
    void Display() const
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;

        } while (temp != head);

        cout << endl;
    }


    // --------------------------------------------------
    // DELETE FROM END
    // --------------------------------------------------

    // Deletes the last node of the circular linked list
    void DeletionFromEnd()
    {
        if (head == NULL)
        {
            return;
        }

        // Only one node
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        // Find second-last node
        while (temp->next->next != head)
        {
            temp = temp->next;
        }

        Node* lastNode = temp->next;

        // Second-last points back to head
        temp->next = head;

        delete lastNode;
    }


    // --------------------------------------------------
    // DELETE FROM START
    // --------------------------------------------------

    // Deletes the first node of the circular linked list
    void DeletionFromStart()
    {
        if (head == NULL)
        {
            return;
        }

        // Only one node
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        // Find last node
        while (temp->next != head)
        {
            temp = temp->next;
        }

        Node* oldHead = head;

        // Move head to next node
        head = head->next;

        // Last node points to new head
        temp->next = head;

        delete oldHead;
    }


    // --------------------------------------------------
    // DELETE AFTER POSITION
    // --------------------------------------------------

    // Deletes the node after the specified 0-based position
    void DeleteAfter(int position)
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        // Move to required position
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;

            if (temp == head)
            {
                cout << "Position out of bounds.\n";
                return;
            }
        }

        Node* nodeToDelete = temp->next;

        // If the node after temp is head,
        // we are deleting the first node
        if (nodeToDelete == head)
        {
            DeletionFromStart();
            return;
        }

        temp->next = nodeToDelete->next;

        delete nodeToDelete;
    }


    // --------------------------------------------------
    // CLEAR
    // --------------------------------------------------

    // Deletes all nodes from the circular linked list
    void clear()
    {
        if (head == NULL)
        {
            return;
        }

        // Only one node
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head->next;

        while (current != head)
        {
            Node* nextNode = current->next;

            delete current;

            current = nextNode;
        }

        delete head;
        head = NULL;
    }
};


// ==================================================
// MAIN
// ==================================================

int main()
{
    CircularSinglyLinkedList list;


    // Insert at tail
    cout << "Insertion at Tail:\n";

    list.InsertionAtTail(1);
    list.InsertionAtTail(2);
    list.InsertionAtTail(3);

    list.Display();


    // Insert at start
    cout << "\nInsertion at Start:\n";

    list.InsertionAtStart(0);

    list.Display();


    // Insert after position 2
    cout << "\nInsert After Position 2:\n";

    list.InsertAfter(2, 5);

    list.Display();


    // Search
    cout << "\nSearching for 2: ";

    if (list.SearchingForKey(2))
        cout << "Found\n";
    else
        cout << "Not Found\n";


    // Delete from end
    cout << "\nDeletion From End:\n";

    list.DeletionFromEnd();

    list.Display();


    // Delete from start
    cout << "\nDeletion From Start:\n";

    list.DeletionFromStart();

    list.Display();


    // Delete after position
    cout << "\nDelete After Position 1:\n";

    list.DeleteAfter(1);

    list.Display();


    // Clear
    list.clear();

    cout << "\nList cleared.\n";

    return 0;
}
