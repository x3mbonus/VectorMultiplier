#pragma once
#include "Vector.h"
#include "CreateType.h"

namespace Vectors
{
	class VectorCreator
	{
	private:
	//Стефан: это наверно не скомпилируется. Будь повнимательнее!!
		int _sizeT;
		Vector * createFromConsole(string vectorName);
		Vector * createRandom();
	public:
		Vector * Create(CreateType createType, string vectorName);
		void SetSize(int size);
		int GetSize() const;
	
		VectorCreator(int size);
		~VectorCreator(void);
	};
}

