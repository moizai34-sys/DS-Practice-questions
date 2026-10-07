#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data= val;
        next= NULL;
    }

};

class linkedlist{

    node* tail;
    
    public:
    node* head;
    linkedlist(){
        head=NULL;

    }

    void pushfront(int val){
        
        node* newnode=new node(val);
        // node newnode(val);// this is static approach so we dont use thiat we use new keyword approach as we use just above
        if (head==NULL){
            head=tail=newnode;
        }else{
            newnode->next=head; 
            head=newnode;

        }


    }
    void pushback(int val){

        node* newnode=new node(val);

        node* temp =head;
         if (head==NULL){
            head=tail=newnode;
        }else{
           
            

            tail->next=newnode;
            tail=newnode;
        
        }
    }
    void popfront(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
            node* temp=head;
            head=temp->next;
            temp->next=NULL;
            delete temp;
        }
    }
    void popback(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
            node* temp=head;
            while(temp->next!=tail){
               
                temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
            tail=temp;

           
            
        }
    }
    void search(int val){

        node* temp=head;
        int idx=0;
        while(temp!=NULL){
            
            if (temp->data==val)
            {
               cout<<"Your searched element is found at index :"<<idx<<endl; 
               return;
            }
            temp=temp->next;
            idx++;
        }
        cout<<"Sorry.. Your required element is not found in the list"<<endl;

    }
    void insert(int val, int pos){
        node* temp=head;
        if (pos<0)
        {
            cout<<"You entered invalid position"<<endl;
        }
        else if (pos==0)
        {
            pushfront(val);
            return;
        }
        else{
            
            for(int i=0; i<pos-1;i++){
                if (temp== NULL){
                    cout<<"invalid position"<<endl;
                    
                }
                temp=temp->next;
            }
            node* newnode=new node(val);
            newnode->next=temp->next;
            temp->next=newnode;


        }
        
    }
    void print_list(){
        node* temp=head;

        while(temp!= NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
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

    void search_middle(){
        int count=1;

        node* fast=head;
        node* slow=head;
        
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            count++;
            fast=fast->next->next;
            
            
        }
        cout<<"Middle of linked list "<<count<<" and value at middle is: "<<slow->data<<endl;
    }
};

node * reversell(node* head, node* tail)
{
    node* curr=head;
    node* naxt=NULL;
    node* prev=NULL;
    node* stop=tail->next;

    while (curr!=stop)
    {
        naxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=naxt;
    }
    return prev;
    
}
node* findkthnode(int k, node* n)
{
    node* kthnode = n;

    for (int i = 1; i < k; i++)
    {
        kthnode = kthnode->next;
    }

    return kthnode;
}


void reversekgroups(linkedlist& l1, int k)
{
    int n = l1.len_of_ll() / k;

    node* temp = l1.head;
    node* prevgroup = NULL;

    for (int j = 0; j < n; j++)
    {
        // Find kth node of current group
        node* kthnode = findkthnode(k, temp);

        // Save first node of next group
        node* nextnode = kthnode->next;

        // Reverse current group
        reversell(temp, kthnode);

        // First group
        if (j == 0)
        {
            l1.head = kthnode;
        }
        else
        {
            prevgroup->next = kthnode;
        }

        // temp is now the last node of reversed group
        temp->next = nextnode;

        // Save last node of current group
        prevgroup = temp;

        // Move to next group
        temp = nextnode;
    }
}
int main(){

    linkedlist l1;

    l1.pushfront(1);
    l1.pushback(2);
    l1.pushback(3);
    l1.pushback(4);
    l1.pushback(5);
    l1.pushback(6);
    l1.pushback(7);
    l1.pushback(8);
    l1.pushback(9);
    l1.pushback(10);

    
    l1.print_list();

    cout<<endl<<"After reversing k groups:"<<endl;

    reversekgroups(l1,3);

    l1.print_list();

    // l2.search_middle();

    // l1.print_list();
    // l1.search_middle();

    // l2.search(7);

  

    return 0;
}