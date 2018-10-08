// Ilwel Isaac Campos Braga
// Mat 1440459
// ED1

#ifndef QUEUE
#define QUEUE
#include <iostream>
#include "Link.cpp"

using namespace std;

// class six -- Queue --

class Queue{
private:    Link* _head; // attributes
            Link* _tail;

                         // private method signatures

            bool is_Empty();

public:
            Queue(){     // constructor

                _head = NULL;
                _tail = NULL;

            }

            ~Queue(){


            }

                        // public method signatures

            void print_Info       ();
            int queue_In   (int elm);
            int dequeue           ();
            bool search_For (int st);

};
                        //private implementation

bool Queue :: is_Empty(){

    return _head == NULL;

}

                        // public implementation

void Queue :: print_Info(){

    Queue aux;

    while(!is_Empty()){

        // printing info

        cout << _head->Get_info() << " ";
        aux.queue_In(dequeue());

    }
    cout << endl;

    while(!aux.is_Empty()){

        // queuing all the links

        queue_In(aux.dequeue());

    }

}

int Queue ::queue_In(int elm){

    // implicit method

    Link* neil = new Link();
    neil->Set_info(elm);

    if(is_Empty()){

        _head = neil;
        _tail = neil;

    }else {

        _tail->Set_next(neil);
        _tail = neil;

    }

    return elm;

}

int Queue :: dequeue(){

    // implicit method

    if(!is_Empty()){

        Link* aux = _head;
        int return_of_function = aux->Get_info();

        _head = aux->Get_next();
        aux = NULL;
        delete aux;

        return return_of_function;

    }

}

bool Queue :: search_For(int st){

    Queue aux;

    bool i_find = false;

    while(!is_Empty()){

        // searching

        if(_head->Get_info() == st) i_find = true;
        aux.queue_In(dequeue());

    }

    while(!aux.is_Empty()){

        // queuing all the link

        queue_In(aux.dequeue());

    }

    return i_find;

}
#endif // QUEUE
