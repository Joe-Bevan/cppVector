#pragma once
#include <algorithm>

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
	T GetY() const { return y; }
	T GetX() const { return x; }
		
	void SetX(const T X) { x = X; }
	void SetY(const T Y) { y = Y; }

	// Operator overloads
	vec2d operator+ (const vec2d& vec) { return vec2d(x + vec.x, y + vec.y); }
	vec2d& operator+= (const vec2d& vec) { x += vec.x; y += vec.y; return *this; } // since 'this' is a pointer we derefrence it
	vec2d operator- (const vec2d& vec) { return vec2d(x - vec.x, y - vec.y); }
	vec2d& operator-= (const vec2d& vec) { x -= vec.x; y -= vec.y; return *this; }
	vec2d operator* (float value) { return vec2d(x * value, y * value); }
	vec2d operator* (vec2d& vec) { return vec2d(x * vec.x, y * vec.y); }
	vec2d& operator*= (float value) { x *= value; y *= value; return *this; }
	vec2d& operator*= (vec2d& vec) { x *= vec.x; y *= vec.y; return *this; }
	vec2d operator/ (float value) { return vec2d(x / value, y / value); }
	vec2d operator/ (vec2d vec) { return vec2d(x / vec.x, y / vec.y); }
	vec2d& operator/= (float value) { x /= value; y /= value; return *this; }
	vec2d& operator/= (vec2d& vec) { x /= vec.x; y /= vec.y; return *this; }
	vec2d& operator= (const vec2d& vec) { x = vec.x; y = vec.y; return *this; }

	// Basic functions
	float Square() { return x * x + y * y; }
	float Magnitude() { return sqrt(Square()); }
	float Distance(const vec2d& vec) { vec2d sum = *this + vec; return sum.Magnitude(); }
	float Min() { T m = x; m = std::min(x, m); m = std::min(y, m); return m; } // we set to var x as setting to 0 / 999 isn't wise
	vec2d Min(vec2d& vec) { return vec2d(std::min(x, vec.x), std::min(y, vec.y)); }
	float Max() { T m = x; m = std::max(x, m); m = std::max(y, m); return m; }
	vec2d Max(vec2d& vec) { return vec2d(std::max(x, vec.x), std::max(y, vec.y)); } // Returns a new vector using the largest values of the two vectors


	// Vector operations
	float DotProduct(const vec2d& vec) { x * vec.x + y * vec.y; } // return double?
	vec2d& Normalize() { if (Magnitude() != 0) return *this /= Magnitude(); }
};