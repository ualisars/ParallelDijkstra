#include "AdjMatrix.h"

int AdjMatrix::AddEdge(int edgesAdded)
{
	int randomNumber;
	if (edgesAdded < 5)
	{
		randomNumber = Utils::GenerateRandomNumber(-100, 100);
	}
	else
	{
		randomNumber = Utils::GenerateRandomNumber(-100, 50);
	}

	if (randomNumber > 0)
	{
		return Utils::GenerateRandomNumber(1, 100);
	}
	return 0;
}

int** AdjMatrix::Init(unsigned int verticesNumber, unsigned int edgesNumber)
{
	int** mat = new int*[verticesNumber];
	for (int i = 0; i < verticesNumber; ++i)
	{
		mat[i] = new int[verticesNumber];
	}

	for (int i = 0; i < verticesNumber; ++i)
	{
		int edgesAdded = 0;
		for (int j = 0; j < verticesNumber; ++j)
		{
			int value;
			if (edgesNumber != 0)
			{

				value = AddEdge(edgesAdded);
				edgesAdded += 1;
				if (value != 0)
					edgesNumber -= 1;
			}
			else
			{
				value = 0;
			}

			mat[i][j] = value;
		}
	}
	return mat;
}

int** AdjMatrix::Transpose(int ** sourceMat, unsigned int sourceVerticesNumber)
{
	int** mat = new int*[sourceVerticesNumber];
	for (int i = 0; i < sourceVerticesNumber; ++i)
	{
		mat[i] = new int[sourceVerticesNumber];
	}

	for (int i = 0; i < sourceVerticesNumber; ++i)
	{
		for (int j = 0; j < sourceVerticesNumber; ++j)
		{
			mat[j][i] = sourceMat[i][j];
		}
	}

	return mat;
}

void AdjMatrix::PrintMat(int ** mat, int verticesNumber)
{
	for (int i = 0; i < verticesNumber; ++i)
	{
		for (int j = 0; j < verticesNumber; ++j)
		{
			std::cout << mat[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int ** AdjMatrix::Test4by4Matrix()
{
	int** mat = new int*[4];
	for (int i = 0; i < 4; ++i)
	{
		mat[i] = new int[4];
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			mat[i][j] = 0;
		}
	}

	mat[0][1] = 2;
	mat[0][2] = 9;
	mat[1][2] = 3;
	mat[1][3] = 14;
	mat[2][3] = 5;

	return mat;
}

void AdjMatrix::RemoveMatrix(int** mat, unsigned int verticesNumber)
{
	for (int i = 0; i < verticesNumber; ++i)
	{
		delete[] mat[i];
	}
	delete[] mat;
}
