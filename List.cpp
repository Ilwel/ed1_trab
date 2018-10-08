// Ilwel Isaac Campos Braga
// Mat 1440459
// ED1

#ifndef LIST
#define LIST
#include <iostream>
#include "Link.cpp"

using namespace std;

//class three -- List --

class List{
private:    int   _size; // attributes
            Link* _first;
            Link* _last;


                         // private method signatures

            bool is_Empty                             ();
            bool correct_Pos(int pos, bool insrt = true);
            void null_List                            ();

public:
            List(){      // constructor

                _first = NULL;
                _last  = NULL;
                _size  = 0;

            }

            ~List(){     // destructor

                null_List();

            }

                         // public method signatures

            void print_Info                      ();
            int insert_In(int elm, bool bgn = true);
            int insert_Pos       (int pos, int elm);
            int remove_Pos                (int pos);
            bool search_For                (int st);


};
                         // private implementation

bool List :: is_Empty(){

    return _first == NULL;

}

bool List :: correct_Pos(int pos, bool insrt){

    if(insrt) return pos <= _size + 1 and pos > 0;
    else      return pos <= _size and pos > 0;

}

void List :: null_List(){

    while(!is_Empty()){

        remove_Pos(_size);

    }

}


                          // public implementation

void List :: print_Info(){

    Link* aux;

    // scrolling trough all the links

    for(aux = _first; aux != NULL; aux = aux->Get_next()){

        // printing info

        cout << aux->Get_info() << " ";

    }
    cout << endl;

}

int List :: insert_In(int elm, bool bgn){

    Link* neil = new Link();
    neil->Set_info(elm);

    if(bgn){

        // in begin

        if(is_Empty()){

            _first = neil;
            _last  = neil;

        }else{

            neil->Set_next(_first);
            _first = neil;

        }

    }else{

        // in end

        if(is_Empty()){

            _first = neil;
            _last  = neil;

        }else{

            _last->Set_next(neil);
            _last = neil;

        }

    }

    _size++;
    return elm;

}

int List :: insert_Pos(int pos, int elm){

    if(correct_Pos(pos)){

        if(pos == 1){

            // in first position

            insert_In(elm);
            return elm;

        }else if(pos == _size){

            // in last position

            insert_In(elm, false);
            return elm;

        }else{

            // other positions

            int i = 0;
            Link* aux;
            Link* neil = new Link();
            neil->Set_info(elm);

            for(i = 0, aux = _first; i < pos - 2; i++, aux = aux->Get_next());

            neil->Set_next(aux->Get_next());
            aux->Set_next(neil);

        }

        _size++;
        return elm;

    }

}

int List :: remove_Pos(int pos){

    if(correct_Pos(pos, false)){

        if(pos == 1){

            // in first position

            int return_of_function = _first->Get_info();
            _first = _first->Get_next();
            _size--;
            return return_of_function;

        }else{

            // other positions

            int i = 0;
            Link* aux;

            for(i = 0, aux = _first; i < pos - 2; i++, aux = aux->Get_next());

            Link* aux_2 = aux->Get_next();

            int return_of_function = aux->Get_next()->Get_info();

            aux->Set_next(aux_2->Get_next());
            aux_2 = NULL;
            delete aux_2;

            _size--;
            return return_of_function;
        }

    }

}

bool List :: search_For(int st){

    Link* aux;

    for(aux = _first; aux != NULL; aux = aux->Get_next()){

        // searching in list

        if(aux->Get_info() == st) return true;

    }

    return false;
}
#endif // LIST
