#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;
class CArray_1D {
	int* array;	//дані-члени класу
	int size;
	int start;
	int finish;
public:
	void Create_ar1D(int n); //функції-члени класу
	void Clear();
	void Search_Pos();
	void Input_ar1D();
	void Print_ar1D();
	int Sum_ar1D();
};

int main()
{
	int size;
	cout << "Enter the size of array:" << endl;
	cin >> size;
	CArray_1D obj1;
	obj1.Create_ar1D(size);
	obj1.Input_ar1D();
	obj1.Print_ar1D();
	obj1.Search_Pos();
	int sum = obj1.Sum_ar1D();
	cout << endl << "Sum = " << sum << endl;
	system("pause");
}
void CArray_1D::Create_ar1D(int n)
{
	size = n;
	array = (int*)malloc(size * sizeof(int));
	//виділення пам’яті під масив
}
void CArray_1D::Clear()
{
	free(array);
	//звільнення памяті 
}
void CArray_1D::Input_ar1D()
{
	cout << endl << "Enter numbers of array:" << endl;
	for (int i = 0; i < size; i++) //заповнення масиву
	{
		cout << "array[" << i << "] = ";
		cin >> array[i];
	}
}
void CArray_1D::Print_ar1D()
{
	cout << endl << "Numbers of array:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "array[" << i << "] = " << array[i] << endl;
		//виведення масиву на екран
	}
}

void CArray_1D::Search_Pos() //находження першого і другого позитивних чисел
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] > 0)
		{
			start = i; 
			cout << endl << "Start = " << array[start]<< endl;
			i++;
			for (; i < size; i++)
			{
				if (array[i] > 0) 
				{
					finish = i;
					cout << endl << "Finish = " << array[finish] << endl;
					return;
				}
			}
		}
	}

}



int CArray_1D::Sum_ar1D() //додавання чисел
{
	int sum = 0;
	for (; start + 1 < finish; start++)
	{
		sum = sum + array[start + 1];
	}
	return sum;
}
