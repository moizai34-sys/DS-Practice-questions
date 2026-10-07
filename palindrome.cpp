#include <iostream>
using namespace std;

class node
{
public:
    string character;
    int data;
    node *next;

public:
    node() {}
    // node(string c)
    // {
    //     character = c;
    //     next = NULL;
    // }
    node(int val)
    {
        data=val;
        next = NULL;
    }
   
};

class linkedList
{

public:
    node *head;
    node *tail;

    linkedList()
    {
        head = NULL;
        tail = NULL;
    }
    

    // void pushback_str(string val)
    // {

    //     node *newnode = new node(val);

    //     node *temp = head;
    //     if (head == NULL)
    //     {
    //         head = tail = newnode;
    //     }
    //     else
    //     {

    //         tail->next = newnode;
    //         tail = newnode;
    //     }
    // }

    void pushback_int(int val)
    {

        node *newnode = new node(val);

        node *temp = head;
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



    void popback(){
        node* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;

        }
        temp->next=NULL;
        delete tail;
        tail=temp;
        
    }

    void popfront()
    {
        node* temp=head;
        head=head->next;
        delete temp;
    }

    // void pushfront_str(string val)
    // {
    //     node *newnode = new node(val);

    //     if (head == NULL)
    //     {
    //         head = tail = newnode;
    //     }
    //     else
    //     {
    //         newnode->next = head;
    //         head = newnode;
    //     }
    // }

    void pushfront_int(int val)
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
   

    void print_list()
    {
        node *temp = head;
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
            cout << "NULL";
        }
    }

    void reverse_list()
    {
        node *curr = head;
        node *prev = NULL;
        node *naxt = NULL;

        while (curr != NULL)
        {
            naxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = naxt;
        }
        head = prev;
    }
    int len_of_ll()
    {
        node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    // string *copy_to_array_str()
    // {
    //     int sizearr = len_of_ll();

    //     string *arr = new string[sizearr];

    //     int count = 0;
    //     node *temp = head;

    //     while (temp != NULL)
    //     {
    //         arr[count] = temp->character;
    //         count++;
    //         temp = temp->next;
    //     }

    //     return arr;
    // }

    int *copy_to_array_int()
    {
        int sizearr = len_of_ll();

        int *arr = new int[sizearr];

        int count = 0;
        node *temp = head;

        while (temp != NULL)
        {
            arr[count] = temp->data;
            count++;
            temp = temp->next;
        }

        return arr;
    }

   
    // void check_palindrome_str(linkedList &l)
    // {

    //     int sizearray = l.len_of_ll();

    //     string *array1 = l.copy_to_array_str();

    //     l.reverse_list();

    //     string *array2 = l.copy_to_array_str();

    //     for (int i = 0; i < sizearray; i++)
    //     {
    //         if (array1[i] != array2[i])
    //         {
    //             cout << "Linked list is not palindrome" << endl;
    //             l.reverse_list();

    //             delete[] array1;
    //             delete[] array2;

    //             return;
    //         }
    //     }

    //     cout << "Linked list is palindrome" << endl;

    //     delete[] array1;
    //     delete[] array2;
    // }

        void check_palindrome_int(linkedList &l)
    {

        int sizearray = l.len_of_ll();

        int *array1 = l.copy_to_array_int();

        l.reverse_list();

        int *array2 = l.copy_to_array_int();

        for (int i = 0; i < sizearray; i++)
        {
            if (array1[i] != array2[i])
            {
                cout << "Linked list is not palindrome" << endl;
                l.reverse_list();

                delete[] array1;
                delete[] array2;

                return;
            }
        }

        cout << "Linked list is palindrome" << endl;

        delete[] array1;
        delete[] array2;
    }
};

int main()
{
   


    
    linkedList l1;
    l1.pushfront_int(7);
    l1.pushback_int(8);
    l1.pushback_int(8);
    l1.pushback_int(7);
   
    l1.print_list();
    cout<<endl;
    l1.check_palindrome_int(l1);

    


}