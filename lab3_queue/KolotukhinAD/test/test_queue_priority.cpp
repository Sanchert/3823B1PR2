#include "priority_queue.h"

#include <gtest.h>

TEST(TPriorityQueue, can_create)
{
  ASSERT_NO_THROW(TPriorityQueue<int> queue);
}

TEST(TPriorityQueue, can_create_copy)
{
  TPriorityQueue<int> queue_1;
  ASSERT_NO_THROW(TPriorityQueue<int> queue_2(queue_1));
}

TEST(TPriorityQueue, copied_queue_is_equal_to_source_one)
{
  Pair<int> a = {1, 1};
  TPriorityQueue<int> queue_1;
  queue_1.push(a);
  TPriorityQueue<int> queue_2(queue_1);

  EXPECT_EQ(true, (queue_1 == queue_2));
}

TEST(TPriorityQueue, copied_queue_has_its_own_memory)
{
  Pair<int> a = {1, 1};
  TPriorityQueue<int> queue_1;
  queue_1.push(a);
  TPriorityQueue<int> queue_2(queue_1);

  EXPECT_NE(&queue_1, &queue_2);
}

TEST(TPriorityQueue, can_push_element)
{
  TPriorityQueue<int> queue;
  Pair<int> a = {1,1};
  ASSERT_NO_THROW(queue.push(a));
}

TEST(TPriorityQueue, can_get_size)
{
  size_t size = 5;
  TPriorityQueue<int> queue;
  for (int i = 1; i <= size; i++) {
    Pair<int> a = {i*2,i};
    queue.push(a);
  }
  EXPECT_EQ(size, queue.getSize());
}

TEST(TPriorityQueue, can_assign_to_itself)
{
  size_t size = 10;
  TPriorityQueue<int> queue(size);
  for (int i = 0; i < size; i++) {
    Pair<int> a = {2 * i, i};
    queue.push(a);
  }
  queue = queue;

  EXPECT_EQ(2 * (size - 1), queue.top());
}

TEST(TPriorityQueue, can_assign_queues_of_equal_size)
{
  size_t size = 10;
  TPriorityQueue<int> queue_1(size);
  TPriorityQueue<int> queue_2(size);
  for (int i = 0; i < size; i++) {
    Pair<int> a = {2 * i, i};
    queue_2.push(a);
  }
  queue_1 = queue_2;

  EXPECT_EQ(18, queue_1.top());
}

TEST(TPriorityQueue, assign_operator_change_queue_size)
{
  size_t size_1 = 5, size_2 = 10;
  TPriorityQueue<int> queue_1(size_1);
  TPriorityQueue<int> queue_2(size_2);
  for (int i = 0; i < size_2; i++) {
    Pair<int> a = {2 * i, i};
    queue_2.push(a);
  }
  queue_1 = queue_2;

  EXPECT_EQ(size_2, queue_1.getSize());
}

TEST(TPriorityQueue, can_assign_queues_of_different_size)
{
  size_t size_1 = 5, size_2 = 10;
  TPriorityQueue<int> queue_1(size_1);
  TPriorityQueue<int> queue_2(size_2);
  for (int i = 0; i < size_2; i++) {
    Pair<int> a = {2 * i, i};
    queue_2.push(a);
  }
  queue_1 = queue_2;

  EXPECT_EQ(2 * (size_2 - 1), queue_1.top());
}

TEST(TPriorityQueue, push_element_change_size)
{
  TPriorityQueue<int> queue;
  EXPECT_EQ(0, queue.getSize());
  Pair<int> a = {1,1};
  queue.push(a);
  EXPECT_EQ(1, queue.getSize());
}

TEST(TPriorityQueue, can_get_top_element_from_not_empty_queue)
{
  size_t size = 5;
  TPriorityQueue<int> queue;
  for (int i = 0; i < size; i++) {
    Pair<int> pair = {2 * i, i};
    queue.push(pair);
  }
  EXPECT_NO_THROW(queue.top());
  EXPECT_EQ(2 * (size - 1), queue.top());
}

TEST(TPriorityQueue, cant_get_top_element_from_empty_queue)
{
  TPriorityQueue<int> queue;
  EXPECT_ANY_THROW(queue.top());
}

TEST(TPriorityQueue, can_pop_not_empty_queue)
{
  size_t size = 5;
  TPriorityQueue<int> queue;
  for (int i = 0; i < size; i++) {
    Pair<int> pair = {2 * i, i};
    queue.push(pair);
  }
  int val = queue.pop();

  EXPECT_EQ(8, val);
  EXPECT_EQ(6, queue.top());
  EXPECT_EQ(size - 1, queue.getSize());
}

TEST(TPriorityQueue, cant_pop_empty_queue)
{
  TPriorityQueue<int> queue;
  EXPECT_ANY_THROW(queue.pop());
}