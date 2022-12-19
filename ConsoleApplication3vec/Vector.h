#ifndef HELLO_WORLD_VECTOR_H
#define HELLO_WORLD_VECTOR_H


class Vector {
public:
    double x, y;

    Vector();
    Vector(double _x, double _y);

    double getLen();

    void setX(double _x);
    double getX();
    
    void setY(double _y);
    double getY();

    double getPhi();
    double getPhiDeg();
    
    Vector operator+(const Vector& vector) const;
    void operator+=(const Vector& vector);
   
    Vector operator*(const double& a) const;
    void operator*=(const double& vector);
   
    Vector operator-(const Vector& vector) const;
    void operator-=(const Vector& vector);
   
    Vector operator/(const double& a) const;
    void operator/=(const double& a);

    bool operator==(const Vector& vector) const;
    bool operator!=(const Vector& vector) const;

    double kosoe_product(const Vector& vector) const;
    double scalar_product(const Vector& vector) const;
    void norm();
    void change_angle(double phi);
    void change_len(const double N);
    double cos_phi(Vector& vector) const;

};


#endif //HELLO_WORLD_VECTOR_H
