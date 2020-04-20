#include <iostream>
using namespace std;
class Student
{

private:
    string Name;
    int ID;
    float GPA;
public:
    Student(){};
    Student(string name,int id ,float gpa)
    {
        this->Name=name;
        this->ID=id;
        this->GPA=gpa;
    }

    void print()
    {
        cout <<"Name " <<Name<<" ID " <<ID <<" GPA "<<GPA <<endl;
    }
    int get_ID()
    {
        return ID ;
    }



};
class student_list
{

    struct node
     {
        Student data;
        node *next;

    };

    node *last;
    node *first,*head;
    int length;
public:
    student_list()
    {
        last = NULL;
        first=NULL;
        head=NULL;
        length = 0;

    }

    bool isEmpty()
    {
        return length == 0;
    }
    void  insert(Student s)
    {
        node *newNode = new node;
        newNode->data = s;
        if (isEmpty())
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else
        {
            last->next = newNode;
            newNode->next = NULL;
        }
        length++;
       //cout<<last->next<<endl;
    }
    node *cur = last;

    ostream &operator<< ( ostream& out ,const student_list *e)
    {

    }
    void print()
    {

        for(int i=0; i < length; i++){

            cout << last -> data << endl;
            cout << last -> next << endl;
        }


    }


    void remove(int item)
    {
        if (isEmpty())
        {
            cout << "Can not remove from empty list\n";
            return;
        }

        node *current, *trailCurrent;
        if (last->data.get_ID() == item)
        {
            current = first;

            first = first->next;
            delete current;
            length--;
            if (length == 0)
                last = NULL;
        }
        else
        {
            current = first->next;
            trailCurrent = first;
            while (current != NULL)
            {
                if (current->data.get_ID() == item)
                    break;
                trailCurrent = current;
                current = current->next;
            }

            if (current == NULL)
                cout << "The item is not there\n";
            else
            {
                trailCurrent->next = current->next;
                if (last == current) //delete the last item
                    last = trailCurrent;
                delete current;
                length--;
            }
        }
    }


};

int main() {
    Student s1("karim",20170200,3.1);
    Student s2("bahha",20170201,3.2);
    Student s3("nasr",20170202,3.3);
    //s1.print();
    student_list list;
    list.insert(s1);
    list.insert(s2);
    list.insert(s3);
    list.print();
   // list.remove(20170200);

    return 0;
}