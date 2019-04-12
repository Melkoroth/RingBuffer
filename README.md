# RingBuffer
This is a fixed-size (static) implementation of a ring buffer container with FIFO operations which can hold any kind of thing inside it.

## Usage
First of all you should define the desired size in RingBuffer.h
```cpp
//Tweak this to your desired capacity
#define MAXLENGTH 10
```

Then, on your main program you declare the object as follows:
```cpp
//For int
CRingBuffer<int> buff;
//For bool
CRingBuffer<bool> buff;
//And so forth
//You can also hold another class inside the container
CRingBuffer<SomeClass> buff;
```

Once done, you can work with the following methods:
```cpp
//Adds TElem the last in the buffer
void addLast(const TElem&);
//Returns the first element of the buffer
const TElem& first() const;
//Deletes the first element in the buffer
void deleteFirst();
//Returns the state of the buffer
bool isEmpty() const;
bool isFull() const;
//Return the number of elements in buffer
int length() const;
//Returns max number of elements
int maxLength() const;
```

### Caveats
* You should always test for isEmpty() before getting an element using first() if you don't want to get some garbage in return.

## Running tests
```bash
platformio test
```