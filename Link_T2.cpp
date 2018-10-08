// Ilwel Isaac Campos Braga
// Mat 1440459
// ED1

#ifndef LINK_T2
#define LINK_T2
#include <iostream>

using namespace std;

//class two -- Link_T2 --

class Link_T2{
private:    int      _info; // attributes
            Link_T2* _next;
            Link_T2* _prev;
public:

            Link_T2(){      // constructor

                _next = NULL;
                _prev = NULL;

            }

            ~Link_T2(){     // destructor

                delete _next;
                delete _prev;

            }
                            // public methods

            int Get_info()      { return _info; }
            Link_T2* Get_next() { return _next; }
            Link_T2* Get_prev() { return _prev; }

            void Set_info(int st)      { _info = st; }
            void Set_next(Link_T2* st) { _next = st; }
            void Set_prev(Link_T2* st) { _prev = st; }

};
#endif // LINK_T2
