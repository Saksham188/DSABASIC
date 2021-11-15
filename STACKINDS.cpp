///Stack stores a list of items in which an item can be added to or removed from the list only at one end.Its based on LIFO mechanism.(Last In First Out).
/// It has many operations. push(x)=Top pos pe element aa jayega  ,pop()=Removes top element from Stack ,top()=its a ptr which returns topmost value, empty()=It tells whether stack is empty or not.It returns true or false.
/// Time Complexity=O(1).     top pe ham initially -1 lete hai. push mein top++ karte, pop mein top--. for empty if top=-1 then stack is empty.
///

#include<iostream>
using namespace std;

#define n 100

class Stack
{
    int* arr;
    int top;

public:
    Stack()
    {
        arr=new int[n];
        top=-1;
    }

    void push(int x)
    {
       if(top==n-1) ///yani upar tak full hogya ho agar stack.
       {
           cout<<"Stack Overflow"<<endl;
           return;
       }

       top++; ///isse -1 se 0 hogi value.
       arr[top]=x;
    }

    void Pop()
    {
        if(top==-1)
        {
            cout<<"No element to pop\n";
            return;
        }
        top--; ///matlab agar value ho toh top-- kardo isse last element pop hojayega.
    }

   int Top()
   {
       if(top==-1)
       {
           cout<<"No element in Stack"<<endl;
           return -1;
       }
       return arr[top];
   }

   bool Empty()
   {
       if(top==-1)
        return true;
       else
        return false;
   }
};
int main()
{
    Stack Stack1;
    cout<<Stack1.Empty()<<endl;
    Stack1.push(1);
    Stack1.push(2);
    Stack1.push(3);
    Stack1.push(4);
    Stack1.push(5);
    cout<<Stack1.Top()<<endl;
    Stack1.Pop();
    cout<<Stack1.Top()<<endl;
    Stack1.Pop();
    Stack1.Pop();
    Stack1.Pop();
    Stack1.Pop();
    Stack1.Pop();
    cout<<Stack1.Top()<<endl;
    cout<<Stack1.Empty();
}



















































