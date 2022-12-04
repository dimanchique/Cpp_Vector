#include "Vector2D.h"

Vector2D Vector2D::operator+(const Vector2D &right) const {
    Vector2D temp(*this);
    temp += right;
    return temp;
}

Vector2D Vector2D::operator-(const Vector2D &right) const {
    Vector2D temp(*this);
    temp -= right;
    return temp;
}

Vector2D &Vector2D::operator+=(const Vector2D &right) {
    X += right.X;
    Y += right.Y;
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &right) {
    X -= right.X;
    Y -= right.Y;
    return *this;
}

bool Vector2D::operator==(const Vector2D &right) const{
    return (X == right.X && Y == right.Y);
}

Vector2D Vector2D::operator*(const float Value) const {
    Vector2D temp(*this);
    temp *= Value;
    return temp;
}

Vector2D Vector2D::operator/(float Value) const {
    Vector2D temp(*this);
    if (Value != .0f)
        temp /= Value;
    else
        printf("Attempt to divide vector (%.4f; %.4f) by zero", X, Y);

    return temp;
}

Vector2D &Vector2D::operator*=(const float Value) {
    X *= Value;
    Y *= Value;
    return *this;
}

Vector2D &Vector2D::operator/=(float Value) {
    X /= Value;
    Y /= Value;
    return *this;
}

void Vector2D::Rotate(float Degrees) {
    float Radians = DegToRad(Degrees)
    float x_1 = X;
    auto cos_rad = std::cos(Radians);
    float sin_rad = std::sin(Radians);
    X = ((X * cos_rad) - (Y * sin_rad));
    Y = (x_1 * sin_rad) + (Y * cos_rad);
}

float Vector2D::GetRotation() const {
    return GetAngleBetweenVectors(*this, XVector());
}

void Vector2D::Normalize() {
    if(X != 0 || Y != 0){
        const float d = GetMagnitude();
        X /= d;
        Y /= d;
    }
    else
        printf("Can't normalize zero vector");
}

Vector2D Vector2D::GetNormalized() const {
    Vector2D temp(*this);
    temp.Normalize();
    return temp;
}

float Vector2D::GetMagnitude() const {
    auto quad = X*X + Y*Y;
    float length = 1.0f;
    for (;;) {
        float nx = (length + quad / length) / 2;
        if (std::abs (length - nx) < epsilon)
            break;
        length = nx;
    }
    return length;
}

bool Vector2D::IsUnitVector() const {
    return std::abs(GetMagnitude() - 1.0f) < epsilon;
}

float Vector2D::GetDotProduct(const Vector2D &right) const {
    return X * right.X + Y * right.Y;
}

float Vector2D::GetAngleRelativeToVector(const Vector2D &right) const {
    const auto dot = GetDotProduct(right);
    return std::acos(dot/(GetMagnitude() * right.GetMagnitude()));
}

float Vector2D::GetDistanceToVector(const Vector2D &right) const {
    return (*this-right).GetMagnitude();
}

float Vector2D::GetDotProduct(const Vector2D &left, const Vector2D &right) {
    return left.GetDotProduct(right);
}

float Vector2D::GetAngleBetweenVectors(const Vector2D &left, const Vector2D &right) {
    return left.GetAngleRelativeToVector(right);
}

float Vector2D::GetDistanceBetweenVectors(const Vector2D &left, const Vector2D &right) {
    return left.GetDistanceToVector(right);
}

Vector2D Vector2D::GetRandomRotatedVector() {
    return Vector2D((float)std::experimental::randint(-100, 100)/100,
                    (float)std::experimental::randint(-100, 100)/100).GetNormalized();
}
