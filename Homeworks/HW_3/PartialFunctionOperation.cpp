#include "PartialFunctionOperation.h"

PartialFunctionOperation::PartialFunctionOperation() {
	functions = new PartialFunction * [capacity];
}

void PartialFunctionOperation::resize() {
	PartialFunction** newFuncs = new PartialFunction * [capacity *= 2];
	for (size_t i = 0; i < count; i++) {
		newFuncs[i] = functions[i];
	}
	delete[] functions;
	functions = newFuncs;
}

void PartialFunctionOperation::copyFrom(const PartialFunctionOperation& other) {
	count = other.count;
	capacity = other.capacity;
	functions = new PartialFunction * [capacity];
	for (size_t i = 0; i < count; i++) {
		functions[i] = other.functions[i]->clone();
	}
}
void PartialFunctionOperation::moveFrom(PartialFunctionOperation&& other) {
	functions = other.functions;
	other.functions = nullptr;

	count = other.count;
	other.count = 0;

	capacity = other.capacity;
	other.capacity = 0;
}
void PartialFunctionOperation::free() {
	for (size_t i = 0; i < count; i++) {
		delete functions[i];
	}
	delete[] functions;
	functions = nullptr;

	count = capacity = 0;
}

PartialFunctionOperation::PartialFunctionOperation(PartialFunction**&& functions, size_t count) {
	this->functions = functions;
	this->count = count;
}

PartialFunctionOperation::PartialFunctionOperation(const PartialFunctionOperation& other) {
	copyFrom(other);
}
PartialFunctionOperation::PartialFunctionOperation(PartialFunctionOperation&& other) noexcept {
	moveFrom(std::move(other));
}

PartialFunctionOperation& PartialFunctionOperation::operator=(const PartialFunctionOperation& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
PartialFunctionOperation& PartialFunctionOperation::operator=(PartialFunctionOperation&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

PartialFunctionOperation::~PartialFunctionOperation() {
	free();
}

size_t PartialFunctionOperation::getCount() const {
	return count;
}
size_t PartialFunctionOperation::getCapacity() const {
	return capacity;
}

const PartialFunction* PartialFunctionOperation::operator[](size_t index) const {
	if (index >= count) {
		throw std::invalid_argument("invalid index");
	}
	return functions[index];
}
PartialFunction* PartialFunctionOperation::operator[](size_t index) {
	if (index >= count) {
		throw std::invalid_argument("invalid index");
	}
	return functions[index];
}

void PartialFunctionOperation::addFunc(UniquePointer<PartialFunction>& newFunc) {
	if (count == capacity) {
		resize();
	}
	functions[count++] = newFunc.release();
}
void PartialFunctionOperation::addFunc(const SharedPtr<PartialFunction>& newFunc) {
	if (count == capacity) {
		resize();
	}
	functions[count++] = newFunc.operator->();
}
void PartialFunctionOperation::addFunc(PartialFunction* newFunc) {
	if (count == capacity) {
		resize();
	}
	functions[count++] = newFunc->clone();
}