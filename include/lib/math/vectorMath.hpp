

#ifndef TEN_TRILLION_VECTORMATH_HPP
#define TEN_TRILLION_VECTORMATH_HPP

#include "tentrillion_export.h"

namespace TenTrillionGameEngine {
struct TENTRILLION_GAME_ENGINE_EXPORT Vector {
	// This is the X Position of the Vector.
	int x;
	// This is the Y Position of the Vector.
	int y;
	// This is the Z Position of the Vector.
	int z;

	// This adds two vectors together.
	Vector operator+(const Vector &vector) const;
	// This subtracts two vectors together.
	Vector operator-(const Vector &vector) const;
	// This multiplies two vectors together.
	Vector operator*(const Vector &vector) const;
	// This divides two vectors together.
	Vector operator/(const Vector &vector) const;
};
} // namespace TenTrillionGameEngine
#endif // TEN_TRILLION_VECTORMATH_HPP
