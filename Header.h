#pragma once
// #include <iostream>
//  #include <windows.h>
// #include <vector>
// using namespace std;

template <typename T>
class MyArr {
 private:
  T* arr;
  int capacity;  // ���-�� ������
  int size;      // ���-�� ���������
  int num;

 public:
  MyArr();
  MyArr(int n);
  MyArr(const MyArr<T>&);
  ~MyArr();
  int get_size();
  int get_capacity();
  void clear();
  bool empty();
  const T& operator[](int index);
  bool check_value(int index);
  bool change_value(int index, T value);
  int get_index(T value);
  void push_back(const T ob);
  bool erase(int index);
  bool set_value(int index, T value);
  bool del_value(T value);

  class Iterator {
   private:
    T* tmp;

   public:
    T get_tmp();
    Iterator(T* val);
    Iterator();
    T& operator+(int n);
    T& operator-(int n);
    T& operator--(int);
    T& operator++(int);
    T& operator--();
    T& operator++();
    bool operator!=(const Iterator& it);
    bool operator==(const Iterator& it);
    T& operator*();
    void operator=(T* val);
  };
  inline T* begin() const noexcept;
  inline T* end() const noexcept;
};

#include "header.inl"