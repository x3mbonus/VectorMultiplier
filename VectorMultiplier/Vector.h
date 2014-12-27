#pragma once
#include <string>

using namespace std;
namespace Vectors
{
	class Vector
	{
	private:
		double * _coords;
		int _size;
	public:
		string GetName() const;
		int GetSize() const;
		const double & operator[](int index) const;
		Vector(int size, double coords []);
		~Vector(void);
	};
}
