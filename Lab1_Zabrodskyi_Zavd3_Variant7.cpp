#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
class CArray_3D{
	int* array;	//дані-члени класу
	int size;
 public: 
	void Create_ar3D(int n); //функції-члени класу
	void Clear();
	void Input_ar3D();
	void Print_array();
	void Converting();
	int Square(int x);
};
int main()
{
	int size;
	cout << "Enter the size of array:" << endl;
	cin >> size;
	CArray_3D obj1;
	obj1.Create_ar3D(size);
	obj1.Input_ar3D();
	obj1.Converting();
	obj1.Print_array();
	system("pause");
}
void CArray_3D::Create_ar3D(int n)
{
	size = n;
	array = (int*)malloc(size*sizeof(int));
	//виділення пам’яті під масив
}
void CArray_3D::Clear()
{
	free(array);
	//звільнення памяті 
}
void CArray_3D::Input_ar3D()
{
	cout<<endl<<"Enter numbers of array:"<<endl;
	for(int i=0; i<size; i++) //заповнення масиву
	{
		cout << "array[" << i << "] = ";
		cin >> array[i];
	} 
}
int CArray_3D::Square(int b)
//функція знаходження квадратного корення
{
	int p = b;
	int square = sqrt(p);
	return square;
}
void CArray_3D::Converting()
//функція перетворення масиву 
{
    for(int j = 0; j < size; j++)
    {
        if(array[j] % 2 == 0)
        {
            array[j] = Square(array[j]);
        }    
    }
}
void CArray_3D::Print_array()
{
	cout << endl << "Новий одновимірний масив:" << endl;
	for(int i=0; i<size; i++)
	{
		cout<<"array["<<i<<"] = "<<array[i]<<endl;
		//виведення масиву на екран
	} 
}