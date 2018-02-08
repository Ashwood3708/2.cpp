/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Abdul
 *
 * Created on February 7, 2018, 11:10 AM
 */

#include <iostream>
#include <cstdlib>   // for srand and rand
#include <ctime>     // for time

using namespace std;

typedef int ElementType;

struct node {
    ElementType data;
    node * next;
    node * prev;
};

class LinkedList {
public:
    LinkedList(); // Create an empty list
    bool Empty(); // Return true if the list is empty, otherwise return false
    void InsertAtEnd(ElementType x); // Insert a value x at the end of the list
    void Delete(node *x); // If value x is in the list, remove x (all instances)
    void Display(); // Display the data values in the list
    void Game(ElementType even, ElementType odd);
    void Game2(ElementType even, ElementType odd);
    void Previous(); // find previous node

private:
    node * first; // Pointer
    int N;
};

bool LinkedList::Empty() {
    bool k = false;
    if (first == NULL) { //loop checks if array has a first value
        k = true;
    }

    return k;
}

void LinkedList::Previous() {

    cout << "enter word to see prev. of" << endl;
    ElementType x;
    cin>>x;

    node * travel;
    travel = first;
    while (travel->data != x) {
        travel = travel->next;
    }

    cout << "the prev. = " << travel->prev->data << endl;
}

void LinkedList::InsertAtEnd(ElementType x) {

    node *newNode = new node; //makes new node
    newNode->data = x;
    newNode->next = newNode;
    newNode->prev = newNode;
    node *travel; //node to traverse list
    travel = first;

    if (Empty() == true) {
        first = newNode;
        N++;
    } else {
        while (travel->next != first) { //loop to have node find last position
            travel = travel->next;
        }
        travel->next = newNode;
        newNode->prev = travel;
        newNode->next = first;
        first->prev = newNode;
        N++;
    }


}

void LinkedList::Delete(node *x) {
    if (first == x) {
        if (N == 1) {
            delete first;
            first = NULL;
        } else {
            first->next->prev = first->prev;
            first->prev->next = first->next;
            first = first->next;
            delete x;
        }

        N--;
    } else {
        x->next->prev = x->prev;
        x->prev->next = x->next;
        delete x;
        N--;
    }

}

void LinkedList::Display() {
    node*traverse;
    traverse = first;

    cout << endl;
    if (Empty() == true) {
        cout << "the list is empty " << endl;

    } else {
        cout << traverse->data;
        traverse = traverse->next;
        while (traverse != first) {
            cout << " -> " << traverse->data;
            traverse = traverse->next;
        }
        cout << endl;
    }
}

void LinkedList::Game(ElementType even, ElementType odd) {
    int turn = 1;
    node*travel = first;

    //Display();
    while (N != 1) {
        if (1 == turn % 2) {
            for (int i = 0; i < odd; i++) {
               // cout << travel->prev->data << " <- (" << travel->data << ") -> " << travel->next->data << endl;
                travel = travel->next;

            }


        } else {
            for (int k = 0; k < even; k++) {
               // cout << travel->prev->data << " -> (" << travel->data << ") -> " << travel->next->data << endl;

                travel = travel->next;

            }

        }
        
        cout << "Turn " << turn <<" ";
        turn++;
        cout << "Deleting " << travel->prev->data ;
        Delete(travel->prev);
        Display();
        
    }
    cout << "The winner is " << travel->data << endl;
}

LinkedList::LinkedList() {
    N = 0;
    first = NULL;
}

/*
 * 
 */
int main(int argc, char** argv) {

    int a[argc], even, odd;

    LinkedList r;
    for (int i = 1; i < argc; i++) {
        a[i] = atoi(argv[i]);
    }
    odd = a[2];
    even = a[3];

    for (int j = 0; j < a[1]; j++) {
        r.InsertAtEnd((1 + j));
    }

    r.Game(even, odd);

    return 0;
}

