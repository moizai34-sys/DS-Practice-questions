#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string data;
    node *next;

    node(string val)
    {
        data = val;
        next = NULL;
    }
};

class circular_ll
{

    node *head;
    node *tail;

public:
    circular_ll()
    {
        head = NULL;
    }

    void pushfront(string val)
    {

        node *newnode = new node(val);
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
    void pushback(string val)
    {

        node *newnode = new node(val);

        node *temp = head;
        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
        }
        else
        {

            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }

    void insert_at_pos(string val, int pos)
    {
        node *newnode = new node(val);
        if (pos == 1)
        {
            pushfront(val);
            return;
        }

        node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;

        if (temp == tail)
        {
           pushback(val);
        }
    }
    void search(string val){
        node* temp=head;
         int pos=1;
        while(temp!=tail){
            if(temp->data==val){
                cout<<"Found at position: "<<pos<<endl;
                return;
            }
            temp=temp->next;
            pos++;
        }
    }
    void popfront()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            node *temp = head;
            head = temp->next;
            delete temp;
            tail->next = head;
        }
    }
    void popback()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            node *temp = head;
            while (temp->next != tail)
            {

                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;
        }
    }
    int len_of_ll()
    {
        node *temp = head->next;
        int count = 1;
        while (temp != head)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
  

   void update_list()
    {
        if (head == NULL)
        {
            return;
        }

        node *temp = tail;

        while (head != tail)
        {
            temp = temp->next;
            temp = temp->next;

            node *todelete = temp->next;

            cout << "Removed: " << todelete->data << endl;

            if (todelete == head)
            {
                head = head->next;
            }

            if (todelete == tail)
            {
                tail = temp;
            }

            temp->next = todelete->next;

            delete todelete;

            tail->next = head;
        }
    }

    void print_list()
    {

        if (head == NULL)
        {
            cout << "Linked list is empty.." << endl;
            return;
        }
        else
        {
            cout << head->data;
            node *temp = head->next;
            while (temp != head)
            {
                cout << "," << temp->data;
                temp = temp->next;
            }
        }
    }
    void input_ll(){

        int n=6;
        
        cout<<"Enter 11 players"<<endl;
        
        for (int i = 0; i < n; i++)
        {
            
            string dat;
            

            cout<<"Enter player "<<i+1<<":";

            getline(cin,dat);
            
            if (i==0)
            {
                pushfront(dat);
            }
            else{
                pushback(dat);
            }
        }
        cin.ignore();
        
    }
};
int main()
{

    circular_ll l1;

    l1.input_ll();


    l1.update_list();

    cout << endl;
    l1.print_list();

    return 0;
}