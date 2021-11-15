/// Making Pop Operation costly.
/// Isme push mein directly q1 mein push kar dete.
/// Pop ke lie ham q1 mein se eg 4321(is order mein rakha ho) hai toh first 3 nikalte ie 123 ko ek ek karke nikalke q2 mein dalo and fir 4 ko pop kardo and end mein swap kardo.
///
///
#include<bits/stdc++.h>
using namespace std;

class Stack
{
    int N; ///its for size of stack.
    queue<int> q1;
    queue<int> q2;
public:
    Stack()
    {
        N=0;
    }

    void pop()
    {
        if(q1.empty())
        {
            return;
        }

        while(q1.size()!=1) ///yani jab tak sirf ek element na bach jaye tab tak chalao.
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;

        queue<int>temp=q1;
        q1=q2;
        q2=temp;
    }

    void push(int value)
    {
        q1.push(value);
        N++;
    }

    int top()
    {
        if(q1.empty())
            return -1;
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q2.push(ans);

        queue<int>temp=q1;
        q1=q2;
        q2=temp;

        return ans;
    }

    int size()
    {
        return N;
    }
};

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    cout<<s1.top()<<endl;
    s1.pop();

    cout<<s1.top()<<endl;
    s1.pop();

    cout<<s1.top()<<endl;
    s1.pop();

    cout<<s1.top()<<endl;
    s1.pop();

    cout<<s1.size();

}





























































