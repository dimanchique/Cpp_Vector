#pragma once
#include <experimental/random>

#define epsilon 1e-6
#define RadToDeg(x) (x) * 57.295779513f;
#define DegToRad(x) (x) * 0.01745329252f;

struct Vector3D{
    float X, Y, Z;

    Vector3D() : X(0), Y(0), Z(0) {};
    Vector3D(float X, float Y, float Z) : X(X), Y(Y), Z(Z) {};

    Vector3D operator+(const Vector3D &right) const;
    Vector3D operator-(const Vector3D &right) const;
    Vector3D &operator+=(const Vector3D &right);
    Vector3D &operator-=(const Vector3D &right);
    bool operator==(const Vector3D &right) const;
    bool operator!=(const Vector3D &right) const;
    Vector3D operator*(float Value) const;
    Vector3D operator/(float Value) const;
    Vector3D &operator*=(float Value);
    Vector3D &operator/=(float Value);

    void Normalize();
    [[nodiscard]] Vector3D GetNormalized() const;
    [[nodiscard]] float GetMagnitude() const;
    [[nodiscard]] bool IsUnitVector() const;
    [[nodiscard]] float GetDotProduct(const Vector3D &right) const;
    [[nodiscard]] Vector3D GetCrossProduct(const Vector3D &right) const;
    [[nodiscard]] float GetTripleProduct(const Vector3D &middle, const Vector3D &right) const;
    [[nodiscard]] float GetAngleRelativeToVector(const Vector3D &right) const;
    [[nodiscard]] float GetDistanceToVector(const Vector3D &right) const;

    static float GetDotProduct(const Vector3D &left, const Vector3D &right);
    static Vector3D GetCrossProduct(const Vector3D &left, const Vector3D &right);
    static float GetTripleProduct(const Vector3D &left, const Vector3D &middle, const Vector3D &right);
    static float GetAngleBetweenVectors(const Vector3D &left, const Vector3D &right);
    static float GetDistanceBetweenVectors(const Vector3D &left, const Vector3D &right);
    static Vector3D GetRandomRotatedVector();

    static Vector3D XVector() { return {1, 0, 0}; }
    static Vector3D YVector() { return {0, 1, 0}; }
    static Vector3D ZVector() { return {0, 0, 1}; }
};

inline Vector3D operator*(const float Value, const Vector3D &other)
{
    return other*Value;
}