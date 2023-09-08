#include "vector.h"

//=======================================================================

Vector& Vector::operator += (const Vector &other)
{
    this->x_ += other.x_;
    this->y_ += other.y_;
    return *this;
}

//=======================================================================

Vector& Vector::operator -= (const Vector &other)
{
    this->x_ -= other.x_;
    this->y_ -= other.y_;
    return *this;
}

//=======================================================================

Vector& Vector::operator *= (const double scale)
{
    this->x_ *= scale;
    this->y_ *= scale;
    return *this;
}

//=======================================================================

double Vector::operator ! ()
{
    double len = (this->x_ * this->x_) + 
                 (this->y_ * this->y_);

    len = sqrt(len);

    return len;
}

//=======================================================================


Vector Vector::operator ~ () 
{
    double len = !(*this);

    Vector res(this->x_ / len, this->y_ / len);

    return res;
}


//=======================================================================

Vector Vector::operator & ()
{
    Vector res(this->GetY() * -1.0, this->GetX());

    return res;
}


//=======================================================================

Vector operator + (const Vector &vec1, const Vector &vec2)
{
    Vector res = vec1;
    res += vec2;

    return res;
}

//=======================================================================

Vector operator - (const Vector &vec1, const Vector &vec2)
{
    Vector res = vec1;
    res -= vec2;
    
    return res;
}

//=======================================================================

Vector operator * (const Vector &vec, const double scale)
{
    Vector res = vec;
    res *= scale;

    return res;
}

//=======================================================================