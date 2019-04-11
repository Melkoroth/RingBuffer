# RingBuffer implementation
This is a fixed-size (static) implementation of a ring buffer with FIFO operations.

## Usage
First of all you should define the desired size in RingBuffer.h
```cpp
//Tweak this to your desired capacity
#define MAXLENGTH 10
```

## Running tests
```bash
platformio test
```