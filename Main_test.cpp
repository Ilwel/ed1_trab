#include <iostream>
#include "List.cpp"
#include "List_T2.cpp"
#include "Stack.cpp"
#include "Queue.cpp"

using namespace std;

int main(void){

    // list tests
    List L1;
    L1.insert_In(2);
    L1.insert_In(3);
    L1.insert_In(4, false);

    L1.insert_Pos(1, 0);
    L1.insert_Pos(2, 1);
    L1.insert_Pos(3, 13);
    L1.insert_Pos(7, 11);
    L1.print_Info();
    L1.remove_Pos(1);
    L1.remove_Pos(6);
    L1.remove_Pos(4);
    L1.print_Info();


    cout << L1.search_For(1) << " " << L1.search_For(123) << endl;
    cout << endl;

    List_T2 L2;
    L2.insert_In(2);
    L2.insert_In(3);
    L2.insert_In(4, false);

    L2.insert_Pos(1, 0);
    L2.insert_Pos(2, 1);
    L2.insert_Pos(3, 13);
    L2.insert_Pos(7, 11);
    L2.print_Info();
    L2.remove_Pos(1);
    L2.remove_Pos(6);
    L2.remove_Pos(4);
    L2.print_Info();


    cout << L1.search_For(1) << " " << L1.search_For(123) << endl;
    cout << endl;

    // stack tests
    Stack S1;
    S1.push(3);
    S1.push(4);
    S1.push(5);
    S1.print_Info();
    S1.print_Info();
    S1.pop();
    S1.print_Info();
    S1.pop();
    S1.print_Info();

    cout << S1.search_For(3) << " " << S1.search_For(1) << endl;
    cout << endl;

    // queue tests
    Queue Q1;
    Q1.queue_In(2);
    Q1.queue_In(3);
    Q1.queue_In(4);
    Q1.print_Info();
    Q1.print_Info();
    Q1.dequeue();
    Q1.print_Info();

    cout << Q1.search_For(3) << " " << Q1.search_For(78) << endl;

    return 0;

}
