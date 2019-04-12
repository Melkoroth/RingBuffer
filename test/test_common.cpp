#include <unity.h>
#include <RingBuffer.h>
//TODO: Remove
#include <iostream>

void test_maxLength() {
	CRingBuffer<int> buff;
	TEST_ASSERT_EQUAL_INT(10, buff.maxLength());
}

void test_empty_isEmpty() {
	CRingBuffer<int> buff;
	TEST_ASSERT_TRUE(buff.isEmpty());
}

void test_empty_length() {
	CRingBuffer<int> buff;
	TEST_ASSERT_EQUAL_INT(0, buff.length());
}

void test_not_empty_is_not_isEmpty() {
	CRingBuffer<int> buff;
	buff.addLast(1);
	TEST_ASSERT_FALSE(buff.isEmpty());
	TEST_ASSERT_EQUAL_INT(1, buff.length());
}

void test_not_empty_length() {
	CRingBuffer<int> buff;
	buff.addLast(1);
	TEST_ASSERT_EQUAL_INT(1, buff.length());
}

void test_simple_add_retrieve() {
	CRingBuffer<int> buff;
	buff.addLast(1);
	TEST_ASSERT_EQUAL_INT(1, buff.first());
}

void test_full_buffer_items_and_length() {
	CRingBuffer<int> buff;
	for (int i = 0; i < buff.maxLength(); i++) {
		buff.addLast(i);
		TEST_ASSERT_EQUAL_INT(i + 1, buff.length());
	}
	TEST_ASSERT_TRUE(buff.isFull());
	for (int i = 0; i < buff.maxLength(); i++) {
		TEST_ASSERT_EQUAL_INT(i, buff.first());
		buff.deleteFirst();
		TEST_ASSERT_EQUAL_INT(buff.maxLength() - i - 1, buff.length());
	}
}

void test_full_buffer_plus_items_and_length() {
	CRingBuffer<int> buff;
	while (!buff.isFull()) {
		buff.addLast(1);
	}
	buff.addLast(555);
	TEST_ASSERT_TRUE(buff.isFull());
	TEST_ASSERT_EQUAL_INT(buff.maxLength(), buff.length());
	while (!(buff.length() == 1)) {
		TEST_ASSERT_EQUAL_INT(1, buff.first());
		buff.deleteFirst();
		TEST_ASSERT_FALSE(buff.isEmpty());
	}
	TEST_ASSERT_EQUAL_INT(1, buff.length());
	TEST_ASSERT_EQUAL_INT(555, buff.first());
}

void test_full_buffer_various_times() {
	CRingBuffer<int> buff;
	for (int i = 0; i < 15; i++) {
		buff.addLast(1);
	}
	for (int i = 0; i < buff.maxLength() - 1; i++) {
		buff.deleteFirst();
	}
	TEST_ASSERT_EQUAL_INT(1, buff.length());
	TEST_ASSERT_EQUAL_INT(1, buff.first());

	while (!buff.isFull()) {
		buff.addLast(2);
		TEST_ASSERT_EQUAL_INT(1, buff.first());
	}
	TEST_ASSERT_EQUAL_INT(1, buff.first());
	buff.deleteFirst();
	TEST_ASSERT_EQUAL_INT(2, buff.first());
	for (int i = 0; i < buff.maxLength() - 2; i++) {
		buff.deleteFirst();
	}
	TEST_ASSERT_EQUAL_INT(1, buff.length());
	TEST_ASSERT_EQUAL_INT(2, buff.first());
}

void test_copy_constructor() {
	CRingBuffer<int> buff;
	for (int i = 0; i < buff.maxLength(); i++) {
		buff.addLast(i);
	}
	CRingBuffer<int> buff2(buff);
	while (!buff.isEmpty()) {
		buff.deleteFirst();
	}
	TEST_ASSERT_FALSE(buff2.isEmpty());
	TEST_ASSERT_TRUE(buff2.isFull());
	TEST_ASSERT_EQUAL_INT(buff2.maxLength(), buff2.length());
	for (int i = 0; i < buff2.maxLength(); i++) {
		TEST_ASSERT_EQUAL_INT(i, buff2.first());
		buff2.deleteFirst();
		TEST_ASSERT_EQUAL_INT(buff2.maxLength() - i - 1, buff2.length());
	}
}

void test_copy_constructor_plus_items() {
	CRingBuffer<int> buff;
	while (!buff.isFull()) {
		buff.addLast(1);
	}
	buff.addLast(555);
	CRingBuffer<int> buff2(buff);
	TEST_ASSERT_TRUE(buff2.isFull());
	TEST_ASSERT_EQUAL_INT(buff2.maxLength(), buff2.length());
	while (!(buff2.length() == 1)) {
		TEST_ASSERT_EQUAL_INT(1, buff2.first());
		buff2.deleteFirst();
		TEST_ASSERT_FALSE(buff2.isEmpty());
	}
	TEST_ASSERT_EQUAL_INT(1, buff2.length());
	TEST_ASSERT_EQUAL_INT(555, buff2.first());
}

void test_equal_operator() {
	CRingBuffer<int> buff;
	for (int i = 0; i < buff.maxLength(); i++) {
		buff.addLast(i);
	}
	CRingBuffer<int> buff2;
	buff2 = buff;
	while (!buff.isEmpty()) {
		buff.deleteFirst();
	}
	TEST_ASSERT_FALSE(buff2.isEmpty());
	TEST_ASSERT_TRUE(buff2.isFull());
	TEST_ASSERT_EQUAL_INT(buff2.maxLength(), buff2.length());
	for (int i = 0; i < buff2.maxLength(); i++) {
		TEST_ASSERT_EQUAL_INT(i, buff2.first());
		buff2.deleteFirst();
		TEST_ASSERT_EQUAL_INT(buff2.maxLength() - i - 1, buff2.length());
	}
}

void test_equal_operator_plus_items() {
	CRingBuffer<int> buff;
	while (!buff.isFull()) {
		buff.addLast(1);
	}
	buff.addLast(555);
	CRingBuffer<int> buff2;
	buff2 = buff;
	TEST_ASSERT_TRUE(buff2.isFull());
	TEST_ASSERT_EQUAL_INT(buff2.maxLength(), buff2.length());
	while (!(buff2.length() == 1)) {
		TEST_ASSERT_EQUAL_INT(1, buff2.first());
		buff2.deleteFirst();
		TEST_ASSERT_FALSE(buff2.isEmpty());
	}
	TEST_ASSERT_EQUAL_INT(1, buff2.length());
	TEST_ASSERT_EQUAL_INT(555, buff2.first());
}

/*
void test_empty_first_returns_zero() {
	CRingBuffer<int> buff;
	TEST_ASSERT_EQUAL_INT(0, buff.first());
	while (!buff.isFull()) {
		buff.addLast(1);
	}
	while (!buff.isEmpty()) {
		buff.deleteFirst();
	}
	TEST_ASSERT_EQUAL_INT(0, buff.first());
}
*/

void process() {
    UNITY_BEGIN();
    RUN_TEST(test_maxLength);
    RUN_TEST(test_empty_isEmpty);
    RUN_TEST(test_empty_length);
    RUN_TEST(test_not_empty_is_not_isEmpty);
    RUN_TEST(test_not_empty_length);
    RUN_TEST(test_simple_add_retrieve);
    RUN_TEST(test_full_buffer_items_and_length);
    RUN_TEST(test_full_buffer_plus_items_and_length);
    RUN_TEST(test_full_buffer_various_times);
    RUN_TEST(test_copy_constructor);
    RUN_TEST(test_equal_operator);
    RUN_TEST(test_copy_constructor_plus_items);
    RUN_TEST(test_equal_operator_plus_items);
    //RUN_TEST(test_empty_first_returns_zero);
    UNITY_END();
}

#ifdef ARDUINO

#include <Arduino.h>
void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    process();
}

void loop() {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(500);
}

#else

int main(int argc, char **argv) {
    process();
    return 0;
}

#endif