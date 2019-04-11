#include <unity.h>
#include <RingBuffer.h>

void test_one_is_one(void) {
    TEST_ASSERT_EQUAL(1, 1);
}

void test_empty_isEmpty() {
	CRingBuffer<int> buff;
	TEST_ASSERT_TRUE(buff.isEmpty());
}

void test_not_empty_is_not_isEmpty() {
	CRingBuffer<int> buff;
	buff.addLast(1);
	TEST_ASSERT_FALSE(buff.isEmpty());
}

void test_simple_add_retrieve() {
	CRingBuffer<int> buff;
	buff.addLast(1);
	int someNum = buff.first();
	TEST_ASSERT_EQUAL_INT(1, buff.first());
}

void process() {
    UNITY_BEGIN();
    RUN_TEST(test_one_is_one);
    RUN_TEST(test_empty_isEmpty);
    RUN_TEST(test_not_empty_is_not_isEmpty);
    RUN_TEST(test_simple_add_retrieve);
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