#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

template<class T>
class myList {

    /// The one node in the linked list
    struct Node {
        T data;
        Node *next = NULL;
        Node *prev = NULL;
    };

    Node *head;
    Node *tail;
    Node *dummyNode;
    int length;


public:

    class iterator {
        friend class myList; // so the private data can be accessed from parent
        Node *it;

        public:
            T& operator*(){return it -> data;}

            void operator++(){
                try{
                    /// if nothing after then it's the end
                    if(it -> next == NULL) throw it;
                    it = it -> next;

                } catch(Node *x){
                    cout << "The iterator is at the end!" << endl;
                }
            }

            void operator--(){
                try{
                    /// if nothing before then it's the start
                    if(it -> prev == NULL) throw it;
                    it = it -> prev;

                } catch(Node *x){
                    cout << "The iterator is at the start!" << endl;
                }
            }

            bool operator==(const iterator& x){return (this->it == x.it);}
    };

    myList(){
        head = tail = dummyNode = new Node;
        length = 0;
    }

    myList(T value, int initial_size){
        head = tail = dummyNode = new Node;
        length = 0;

        for(int i=0; i < initial_size; i++){
            Node *newNode = new Node;
            newNode -> data = value;

            if (length == 0){
                /// put before the head (dummy node)
                newNode -> next = head; // prepend the node to the head
                head -> prev = newNode; // append the head to the node

                /// update the head & the tail to the new node
                head = tail = newNode;
            } else {
                /// put after the tail
                newNode -> prev = tail;
                tail -> next = newNode;

                /// update the tail
                tail = newNode;
            }

            /// attach the dummy node
            tail -> next = dummyNode;
            dummyNode -> prev = tail;

            /// update the length
            length++;

        }
    }

    int size(){ return length; }

    /// ======== for debugging ========
    void print(){
        Node *it = head;

        cout << "======[ info ]======\n" << endl;
        cout << "HEAD -> " << head << endl;
        cout << "TAIL -> " << tail << endl;
        cout << "DUMM -> " << dummyNode << endl;

        cout << endl;

        for(int i=0; i < length; i++){
            cout << "=====[" << it << "]=====" << endl;
            cout << "\n[N" << i << "]: " << it -> prev << endl;
            cout << "[N" << i << "]: " << it -> data << endl;
            cout << "[N"<< i << "]: " << it -> next << endl << endl;

            it = it -> next;
        }
            cout << "====================" << endl;

    }

    iterator begin(){
        iterator x;
        x.it = head;

        return x;
    }

    iterator end(){
        iterator x;
        x.it = tail -> next; /// the dummy node

        return x;
    }

    myList<T>& operator= (myList<T> another){

        /// a pointer to copy the data from the original
        iterator it = another.begin();

        for(int i=0; i < another.length; i++){
            Node *newNode = new Node;

            if(this->length == 0){
                /// put before the head (dummy node)
                newNode -> next = this->head;
                this->head -> prev = newNode;

                /// transfer the data value
                newNode -> data = *it;

                /// update the head & the tail to the new node
                this->head = this->tail = newNode;
            } else {
                /// put after the tail
                newNode -> prev = this->tail;
                this->tail -> next = newNode;

                /// transfer the data value
                newNode -> data = *it;

                /// update the tail
                this->tail = newNode;
            }

            ++it;

            /// attach the dummy node
            this->tail -> next = this->dummyNode;
            this->dummyNode -> prev = this->tail;

            /// update the length
            this->length++;
        }

        return *this; /// to return the value itself
    }

    iterator erase(iterator pos){
        try {
            /// if the iterator points to the dummy node
            /// which is after the end
            if(pos == this -> end()) throw pos;

            else if(pos == this -> begin()){ // if erasing the head

                pos.it = pos.it -> next; // advance the pos
                delete head; // delete the first node

                head = pos.it; // advance the head
                length--; // update the length

                return pos;
            }

            else if(pos.it == this -> tail){ // if erasing the tail

                tail = tail -> prev; // make the tail go back
                pos.it = pos.it -> next; // get the next node

                delete tail -> next; // delete the last node
                length--; // update the length

                return pos;
            }

            /// === if not the previous cases then it's in the middle ===
            else {

                /// making the previous of the next node = the previous node directly
                pos.it -> next -> prev = pos.it -> prev;

                /// making the next of the previous node = the next node directly
                pos.it -> prev -> next = pos.it -> next;


                /// the iterator that points to the next node
                iterator tmp = pos;
                tmp.it = pos.it -> next;

                /// delete the previous (the needed) node from memory
                delete pos.it;
                length--; /// decrement the length

                /// return the iterator of the next node
                return tmp;

            }

        } catch(iterator x){
            cout << "Can not erase after the end of the linked list!" << endl;
            return pos; /// the dummy node
        }

    }

    void insert(T value, iterator pos){

        /// create the new node
        Node *newNode = new Node;
        newNode->data = value;

        /// if the insertion is at head
        if(pos == this->begin()){
            head -> prev = newNode; // connect them
            newNode -> next = head;

            head = newNode; // move the head back
        }

        /// if the insertion is at tail
        else if(pos.it == this->tail){
            tail->next = newNode; // connect them
            newNode->prev = tail;

            tail = newNode; // mode the tail to the front
        }

        /// if the insertion is at middle
        else {
            // connecting the new node after the previous node
            pos.it -> prev -> next = newNode;
            newNode -> prev = pos.it -> prev;

            // connecting the current node after the new node
            pos.it -> prev = newNode;
            newNode -> next = pos.it;
        }

        length++;

    }

    ~myList(){
        Node *tmp;

        /// deleting from the head to the tail
        for(int i=0; i < length; i++){
            tmp = head;

            head = head -> next;
            delete tmp; /// deallocate each node
        }
    }


};

int main(){

    myList<int> defaultList;

    myList<int> initialList(3, 5);
    initialList.print();
    cout << "Size = " << initialList.size() << endl;
    cout << endl;

    myList<int>::iterator it = initialList.begin();
    ++it;
    initialList.insert(99, it);

    it = initialList.end(); /// return an iterator for the dummy node
    --it;

    initialList.erase(it);

    initialList.print();
    cout << "Size = " << initialList.size() << endl;
    cout << endl;

    myList<int> deepList;
    deepList = initialList;
    deepList.print();
    cout << "Size = " << deepList.size() << endl;
    cout << endl;

    myList<int>::iterator ni = deepList.begin();
    ++ni; // second = 99
    cout << "The value of the iterator: " << *ni << endl;

    myList<int>::iterator nx = deepList.begin();
    ++nx;

    if(ni == nx) cout << "Both points to the same node" << endl;

    return 0;
}
