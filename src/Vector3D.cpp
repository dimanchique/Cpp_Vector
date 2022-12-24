#include "Vector3D.h"

Vector3D Vector3D::operator+(const Vector3D &right) const {
    Vector3D temp(*this);
    temp += right;
    return temp;
}

Vector3D Vector3D::operator-(const Vector3D &right) const {
    Vector3D temp(*this);
    temp -= right;
    return temp;
}

Vector3D &Vector3D::operator+=(const Vector3D &right) {
    X += right.X;
    Y += right.Y;
    Z += right.Z;
    return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &right) {
    X -= right.X;
    Y -= right.Y;
    Z -= right.Z;
    return *this;
}

bool Vector3D::operator==(const Vector3D &right) const {
    return (X == right.X && Y == right.Y && Z == right.Z);
}

bool Vector3D::operator!=(const Vector3D &right) const {
    return !(*this==right);
}

Vector3D Vector3D::operator*(const float Value) const {
    Vector3D temp(*this);
    temp *= Value;
    return temp;
}

Vector3D Vector3D::operator/(float Value) const {
    Vector3D temp(*this);
    if (Value != .0f)
        temp /= Value;
    else
        printf("Attempt to divide vector (%.4f; %.4f; %.4f) by zero", X, Y, Z);

    return temp;
}

Vector3D &Vector3D::operator*=(const float Value) {
    X *= Value;
    Y *= Value;
    Z *= Value;
    return *this;
}

Vector3D &Vector3D::operator/=(float Value) {
    X /= Value;
    Y /= Value;
    Z /= Value;
    return *this;
}

void Vector3D::Normalize() {
    if (X != 0 || Y != 0 || Z != 0) {
        const float d = GetMagnitude();
        X /= d;
        Y /= d;
        Z /= d;
    } else
        printf("Can't normalize zero vector");
}

Vector3D Vector3D::GetNormalized() const {
    Vector3D temp(*this);
    temp.Normalize();
    return temp;
}

float Vector3D::GetMagnitude() const {
    auto quad = X * X + Y * Y + Z * Z;
    float length = 1.0f;
    for (;;) {
        float nx = (length + quad / length) / 2;
        if (std::abs(length - nx) < epsilon)
            break;
        length = nx;
    }
    return length;
}

bool Vector3D::IsUnitVector() const {
    return std::abs(GetMagnitude() - 1.0f) < epsilon;
}

float Vector3D::GetDotProduct(const Vector3D &right) const {
    return X * right.X + Y * right.Y + Z * right.Z;
}

Vector3D Vector3D::GetCrossProduct(const Vector3D &right) const {
    return {Y * right.Z - Z * right.Y,
            Z * right.X - X * right.Z,
            X * right.Y - Y * right.X};
}

float Vector3D::GetTripleProduct(const Vector3D &middle, const Vector3D &right) const {
    return GetDotProduct(GetCrossProduct(middle, right));
}

float Vector3D::GetAngleRelativeToVector(const Vector3D &right) const {
    const auto dot = GetDotProduct(right);
    return std::acos(dot / (GetMagnitude() * right.GetMagnitude()));
}

float Vector3D::GetDistanceToVector(const Vector3D &right) const {
    return (*this-right).GetMagnitude();
}

float Vector3D::GetDotProduct(const Vector3D &left, const Vector3D &right) {
    return left.GetDotProduct(right);
}

Vector3D Vector3D::GetCrossProduct(const Vector3D &left, const Vector3D &right) {
    return left.GetCrossProduct(right);
}

float Vector3D::GetTripleProduct(const Vector3D &left, const Vector3D &middle, const Vector3D &right) {
    return left.GetTripleProduct(middle, right);
}

float Vector3D::GetAngleBetweenVectors(const Vector3D &left, const Vector3D &right) {
    return left.GetAngleRelativeToVector(right);
}

float Vector3D::GetDistanceBetweenVectors(const Vector3D &left, const Vector3D &right) {
    return left.GetDistanceToVector(right);
}

Vector3D Vector3D::GetRandomRotatedVector() {
    return Vector3D((float)std::experimental::randint(-100, 100)/100,
                    (float)std::experimental::randint(-100, 100)/100,
                    (float)std::experimental::randint(-100, 100)/100).GetNormalized();
}
