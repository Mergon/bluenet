/**
 * Author: Anne van Rossum
 * Date: 6 Nov., 2014
 * License: LGPLv3+, Apache License, or MIT, your choice
 */

#ifndef CS_BUFFER_H
#define CS_BUFFER_H

#include <stdlib.h> // malloc, free
#include <stdint.h> // uint32_t
#include <drivers/serial.h>

// can only be used from C++

// define buffer
// TODO: current implementation is crap
template <class T>
struct buffer {
	T *buffer;
	T *ptr;
	uint16_t size;

	// pushes till end of buffer
	void push(T value) {
		if (full()) return;
		*ptr = value;
		ptr++;
		//log(DEBUG, "Add #%u", (uint8_t)(ptr-buffer));
	}

	// pops till beginning... 0xdeafabba is an error code
	T pop() {
//		uint32_t value = *ptr;
//		if (empty()) return 0xdeafabba;
//		ptr--;
		if (empty()) return 0xdeafabba; // TODO: Assumes uint32_t for T
		T value = *(--ptr);
		return value;
	}

	bool empty() {
		return (ptr == buffer);
	}

	bool full() {
		return ((uint16_t)(ptr - buffer) == size);
	}

	void clear() {
		ptr = buffer;
	}

	uint16_t count() {
		//log(DEBUG, "Current count: %u", ptr-buffer); //seems to wait..
		return (uint16_t)(ptr - buffer);
	}
};

// define alias for struct buffer
template <class T>
using buffer_t = buffer<T>;
//typedef struct buffer buffer_t;

#endif // CS_BUFFER_H
