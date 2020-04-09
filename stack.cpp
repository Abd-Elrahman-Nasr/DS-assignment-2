#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

template <class X>
class Stack
{
    X *arr;
    int top;
    int capacity;

public:
    Stack ()
    {

    };
    Stack(X *i, int size)
    {
        capacity = SIZE;
        arr = new X[capacity];
        for(int j = 0 ; j < size ; j++)
            arr[j] = i[j];
        top = size - 1;
    }
    //destructor
    ~Stack(){
        delete[] arr;
    }

    void push(X j)
    {
        if (isFull())
        {
            cout << "Stack is full";
            exit(EXIT_FAILURE);
        }

        cout << "Adding  " << j << endl;
        arr[++top] = j;
    };

   void pop(X &Element )
    {
        if (isEmpty())
        {
            cout << "STACK IS EMPTY";
            exit(EXIT_FAILURE);
        }
        else
        {
            Element=arr[top];
            top--;

        }

    };
    X get_top(X &Element )
    {
        if (isEmpty())
        {
            cout << "STACK IS EMPTY ON GET_TOP" <<endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            return arr[top];

        }

    };



    int size()
    {
        return top + 1;
    };
    bool isEmpty()
    {
        return top == -1;
    };
    bool isFull()
    {
        return top == capacity - 1;	// or return size() == capacity;

    };
    void print ()
    {
        cout<<"[";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "]";
        cout << endl;
    }


};

int main()
{

    int x=0;
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    Stack<int> s(arr, size);
     s.push(5);
     s.push(6);
    s.push(7);
    s.pop(x);
    s.pop(x);
    s.print();
    cout <<"TOP Element =  "<<s.get_top(x)<<endl;
    cout << "Stack SIZE =  " << s.size() << endl;
    // check if Stack is empty or not
    if (s.isEmpty())
        cout << "Stack Is Empty\n";
    else
        cout << "Stack Is Not Empty\n";

}