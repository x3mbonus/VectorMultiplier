// VectorMultiplier.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VectorMultiplier.h"
#include "VectorCreator.h"
#include <iostream>
#include <string>

using namespace std;
using namespace Vectors;

string getVectorForPrint(double * vector, int size);
double * enterAndGetVector(string vectorName, int size);

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter vector size:";
	int size;
	cin >> size;
	if (size > 0)
	{
		VectorCreator creator(size);
		Vector * vector1 = creator.Create(CreateType::FromConsole, "Vector 1");
		Vector * vector2 = creator.Create(CreateType::Random, "");

		VectorMultiplier multiplier(*vector1, *vector2);
		const Vector * vector3 = multiplier.GetVectorMultiplication();

		cout << "Vector 1 = " << vector1->GetName() << endl;
		cout << "Vector 2 = " << vector2->GetName() << endl;
		cout << "Scalar = " << multiplier.GetScalarMultiplication() << endl;		
		cout << "Vector 3 = " << vector3->GetName() << endl;
		delete vector1, vector2;
	}
	system("pause");

	
	return 0;
}