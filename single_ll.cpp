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

    node* head;
    node* tail;

    public:
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
            cout<<temp->data<<" "<<endl;
            temp=temp->next;
        }
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

    l1.pushfront(1);
    l1.pushfront(2);
    l1.pushfront(3);
    // l1.pushback(4);
    // l1.popfront();
    // l1.popback();
    // l1.pushfront(5);
    // l1.pushback(6);
    // l1.popback();
    linkedlist l2;

    l2.pushfront(3);
    l2.pushfront(2);
    l2.pushfront(1);
    l2.pushfront(6);
    l2.pushback(7);
    
    l2.print_list();

    // l2.search_middle();

    // l1.print_list();
    // l1.search_middle();

    // l2.search(7);

  

    return 0;
}