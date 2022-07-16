///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for homogeneous points.
 *	\file		IceHPoint.h
 *	\author		Pierre Terdiman
 *	\date		April, 4, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef __ICEIceHPoint_H__
#define __ICEIceHPoint_H__

	class ICEMATHS_API IceHPoint : public Point
	{
		public:

		//! Empty constructor
		inline_				IceHPoint()																		{}
		//! Constructor from floats
		inline_				IceHPoint(float _x, float _y, float _z, float _w=0.0f) : Point(_x, _y, _z), w(_w)	{}
		//! Constructor from array
		inline_				IceHPoint(const float f[4]) : Point(f), w(f[3])									{}
		//! Constructor from a Point
		inline_				IceHPoint(const Point& p, float _w=0.0f) : Point(p), w(_w)							{}
		//! Destructor
		inline_				~IceHPoint()																		{}

		//! Clear the point
		inline_	IceHPoint&		Zero()											{ x =			y =			z =			w = 0.0f;		return *this;	}

		//! Assignment from values
		inline_	IceHPoint&		Set(float _x, float _y, float _z, float _w )	{ x  = _x;		y  = _y;	z  = _z;	w  = _w;		return *this;	}
		//! Assignment from array
		inline_	IceHPoint&		Set(const float f[4])							{ x  = f[_X];	y  = f[_Y];	z  = f[_Z];	w  = f[_W];		return *this;	}
		//! Assignment from another h-point
		inline_	IceHPoint&		Set(const IceHPoint& src)							{ x  = src.x;	y  = src.y;	z  = src.z;	w = src.w;		return *this;	}

		//! Add a vector
		inline_	IceHPoint&		Add(float _x, float _y, float _z, float _w )	{ x += _x;		y += _y;	z += _z;	w += _w;		return *this;	}
		//! Add a vector
		inline_	IceHPoint&		Add(const float f[4])							{ x += f[_X];	y += f[_Y];	z += f[_Z];	w += f[_W];		return *this;	}

		//! Subtract a vector
		inline_	IceHPoint&		Sub(float _x, float _y, float _z, float _w )	{ x -= _x;		y -= _y;	z -= _z;	w -= _w;		return *this;	}
		//! Subtract a vector
		inline_	IceHPoint&		Sub(const float f[4])							{ x -= f[_X];	y -= f[_Y];	z -= f[_Z];	w -= f[_W];		return *this;	}
		
		//! Multiplies by a scalar
		inline_	IceHPoint&		Mul(float s)									{ x *= s;		y *= s;		z *= s;		w *= s;			return *this;	}

		//! Returns MIN(x, y, z, w);
				float		Min()								const		{ return MIN(x, MIN(y, MIN(z, w)));										}
		//! Returns MAX(x, y, z, w);
				float		Max()								const		{ return MAX(x, MAX(y, MAX(z, w)));										}
		//! Sets each element to be componentwise minimum
				IceHPoint&		Min(const IceHPoint& p)							{ x = MIN(x, p.x); y = MIN(y, p.y); z = MIN(z, p.z); w = MIN(w, p.w);	return *this;	}
		//! Sets each element to be componentwise maximum
				IceHPoint&		Max(const IceHPoint& p)							{ x = MAX(x, p.x); y = MAX(y, p.y); z = MAX(z, p.z); w = MAX(w, p.w);	return *this;	}

		//! Computes square magnitude
		inline_	float		SquareMagnitude()					const		{ return x*x + y*y + z*z + w*w;											}
		//! Computes magnitude
		inline_	float		Magnitude()							const		{ return sqrtf(x*x + y*y + z*z + w*w);									}

		//! Normalize the vector
		inline_	IceHPoint&		Normalize()
							{
								float M = Magnitude();
								if(M)
								{
									M = 1.0f / M;
									x *= M;
									y *= M;
									z *= M;
									w *= M;
								}
								return *this;
							}

		// Arithmetic operators
		//! Operator for IceHPoint Negate = - IceHPoint;
		inline_	IceHPoint		operator-()							const		{ return IceHPoint(-x, -y, -z, -w);							}

		//! Operator for IceHPoint Plus  = IceHPoint + IceHPoint;
		inline_	IceHPoint		operator+(const IceHPoint& p)			const		{ return IceHPoint(x + p.x, y + p.y, z + p.z, w + p.w);		}
		//! Operator for IceHPoint Minus = IceHPoint - IceHPoint;
		inline_	IceHPoint		operator-(const IceHPoint& p)			const		{ return IceHPoint(x - p.x, y - p.y, z - p.z, w - p.w);		}

		//! Operator for IceHPoint Mul   = IceHPoint * IceHPoint;
		inline_	IceHPoint		operator*(const IceHPoint& p)			const		{ return IceHPoint(x * p.x, y * p.y, z * p.z, w * p.w);		}
		//! Operator for IceHPoint Scale = IceHPoint * float;
		inline_	IceHPoint		operator*(float s)					const		{ return IceHPoint(x * s, y * s, z * s, w * s);				}
		//! Operator for IceHPoint Scale = float * IceHPoint;
		inline_	friend	IceHPoint	operator*(float s, const IceHPoint& p)			{ return IceHPoint(s * p.x, s * p.y, s * p.z, s * p.w);		}

		//! Operator for IceHPoint Div   = IceHPoint / IceHPoint;
		inline_	IceHPoint		operator/(const IceHPoint& p)			const		{ return IceHPoint(x / p.x, y / p.y, z / p.z, w / p.w);		}
		//! Operator for IceHPoint Scale = IceHPoint / float;
		inline_	IceHPoint		operator/(float s)					const		{ s = 1.0f / s; return IceHPoint(x * s, y * s, z * s, w * s);	}
		//! Operator for IceHPoint Scale = float / IceHPoint;
		inline_	friend	IceHPoint	operator/(float s, const IceHPoint& p)			{ return IceHPoint(s / p.x, s / p.y, s / p.z, s / p.w);		}

		//! Operator for float DotProd = IceHPoint | IceHPoint;
		inline_	float		operator|(const IceHPoint& p)			const		{ return x*p.x + y*p.y + z*p.z + w*p.w;						}
		// No cross-product in 4D

		//! Operator for IceHPoint += IceHPoint;
		inline_	IceHPoint&		operator+=(const IceHPoint& p)						{ x += p.x; y += p.y; z += p.z; w += p.w;	return *this;	}
		//! Operator for IceHPoint += float;
		inline_	IceHPoint&		operator+=(float s)								{ x += s;   y += s;   z += s;   w += s;		return *this;	}

		//! Operator for IceHPoint -= IceHPoint;
		inline_	IceHPoint&		operator-=(const IceHPoint& p)						{ x -= p.x; y -= p.y; z -= p.z; w -= p.w;	return *this;	}
		//! Operator for IceHPoint -= float;
		inline_	IceHPoint&		operator-=(float s)								{ x -= s;   y -= s;   z -= s;   w -= s;		return *this;	}

		//! Operator for IceHPoint *= IceHPoint;
		inline_	IceHPoint&		operator*=(const IceHPoint& p)						{ x *= p.x; y *= p.y; z *= p.z; w *= p.w;	return *this;	}
		//! Operator for IceHPoint *= float;
		inline_	IceHPoint&		operator*=(float s)								{ x*=s; y*=s; z*=s; w*=s;					return *this;	}

		//! Operator for IceHPoint /= IceHPoint;
		inline_	IceHPoint&		operator/=(const IceHPoint& p)						{ x /= p.x; y /= p.y; z /= p.z; w /= p.w;	return *this;	}
		//! Operator for IceHPoint /= float;
		inline_	IceHPoint&		operator/=(float s)								{ s = 1.0f / s; x*=s; y*=s; z*=s; w*=s;		return *this;	}

		// Arithmetic operators

		//! Operator for Point Mul = IceHPoint * Matrix3x3;
				Point		operator*(const Matrix3x3& mat)		const;
		//! Operator for IceHPoint Mul = IceHPoint * Matrix4x4;
				IceHPoint		operator*(const Matrix4x4& mat)		const;

		// IceHPoint *= Matrix3x3 doesn't exist, the matrix is first casted to a 4x4
		//! Operator for IceHPoint *= Matrix4x4
				IceHPoint&		operator*=(const Matrix4x4& mat);

		// Logical operators

		//! Operator for "if(IceHPoint==IceHPoint)"
		inline_	bool		operator==(const IceHPoint& p)			const		{ return ( (x==p.x)&&(y==p.y)&&(z==p.z)&&(w==p.w));			}
		//! Operator for "if(IceHPoint!=IceHPoint)"
		inline_	bool		operator!=(const IceHPoint& p)			const		{ return ( (x!=p.x)||(y!=p.y)||(z!=p.z)||(w!=p.w));			}

		// Cast operators

		//! Cast a IceHPoint to a Point. w is discarded.
		inline_				operator	Point()					const		{ return Point(x, y, z);									}

		public:
				float		w;
	};

#endif // __ICEIceHPoint_H__

