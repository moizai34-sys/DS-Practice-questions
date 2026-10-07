#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* child;

    node(int val){
        data= val;
        next= NULL;
        child =NULL;
    }

};

class linkedlist{

    node* head;
    node* tail;


    public:
    node* head1;
    node* head2;
    node* head3;
    linkedlist(){
        head=head1=head2=head3=tail=NULL;

    }

    void pushfront(int val){
        
        node* newnode=new node(val);
        // node newnode(val);// this is static approach so we dont use thiat we use new keyword approach as we use just above
        if (head==NULL){
            head=tail=newnode;
        }else{
            newnode->next=head; 
            head=newnode;
            if (head->next!=NULL)
            {
                head1=head->next;
            }
            else if (head1->next->next!=NULL)
            {
                head3=head1->next->next;
            }
            else if (head1->child!=NULL)
            {
                head2=head1->child;
            }
            else{
                return;
            }
            
            
            

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
    void add_child(int val,node* h){
        node* newnode=new node(val);
        if (h==NULL)
        {
            cout<<"There is not any node present so add child node is not possible"<<endl;
            return;
        }
        else{
            
            h->child=newnode;
          
        }
        

    }
    
    void print_list(){
        node* temp=head;

        while(temp!= NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
            if (temp==head1)
            {
                node* temp1=head1;
                while (temp1!=NULL)
                {
                    cout<<temp1->data<<"->";
                    temp1=temp1->child;
                    if (temp1==head2)
                    {
                        node* temp2=head2;
                        while (temp2!=NULL)
                        {
                            cout<<temp2->data<<"->";
                            temp2=temp2->next;
                        }
                        head1=head1->child;
                    }
                    
                }
                temp=temp->next;
            }
            if (temp==head3)
            {
                node* temp3=head3;
                while (temp3!=NULL)
                {
                    cout<<temp3->data<<"->";
                }
                temp=temp->next;
            }
            
            
        }
        cout<<"NULL"<<endl;
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
int main(){

    linkedlist l1;

    l1.pushfront(10);
    l1.pushback(20);
    cout<<endl<<l1.head1<<endl;
    l1.print_list();

  

    return 0;
}