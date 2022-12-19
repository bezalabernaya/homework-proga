#include "Vector.h"
#include <iostream>
#include <cmath>
#define M_PI 3.1415926


Vector::Vector() : x(0.0), y(0.0) {};
Vector::Vector(double _x, double _y) : x(_x), y(_y) {};

void Vector::setX(double _x) {
    x = _x;
}
void Vector::setY(double _y) {
    y = _y;
}

double Vector::getX() {
    return x;
}
double Vector::getY() {
    return y;
}

double Vector::getLen() {
    return std::sqrt(x * x + y * y);
}

double Vector::getPhi() {
    return std::atan2(y, x);
}

double Vector::getPhiDeg() {
    return getPhi() * 180 / M_PI;
}

Vector Vector::operator+(const Vector& vector) const {
    return Vector(x + vector.x, y + vector.y);
}

void Vector::operator+=(const Vector& vector) {
    x += vector.x;
    y += vector.y;
}

Vector Vector::operator*(const double& a) const {
    return Vector(x * a, y * a);
}

void Vector::operator*=(const double& a) {
    x *= a;
    y *= a;
}

Vector Vector::operator-(const Vector& vector) const {
    return Vector(x - vector.x, y - vector.y);
}

void Vector::operator-=(const Vector& vector) {
    x -= vector.x;
    y -= vector.y;
}

Vector Vector::operator/(const double& N) const {
    if (N != 0) return Vector(x / N, y / N);

}

void Vector::operator/=(const double& N) {
    if (N != 0) {
        x /= N;
        y /= N;
    }
}

bool Vector::operator==(const Vector& vector) const {
    return x == vector.x && y == vector.y;
}

bool Vector::operator!=(const Vector& vector) const {
    return x != vector.x or y != vector.y;
}

double Vector::kosoe_product(const Vector& vector) const {
    return x * vector.y - vector.x * y;
}

double Vector::scalar_product(const Vector& vector) const {
    return x * vector.x + y * vector.y;
}


void Vector::norm() {
    double len = sqrt(x * x + y * y);
    x /= len;
    y /= len;
}


void Vector::change_angle(double phi) {
    phi = phi / 180 * M_PI;
    double t1 = x * cos(phi) - y * sin(phi);
    double t2 = x * sin(phi) + y * cos(phi);
    x = t1;
    y = t2;
}

void Vector::change_len(const double N) {   
    double len = sqrt(x * x + y * y);
    x /= len;
    y /= len;
    x *= N;
    y *= N;
}

double Vector::cos_phi(Vector& vector) const { 
    double len1 = sqrt(x * x + y * y);
    double len2 = vector.getLen();
    return (x * vector.x + y * vector.y) / (len1 * len2);
}