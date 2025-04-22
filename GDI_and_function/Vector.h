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
        tmp.x = x_tmp;
        tmp.y = y_tmp;
        return tmp;
    }

    Vector2 normalize(const Vector2& p1) {
        Vector2 tmp;
        tmp.x = p1.x / sqrt(p1.x * p1.x + p1.y * p1.y);
        tmp.y = p1.y / sqrt(p1.x * p1.x + p1.y * p1.y);
    }

    Vector2 squr(const Vector2& p1) {
        Vector2 tmp;
        tmp.x = sqrt(p1.x);
        tmp.y = sqrt(p1.y);
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
        tmp.x = x + p1.x;
        tmp.y = y + p1.y;
        return tmp;
    }
    Vector2 operator- (const Vector2& p1) {
        Vector2 tmp;
        tmp.x = x - p1.x;
        tmp.y = y - p1.y;
        return tmp;
    }

    Vector2 operator* (const int scalar) {
        Vector2 tmp;
        tmp.x = x * scalar;
        tmp.y = y * scalar;
        return tmp;
    }
    Vector2 operator/ (const int scalar) {
        Vector2 tmp;
        tmp.x = x / scalar;
        tmp.y = y / scalar;
        return tmp;
    }

    bool IsZero() {
        return x == 0.0 && y == 0.0;
    }
    float GetX() const { return x; }
    float GetY() const { return y; }
};