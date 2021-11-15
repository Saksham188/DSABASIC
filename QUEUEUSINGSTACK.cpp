///Approach1: Using 2 Stacks and DeQueue operation costly. enqueue not much costly.
/// EnQueue Operation: Push x to Stack1.
///Dequeue Operation: 1.If both stacks are empty then print error. 2.If stack2 is empty,while stack1 is not empty,push everything from stack1 to stack2. 3.Pop the element from stack2 and return it.
/// Time Complexity of Push ie Enqueue is O(1) and in Pop in worst case it will be O(n)

/*
#include<bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if(s1.empty()&& s2.empty())
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int TopValue=s2.top(); ///hame return karna hoga s2 ke top ki value.
        s2.pop();
        return TopValue;
    }
    bool Empty()
    {
        if(s1.empty() and s2.empty())
            return true;
        return false;
    }
};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

}
*/

///Approach2:
///Using function call stack and one self made stack.
/// Enqueue remains same.
/// For Dequeue: If stack1 is empty print error. 2. If Stack1 has only 1 element return it. 3. Recursively pop everything from stack1,store the popped item in a variable res,push res back to stack1 and return res.
///
///
///
#include<bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1;

public:

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if(s1.empty())
        {
            cout<<"Queue is empty\n";
            return -1;
        }

        int x=s1.top();
        s1.pop();

        if(s1.empty())
            return x;
        int item=pop(); ///recursive call
        s1.push(x);
        return item;
    }

    bool Empty()
    {
        if(s1.empty())
            return true;
        return false;
    }
};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

}
















































