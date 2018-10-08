// Ilwel Isaac Campos Braga
// Mat 1440459
// ED1

#ifndef LINK
#define LINK
#include <iostream>

using namespace std;

// class one -- Link --

class Link{
private:    int   _info; // attributes
            Link* _next;
public:

            Link(){      // constructor

                _next = NULL;

            }

            ~Link(){     // destructor

                delete _next;

            }
                         // public methods

            int Get_info()   { return _info; }
            Link* Get_next() { return _next; }

            void Set_info(int st)   { _info = st; }
            void Set_next(Link* st) { _next = st; }

};
#endif // LINK
