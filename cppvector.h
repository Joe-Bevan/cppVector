#pragma once
#include <algorithm>
// Uncomment to disable assert()
//#define NDEBUG
#include <assert.h>

template<typename T>
class vec2d {
public:
	T x, y;
	vec2d() = default;
	~vec2d() = default;
	vec2d(T X, T Y)
		: x(X), y(Y) {}
	vec2d(const vec2d& vec)
		: x(vec.x), y(vec.y) {}


	T& GetX() { return x; }
	T& GetY() { return y; }
	const T& GetY() const { return y; }
	const T& GetX() const { return x; }
		
	void SetX(const T X) { x = X; }
	void SetY(const T Y) { y = Y; }

	// Operator overloads
	vec2d operator+ (const vec2d& vec) const { return vec2d(x + vec.x, y + vec.y); }
	vec2d& operator+= (const vec2d& vec) { x += vec.x; y += vec.y; return *this; }
	vec2d operator- (const vec2d& vec) const { return vec2d(x - vec.x, y - vec.y); }
	vec2d& operator-= (const vec2d& vec) { x -= vec.x; y -= vec.y; return *this; }
	vec2d operator* (float value) const { return vec2d(x * value, y * value); }
	vec2d operator* (vec2d& vec) const { return vec2d(x * vec.x, y * vec.y); }
	vec2d& operator*= (float value) { x *= value; y *= value; return *this; }
	vec2d& operator*= (vec2d& vec) { x *= vec.x; y *= vec.y; return *this; }
	vec2d operator/ (float value) const { assert(value != 0); return vec2d(x / value, y / value); }
	vec2d operator/ (vec2d vec) const { assert(vec.x != 0 && vec.y != 0); return vec2d(x / vec.x, y / vec.y); }
	vec2d& operator/= (float value) { assert(value != 0); x /= value; y /= value; return *this; }
	vec2d& operator/= (const vec2d& vec) { assert(vec.x != 0 && vec.y != 0); x /= vec.x; y /= vec.y; return *this; }
	vec2d& operator= (const vec2d& vec) { x = vec.x; y = vec.y; return *this; }

	// Basic functions
	float Square() { return x * x + y * y; }
	float Magnitude() { return sqrt(Square()); }
	float Distance(const vec2d& vec) { vec2d sum = *this + vec; return sum.Magnitude(); }
	float Min() { T m = x; m = std::min(x, m); m = std::min(y, m); return m; } // We set to var x as setting to 0 || 999 isn't wise
	vec2d Min(vec2d& vec) { return vec2d(std::min(x, vec.x), std::min(y, vec.y)); }
	float Max() { T m = x; m = std::max(x, m); m = std::max(y, m); return m; }
	vec2d Max(vec2d& vec) { return vec2d(std::max(x, vec.x), std::max(y, vec.y)); } // Returns a new vector using the largest values of the two vectors

	// Vector operations
	float DotProduct(const vec2d& vec) { x * vec.x + y * vec.y; }
	vec2d& Normalize() { if (Magnitude() != 0) return *this /= Magnitude(); }
};


template<typename T>
class vec3d {
public:
	T x, y, z;
	vec3d() = default;
	~vec3d() = default;
	vec3d(T X, T Y, T Z)
		: x(X), y(Y), z(Z) {}
	vec3d(const vec3d& vec)
		: x(vec.x), y(vec.y), z(vec.z) {}


	T& GetX() { return x; }
	T& GetY() { return y; }
	T& GetZ() { return z; }
	const T& GetY() const { return y; }
	const T& GetX() const { return x; }
	const T& GetZ() const { return z; }

	void SetX(const T X) { x = X; }
	void SetY(const T Y) { y = Y; }
	void SetZ(const T Z) { z = Z; }

	// Operator overloads
	vec3d operator+ (const vec3d& vec) const { return vec3d(x + vec.x, y + vec.y, z + vec.z); } 
	vec3d& operator+= (const vec3d& vec) { x += vec.x; y += vec.y; z += vec.z; return *this; }
	vec3d operator- (const vec3d& vec) const { return vec3d(x - vec.x, y - vec.y, z - vec.z); }
	vec3d& operator-= (const vec3d& vec) { x -= vec.x; y -= vec.y; z -= vec.z; return *this; }
	vec3d operator* (float value) const { return vec3d(x * value, y * value, z * value); }
	vec3d operator* (vec3d& vec) const { return vec3d(x * vec.x, y * vec.y, z * vec.z); }
	vec3d& operator*= (float value) { x *= value; y *= value; z *= value; return *this; }
	vec3d& operator*= (vec3d& vec) { x *= vec.x; y *= vec.y; z *= vec.z; return *this; }
	vec3d operator/ (float value) const { return vec3d(x / value, y / value, z / value); }
	vec3d operator/ (vec3d vec) const { return vec3d(x / vec.x, y / vec.y, z / vec.z); }
	vec3d& operator/= (float value) { x /= value; y /= value; z /= value; return *this; }
	vec3d& operator/= (vec3d& vec) { x /= vec.x; y /= vec.y; z /= vec.z; return *this; }
	vec3d& operator= (const vec3d& vec) { x = vec.x; y = vec.y; z = vec.z; return *this; }

	// Basic functions
	float Square() { return x * x + y * y + z * z; }
	float Magnitude() { return sqrt(Square()); }
	float Distance(const vec3d& vec) { vec3d sum = *this + vec; return sum.Magnitude(); }
	float Min() { T m = x; m = std::min(x, m); m = std::min(y, m); m = std::min(z, m); return m; } 
	vec3d Min(vec3d& vec) { return vec3d(std::min(x, vec.x), std::min(y, vec.y), std::min(z, vec.z)); }
	float Max() { T m = x; m = std::max(x, m); m = std::max(y, m); m = std::max(z, m); return m; }
	vec3d Max(vec3d& vec) { return vec3d(std::max(x, vec.x), std::max(y, vec.y), std::max(z, vec.z)); }

	// Vector operations
	float DotProduct(const vec3d& vec) { x * vec.x + y * vec.y + z * vec.z; }
	vec3d& CrossProduct(const vec3d& vec) { x = y * vec.z - z * vec.y; y = z * vec.x - x * vec.z; z = x * vec.y - y * vec.x; return *this; } // Needs testing
	vec3d CrossProduct(const vec3d a, const vec3d b) const { return vec3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); } // Needs testing
	vec3d& Normalize() { if (Magnitude() != 0) return *this /= Magnitude(); }
};
