#include "Set.h"

Set::Set(const std::string& element)
{
	elements.insert(element); // Создание множества из строки
}

Set::Set(const std::vector<char>& stack)
{
	std::string element(stack.begin(), stack.end());
	elements.insert(element); // Создание множества из символа
}

const std::set<std::string>& Set::getElements() const
{
	return elements;
}

bool Set::isEmpty() const
{
	return elements.empty();
}

void Set::addElement(const std::string& element)
{
	elements.insert(element);
}

void Set::removeElement(const std::string& element)
{
	elements.erase(element);
}

size_t Set::cardinality() const
{
	return elements.size();
}

bool Set::contains(const std::string& element) const
{
	return elements.count(element) > 0;
}

Set Set::operator+(const Set& other) const
{
	Set result = *this;
	result += other;
	return result;
}

Set& Set::operator+=(const Set& other)
{
	for (const auto& element : other.elements) {
		elements.insert(element);
	}
	return *this;
}

Set Set::operator*(const Set& other) const
{
	Set result;
	for (const auto& element : elements) {
		if (other.contains(element)) {
			result.addElement(element);
		}
	}
	return result;
}

Set& Set::operator*=(const Set& other)
{
	*this = *this * other;
	return *this;
}

Set Set::operator-(const Set& other) const
{
	Set result = *this;
	result -= other;
	return result;
}

Set& Set::operator-=(const Set& other)
{
	Set result = *this;
	for (const auto& element : other.elements) {
		result.removeElement(element);
	}
	*this = result;
	return *this;
}

Set Set::operator[](const std::string& element) const
{
	Set result;
	for (const auto& subset : elements) {
		if (subset.find(element) != std::string::npos) {
			result.addElement(subset);
		}
	}
	return result;
}

void Set::printSet(const Set& set)
{
	std::cout << "{";
	const auto& elements = set.getElements();
	for (auto it = elements.begin(); it != elements.end(); ++it) {
		std::cout << *it;
		if (std::next(it) != elements.end()) {
			std::cout << ", ";
		}
	}
	std::cout << "}" << std::endl;
}

Set Set::booleanSet(const Set& set)
{
	Set result;
	result.addElement("{}"); // Добавление пустого множества в результат

	std::vector<std::string> elements(set.getElements().begin(), set.getElements().end());

	// Создание всех возможных подмножеств исходного множества
	for (size_t i = 0; i < (1 << elements.size()); ++i) {
		std::string subset = "{";

		for (size_t j = 0; j < elements.size(); ++j) {
			if (i & (1 << j)) {
				subset += elements[j] + ", ";
			}
		}

		if (!subset.empty()) {
			subset = subset.substr(0, subset.length() - 2); // Удаляем последнюю запятую и пробел
		}

		subset += "}";
		result.addElement(subset);
	}

	return result;
}
