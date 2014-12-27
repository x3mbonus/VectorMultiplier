#include "stdafx.h"
#include "VectorCreator.h"
#include <iostream>
#include <string>
#include <time.h>

namespace Vectors
{
	Vector * VectorCreator::createFromConsole(string vectorName)
	{
		double * coords = new double[_size];
	
		cout << "Enter " << vectorName << ":" << endl;

		for(int i = 0; i < _size; i++)
		{
			cout << i + 1 << ":";
			cin >> coords[i];
		}
		Vector * vector = new Vector(_size, coords);
		delete [] coords;
		coords = nullptr;
		return vector;
	}

	Vector * VectorCreator::createRandom()
	{
		double * coords = new double[_size];
		//Наверно не надо запускать каждый раз и можно вынести в main
		srand(time(0));
		for(int i = 0; i < _size; i++)
		{
			coords[i] = rand() % 10;
		}
		Vector * vector = new Vector(_size, coords);
		delete [] coords;
		coords = nullptr;
		return vector;
	}

	Vector * VectorCreator::Create(CreateType createType, string vectorName)
	{
		switch (createType)
		{
		case CreateType::FromConsole:
			return createFromConsole(vectorName);
		case CreateType::Random:
			return createRandom();
		}
		return nullptr;
	}


	void VectorCreator::SetSize(int size)
	{
		if (size <= 0)
		{
			throw invalid_argument("Incorrect size of vector (Size = "+to_string(size)+")");
		}
		_size = size;
	}

	int VectorCreator::GetSize() const
	{
		return _size;
	}
	
	VectorCreator::VectorCreator(int size)
	{
		_size = size;
	}


	VectorCreator::~VectorCreator(void)
	{
	}
}