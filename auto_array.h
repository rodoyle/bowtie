/*
 * auto_array.h
 *
 *  Created on: Oct 12, 2009
 *      Author: langmead
 */

#include <cstring>

#ifndef AUTO_ARRAY_H_
#define AUTO_ARRAY_H_

template<typename T>
class AutoArray {
public:
	AutoArray(size_t sz) {
		t_ = new T[sz];
		sz_ = sz;
	}
	~AutoArray() { delete[] t_; }
	T& operator[](size_t sz) {
		return t_[sz];
	}
	const T& operator[](size_t sz) const {
		return t_[sz];
	}
private:
	T *t_;
	size_t sz_;
};

#endif /* AUTO_ARRAY_H_ */