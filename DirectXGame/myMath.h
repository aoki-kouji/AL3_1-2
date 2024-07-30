#include "Matrix4x4.h"
#include "Vector3.h"

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);
// 行列の掛け算
Matrix4x4 MatrixMultiply(Matrix4x4& m1, Matrix4x4& m2);

Vector3 operator+(const Vector3& v);
Vector3 operator-(const Vector3& v);

Vector3& operator+=(Vector3& lhv, const Vector3& rhv);

Vector3& operator-=(Vector3& lhv, const Vector3& rhv);

Vector3& operator*=(Vector3& v, float s);

Vector3& operator/=(Vector3& v, float s);

const Vector3 operator+(const Vector3& v1, const Vector3& v2);

const Vector3 operator-(const Vector3& v1, const Vector3& v2);

const Vector3 operator*(const Vector3& v, float s);

const Vector3 operator*(float s, const Vector3& v);

const Vector3 operator/(const Vector3& v, float s);