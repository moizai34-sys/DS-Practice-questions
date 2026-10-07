#include <iostream>
using namespace std;


// =========================
// Node
// =========================

class node
{
public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};


// =========================
// Linked List
// =========================

class linkedlist
{
public:
    node* head;
    node* tail;

    linkedlist()
    {
        head = tail = NULL;
    }


    int len_of_ll()
    {
        node* temp = head;
        int count = 0;

        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        return count;
    }

    int givepos(node* n){

        int count=1;
        node* temp=head;
        while (temp!=NULL)
        {
            if (temp==n)
            {
                return count;
            }
            else{
                temp=temp->next;
                count++;
            }
            
        }
        
    }
    void pushfront(int val)
    {
        node* newnode = new node(val);

        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }


    void pushback(int val)
    {
        node* newnode = new node(val);

        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }


    void print_list()
    {
        node* temp = head;

        if (head == NULL)
        {
            cout << "List is empty.." << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
    }
};


// =========================
// Insertion Sort
// =========================

void insertion_sort(linkedlist& l1)
{
    if (l1.head == NULL || l1.head->next == NULL)
        return;

    node* sh = l1.head;
    node* temp = sh->next;

    // Separate first node
    sh->next = NULL;

    while (temp != NULL)
    {
        node* nextnode = temp->next;

        node* t1 = sh;
        node* prev = NULL;

        // Find correct position
        while (t1 != NULL && t1->data <= temp->data)
        {
            prev = t1;
            t1 = t1->next;
        }

        // Insert at beginning
        if (prev == NULL)
        {
            temp->next = sh;
            sh = temp;
        }

        // Insert somewhere after first node
        else
        {
            temp->next = prev->next;
            prev->next = temp;
        }

        temp = nextnode;
    }

    l1.head = sh;

    // Update tail
    node* t = l1.head;

    while (t->next != NULL)
    {
        t = t->next;
    }

    l1.tail = t;
}


// =========================
// Binary Search
// =========================



// =========================
// Main
// =========================
node* middlenode(node* s,node* e){
    
    node* slow=s;
    node* fast=s->next;

    while(fast!=e&&fast->next!=e)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

void binarysearch(int val,linkedlist& l1){

    node* had=l1.head;
    node* tail=NULL;
    
    while(had!=tail){
        node* mid=middlenode(had,tail);
        if(mid->data==val)
        {
            int pos;
            pos=l1.givepos(mid);
            cout<<endl<<"Your element is found at pos: "<<pos<<endl;
            return;
        }
        else if(mid->data<val){
            had=mid->next;
        }
        else{
            tail=mid;
        }

    }
    
    cout<<"Value not found.."<<endl;
    return;
}
int main()
{
    linkedlist l1;

    l1.pushfront(5);
    l1.pushfront(1);
    l1.pushfront(2);
    l1.pushfront(3);
    l1.pushfront(10);
    l1.pushfront(9);
    l1.pushfront(6);

    cout << "Original List: ";
    l1.print_list();


    // Sort the linked list first
    insertion_sort(l1);

    cout << "Sorted List: ";
    l1.print_list();


    binarysearch(9,l1);
   

    return 0;
}




