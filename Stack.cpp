// Ilwel Isaac Campos Braga
// Mat 1440459
// ED1

#ifndef STACK
#define STACK
#include <iostream>
#include "Link.cpp"

using namespace std;

// class five -- Stack --

class Stack{
private:    Link* _top; // attributes

                        // private method signatures
            bool is_Empty  ();
            void null_Stack();

public:
            Stack(){    // constructor

                _top = NULL;

            }

            ~Stack(){   // destructor

                null_Stack();
            }

                        // public method signatures

            void print_Info       ();
            int push       (int elm);
            int pop               ();
            bool search_For (int st);

};
                        // private implementation

bool Stack :: is_Empty(){

    return _top == NULL;

}

void Stack :: null_Stack(){

    while(!is_Empty()){

        pop();

    }

}

                        // public implementation

void Stack :: print_Info(){

    Stack aux;

    while(!is_Empty()){

        // printing info

        cout << _top->Get_info() << " ";
        aux.push(pop());

    }
    cout << endl;

    while(!aux.is_Empty()){

        // pushing all links

        push(aux.pop());

    }

}

int Stack :: push(int elm){

    // implicit method

    Link* neil = new Link();
    neil->Set_info(elm);

    if(is_Empty()){

        _top = neil;

    }else{

        neil->Set_next(_top);
        _top = neil;

    }

    return elm;

}

int Stack :: pop(){

    // implicit method

    if(!is_Empty()){

        Link* aux = _top;
        int return_of_function = aux->Get_info();

        _top = aux->Get_next();
        aux = NULL;
        delete aux;

        return return_of_function;

    }

}

bool Stack :: search_For(int st){

    Stack aux;

    bool i_find = false;

    while(!is_Empty()){

        // searching in stack

        if(st == _top->Get_info()) i_find = true;
        aux.push(pop());

    }

    while(!aux.is_Empty()){

        // pushing all the links

        push(aux.pop());

    }

    return i_find;

}
#endif // STACK
