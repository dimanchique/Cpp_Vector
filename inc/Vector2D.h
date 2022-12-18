#pragma once
#include <experimental/random>

#define epsilon 1e-6
#define RadToDeg(x) (x) * 57.295779513f;
#define DegToRad(x) (x) * 0.01745329252f;

struct Vector2D{
    float X, Y;

    Vector2D() : X(0), Y(0) {};
    Vector2D(float X, float Y) : X(X), Y(Y) {};

    Vector2D operator+(const Vector2D &right) const;
    Vector2D operator-(const Vector2D &right) const;
    Vector2D &operator+=(const Vector2D &right);
    Vector2D &operator-=(const Vector2D &right);
    bool operator==(const Vector2D &right) const;
    bool operator!=(const Vector2D &right) const;
    Vector2D operator*(float Value) const;
    Vector2D operator/(float Value) const;
    Vector2D &operator*=(float Value);
    Vector2D &operator/=(float Value);

    [[nodiscard]] Vector2D GetNormalVector() const;
    void Rotate(float Degrees);
    [[nodiscard]] float GetRotation() const;
    void Normalize();
    [[nodiscard]] Vector2D GetNormalized() const;
    [[nodiscard]] float GetMagnitude() const;
    [[nodiscard]] bool IsUnitVector() const;
    [[nodiscard]] float GetDotProduct(const Vector2D &right) const;
    [[nodiscard]] float GetAngleRelativeToVector(const Vector2D &right) const;
    [[nodiscard]] float GetDistanceToVector(const Vector2D &right) const;

    static Vector2D GetNormalVector(const Vector2D &vec);
    static float GetDotProduct(const Vector2D &left, const Vector2D &right);
    static float GetAngleBetweenVectors(const Vector2D &left, const Vector2D &right);
    static float GetDistanceBetweenVectors(const Vector2D &left, const Vector2D &right);
    static Vector2D GetRandomRotatedVector();

    static Vector2D XVector() { return {1, 0}; }
    static Vector2D YVector() { return {0, 1}; }
};

inline Vector2D operator*(const float Value, const Vector2D &other)
{
    return other.operator*(Value);
}

