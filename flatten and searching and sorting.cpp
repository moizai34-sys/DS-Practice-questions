#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* child;
    node* next;
    node(int val){
        data=val;
        next=child=NULL;

    }
};

// class linkedlist{

//     public:
//     node* head;
//     linkedlist()
//     {
//         head=NULL;

//     }
//     void pushback(node& n)
//     {
//         if(head==NULL)
//     }
// }
class linkedlist
{
    public:
    node* head;
    node* tail;
    linkedlist(){
        head=tail=NULL;
    }
    void pushfront(int val)
    {
        node* newnode=new node(val);
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }

    void pushback(int val)
    {
        node* newnode=new node(val);
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }


    void display(){
        if (head == NULL)
        {
            cout<<"List is empty.."<<endl;
            return;
        }
        node* temp=head;
        while (temp!=NULL)
        {
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
node* node_at_pos(int pos)
{
    if (head == NULL || pos < 1 || pos > len_of_ll())
        return NULL;

    node* temp = head;

    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    return temp;
}
    int nodepos(node* n)
{
    int pos = 1;
    node* temp = head;

    while (temp != NULL)
    {
        if (temp == n)
        {
            return pos;
        }

        temp = temp->next;
        pos++;
    }

    return -1;
}



};

void comb_sort(linkedlist& l1){

    int gap=l1.len_of_ll();
    bool swapped=true;
    while (gap!=1||swapped)
    {
        gap=gap*10/13;
        if(gap<1)
        {
            gap=1;
        }
        swapped=false;
        for (int i = 0; i+gap < l1.len_of_ll(); i++)
        {
            node* first=l1.node_at_pos(i+1);
            node* second=l1.node_at_pos(i+gap+1);
            if (first->data>second->data)
            {
                int temp=first->data;
                first->data=second->data;
                second->data=temp;
                swapped=true;
            }
            
        }
        
    }
    
}

void shell_sort(linkedlist& l1){

    int n=l1.len_of_ll();
    for (int gap = n/2; gap > 0; gap/=2)
    {
        for (int i = 0; i < n; i++)
        {
            node* current=l1.node_at_pos(i+1);

            int temp=current->data;
            int j=i;
            while (j>=gap)
            {
                node* prev=l1.node_at_pos(j-gap+1);
                if (prev->data<=temp)
                {
                    break;
                }
                else{
                    node* target=l1.node_at_pos(j+1);
                    target->data=prev->data;
                    j=j-gap;
                }
                node* target=l1.node_at_pos(j+1);
                target->data=temp;
                
            }
            
        }
        
    }
    
}
    void flatten(linkedlist& l1)         //if you dont want to add child next to its parent and only flatten the linked list
    {
        node* curr=l1.head;
        node* last=l1.head;

        while(last->next!=NULL)
        {
            last=last->next;
        }
        while (curr!=NULL)
        {
            if (curr->child!=NULL)
            {
                last->next=curr->child;
                node* tmp=curr->child;
                while (tmp->next!=NULL)
                {
                    tmp=tmp->next;
                }
                last=tmp;

            }
            curr=curr->next;
        }
        

        


    }
//     void insertion_sort(linkedlist& l1)
// {
//     if (l1.head == NULL || l1.head->next == NULL)
//         return;

//     node* sh = l1.head;
//     node* temp = sh->next;

//     sh->next = NULL;

//     while (temp != NULL)
//     {
//         node* nextnode = temp->next;
//         node* t1 = sh;
//         node* prev = NULL;

//         while (t1 != NULL && t1->data <= temp->data)
//         {
//             prev = t1;
//             t1 = t1->next;
//         }

//         if (prev == NULL)
//         {
//             temp->next = sh;
//             sh = temp;
//         }
//         else
//         {
//             temp->next = prev->next;
//             prev->next = temp;
//         }

//         temp = nextnode;
//     }

//     l1.head = sh;

//         node* t = l1.head;

//     while (t->next != NULL)
//     {
//         t = t->next;
//     }

//     l1.tail = t;

// }

void fltten(linkedlist& l1){     // if you want to add child after its parent while flattening the linked list
    node* temp=l1.head;
    node* naxt=NULL;
    node* tail=NULL;

    while(temp!=NULL)
    {
        if(temp->child!=NULL)
        {
            naxt=temp->next;
            temp->next=temp->child;
            tail=temp->child;
            
            while(tail->next!=NULL)
            {
                tail=tail->next;
            }
            tail->next=naxt;
            
        }
        temp=temp->next;
    }
}

 void reverse_list(node* s,node* e)
    {
        node *curr = s;
        node *prev = NULL;
        node *naxt = NULL;

        while (curr !=e->next)
        {
            naxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = naxt;
        }
        e = prev;
    }
void reversekgroups(int k,linkedlist& l1){

    node* orghead=l1.head;
    node* temp=l1.head;
    node* tmp=temp;
    node* naxt;
    node* temp1;
    node* tail=NULL;
    int len=l1.len_of_ll();
    int count=len/k;
    int c=1;
    while(c!=count)
    {
        int cnt=1;
        while(cnt!=3)
        {
            tmp=tmp->next;
            cnt++;
        }
        tail=tmp;
        naxt=tail->next;
        reverse_list(temp,tail);
       temp->next=naxt;
       if (c==1){
        orghead=tail;
        tail=NULL;
        temp1=temp;
       }
       if(c>1)
       {
        temp1->next=temp;
       }
       temp=naxt;
       tmp=temp;
       
       
        c++;

    }
  


    }
    void interpolationsearch(linkedlist& l1, int val)
{
    node* temphead = l1.head;
    node* temptail = l1.tail;

    while (temphead != NULL && temptail != NULL &&
           temphead->data <= temptail->data &&
           val >= temphead->data && val <= temptail->data)
    {
        int low = l1.nodepos(temphead);
        int high = l1.nodepos(temptail);

        if (temphead == temptail)
        {
            if (temphead->data == val)
                cout << "your element found at pos: " << low << endl;
            else
                cout << "element not found" << endl;

            return;
        }

        int pos = low + (int)(
            ((double)(val - temphead->data) /
            (temptail->data - temphead->data))
            * (high - low)
        );

        node* findnode = l1.node_at_pos(pos);

        if (findnode->data == val)
        {
            cout << "your element found at pos: " << pos << endl;
            return;
        }
        else if (findnode->data < val)
        {
            temphead = findnode->next;
        }
        else
        {
            temptail = l1.node_at_pos(pos - 1);
        }
    }

    cout << "element not found" << endl;
}
void insertionsort_sort(linkedlist& l1){
    int n=l1.len_of_ll();
for( int i=1;i<n;i++)
{
    node* Key=l1.node_at_pos(i+1);
   int key=Key->data;
   int prev=i-1;

   while(prev>=0)
   {
     node* Prev=l1.node_at_pos(prev+1);
     if(Prev->data<=key)
     {
     break;
     
     }
     else{
      
      node* target=l1.node_at_pos(prev+2);
      target->data=Prev->data;
      prev--;
     }
      node* target=l1.node_at_pos(prev+2);
      target->data=key;
       

    
   }

}
    l1.head=l1.node_at_pos(1);
    l1.tail=l1.node_at_pos(n);
}
void selection_sort(linkedlist& l1){
    int n=l1.len_of_ll();
    for (int i = 0; i <n-1; i++)
    {
        int minindex=i;
        node* ithnode=l1.node_at_pos(i+1);
        node* minnode=l1.node_at_pos(minindex+1);
        for (int j = i+1; j< n; j++)
        {
            node* J=l1.node_at_pos(j+1);
            
            if (J->data<minnode->data)
            {
                minindex=j;
            }
            minnode=l1.node_at_pos(minindex+1);
            

        }
        
        node* minind=l1.node_at_pos(minindex+1);
        int temp=ithnode->data;
        ithnode->data=minind->data;
        minind->data=temp;
        
    }

    l1.head=l1.node_at_pos(1);
    l1.tail=l1.node_at_pos(n);
    
}

int main(){

//     node* n1=new node(1);
//     node* n2=new node(3);
//     node* n3=new node(5);
//     node* n4=new node(9);
//     node* n5=new node(6);
//     node* n6=new node(8);
//     node* n7=new node(10);
//     node* n8=new node(11);
//     node* n9=new node(12);
//     n1->next=n2;
//     n2->next=n3;
//     n3->next=n4;
//     n2->child=n5;
//     n5->next=n6;
//     n6->next=n7;
//     n7->next=n8;
//     n8->child=n9;
//     linkedlist l1;
//     l1.head=n1;
//     linkedlist l2;
//     node* node1=new node(2);       //2->5->7->9
//     node* node2=new node(5);       //   |
//     node* node3=new node(7);       //   v
//     node* node4=new node(9);       //   6 -> 8 -> 10 -> 11
//     node* node5=new node(6);       //                    |
//     node* node6=new node(8);       //                    v
//     node* node7=new node(10);      //                    12
//     node* node8=new node(11);
//     node* node9=new node(12);
//     node1->next=node2;
//     node2->next=node3;
//     node3->next=node4;
//     node2->child=node5;
//     node5->next=node6;
//     node6->next=node7;
//     node7->next=node8;
//     node8->child=node9;
//     l2.head=node1;

//     l1.display();

//     cout<<endl;
//     cout<<"After flatten:"<<endl;
//     flatten(l1);
//     l1.display();

//     cout<<endl<<"After flatten:"<<endl;
//     fltten(l2);
//     l2.display();
//     cout<<endl;

//     cout<<"After sorting"<<endl;
//     insertion_sort(l1);
//     l1.display();

//     linkedlist l3;

//     l3.pushfront(1);
//     l3.pushback(7);
//     l3.pushback(5);
//     l3.pushback(4);
//     l3.pushback(2);
//     insertion_sort(l3);
//     cout<<endl;

//     l3.display();
//     cout<<endl;

    

// cout << l3.node_at_pos(1)->data << endl;
// cout << l3.node_at_pos(2)->data << endl;
// cout << l3.node_at_pos(3)->data << endl;
// cout << l3.node_at_pos(4)->data << endl;
// cout << l3.node_at_pos(5)->data << endl;
// cout<<endl<<l3.nodepos(l3.head->next->next->next);


// cout<<endl;
// interpolationsearch(l3,4);
linkedlist l1;
node* n1=new node(10);
    node* n2=new node(20);
    node* n3=new node(30);
    node* n4=new node(60);
    node* n5=new node(90);
    node* n6=new node(40);
    node* n7=new node(70);
    node* n8=new node(80);
    node* n9=new node(50);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n2->child=n6;
    n6->child=n7;
    n6->next=n8;
    n4->child=n9;

    l1.head=n1;
    
   

    fltten(l1);


    cout<<endl;
    l1.display();

    cout<<endl<<"After sorting"<<endl;
    selection_sort(l1);

    l1.display();

     cout<<endl;
    interpolationsearch(l1,40);

    
}




   
/*
void insertionsort_sort(linkedlist& l1){
for( int i=1;i<n;i++)
{
    node* Key=l1.node_at_pos(i+1)
   int key=Key->data;
   int prev=i-1;

   while(prev>=0)
   {
     node* prev=l1.node_at_pos(prev+1);
     if(prev.data<=key)
     {
     break;
     
     }
     else{
      
      node* target=l1.node_at_pos(prev+2);
      target.data=prev.data;
      prev--;
     }
      node* target=l1.node_at_pos(prev+2);
      target.data=key;
       

    
   }
}}
*/


