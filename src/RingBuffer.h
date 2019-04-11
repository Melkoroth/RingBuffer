// #############################################################################
// #
// # Name       : RingBuffer.h
// # Author     : Juan L. Perez Diez <ender.vs.melkor at gmail>
// 
// # Description: Implements a class containing a ring buffer. 
// 
// #  This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// #############################################################################

#ifndef __RINGBUFFER_H
#define __RINGBUFFER_H

//Tweak this to your desired capacity
#define MAXLENGTH 10

template <class TElem>
class CRingBuffer {
	public:
		CRingBuffer();
		CRingBuffer(const CRingBuffer<TElem>&);
		CRingBuffer &operator=(const CRingBuffer<TElem>&);
		virtual ~CRingBuffer() {}

		//Adds TElem the last in the buffer
		void addLast(const TElem&);
		//Returns the first element of the buffer
		const TElem& first() const;
		//Deletes the first element in the buffer
		void deleteFirst();
		//Returns the state of the buffer
		bool isEmpty();

	private:
		int _start, _end;
		int _length;
		TElem _buff[MAXLENGTH];

		void copy(const CRingBuffer<TElem>&);
};

// *********************************************
// Implementation
// *********************************************
template <class TElem>
CRingBuffer<TElem>::CRingBuffer() : _start(0), _end(-1), _length(0) {}

template <class TElem>
CRingBuffer<TElem>::CRingBuffer(const CRingBuffer<TElem>& other) {
	copy(other);
}

template <class TElem>
CRingBuffer<TElem>& CRingBuffer<TElem>::operator=(const CRingBuffer<TElem>& other) {
	if (this != &other)
		copy(other);
	return *this;
}

template <class TElem>
void CRingBuffer<TElem>::copy(const CRingBuffer<TElem>& other) {
	_length = other._length;
	for (int i = 0; i < _length; i++) {
		_buff[i] = other._buff[(other._start + i) % MAXLENGTH];
	}
	_start = 0;
	_end = _length - 1;
}

template <class TElem>
void CRingBuffer<TElem>::addLast(const TElem& elem) {
	_end = (_end + 1) % MAXLENGTH;
	_length++;
	_buff[_end] = elem;
}

template <class TElem>
const TElem& CRingBuffer<TElem>::first() const {
	if (!isEmpty())
		return _buff[_start];
	else
		return 0;
}

template <class TElem>
void CRingBuffer<TElem>::deleteFirst() {
	if(!isEmpty()) {
		_start = (_start + 1) % MAXLENGTH;
		_length--;
	}
}

template <class TElem>
bool CRingBuffer<TElem>::isEmpty() {
	return _length == 0;
}

#endif