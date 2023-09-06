#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "../generals_func/generals.h"
#include "../log_info/log_errors.h"

#define USE_DUMP

class Vector 
{

    public:
    
        Vector (double x, double y): x_(x), y_(y) {}

        ~Vector ()
        {
            x_ = NAN;
            y_ = NAN;
        }

        double GetX() const
        {
            return x_;
        }


        double GetY() const
        {
            return y_;
        }

        Vector& operator += (const Vector &other);
        Vector& operator -= (const Vector &other);
        Vector& operator *= (const double scale);

    private:     
        double x_;
        double y_;
};

enum Vector_errors
{
    X_COORD_IS_NAN = 1 << 0, 
    Y_COORD_IS_NAN = 1 << 1
};


Vector operator + (const Vector &vec1, const Vector &vec2);

Vector operator - (const Vector &vec1, const Vector &vec2);

Vector operator * (const Vector &vec, const double scale);

typedef Vector Dot;

const Dot Null_dot = Vector(0.0, 0.0);

const Vector Unit_vector_x = Vector(1.0, 0.0);
const Vector Unit_vector_y = Vector(0.0, 1.0);


#endif //#endif _VECTOR_H_