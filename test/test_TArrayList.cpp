#include "../gtest/gtest.h"
#include "ArrayList.h"
#include "ArrayListIterator.h"


TEST(TArrayList, can_create_Arraylist)
{
  ASSERT_NO_THROW(TArrayList<int> A(10));
}

TEST(TArrayList, can_create_Arraylist_Iterator)
{
  TArrayList<int> A(10);
  ASSERT_NO_THROW(TArrayListIterator<int> i(A));
}

TEST(TArrayList, can_copy_Arraylist)
{
  TArrayList<int> A(10);
  ASSERT_NO_THROW(TArrayList<int> temp2(A));
}

TEST(TArrayList, can_copy_Arraylist_Iterator)
{
  TArrayList<int> A(10);
  TArrayListIterator<int> i(A);
  ASSERT_NO_THROW(TArrayListIterator<int> j = i);
}

TEST(TArrayList, can_insert_elem_first)
{
  TArrayList<int> A(10);
  ASSERT_NO_THROW(A.InsFirst(1));
}

TEST(TArrayList, can_insert_elem_last)
{
  TArrayList<int> A(10);
  ASSERT_NO_THROW(A.InsLast(1));
}

TEST(TArrayList, can_insert_through_iterator)
{
  TArrayList<char> A(10);
  A.InsFirst('a');
  A.InsLast('b');
  A.InsFirst('c');
  TArrayListIterator<char> i(A, 1);
  ASSERT_NO_THROW(A.Ins(i, 'd'));
}

TEST(TArrayList, check_isFull)
{
  TArrayList<char> A(1);
  A.InsFirst('a');

  EXPECT_EQ(A.IsFull(), true);
}

TEST(TArrayList, check_isEmpty)
{
  TArrayList<char> A(1);
  A.InsFirst('a');

  EXPECT_EQ(A.IsEmpty(), false);
}

TEST(TArrayList, can_del_first)
{
  TArrayList<char> A(1);
  A.InsFirst('a');

  ASSERT_NO_THROW(A.DelFirst());
}

TEST(TArrayList, can_del_last)
{
  TArrayList<char> A(1);
  A.InsFirst('a');

  ASSERT_NO_THROW(A.DelLast());
}

TEST(TArrayList, can_Get_first)
{
  TArrayList<char> A(1);
  A.InsFirst('a');

  EXPECT_EQ(A.GetFirst(), 'a');
}

TEST(TArrayList, can_Get_last)
{
  TArrayList<char> A(1);
  A.InsFirst('a');

  EXPECT_EQ(A.GetLast(), 'a');
}

TEST(TArrayList, can_del_iterator)
{
  TArrayList<char> A(1);
  A.InsFirst('a');
  TArrayListIterator<char> i(A, 1);

  ASSERT_NO_THROW(A.Del(i));
}

TEST(TArrayList, can_get_count)
{
  TArrayList<char> A(1);
  A.InsFirst('a');

  EXPECT_EQ(A.GetCount(), 1);
}

TEST(TArrayList, can_GetData_iterator)
{
  TArrayList<char> A(1);
  A.InsFirst('a');
  TArrayListIterator<char> i(A, 1);
  ASSERT_NO_THROW(i.GetData());
}

TEST(TArrayList, can_GetIndex_iterator)
{
  TArrayList<char> A(1);
  A.InsFirst('a');
  TArrayListIterator<char> i(A, 1);
  ASSERT_NO_THROW(i.GetIndex());
}