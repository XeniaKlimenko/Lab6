#pragma once
template <class T>
class TArrayList;

using namespace std;

template <class T>
class TArrayListIterator
{
protected:
  TArrayList<T>& list;
  int index;
public:
  TArrayListIterator(TArrayList<T>& _list, int _index = -2);
  TArrayListIterator(TArrayListIterator<T>& _v);
  ~TArrayListIterator();

  bool IsGoNext();
  void GoNext();

  bool operator == (const TArrayListIterator<T>& _v);
  bool operator != (const TArrayListIterator<T>& _v);

  T& operator * (int);
  T& operator * ();

  TArrayListIterator<T>& operator ++ ();

  TArrayListIterator<T>& operator = (const TArrayListIterator<T>& _v);

  T GetData();
  T GetIndex();
};


template <class T>
inline TArrayListIterator<T>::TArrayListIterator(TArrayList<T>& _list, int _index): list(_list)
{
  this->index = _index;
}

template <class T>
inline TArrayListIterator<T>::TArrayListIterator(TArrayListIterator<T>& _v): list(_v.list), index(_v.index)
{
}

template <class T>
inline TArrayListIterator<T>::~TArrayListIterator()
{
  index = -2;
}

template <class T>
inline bool TArrayListIterator<T>::IsGoNext()
{
  return index >= 0;
}

template <class T>
inline void TArrayListIterator<T>::GoNext()
{
  if (IsGoNext())
    index = list.links[index];
}

template <class T>
inline bool TArrayListIterator<T>::operator==(const TArrayListIterator<T>& _v)
{
  return index == _v.index;
}

template <class T>
inline bool TArrayListIterator<T>::operator!=(const TArrayListIterator<T>& _v)
{
  return !this->operator==(_v);
}

template <class T>
inline T& TArrayListIterator<T>::operator*(int)
{
  return list.data[index];
}

template <class T>
inline T& TArrayListIterator<T>::operator*()
{
  return list.data[index];
}

template <class T>
inline TArrayListIterator<T>& TArrayListIterator<T>::operator++()
{
  GoNext();
  return *this;
}

template <class T>
inline TArrayListIterator<T>& TArrayListIterator<T>::operator=(const TArrayListIterator<T>& _v)
{
  list = _v.list;
  index = _v.index;
}

template <class T>
inline T TArrayListIterator<T>::GetData()
{
  if (index < 0)
    throw "negative index";
  return list.data[index];
}

template <class T>
inline T TArrayListIterator<T>::GetIndex()
{
  if (index < 0)
  {
    throw "negative index";
  }
  return index;
}
