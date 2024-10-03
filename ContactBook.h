#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Contact {
private:
    string name;
    string number;
public:
    Contact(const string& name, const string& number);
    string getName() const;
    string getNumber() const;
    void Display() const;

};

class ContactBook {
private:
    static const int MAX_SIZE = 100;
    Contact* contacts[MAX_SIZE];
    unsigned int curr_size = 0;
public:
    ContactBook();
    /*Copied Constructor*/
    ContactBook(const ContactBook& rhs);
    /*Overloading here*/
    ContactBook& operator =(const ContactBook& rhs);
    ~ContactBook();

    Contact* Find(const string& look) const;
    void Add(const Contact& contact);
    void AddContacts(const vector<Contact*>& list_one);
    void Remove(const Contact& contact);
    void Display() const;
    void Alphabetize();

    ContactBook& operator+=(const Contact& contact);
    ContactBook& operator+=(const ContactBook& rhs);
    ContactBook operator+(const ContactBook& rhs) const;
    ContactBook& operator-=(const Contact& contact);
    bool operator==(const ContactBook& rhs) const;
    bool operator!=(const ContactBook& rhs)const;
    ContactBook operator-(const ContactBook& rhs)const;
    ContactBook& operator-=(const ContactBook& rhs);

};