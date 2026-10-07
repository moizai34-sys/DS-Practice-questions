#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class linkedlist
{
    node *head;
    node *tail;

public:
    linkedlist()
    {
        head = tail = NULL;
    }

    void pushfront(int val)
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

    void popfront()
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    void pushback(int val)
    {

        node *newnode = new node(val);

        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        else
        {

            tail->next = newnode;
            tail = newnode;
            return;
        }
    }

    void popback()
    {
        node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void print_list()
    {
        node *temp = head;

        while (temp != NULL)
        {

            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
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

    bool check_even()
    {
        node *temp = head;
        bool is_even = false;
        while (temp != NULL)
        {
            if (temp->data % 2 == 0)
            {
                is_even = true;
            }
            else
            {
                return false;
            }
            temp = temp->next;
        }
        return is_even;
    }

    bool check_odd()
    {
        node *temp = head;
        bool is_odd = false;
        while (temp != NULL)
        {
            if (temp->data % 2 != 0)
            {
                is_odd = true;
            }
            else
            {
                return false;
            }
            temp = temp->next;
        }
        return is_odd;
    }
    void input_ll(){
        int no_of_elements = 0;
    cout << "How many elemnts you want to insert in linked list:";
    cin >> no_of_elements;

    for (int i = 1; i <= no_of_elements; i++)
    {
        int number = 0;
        cout << "Enter Element " << i << ":";
        cin >> number;
        int choice;
        cout << "From where you want to insert elemnt from back or front?" << endl;
        cout << "For front Enter 1 " << endl
             << "for back enter 2" << endl
             << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            pushfront(number);
            cout<<endl;
            break;
        case 2:
            pushback(number);
            cout<<endl;
            break;
        default:
            break;
        }
        char selection;
        cout << "Do you want to pop any elemnt??" << endl;
        cout << "Enter 'Y' for yes and 'N' for no." << endl;
        cout << "Enter your selection:";
        cin >> selection;
        if (selection == 'N' || selection == 'n')
        {
            continue;
        }
        else
        {
            int Choice;
            cout << "Enter 1 for pop from front " << endl
                 << "Enter 2 for pop from back." << endl;
            cout << "Enter your choice:";
            cin >> Choice;
            switch (Choice)
            {
            case 1:
                popfront();
                cout<<endl;
                i--;
                break;
            case 2:
                popback();
                cout<<endl;
                i--;
                break;
            default:
                break;
            }
        }
    }

    }

    void rearrange_list()
    {

        bool iseven = check_even();
        bool isodd = check_odd();

        if (iseven == true)
        {
            cout << "List is already arranged in required order." << endl;
            return;
        }
        else if (isodd == true)
        {
            cout << "List is already arranged in required order." << endl;
            return;
        }

        else
        {
            int sizeofll = len_of_ll();

            node *prev = NULL;
            node *Next = NULL;
            for (int i = 0; i < sizeofll; i++)
            {
                prev = head;
                Next = prev->next;

                while (prev->next != NULL && Next != NULL)
                {
                    if (Next->data % 2 == 0)
                    {

                        int Temp = prev->data;
                        prev->data = Next->data;
                        Next->data = Temp;
                        prev = prev->next;
                        Next = Next->next;
                    }
                    else
                    {
                        prev = prev->next;
                        Next = prev->next;
                    }
                }
            }
            cout << "List has arranged in required order.";
        }
    }
};

int main()
{
    linkedlist l1;
    l1.input_ll();
    cout<<endl;

    l1.print_list();
    cout<<endl;

    l1.rearrange_list();
    cout << endl;

    l1.print_list();
}