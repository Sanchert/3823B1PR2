#include "queue_lite.h"

#include <gtest.h>

TEST(TQueue, can_create_queue)
{
  ASSERT_NO_THROW(TQueue<int> queue());
}

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> queue(1));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
  ASSERT_ANY_THROW(TQueue<int> queue(-1));
}

TEST(TQueue, can_create_copy)
{
  TQueue<int> queue_1(1);
  ASSERT_NO_THROW(TQueue<int> queue_2(queue_1));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
  TQueue<int> queue_1(10);
  TQueue<int> queue_2(queue_1);

  EXPECT_EQ(true, (queue_1 == queue_2));
}

TEST(TQueue, copied_queue_has_its_own_memory)
{
  TQueue<int> queue_1(1);
  TQueue<int> queue_2(queue_1);

  EXPECT_NE(&queue_1, &queue_2);
}

TEST(TQueue, can_get_size)
{
  size_t size = 1;
  TQueue<int> queue(size);

  EXPECT_EQ(size, queue.getSize());
}

TEST(TQueue, can_assign_to_itself)
{
  size_t size = 10;
  TQueue<int> queue(size);
  for (size_t i = 0; i < size; i++) {
    queue.Push(i);
  }
  queue = queue;

  EXPECT_EQ(0, queue.top());
}

TEST(TQueue, can_assign_queues_of_equal_size)
{
  size_t size = 10;
  TQueue<int> queue_1(size);
  TQueue<int> queue_2(size);
  for (size_t i = 0; i < queue_2.getSize(); i++) {
    queue_2.Push(i);
  }
  queue_1 = queue_2;

  EXPECT_EQ(0, queue_1.top());
}

TEST(TQueue, assign_operator_change_queue_size)
{
  size_t size_1 = 5, size_2 = 10;
  TQueue<int> queue_1(size_1);
  TQueue<int> queue_2(size_2);
  for (size_t i = 0; i < queue_2.getSize(); i++) {
    queue_2.Push(i);
  }
  queue_1 = queue_2;

  EXPECT_EQ(size_2, queue_1.getSize());
}

TEST(TQueue, can_assign_queues_of_different_size)
{
  size_t size_1 = 5, size_2 = 10;
  TQueue<int> queue_1(size_1);
  TQueue<int> queue_2(size_2);
  for (size_t i = 0; i < queue_2.getSize(); i++) {
    queue_2.Push(i);
  }
  queue_1 = queue_2;

  EXPECT_EQ(0, queue_1.top());
}

TEST(TQueue, compare_equal_queues_return_true)
{
  size_t size = 10;
  TQueue<int> queue_1(size);
  TQueue<int> queue_2(size);
  for (size_t i = 0; i < size; i++) {
    queue_1.Push(i);
    queue_2.Push(i);
  }

  EXPECT_EQ(true, queue_1 == queue_2);
}

TEST(TQueue, compare_queue_with_itself_return_true)
{
  TQueue<int> queue(1);
  EXPECT_EQ(true, (queue == queue));
}

TEST(TQueue, queues_with_different_size_are_equal)
{
  size_t size = 1;
  TQueue<int> queue_1(size);
  TQueue<int> queue_2(size * 2);

  EXPECT_EQ(true, queue_1 == queue_2);
}

TEST(TQueue, push_to_queue)
{
  size_t size = 5;
  TQueue<int> queue(size);
  queue.Push(1);
  queue.Push(2);

  EXPECT_EQ(1, queue.top());
}

TEST(TQueue, push_to_queue_with_not_enough_memory)
{
  size_t size = 5;
  TQueue<int> queue(size);
  for (size_t i = 0; i < size; i++) {
    queue.Push(i);
  }
  queue.Push(size);

  EXPECT_EQ(0, queue.top());
  EXPECT_EQ(size * 2, queue.getSize());
}

TEST(TQueue, cant_top_empty_queue)
{
  size_t size = 5;
  TQueue<int> queue(size);
  EXPECT_ANY_THROW(queue.top());
}

TEST(TQueue, pop_not_empty_queue)
{
  size_t size = 5;
  TQueue<int> queue(size);
  for (size_t i = 0; i < size; i++) {
    queue.Push(i);
  }
  int element = queue.pop();

  EXPECT_EQ(0, element);
  EXPECT_EQ(1, queue.top());
  EXPECT_EQ(size, queue.getSize());
}

TEST(TQueue, cant_pop_empty_queue)
{
  size_t size = 5;
  TQueue<int> queue(size);
  EXPECT_ANY_THROW(queue.pop());
}