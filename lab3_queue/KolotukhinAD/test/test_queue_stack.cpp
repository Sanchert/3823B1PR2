#include "queue_stack.h"

#include <gtest.h>

TEST(TTwoStackQueue, can_create)
{
  ASSERT_NO_THROW(TTwoStackQueue<int> queue);
}

TEST(TTwoStackQueue, can_push_element)
{
  TTwoStackQueue<int> queue;
  int value = 1;
  ASSERT_NO_THROW(queue.push(value));
}

TEST(TTwoStackQueue, push_element_change_size)
{
  TTwoStackQueue<int> queue;
  EXPECT_EQ(0, queue.getSize());
  int value = 1;
  queue.push(value);
  EXPECT_EQ(1, queue.getSize());
}

TEST(TTwoStackQueue, can_get_size)
{
  size_t size = 5;
  TTwoStackQueue<int> queue;
  for (size_t i = 1; i <= size; i++) {
    queue.push(i);
  }
  EXPECT_EQ(size, queue.getSize());
}

TEST(TTwoStackQueue, can_create_copy)
{
  TTwoStackQueue<int> queue_1;
  ASSERT_NO_THROW(TTwoStackQueue<int> queue_2(queue_1));
}

TEST(TTwoStackQueue, copied_queue_is_equal_to_source_one)
{
  TTwoStackQueue<int> queue_1;
  queue_1.push(25);
  queue_1.push(50);
  TTwoStackQueue<int> queue_2(queue_1);
  EXPECT_EQ(true, (queue_1 == queue_2));
}

TEST(TTwoStackQueue, can_assign_to_itself)
{
  TTwoStackQueue<int> queue;
  for (int i = 0; i < 10; i++) {
    queue.push(i);
  }
  queue = queue;
  EXPECT_EQ(0, queue.top());
}

TEST(TTwoStackQueue, can_assign_queues_of_equal_size)
{
  size_t size = 10;
  TTwoStackQueue<int> queue_1;
  TTwoStackQueue<int> queue_2;
  for (int i = 0; i < size; i++) {
    queue_2.push(i);
  }
  queue_1 = queue_2;
  EXPECT_EQ(true, queue_1 == queue_2);
}

TEST(TTwoStackQueue, can_assign_queues_of_different_size)
{
  size_t size_1 = 5, size_2 = 10;
  TTwoStackQueue<int> queue_1;
  TTwoStackQueue<int> queue_2;
  for (int i = 0; i < size_1; i++) {
    queue_1.push(i);
  }

  for (int i = 0; i < size_2; i++) {
    queue_2.push(i);
  }

  queue_1 = queue_2;

  EXPECT_EQ(queue_1, queue_2);
}

TEST(TTwoStackQueue, can_get_top_element_from_not_empty_queue)
{
  size_t size = 5;
  TTwoStackQueue<int> queue;
  for (size_t i = 0; i < size; i++) {
    queue.push(i);
  }
  EXPECT_NO_THROW(queue.top());
  EXPECT_EQ(0, queue.top());
}

TEST(TTwoStackQueue, cant_get_top_element_from_empty_queue)
{
  TTwoStackQueue<int> queue;
  EXPECT_ANY_THROW(queue.top());
}

TEST(TTwoStackQueue, can_pop_not_empty_queue)
{
  size_t size = 5;
  TTwoStackQueue<int> queue;
  for (size_t i = 0; i < size; i++) {
    queue.push(i);
  }
  int val = queue.pop();

  EXPECT_EQ(0, val);
  EXPECT_EQ(1, queue.top());
  EXPECT_EQ(size - 1, queue.getSize());
}

TEST(TTwoStackQueue, cant_pop_empty_queue)
{
  TTwoStackQueue<int> queue;
  EXPECT_ANY_THROW(queue.pop());
}
