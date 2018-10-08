// Ilwel Isaac Campos Braga
// Mat 1440459
// ED1

#ifndef LIST_T2
#define LIST_T2
#include <iostream>
#include "Link_T2.cpp"

using namespace std;

//class four -- List_T2 --

class List_T2{
private:    int   _size; // attributes
            Link_T2* _first;
            Link_T2* _last;

                         // private method signatures

            bool is_Empty                             ();
            bool correct_Pos(int pos, bool insrt = true);
            void null_List                            ();

public:
            List_T2(){   // constructor

                _first = NULL;
                _last  = NULL;
                _size  = 0;

            }

            ~List_T2(){  // destructor

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

bool List_T2 :: is_Empty(){

    return _first == NULL;

}

bool List_T2 :: correct_Pos(int pos, bool insrt){

    if(insrt) return pos <= _size + 1 and pos > 0;
    else      return pos <= _size and pos > 0;

}

void List_T2 :: null_List(){

    while(!is_Empty()){

        remove_Pos(_size);

    }

}

                          // public implementation

void List_T2 :: print_Info(){

    Link_T2* aux;

    // scrolling trough all the links

    for(aux = _first; aux != NULL; aux = aux->Get_next()){

        // printing info

        cout << aux->Get_info() << " ";

    }
    cout << endl;

}

int List_T2 :: insert_In(int elm, bool bgn){

    Link_T2* neil = new Link_T2();
    neil->Set_info(elm);

    if(bgn){

        // in begin

        if(is_Empty()){

             _first = neil;
             _last  = neil;

        }else{

            neil->Set_next(_first);
            _first->Set_prev(neil);
            _first = neil;

        }

    }else{

        // in end

        if(is_Empty()){

            _first = neil;
            _last  = neil;

        }else{

            neil->Set_prev(_last);
            _last->Set_next(neil);
            _last = neil;

        }

    }

    _size++;
    return elm;

}

int List_T2 :: insert_Pos(int pos, int elm){

    if(correct_Pos(pos)){

        if(pos == 1){

            // in first position

            insert_In(elm);
            return elm;

        }else if(pos == _size + 1){

            //in last position

            insert_In(elm, false);
            return elm;

        }else{

            // other positions

            int i = 0;
            Link_T2* neil = new Link_T2();
            neil->Set_info(elm);

            Link_T2* aux;

            for(i = 0, aux = _first; i < pos - 2; i++, aux = aux->Get_next());

            neil->Set_next(aux->Get_next());
            neil->Set_prev(aux);
            aux->Get_next()->Set_prev(neil);
            aux->Set_next(neil);

        }

        _size++;
        return elm;

    }

}

int List_T2 :: remove_Pos(int pos){

    if(correct_Pos(pos, false)){

        if(pos == 1){

            // in first position

            int return_of_function = _first->Get_info();
            _first = _first->Get_next();
            _size--;
            return return_of_function;

        }else if(pos == _size){

            // in last position

            int return_of_function = _last->Get_info();
            Link_T2* aux = _last->Get_prev();
            aux->Set_next(NULL);
            _last = aux;
            _size--;
            return return_of_function;


        }else{

            // other positions

            int i = 0;
            Link_T2* aux;

            for(i = 0, aux = _first; i < pos - 2; i++, aux = aux->Get_next());

            Link_T2* aux_2 = aux->Get_next();

            int return_of_function = aux->Get_next()->Get_info();

            aux->Set_next(aux_2->Get_next());
            aux_2->Get_next()->Set_prev(aux);
            aux_2 = NULL;
            delete aux_2;

            _size--;
            return return_of_function;
        }

    }

}

bool List_T2 :: search_For(int st){

    Link_T2* aux;

    for(aux = _first; aux != NULL; aux = aux->Get_next()){

        // searching in list

        if(aux->Get_info() == st) return true;

    }

    return false;
}
#endif // LIST_T2
