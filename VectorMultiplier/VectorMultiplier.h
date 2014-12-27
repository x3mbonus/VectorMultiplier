#pragma once
#include "Vector.h"

namespace Vectors
{
	class VectorMultiplier
	{
	private:
		const Vector & _vector1;
		const Vector & _vector2;
		double _cacheScalarMultiplication;
		Vector * _cacheVectorMultiplication;
		bool checkSize();
		void calcScalar();
		void calcVector();

	public:
		double GetScalarMultiplication();
		const Vector * GetVectorMultiplication();
		VectorMultiplier(const Vector & vector1, const Vector & vector2);
		~VectorMultiplier(void);
	};
}