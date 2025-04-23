#pragma once

#include <iostream>
#include <cmath>

class  Vector2 {
private:
    float x, y;
public:
    virtual ~Vector2() {};
    Vector2 get_vect(const float x_tmp, const float y_tmp) {
        Vector2 tmp;
        x = x_tmp;
        y = y_tmp;
        return *this;
    }

    Vector2 normalize() {
        x = x / sqrt(x * x + y * y);
        y = y / sqrt(x * x + y * y);
        return *this;
    }

    Vector2 squr() {
        Vector2 tmp;
        x = sqrt(x);
        y = sqrt(y);
        return *this;
    }

    float Dot(const Vector2& p1, const Vector2& p2) {
        return  p1.y * p2.y + p1.x * p2.x;
    }

    float Lenghth(const Vector2& p1) {
        return sqrt(p1.x * p1.x + p1.y * p1.y);
    }

    float LengthSQ(const Vector2& p1) {
        return (p1.x * p1.x + p1.y * p1.y);
    }

    Vector2& operator+= (const Vector2& p1) {
        x += p1.x;
        y += p1.y;
        return  *this;
    }

    Vector2& operator-= (const Vector2& p1) {
        x -= p1.x;
        y -= p1.y;
        return  *this;
    }

    float Distance(const Vector2& p1, const Vector2& p2) {
        return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    }

    Vector2 operator+ (const Vector2& p1) {
        Vector2 tmp;
        x = x + p1.x;
        y = y + p1.y;
        return *this;
    }
    Vector2 operator- (const Vector2& p1) {
        x = x - p1.x;
        y = y - p1.y;
        return *this;
    }

    Vector2 operator* (const int scalar) {
        x = x * scalar;
        y = y * scalar;
        return *this;
    }
    Vector2 operator/ (const int scalar) {
        x = x / scalar;
        y = y / scalar;
        return *this;
    }

    bool IsZero() {
        return x == 0.0 && y == 0.0;
    }
    float GetX() const { return x; }
    float GetY() const { return y; }
};