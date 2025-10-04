/*
This file holds the full definition for a 3-dimensional vector class.
It includes member variables for the x, y, and z coordinates.
*/

#pragma once

using namespace std;

class Vec3 {
  public:
    double x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

    // Vector operations
    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    Vec3 operator*(double scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    Vec3 operator/(double scalar) const {
        return Vec3(x / scalar, y / scalar, z / scalar);
    }

    double dot (const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    Vec3 cross(const Vec3& other) const {
        return Vec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    double magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }

    void display() const {
        cout << x << ", " << y << ", " << z << endl;
    }
};

inline Vec3 operator*(double scalar, const Vec3& v) {
    return Vec3(v.x * scalar, v.y * scalar, v.z * scalar);
}
