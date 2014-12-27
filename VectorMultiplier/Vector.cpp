#include "stdafx.h"
#include "Vector.h"

namespace Vectors
{
	string Vector::GetName() const
	{
		string result = "(";
		for (int i = 0; i < _size; i ++)
		{
			if (i > 0)
			{
				result += ", ";
			}
		
			result += to_string(_coords[i]);
		}
		result += ")";
		result += " size = ";
		result += to_string(_size);
		return result;
	}

	int Vector::GetSize() const
	{
		return _size;
	}

	const double & Vector::operator[](int index) const
	{
		if (_coords > 0 && 
			index >= 0 && 
			index < _size)
		{
			return _coords[index];
		}
		return 0.0;
	}

	Vector::Vector(int size, double coords [])
	{
		_size =size;
		if (size > 0)
		{
			_coords = new double[size];
			for(int i = 0; i < size; i++)
			{
				_coords[i] = coords[i];
			}
		}
		else
		{
			_coords = 0;
		}
	}

	Vector::~Vector(void)
	{
		if (_coords > 0)
		{
			delete [] _coords;
			_coords = nullptr;
		}
	}
}