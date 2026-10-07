#include<iostream>
#include<string>
using namespace std;

class Stack
{
    int top;
    int capacity;
    char* arr;

    public:

    Stack(int s)
    {
        top = -1;
        capacity = s;
        arr=new char[capacity];
    }

    void push(char val)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;

        arr[top] = val;
    }

    char pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            
        }
        else
        {
            return arr[top--];
           
        }
        
    }

    char peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }
};

int precedence(char c){

    if (c=='^')
    {
        return 3;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
    
}

string infixtoprefix(string infix)
{
    string prefix="";
    Stack s(infix.length());

    for (int i = infix.length()-1; i >= 0; i--)
    {
        char ch=infix[i];                                               //"a+b*(d+e)"
        if(ch>='a'&& ch<'z'||ch>='A'&&ch<='Z')
        {
            prefix+=ch;

        }
        else if (ch==')')
        {
            s.push(ch);
        }
        else if(ch=='(')
        {
            while (!s.isEmpty()&&s.peek()!=')')
            {
                char op=s.pop();
                prefix+=op;
            }
            if (!s.isEmpty()&&s.peek()==')')
            {
                s.pop();
            }
            
            
        }
        else{
            while (!s.isEmpty()&& precedence(ch)<precedence(s.peek()))
            {
                char op=s.pop();
                prefix+=op;
            }
            s.push(ch);
            
        }
        
    }
    while (!s.isEmpty())
    {
        char c=s.pop();
        prefix+=c;
    }
    

    string result = "";

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        result += prefix[i];
    }

    return result;

  
}

string infixtopostfix(string infix){

    string postfix="";
    Stack s(infix.length());
    for (int i = 0; i < infix.length(); i++)
    {
        char ch=infix[i];
        if (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
        {
            postfix+=ch;
        }
        else if (ch=='(')
        {
            s.push(ch);
        }
        else if (ch==')')
        {
            while (!s.isEmpty()&&s.peek()!='(')
            {
                char op=s.pop();
                postfix+=op;
            }
            if (!s.isEmpty()&&s.peek()=='(')
            {
                s.pop();
            }
            
        }
        else{
            while (!s.isEmpty()&&precedence(ch)<=precedence(s.peek()))
            {
                char p=s.pop();
                postfix+=p;
            }
            s.push(ch);
        }
        

        
        
    }

    while (!s.isEmpty())
    {
        char c=s.pop();
        postfix+=c;
    }
    
    return postfix;
    
}
int main()
{

    string infix="a+b*(d+e)";
    // string postf=infixtoprefix(infix);
    string postfix=infixtopostfix(infix);

    cout<<"Infix :"<<infix<<endl;

    cout<<"Postfix: "<<postfix<<endl;
}