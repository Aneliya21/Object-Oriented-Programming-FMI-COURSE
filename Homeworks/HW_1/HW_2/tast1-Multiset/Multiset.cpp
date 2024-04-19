#include "Multiset.h"

Multiset::Multiset(unsigned n, unsigned k) {
	this->maxNumber = n;
	set_kBits(k);
	setBucketsCount();
	setMaxOccurences();

	buckets = new uint8_t[bucketsCount]{ 0 };
}

Multiset::Multiset(const Multiset& other) {
	copyFrom(other);
}
Multiset& Multiset::operator=(const Multiset& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Multiset::Multiset(Multiset&& other) noexcept {
	moveFrom(std::move(other));
}
Multiset& Multiset::operator=(Multiset&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Multiset::~Multiset() {
	free();
}

void Multiset::free() {
	delete[] buckets;
	buckets = nullptr;

	maxNumber = bucketsCount = maxOccurrences = kBits = 0;
}
void Multiset::copyFrom(const Multiset& other) {
	maxNumber = other.maxNumber;
	bucketsCount = other.bucketsCount;
	maxOccurrences = other.maxOccurrences;
	kBits = other.kBits;

	buckets = new uint8_t[bucketsCount]{ 0 };

	for (unsigned i = 0; i < bucketsCount; i++)
		buckets[i] = other.buckets[i];
}
void Multiset::moveFrom(Multiset&& other) {
	buckets = other.buckets;
	other.buckets = nullptr;

	maxNumber = other.maxNumber;
	bucketsCount = other.bucketsCount;
	maxOccurrences = other.maxOccurrences;
	kBits = other.kBits;

	other.maxNumber = other.bucketsCount = other.maxOccurrences = other.kBits = MultisetConstants::DEF_VALUE;
}

void Multiset::addNumber(unsigned num) {

	if (num > maxNumber) {
		return;
	}

	unsigned countOccur = getCountOfOccurrences(num);
	if (maxOccurrences <= countOccur) {
		return;
	}
	incrementOccurences(num, countOccur + 1);
}

uint8_t Multiset::getMask(unsigned toShift) const {
	uint8_t mask = (1 << toShift);
	return mask;
}
unsigned Multiset::getIndex(unsigned bitPositionInBuckets, unsigned currentBit) const {
	unsigned index = (bitPositionInBuckets + currentBit) / 8;
	return index;
}
unsigned Multiset::toShiftWith(unsigned bitPositionInBuckets, unsigned currentBit) const {
	unsigned offset = (bitPositionInBuckets + currentBit) % 8;
	return offset;
}

void Multiset::addNumberMultipleTimes(unsigned number, unsigned times) {
	if (times > maxOccurrences) {
		times = maxOccurrences;
	}
	for (unsigned i = 0; i < times; i++) {
		addNumber(number);
	}
}

void Multiset::incrementOccurences(unsigned number, unsigned occurrences) {

	unsigned bitPositionInBuckets = number * kBits;

	for (unsigned i = 0; i < kBits; i++) {

		unsigned bucketIndex = getIndex(bitPositionInBuckets, i);
		unsigned toShift = toShiftWith(bitPositionInBuckets, i);

		uint8_t mask = getMask(toShift);
		uint8_t maskOf_kBits = getMask(i);

		if (occurrences & maskOf_kBits) {
			buckets[bucketIndex] |= mask;
		}
		else {
			buckets[bucketIndex] &= ~mask;
		}
		if ((toShift == MultisetConstants::MAX_INDEX_IN_BUCKET) && (i < kBits - 1)) {
			bucketIndex++;
		}
	}
}
unsigned Multiset::getCountOfOccurrences(unsigned num) const {
	if (num > maxNumber) {
		return 0;
	}
	unsigned bitPosition = num * kBits;

	unsigned bucketIndex = bitPosition / MultisetConstants::MAX_K_BITS;
	unsigned bitOffset = bitPosition % MultisetConstants::MAX_K_BITS;

	unsigned result = MultisetConstants::DEF_VALUE; //0

	for (unsigned i = 0; i < kBits; i++) {

		uint8_t mask = getMask(bitOffset + i);

		if (buckets[bucketIndex] & mask) {
			uint8_t maskOf_kBits = getMask(i);

			result |= maskOf_kBits;
		}
	}

	return result;
}

void Multiset::printNumber(unsigned num, unsigned occurances) const {
	for (unsigned i = 0; i < occurances; i++)
		std::cout << num << " ";
}
void Multiset::printSet() const {
	std::cout << '{';
	for (unsigned i = 0; i <= maxNumber; i++)
	{
		unsigned occurrences = getCountOfOccurrences(i);
		printNumber(i, occurrences);
	}
	std::cout << '}';
}

void Multiset::printBits(uint8_t current) const
{
	int startIndex = 8 - 1;
	for (int j = startIndex; j >= 0; j--)
	{
		std::cout << ((current >> j) & 1) << " ";
	}
	std::cout << " | ";
}
void Multiset::printAsInMemory() const
{
	int startInd = 8 - 1;

	for (unsigned i = 0; i < bucketsCount; i++)
	{
		printBits(buckets[i]);
	}
}

void Multiset::setBucketsCount() {
	bucketsCount = ((this->maxNumber + 1) * this->kBits + 7) / 8;
}
void Multiset::setMaxOccurences() {
	if (areValidBits(kBits)) {
		maxOccurrences = (1 << kBits) - 1;
	}
	else {
		return;
	}
}
void Multiset::set_kBits(unsigned kBits) {
	if (areValidBits(kBits)) {
		this->kBits = kBits;
	}
	else {
		return;
	}
}

bool Multiset::areValidBits(unsigned kBits) const {
	return (kBits >= 1 && kBits <= 8);
}

void Multiset::saveToBinaryFile(const char* fileName) const {

	if (!fileName) {
		throw std::exception("fileName if null pointer!");
	}

	std::ofstream ofs(fileName, std::ios::binary);

	if (!ofs.is_open()) {
		throw std::exception("file could NOT open successfully!");
	}

	ofs.write((const char*)&maxNumber, sizeof(unsigned));

	ofs.write((const char*)&bucketsCount, sizeof(unsigned));

	ofs.write((const char*)&kBits, sizeof(unsigned));

	ofs.write((const char*)&maxOccurrences, sizeof(unsigned));

	ofs.write((const char*)buckets, bucketsCount * sizeof(uint8_t));

	ofs.close();
}
void Multiset::readFromBinaryFile(const char* fileName) {

	if (!fileName) {
		throw std::exception("fileName if null pointer!");
	}

	std::ifstream ifs(fileName, std::ios::binary);

	if (!ifs.is_open()) {
		throw std::exception("file could NOT open successfully!");
	}

	ifs.read((char*)&maxNumber, sizeof(unsigned));

	ifs.read((char*)&bucketsCount, sizeof(unsigned));

	ifs.read((char*)&kBits, sizeof(unsigned));

	ifs.read((char*)&maxOccurrences, sizeof(unsigned));

	ifs.read((char*)buckets, bucketsCount * sizeof(uint8_t));

	ifs.close();
}

Multiset intersection(const Multiset& lhs, const Multiset& rhs) {

	if (lhs.maxNumber != rhs.maxNumber) {
		return Multiset(0, 0);
	}

	unsigned maxNumberInIntersection = std::min(lhs.maxNumber, rhs.maxNumber);
	unsigned kBitsInIntersection = std::min(lhs.kBits, rhs.kBits);

	Multiset result(maxNumberInIntersection, kBitsInIntersection);

	for (unsigned i = 0; i <= maxNumberInIntersection; i++) {

		unsigned occurencesInLhs = lhs.getCountOfOccurrences(i);
		unsigned occurencesInRhs = rhs.getCountOfOccurrences(i);

		unsigned occurencesInIntersect = (occurencesInLhs < occurencesInRhs) ?
			occurencesInLhs : occurencesInRhs;

		if (occurencesInIntersect > 0) {
			result.addNumberMultipleTimes(i, occurencesInIntersect);
		}
	}
	return result;
}
Multiset difference(const Multiset& lhs, const Multiset& rhs) {
	//{2,2,3,4,5}
	//{1,2,4}
	//{2, 3, ,5}
	Multiset result(lhs.maxNumber, lhs.kBits);

	for (unsigned i = 0; i <= lhs.maxNumber; i++) {
		unsigned countInLhs = lhs.getCountOfOccurrences(i);
		unsigned countInRhs = rhs.getCountOfOccurrences(i);

		int countInResult = countInLhs - countInRhs;
		if (countInResult < 0) {
			continue;
		}
		else {
			result.addNumberMultipleTimes(i, countInResult);
		}
	}
	return result;
}

Multiset& Multiset::complement() {

	Multiset temp(maxNumber, kBits);

	for (unsigned i = 0; i <= maxNumber; i++) {

		unsigned occurences = getCountOfOccurrences(i);
		unsigned complementOccurences = maxOccurrences - occurences;
	
		temp.addNumberMultipleTimes(i, complementOccurences);
	}
	*this = temp;
	return *this;
}