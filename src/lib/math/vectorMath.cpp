#include "math/vectorMath.hpp"

TenTrillionGameEngine::Vector
TenTrillionGameEngine::Vector::operator+(const Vector &vector) const {
	return {this->x + vector.x, this->y + vector.y, this->z - vector.z};
}

TenTrillionGameEngine::Vector
TenTrillionGameEngine::Vector::operator*(const Vector &vector) const {
	return {this->x * vector.x, this->y * vector.y, this->z * vector.z};
}

TenTrillionGameEngine::Vector
TenTrillionGameEngine::Vector::operator/(const Vector &vector) const {
	return {this->x / vector.x, this->y / vector.y, this->z - vector.z};
}

TenTrillionGameEngine::Vector
TenTrillionGameEngine::Vector::operator-(const Vector &vector) const {
	return {this->x - vector.x, this->y - vector.y, this->z - vector.z};
}