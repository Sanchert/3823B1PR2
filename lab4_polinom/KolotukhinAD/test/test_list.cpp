#include "list.h"

#include <gtest.h>

TEST(list, can_create_list)
{
  ASSERT_NO_THROW(List<int> list);
}


TEST(list, can_create_copy_list)
{
  List<int> list_1;
  list_1.pushBack(1);
  ASSERT_NO_THROW(List<int> list_2(list_1));
}

TEST(list, copy_has_its_own_memory)
{
  List<int> list_1;
  list_1.pushBack(1);
  list_1.pushBack(2);
  list_1.pushBack(3);
  
  List<int> list_2(list_1);
  list_2.removeFrom(0);
  
  EXPECT_EQ(1, list_1[0]);
  EXPECT_EQ(2, list_2[0]);


  EXPECT_EQ(3, list_1.getSize());
  EXPECT_EQ(2, list_2.getSize());
}

TEST(list, copy_is_equal_to_the_source) 
{
  List<int> a;
  for (int i = 0; i < 10; i++) {
    a.pushBack(i);
  }
  List<int> b(a);
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(i, b[i]); 
  }
}


TEST(list, can_push_front)
{
  List<int> a;
  a.pushFront(10);
  a.pushFront(20);
  EXPECT_EQ(20, a[0]);
}

TEST(list, push_front_change_size)
{
  List<int> a;
  a.pushFront(10);
  EXPECT_EQ(1, a.getSize());
  a.pushFront(20);
  EXPECT_EQ(2, a.getSize());
}

TEST(list, push_front_change_head)
{
  EXPECT_EQ(1,1);  
}


TEST(list, can_push_back)
{
  List<int> a;
  a.pushBack(10);
  EXPECT_EQ(10, a[0]);
}

TEST(list, push_back_change_size)
{
  List<int> a;
  a.pushBack(10);
  EXPECT_EQ(1, a.getSize());
  a.pushBack(20);
  EXPECT_EQ(2, a.getSize());
}

TEST(list, push_back_is_the_last_one)
{
  List<int> a;
  a.pushBack(10);
  a.pushBack(10);
  a.pushBack(10);
  a.pushBack(100);
  EXPECT_EQ(100, a[a.getSize() - 1]);
}


TEST(list, can_get_size)
{
  List<int> a;
  a.pushFront(10);
  a.pushFront(20);
  a.pushBack(0);
  EXPECT_EQ(3, a.getSize());
}


TEST(list, can_get_element_by_index)
{
  List<int> a;
  for (int i = 0; i < 10; i++) {
    a.pushBack(i);
  }
  for (int i = 9; i >= 0; i--) {
    EXPECT_EQ(i, a[i]);
  }
}

TEST(list, cant_get_element_outside_from_list)
{
  List<int> a;
  for (int i = 0; i < 10; i++) {
    a.pushBack(i);
  }
  ASSERT_ANY_THROW(a[100]);
}


TEST(list, can_insert_element_at_the_specified_position)
{
  List<int> a;
  for (int i = 0; i < 10; i++) {
    a.pushBack(i);
  }
  a.addTo(3, 100);
  EXPECT_EQ(2  , a[2]);
  EXPECT_EQ(100, a[3]);
  EXPECT_EQ(3  , a[4]);
}

TEST(list, insert_changes_the_size)
{
  List<int> a;
  for (int i = 0; i < 10; i++) {
    a.pushBack(i);
  }
  EXPECT_EQ(10 , a.getSize());
  a.addTo(3, 100);
  EXPECT_EQ(11 , a.getSize());
}

TEST(list, cant_insert_element_outside_the_list)
{
  List<int> a;
  for (int i = 0; i < 10; i++) {
    a.pushBack(i);
  }
  ASSERT_ANY_THROW(a.addTo(100, 100));
}


TEST(list, can_remove_element)
{
  List<int> a;
  a.pushBack(10);
  a.pushBack(20);
  a.pushBack(30);
  ASSERT_NO_THROW(a.removeFrom(1));
}

TEST(list, remove_element_change_size)
{
  List<int> a;
  a.pushBack(10);
  a.pushBack(20);
  a.pushBack(30);
  EXPECT_EQ(3, a.getSize());
  a.removeFrom(1);
  EXPECT_EQ(2, a.getSize());
}

TEST(list, cant_remove_a_notexisting_element)
{
  List<int> a;
  a.pushBack(10);
  a.pushBack(20);
  a.pushBack(30);
  ASSERT_ANY_THROW(a.removeFrom(100));
}

TEST(list, removed_element_is_replaced_by_the_following)
{
  List<int> a;
  a.pushBack(10);
  a.pushBack(20);
  a.pushBack(30);
  a.removeFrom(1);
  EXPECT_EQ(30, a[1]);
}


TEST(list, can_assign_another_list)
{
  List<int> a;
  a.pushFront(10);
  a.pushFront(20);
  a.pushBack(0);
  ASSERT_NO_THROW(List<int> b = a);
}

TEST(list, assigned_list_is_equal_to_the_source_one)
{
  List<int> a;
  for(int i = 0; i < 5; i++)
  {
    a.pushBack(i);
  }
  List<int> b = a;

  EXPECT_EQ(a.getSize(), b.getSize());
  for(int i = 0; i < 5; i++)
  {
    EXPECT_EQ(i, b[i]);
  }
}

TEST(list, assigned_list_has_its_own_memory)
{
  List<int> a;
  a.pushFront(10);
  a.pushFront(20);
  a.pushBack(0);
  List<int> b = a;
  b.removeFrom(0);
  EXPECT_EQ(20, a[0]);
  EXPECT_EQ(10, a[1]);
  EXPECT_EQ(0,  a[2]);
}
