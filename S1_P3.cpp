#include <bits/stdc++.h>
using namespace std;


template<class T>
class Queue
{
private:

    int MX_Capacity;
    int length;
    int Front,Back;
    int init_SZ;

    T *Array;
    T val ;


public:
    Queue()
    {

        MX_Capacity=9999;
        Array=new T[MX_Capacity];
        Back=MX_Capacity-1;
        length=0;
        Front=0;

    };
    Queue(T val ,int init_SZ)
    {

         if (init_SZ <= 0){MX_Capacity = 9999;}
		 else{MX_Capacity = init_SZ;}

		Front = 0;
		Array = new T[MX_Capacity];
		Back = MX_Capacity - 1;
		length = 0;

		for(int i=0 ; i<init_SZ;++i)
        {
            push_Back(val);
        }

    };

    bool ISEmpty(){return (length==0);}
    bool ISFull(){return(length==MX_Capacity);}
    int Size(){return length;}

    T&get_front()
    {
       if(ISEmpty())
       {
           cout << "The Queue is empty,can't return any item.\n";
       }
       else
       {
        return Array[Front];
       }
    }



    void pop_Front()
    {
       if(ISEmpty())
       {
           cout << "The Queue is actually empty.\n";
       }
       else
       {
           ++Front;
           --length;
       }

    };
    void push_Back(T val)
    {

      if(ISFull())
      {
          cout << "The queue is full can't push element.\n";
      }
      else
      {
          Back=(Back+1)%MX_Capacity;
          Array[Back]=val;
          ++length;
      }

    };

    void Print()
    {
        if(!ISEmpty())
        {
          cout <<"The queue items = { ";
          for(int i=Front ; i!=Back; ++i)
          {
              cout << Array[i]<<" ,";
          }
          cout <<Array[Back];
          cout << " }\n\n\n";

        }
        else
        {
           cout << "The Queue is actually empty.\n";
        }
    }


    ~Queue()
    {
      delete[]Array;
    };
};



int main()
{


/**     Pop_front    Push_back**/
/**      Front       Back**/
/** Queue = {1,2,3,4,5} **/

/// Case 1 : integer.
Queue<int>Q(1,9);
Q.Print();


Queue<int>Q2;
Q2.push_Back(1);
Q2.push_Back(2);
Q2.push_Back(3);
Q2.push_Back(4);
Q2.push_Back(5);
cout <<"The front element = "<<Q2.get_front()<<"\n";
cout<<"The size = "<<Q2.Size()<<endl;
Q2.Print();


Q2.pop_Front();
cout <<"The front element = "<<Q2.get_front()<<"\n";
cout<<"The size = "<<Q2.Size()<<endl;
Q2.Print();

Q2.pop_Front();
cout <<"The front element = "<<Q2.get_front()<<"\n";
cout<<"The size = "<<Q2.Size()<<endl;
Q2.Print();


Q2.pop_Front();
cout <<"The front element = "<<Q2.get_front()<<"\n";
cout<<"The size = "<<Q2.Size()<<endl;
Q2.Print();



cout << "\n\n\n\n";


/// Case 2 : Character.
Queue<char>Q3('Z',9);
Q3.Print();


Queue<char>Q4;
Q4.push_Back('A');
Q4.push_Back('B');
Q4.push_Back('C');
Q4.push_Back('D');
Q4.push_Back('E');
cout <<"The front element = "<<Q4.get_front()<<"\n";
cout<<"The size = "<<Q4.Size()<<endl;
Q4.Print();


Q4.pop_Front();
cout <<"The front element = "<<Q4.get_front()<<"\n";
cout<<"The size = "<<Q4.Size()<<endl;
Q4.Print();

Q4.pop_Front();
cout <<"The front element = "<<Q4.get_front()<<"\n";
cout<<"The size = "<<Q4.Size()<<endl;
Q4.Print();


Q4.pop_Front();
cout <<"The front element = "<<Q4.get_front()<<"\n";
cout<<"The size = "<<Q4.Size()<<endl;
Q4.Print();



cout << "\n\n\n\n";


/// Case 3 : String.
Queue<string>Q5("Bahaa",9);
Q5.Print();


Queue<string>Q6;
Q6.push_Back("Bahaa EL-Deen Osama");
Q6.push_Back("Abdelrhman Nasr");
Q6.push_Back("Karim Nur El-Deen");
Q6.push_Back("Mohamed Ahmed ");
Q6.push_Back("Alaa Mostafa");
cout <<"The front element = "<<Q6.get_front()<<"\n";
cout<<"The size = "<<Q6.Size()<<endl;
Q6.Print();


Q6.pop_Front();
cout <<"The front element = "<<Q6.get_front()<<"\n";
cout<<"The size = "<<Q6.Size()<<endl;
Q6.Print();

Q6.pop_Front();
cout <<"The front element = "<<Q6.get_front()<<"\n";
cout<<"The size = "<<Q6.Size()<<endl;
Q6.Print();


Q6.pop_Front();
cout <<"The front element = "<<Q6.get_front()<<"\n";
cout<<"The size = "<<Q6.Size()<<endl;
Q6.Print();

cout << "\n\n\n";


/// Case 4 :floating.
Queue<float>Q8(1.345,9);
Q8.Print();


Queue<float>Q9;
Q9.push_Back(2.345);
Q9.push_Back(5.23435);
Q9.push_Back(6.7687);
Q9.push_Back(7.2343);
Q9.push_Back(8.3456);
cout <<"The front element = "<<Q9.get_front()<<"\n";
cout<<"The size = "<<Q9.Size()<<endl;
Q9.Print();


Q9.pop_Front();
cout <<"The front element = "<<Q9.get_front()<<"\n";
cout<<"The size = "<<Q9.Size()<<endl;
Q9.Print();

Q9.pop_Front();
cout <<"The front element = "<<Q9.get_front()<<"\n";
cout<<"The size = "<<Q9.Size()<<endl;
Q9.Print();


Q9.pop_Front();
cout <<"The front element = "<<Q9.get_front()<<"\n";
cout<<"The size = "<<Q9.Size()<<endl;
Q9.Print();







    return 0;
}
