#include "stdafx.h"
#include "VectorMultiplier.h"

namespace Vectors
{
	double VectorMultiplier::GetScalarMultiplication()
	{
		calcScalar();
		return _cacheScalarMultiplication;
	}

	const Vector * VectorMultiplier::GetVectorMultiplication()
	{
		calcVector();
		return _cacheVectorMultiplication;
	}

	bool VectorMultiplier::checkSize()
	{
		auto size = _vector1.GetSize();
		auto size2 = _vector2.GetSize();
		return size == size2;
	}

	void VectorMultiplier::calcScalar()
	{
		if (_cacheScalarMultiplication != 0)
		{
			return;
		}
		double result = 0;
		auto size = _vector1.GetSize();
		for (int i = 0; i < size; i++)
		{
			result += _vector1[i] * _vector2[i];
		}
		_cacheScalarMultiplication = result;
	}

	void VectorMultiplier::calcVector()
	{
		double 
			a1 = _vector1[0],
			a2 = _vector1[1],
			a3 = _vector1[2],
			b1 = _vector2[0],
			b2 = _vector2[1],
			b3 = _vector2[2];
		double * result = new double[3];
		result[0] = a2 * b3 - a3 * b2;
		result[1] = a3 * b1 - a1 * b3;
		result[2] = a1 * b2 - a2 * b1;
		
		_cacheVectorMultiplication = new Vector(3, result);
		delete [] result;
		result = nullptr;
	}

	VectorMultiplier::VectorMultiplier(const Vector & vector1, const Vector & vector2) :
		_vector1(vector1),
		_vector2(vector2)
	{
		if (!checkSize())
		{
			throw invalid_argument("Different dimension of the vectors");
		}
	}


	VectorMultiplier::~VectorMultiplier(void)
	{
		if (_cacheVectorMultiplication != nullptr)
		{
			delete _cacheVectorMultiplication;
			_cacheVectorMultiplication = nullptr;
		}
	}
}