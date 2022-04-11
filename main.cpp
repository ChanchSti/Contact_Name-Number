//
//  main.cpp
//  ContactInformation
//
//  Created by Jose Saldivar on 4/11/22.
//

#include <iostream>
using namespace std;

class Foo {
private:
struct Contact {
    string phone, name;
    Contact *next;
}*head, *tail;

public:
Foo();
~Foo();
void insert(string n, string p);
void clear();
void display();
int listSize;

};

Foo::Foo() {
    head = tail = nullptr;
}
Foo::~Foo() {
    clear();
}
void Foo::insert(string n, string p) {
    Contact* c = new Contact;
    c -> name = n;
    c -> phone = p;
    c -> next = nullptr;
    
    if(head == nullptr) {
        head = tail = c;
    }
    else {
        tail->next = c;
        tail = c;
    }
}

void Foo::display() {
    Contact *temp = head;
    if(temp == nullptr)
        cout << "\n" << "Empty List" << endl;
    while(temp != nullptr)
    {
        cout << temp->name << " : " << temp->phone << endl;
        temp = temp->next;
    }
}

void Foo::clear() {
    Contact *temp = head;
    while(head != nullptr) {
        head = temp->next;
        delete temp;
        temp = head;
    }
    delete head;
}



int main() {
    Foo y;
    
    y.insert("John", "209-123-4567");
    y.insert("Doe", "209-321-9876");
    y.insert("Bill", "209-999-3345");

    y.display();
    
    y.clear();
    y.display();
}
