#include "Header.h"

using namespace std;

template <typename T>
int MyArr<T>::get_size() {  //
  return size;
}

template <typename T>
MyArr<T>::MyArr() {  //
  size = 0;
  num = 1;
  capacity = num;
  arr = new T[capacity];
}
template <typename T>
MyArr<T>::MyArr(int n) {  //
  size = 0;
  num = n;
  capacity = n;
  arr = new T[capacity];
}
template <typename T>
MyArr<T>::MyArr(const MyArr<T>& arr_old) {  //
  size = arr_old.size;
  arr = new T[size];
  for (int i = 0; i < arr_old.size; i++) this->arr[i] = arr_old.arr[i];
};
template <typename T>
MyArr<T>::~MyArr() {  //
  delete[] arr;
};

template <typename T>
int MyArr<T>::get_capacity() {  //  -
  return capacity;
}

template <typename T>
void MyArr<T>::clear() {  //
  size = 0;
  delete[] arr;
  arr = new T[size];
}

template <typename T>
bool MyArr<T>::empty() {  //
  return size == 0;
}

template <typename T>
const T& MyArr<T>::operator[](int index) {  //

  if (empty()) {
    throw "The list is empty!";
  } else if (index < 0 || index > size - 1) {
    throw "Index out of range!";
  }

  return arr[index];
}

template <typename T>
bool MyArr<T>::check_value(int index) {  //
  bool choice = false;
  if (index >= 0 && index < size - 1) choice = true;
  return choice;
}

template <typename T>
bool MyArr<T>::change_value(int index, T value) {  //
  bool check = true;
  if (empty()) {
    throw "The list is empty!";
    check = false;
  } else if (index < 0 || index > size - 1) {
    throw "Index out of range!";
    check = false;
  } else {
    arr[index] = value;
  }
  return check;
}

template <typename T>
int MyArr<T>::get_index(T value) {  //
  int check = 0;
  if (empty()) {
    throw "The list is empty!";
  } else {
    int temp = -1;
    int i = 0;
    for (; i < size; i++)
      if (value == arr[i]) {
        temp = 1;
        break;
      }
    if (temp != -1) check = i;
  }
  return check;
}
template <typename T>
void MyArr<T>::push_back(const T ob) {
  // size++; // maybe error
  if (size == capacity) {
    capacity += num;
    T* newArray = new T[capacity];
    for (int i = 0; i < size; i++) newArray[i] = arr[i];
    newArray[size] = ob;
    this->size++;
    delete[] arr;
    arr = newArray;
  } else {
    arr[size] = ob;
    this->size++;
  }
}

template <typename T>
bool MyArr<T>::erase(int index) {
  bool check = true;
  if (empty()) {
    throw "The list is empty!";
    check = false;
  } else if (index < 0 || index > size - 1) {
    throw "Index out of range!";
    check = false;
  } else {
    for (int i = index; i < size; i++) arr[i] = arr[i + 1];
    size--;
    if (size == (capacity) / 2) {
      capacity = size + 1;
      T* newArray = new T[capacity];
      for (int i = 0; i < size; i++) newArray[i] = arr[i];
      delete[] arr;
      arr = newArray;
    }
  }
  return check;
}
template <typename T>
bool MyArr<T>::set_value(int index, T value) {
  bool check = true;
  if (empty()) {
    throw "The list is empty!";
    check = false;
  } else if (index < 0 || index > size - 1) {
    throw "Index out of range!";
    check = false;
  } else {
    arr[index] = value;
  }
  return check;
}

template <typename T>
bool MyArr<T>::del_value(T value) {
  bool check = false;
  if (empty()) {
    throw "The list is empty!";
  } else {
    for (int i = 0; i < size; i++) {
      if (arr[i] == value) {
        erase(i);
        check = true;
        break;
      }
    }
  }
  return check;
}

template <typename T>
T MyArr<T>::Iterator::get_tmp() {
  return *tmp;
}
template <typename T>
MyArr<T>::Iterator::Iterator(T* val) : tmp(val) {}
template <typename T>
MyArr<T>::Iterator::Iterator() {
  tmp = NULL;
}
template <typename T>
T& MyArr<T>::Iterator::operator+(int n) {
  return *(tmp + n);
}
template <typename T>
T& MyArr<T>::Iterator::operator-(int n) {
  return *(tmp - n);
}
template <typename T>
T& MyArr<T>::Iterator::operator--(int) { /*tmp++;*/
  return *(tmp--);
}
template <typename T>
T& MyArr<T>::Iterator::operator++(int) {
  return *(tmp++);
}
template <typename T>
T& MyArr<T>::Iterator::operator--() {
  return *(--tmp);
}
template <typename T>
T& MyArr<T>::Iterator::operator++() {
  return *(++tmp);
}
template <typename T>
bool MyArr<T>::Iterator::operator!=(const Iterator& it) {
  return tmp != it.tmp;
}
template <typename T>
bool MyArr<T>::Iterator::operator==(const Iterator& it) {
  return tmp == it.tmp;
}
template <typename T>
T& MyArr<T>::Iterator::operator*() {
  return *tmp;
}
template <typename T>
void MyArr<T>::Iterator::operator=(T* val) {
  tmp = val;
}




template <typename T>
inline T* MyArr<T>::begin() const noexcept  //    begin()
{
  return arr;
}
template <typename T>
inline T* MyArr<T>::end() const noexcept  //  ""    end()
{
  return arr + size;
}





template <typename T>
T MyArr<T>::rIterator::get_tmp()
{
  return *tmp;
}

template <typename T>
MyArr<T>::rIterator::rIterator(T* val) : tmp(val) {}

template <typename T>
MyArr<T>::rIterator::rIterator()
{
  tmp = NULL;
}
template <typename T>
T &MyArr<T>::rIterator::operator+(int n)
{
  return *(tmp + n);
}
template <typename T>
T &MyArr<T>::rIterator::operator-(int n)
{
  return *(tmp - n);
}
template <typename T>
T &MyArr<T>::rIterator::operator--(int)
{ /*tmp++;*/
  return *(tmp--);
}
template <typename T>
T &MyArr<T>::rIterator::operator++(int)
{
  return *(tmp++);
}
template <typename T>
T &MyArr<T>::rIterator::operator--()
{
  return *(--tmp);
}
template <typename T>
T &MyArr<T>::rIterator::operator++()
{
  return *(++tmp);
}
template <typename T>
bool MyArr<T>::rIterator::operator!=(const Iterator &it)
{
  return tmp != it.tmp;
}
template <typename T>
bool MyArr<T>::rIterator::operator==(const Iterator &it)
{
  return tmp == it.tmp;
}
template <typename T>
T &MyArr<T>::rIterator::operator*()
{
  return *tmp;
}
template <typename T>
void MyArr<T>::rIterator::operator=(T *val)
{
  tmp = val;
}