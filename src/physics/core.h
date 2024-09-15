#pragma once

#include <cmath>

// Book's author is called Ian -> Cyan -> Blue
namespace blue 
{

	/* 
		Single precision is provided by default
	*/
	typedef float real;
	#define real_sqrt sqrtf
	#define real_pow powf

	class Vector3 {
	public:

		real x;
		real y;
		real z;

		// Default constructor creates a zero vector
		Vector3() : x(0), y(0), z(0) {}
		// The explicit constructor creates a vector with the given components
		Vector3(const real x, const real y, const real z): x(x), y(y), z(z) {}

		// Adds given vector to this
		void operator+=(const Vector3& v) {
			x += v.x;
			y += v.y;
			z += v.z;
		}
		// Returns the sum of the given vector with this
		Vector3 operator+(const Vector3& v) {
			return Vector3(x + v.x, y + v.y, z + v.z);
		}
		// Subtracts given vector to this
		void operator-=(const Vector3& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
		}
		// Returns the sum of the given vector with this
		Vector3 operator-(const Vector3& v) {
			return Vector3(x - v.x, y - v.y, z - v.z);
		}
		// Multiplies vector by the given scalar
		void operator*=(const real value) {
			x *= value;
			y *= value;
			z *= value;
		}
		// Returns a copy of the vector scaled by a given value
		Vector3 operator*(const real value) const {
			return Vector3(x * value, y * value, z * value);
		}

		// Flips all components
		void invert() {
			x = -x;
			y = -y;
			z = -z;
		}

		// Gets the magnitude of the vector
		real magnitude() {
			return real_sqrt(x * x + y * y + z * z);
		}

		// Gets the squared magnitude of the vector
		real squareMagnitude() {
			return x * x + y * y + z * z;
		}

		// Turns a non-zero vector into a vector of unit length
		real normalize() {
			real l = magnitude();
			if (l > 0) {
				(*this) *= ((real)1) / l;
			}
		}

		// Adds the given vector scaled by a given amount
		void addScaledVector(const Vector3& vector, real scale) {
			x += vector.x * scale;
			y += vector.y * scale;
			z += vector.z * scale;
		}

		// Returns the component-wise product of this with a given vector
		Vector3 componentProduct(const Vector3& vector) {
			return Vector3(x * vector.x, y * vector.y, z * vector.z);
		}
		// Sets this vector as the component-wise product of this with a given vector
		void componentProductUpdate(const Vector3& vector) {
			x *= vector.x;
			y *= vector.y;
			z *= vector.z;
		}

		// Returns scalar product (dot product or inner product) with a given vector
		real scalarProduct(const Vector3& vector) const {
			return x * vector.x + y * vector.y + z * vector.z;
		}
		real operator*(const Vector3& vector) const {
			return x * vector.x + y * vector.y + z * vector.z;
		}

		// Returns vector product with a given vector
		Vector3 vectorProduct(const Vector3& vector) const {
			return Vector3( y * vector.z - z * vector.y,
							z * vector.x - x * vector.z,
							x * vector.y - y * vector.x );
		}
		Vector3 operator%(const Vector3& vector) const {
			return Vector3(	y * vector.z - z * vector.y,
							z * vector.x - x * vector.z,
							x * vector.y - y * vector.x );
		}
		// Performs the vector product with a given vector
		void operator%=(const Vector3& vector) {
			*this = vectorProduct(vector);
		}

	private:
		real pad = 0; // padding to ensure 4-word alingment

	};

}