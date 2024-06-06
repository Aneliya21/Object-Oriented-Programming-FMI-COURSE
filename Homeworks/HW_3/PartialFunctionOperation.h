#pragma once
#include "PartialFunction.h"
#include "Unique_ptr.hpp"
#include "Shared_ptr.hpp"

class PartialFunctionOperation {

public:
	PartialFunctionOperation();

	PartialFunctionOperation(PartialFunction**&& functions, size_t count);

	PartialFunctionOperation(const PartialFunctionOperation& other);
	PartialFunctionOperation(PartialFunctionOperation&& other) noexcept;

	PartialFunctionOperation& operator=(const PartialFunctionOperation& other);
	PartialFunctionOperation& operator=(PartialFunctionOperation&& other) noexcept;

	~PartialFunctionOperation();

	size_t getCount() const;
	size_t getCapacity() const;

	const PartialFunction* operator[](size_t index) const;
	PartialFunction* operator[](size_t index);

	void addFunc(UniquePointer<PartialFunction>& newFunc);
	void addFunc(const SharedPtr<PartialFunction>& newFunc);
	void addFunc(PartialFunction* newFunc);

protected:
	PartialFunction** functions = nullptr;
	size_t count = 0;
	size_t capacity = 4;

	void resize();

	void copyFrom(const PartialFunctionOperation& other);
	void moveFrom(PartialFunctionOperation&& other);
	void free();
};

