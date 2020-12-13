#ifndef _ArrList_H_
#define _ArrList_H_
#include <iostream>

using namespace std;

template <class T1>
class TArrayListIterator;

template <class T>
class TArrayList
{
protected:
  T* data;
  int* links;
  int size;
  int count;
  int root;
public:
  TArrayList(int _size = 1);
  TArrayList(TArrayList<T>& _v);
  ~TArrayList();

  TArrayList<T>& operator =(TArrayList<T>& _v);

  void InsFirst(T d);
  void InsLast(T d);
  void Ins(TArrayListIterator<T>& e, T d);

  bool IsEmpty(void) const;
  bool IsFull(void) const;

  TArrayListIterator<T> begin ();
  TArrayListIterator<T> end ();

  void DelFirst();
  void DelLast();
  void Del(TArrayListIterator<T>& e);

  T GetFirst();
  T GetLast();

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TArrayList<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TArrayList<T1> &A);

  template <class T1>
  friend class TArrayListIterator;

  int GetCount();
 
};


template <class T1>
ostream& operator<< (ostream& ostr, const TArrayList<T1> &A) 
{
  int i = A.root;
  while (A.links[i] != -1)
  {
    ostr << A.data[i];
    i = A.links[i];
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TArrayList<T1> &A) 
{
  int count;
  istr >> count;
  for (int i = 0; i < count; i++) {
    T1 d;
    istr >> d;
    A.InsLast(d);
  }
  return istr;
}

template <class T>
inline TArrayList<T>::TArrayList(int _size)
{
  if (_size <= 0)
    throw "wrong size";

  size = _size;
  data = new T[size];
  links = new int[size];
  count = 0;

  for (int i = 0; i < size; i++)
    links[i] = -2;

  root = -1;
}

template <class T>
TArrayList<T>::TArrayList(TArrayList<T>& _v)
{
  count = _v.count;
  size = _v.size;
  root = _v.root;

  data = new T[size];
  links = new int[size];

  for (int i = 0; i < size; i++)
  {
    links[i] = _v.links[i];
    data[i] = _v.data[i];
  }

}
template <class T>
TArrayList<T>::~TArrayList()
{
  if (data != nullptr)
  {
    delete[] data;
    delete[] links;
    data = 0;
    links = 0;
    count = 0;
    size = 0;
    root = -1;
  }
}

template <class T>
TArrayList<T>& TArrayList<T>:: operator =(TArrayList<T>& _v)
{
  if (this == &_v)
    return *this;

  if (size != _v.size)
  {
    delete[] data;
    delete[] links;

    data = new T[_v.size];
    links = new int[_v.size];
  }
  count = _v.count;
  size = _v.size;
  root = _v.root;

  for (int i = 0; i < size; i++)
  {
    links[i] = _v.links[i];
    data[i] = _v.data[i];
  }

  return *this;
}

template <class T>
inline void TArrayList<T>::InsFirst(T d)
{
  if (this->IsFull())
    throw logic_error("Error");

  int i = 0;
  for (i = 0; i < size; i++)
  {
    if (links[i] == -2)
      break;
  }
  data[i] = d;
  links[i] = root;
  root = i;

  count++;
}

template <class T>
inline void TArrayList<T>::InsLast(T d)
{
  if (this->IsFull())
    throw logic_error("Error");

  if (this->IsEmpty())
  {
    root = 0;
    data[0] = d;
    links[0] = -1;
  }
  else
  {
    int i = 0;
    for (i = 0; i < size; i++)
    {
      if (links[i] == -2)
        break;
    }

    int end = root;
    while (links[end] != -1)
    {
      end = links[end];
    }

    data[i] = d;
    links[i] = -1;
    links[end] = i;
  }
  count++;
}

template <class T>
inline void TArrayList<T>::Ins(TArrayListIterator<T>& e, T d)
{
  if (this->IsFull())
    throw logic_error("Error");
 
  if (this->IsEmpty())
  {
    root = 0;
    data[0] = d;
    links[0] = -1;
  }
  else
  {
    int temp = e.GetIndex();
    if (links[temp] == -2)
    {
      int end = root;
      while (links[end] != -1)
      {
        end = links[end];
      }
      data[temp] = d;
      links[temp] = -1;
      links[end] = temp;
    }
  }
  count++;
}

template <class T>
inline bool TArrayList<T>::IsEmpty(void) const
{
  return count == 0;;
}

template <class T>
inline bool TArrayList<T>::IsFull(void) const
{
  return count >= size;
}

template <class T>
inline TArrayListIterator<T> TArrayList<T>::begin ()
{
  return TArrayListIterator<T>(*this, root);
}

template <class T>
inline TArrayListIterator<T> TArrayList<T>::end()
{
  return TArrayListIterator<T>(*this, -1);
}

template <class T>
inline void TArrayList<T>::DelFirst()
{
  if (this->IsEmpty())
    throw logic_error("Error");

  int i = root;
  root = links[root];
  links[i] = -2;

  count--;
}

template <class T>
inline void TArrayList<T>::DelLast()
{
  if (this->IsEmpty())
    throw logic_error("Error");

  if (links[root] == -1)
  {
    links[root] = -2;
    root = -1;
  }
  else
  {
    int pEnd = root;
    int end = links[root];

    while (links[end] != -1)
    {
      pEnd = end;
      end = links[end];
    }
    links[pEnd] = -1;
    links[end] = -2;
  }
  count--;
}

template <class T>
inline void TArrayList<T>::Del(TArrayListIterator<T>& e)
{
  if (this->IsEmpty())
    throw logic_error("Error");

  if (links[root] == -1)
  {
    links[root] = -2;
    root = -1;
  }
  else
  {
    int pEnd = e.GetIndex();
    int end = links[root];

    while (links[end] != -1)
    {
      pEnd = end;
      end = links[end];
    }

    links[pEnd] = -1;
    links[end] = -2;
  }
  count--;
}

template <class T>
inline T TArrayList<T>::GetFirst()
{
  if (this->IsEmpty())
    throw logic_error("Error");
  return data[root];
}

template <class T>
inline T TArrayList<T>::GetLast()
{
  if (this->IsEmpty())
    throw logic_error("Error");

  int end = root;
  while (links[end] != -1)
    end = links[end];

  return data[end];
}

template <class T>
inline int TArrayList<T>::GetCount()
{
  return count;
}


#endif


