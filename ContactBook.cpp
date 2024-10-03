#include "ContactBook.h"
#include <iostream>
#include <algorithm>
using namespace std;

Contact::Contact(const string&name, const string&number){
  this->name = name;
  this->number = number;
}

string Contact:: getName() const {
  return name;
}
string Contact:: getNumber() const{
  return number;
}

void Contact::Display()const {
  cout << name << ", " << number << endl;
}


Contact* ContactBook::Find(const string& look) const {
    for (unsigned int i = 0; i < curr_size; i++) {
      bool name_got = contacts[i]->getName() == look;
      bool number_got = contacts[i]->getNumber() == look;
       if (name_got){
          cout << contacts[i]->getName() << " found!"<< endl;
          return contacts[i];
    }   else if(number_got) {
          cout << contacts[i]->getNumber() <<" found!" << endl;
          return contacts[i];
      }
      }

  return nullptr;
  }




void ContactBook::Display() const{
  for (unsigned int i = 0; i < curr_size; i++){
    if (contacts[i] != nullptr) {
      contacts[i]->Display();
    }
  }
}

void ContactBook::Add(const Contact& contact){
  if (curr_size < MAX_SIZE){
    contacts[curr_size++] = new Contact(contact);
  }
}


void ContactBook::AddContacts(const vector<Contact*>& list_one){
  for (int i = 0; i < list_one.size(); i++){
    Add(*list_one[i]);
  }
}

void ContactBook::Remove(const Contact& contact){
  for (unsigned int i = 0; i < curr_size; i++){
    if (contacts[i] != nullptr && contacts[i]->getName() == contact.getName() && contacts[i]->getNumber() == contact.getNumber()) {
      delete contacts[i];
      for (unsigned int j = i; j < curr_size - 1 ; j++ ){
        contacts[j] = contacts[j+1];
      }
      contacts[--curr_size] = nullptr;
      return;
    }
  }
}

bool comp_contacts(Contact* a, Contact* b){
  return a->getName() < b->getName();
}
void ContactBook::Alphabetize(){
  if (curr_size > 0){
    sort(contacts, contacts + curr_size, comp_contacts);
  }
}

ContactBook::ContactBook(): curr_size(0){
  for(unsigned int i = 0; i < MAX_SIZE; i++){
    contacts[i] = nullptr;
  }
  }
ContactBook::~ContactBook(){
  for (unsigned int i = 0; i < curr_size; i++){
    delete contacts[i];
  }
}
ContactBook::ContactBook(const ContactBook& rhs) : curr_size(rhs.curr_size){
  for(unsigned int i = 0; i < curr_size; i++){
    if(rhs.contacts[i] != nullptr){
      contacts[i] = new Contact(*rhs.contacts[i]);
    } else {
      contacts[i] = nullptr;
    }
  }
}

ContactBook& ContactBook::operator= (const ContactBook& rhs){
  if(this != &rhs){
    for(unsigned int i = 0; i < curr_size; i++){
      delete contacts[i];
    }
    curr_size = rhs.curr_size;

    for(unsigned int i = 0; i < curr_size; i++){
      if(rhs.contacts[i] != nullptr){
        contacts[i] = new Contact(*rhs.contacts[i]);
      } else {
        contacts[i]= nullptr;
      }
    }
  }
  return *this;
}

ContactBook& ContactBook::operator+=(const Contact& contact){
  Add(contact);
  return *this;
}

ContactBook& ContactBook::operator+=(const ContactBook& rhs){
  for(unsigned int i = 0; i < rhs.curr_size; i++){
    Add(*rhs.contacts[i]);
  }
  return *this;
}
ContactBook& ContactBook::operator-=(const Contact& contact){
  Remove(contact);
  return *this;
}
ContactBook& ContactBook::operator-=(const ContactBook& rhs){
  for (unsigned int i = 0; i < rhs.curr_size; i++){
    Remove(*rhs.contacts[i]);
  }
  return *this;
}
ContactBook ContactBook::operator-(const ContactBook& rhs)const{
  ContactBook end = *this;
  end -= rhs;
  return end;
}

ContactBook ContactBook::operator+(const ContactBook& rhs) const{
  ContactBook end = *this;
  end += rhs;
  return end;
}

bool ContactBook::operator!=(const ContactBook& rhs) const{
  return !(*this == rhs);
}
bool ContactBook::operator==(const ContactBook& rhs) const {
  if(curr_size != rhs.curr_size){
    return false;
  }

  for (unsigned int i = 0; i < curr_size; i++){
    bool found = false;
    for (unsigned int j = 0; j < rhs.curr_size; j++){
      if (contacts[i]->getName() == rhs.contacts[j]-> getName()&& contacts[i]->getNumber() == rhs.contacts[j]->getNumber()){
        found = true;
        break;
      }
    }
    if (!found){
      return false;
    }
  }
  return true;
}
