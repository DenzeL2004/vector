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

Vector& Vector::operator /= (const double scale)
{
    this->x_ /= scale;
    this->y_ /= scale;
    return *this;
}

//=======================================================================

double Vector::operator ! () const
{
    double len = (this->x_ * this->x_) + 
                 (this->y_ * this->y_);

    len = sqrt(len);

    return len;
}

//=======================================================================


Vector Vector::operator ~ () const
{
    double len = !(*this);

    Vector res(this->x_ / len, this->y_ / len);

    return res;
}


//=======================================================================

Vector Vector::operator & () const
{
    Vector res(this->GetY() * -1.0, this->GetX());

    return res;
}

//=======================================================================

Vector Vector::operator - ()
{
    Vector res = *this;
    res *= -1;
    
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

Vector operator * (const double scale, const Vector &vec)
{
    Vector res = vec;
    res *= scale;

    return res;
}

//=======================================================================

Vector operator / (const Vector &vec, const double scale)
{
    Vector res = vec;
    res /= scale;

    return res;
}

//=======================================================================

double operator , (const Vector &vec1, const Vector &vec2) 
{
    return  vec1.GetX() * vec2.GetX() + 
            vec1.GetY() * vec2.GetY();
}

//=======================================================================

double operator ^ (const Vector &vec1, const Vector &vec2)
{ 
    return  (vec1, vec2) / (!vec1 * !vec2); 
}

//=======================================================================


bool operator && (const Vector &vec1, const Vector &vec2)
{ 
    return  (IsZero(vec1 ^ vec2)); 
}

//=======================================================================


bool operator || (const Vector &vec1, const Vector &vec2)
{ 
    double scale = (vec1, vec2);

    double  len_vec1 = !vec1,
            len_vec2 = !vec2;

    double res = scale / (len_vec1 * len_vec2);
    
    return EqualityDouble(res, -1.0) || EqualityDouble(res, 1.0);  

}

//=======================================================================

double operator << (const Vector &vec1, const Vector &vec2)
{ 
    double cos_corner = vec1 ^ vec2;
    double sin_corner = 1.0 - cos_corner * cos_corner;
    
    return sin_corner * (!vec1) * (!vec2);  

}

//=======================================================================