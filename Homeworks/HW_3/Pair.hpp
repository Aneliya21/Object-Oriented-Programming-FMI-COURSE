#pragma once

template<typename T, typename D>
class Pair {

public:
	Pair() = default;
	Pair(const T& lhs, const D& rhs);
	Pair(T&& lhs, D&& rhs);

	Pair(const T& lhs, D&& rhs);
	Pair(T&& lhs, const D& rhs);

	const T& getLhs() const;
	const D& getRhs() const;

	T& getLhs();
	D& getRhs();

	void setLhs(const T& lhs);
	void setRhs(const D& rhs);

	void setLhs(T&& lhs);
	void setRhs(D&& rhs);

private:
	T lhs;
	D rhs;
};

template<typename T, typename D>
Pair<T, D>::Pair(const T& lhs, const D& rhs) {
	setLhs(lhs);
	setRhs(rhs);
}

template<typename T, typename D>
Pair<T, D>::Pair(T&& lhs, D&& rhs) {
	setLhs(std::move(lhs));
	setRhs(std::move(rhs));
}

template<typename T, typename D>
Pair<T, D>::Pair(const T& lhs, D&& rhs) {
	setLhs(lhs);
	setRhs(std::move(rhs));
}

template<typename T, typename D>
Pair<T, D>::Pair(T&& lhs, const D& rhs) {
	setLhs(std::move(lhs));
	setRhs(rhs);
}

template<typename T, typename D>
const T& Pair<T, D>::getLhs() const {
	return lhs;
}

template<typename T, typename D>
const D& Pair<T, D>::getRhs() const {
	return lhs;
}

template<typename T, typename D>
T& Pair<T, D>::getLhs() {
	return lhs;
}

template<typename T, typename D>
D& Pair<T, D>::getRhs() {
	return rhs;
}

template<typename T, typename D>
void Pair<T, D>::setLhs(const T& lhs) {
	this->lhs = lhs;
}

template<typename T, typename D>
void Pair<T, D>::setRhs(const D& rhs) {
	this->rhs = rhs;
}

template<typename T, typename D>
void Pair<T, D>::setLhs(T&& lhs) {
	this->lhs = std::move(lhs);
}

template<typename T, typename D>
void Pair<T, D>::setRhs(D&& rhs) {
	this->rhs = std::move(rhs);
}

