#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;
class CArray_2D{
	int** array; //дані-члени класу
	int* array_odnovimir;
	int row, col;
	int size;
 public: 
	//функції-члени класу
	void Create_ar2D(int rows, int cols);
	void Input_ar2D();
	void Clear();
	void Seredne_arefmet();
	void Create_array_odnovimir(int cols);
	void Print_array();
};
int main(){
	int rows,colums;
	cout << "Enter the rows of array:" << endl;
	cin >> rows;
	cout << "Enter the colums of array:" << endl;
	cin >> colums;
	CArray_2D obj1;
	obj1.Create_ar2D(rows,colums);
	obj1.Input_ar2D();
	obj1.Create_array_odnovimir(colums);
	obj1.Seredne_arefmet();
	obj1.Print_array();
	system("pause");
}
void CArray_2D::Clear()
{
	free(array);
	//звільнення памяті 
}
void CArray_2D::Create_ar2D(int rows, int cols)
{
	row = rows;
	col = cols;
//виділення пам’яті під двомірний масив
	array = (int**)malloc(row*sizeof(int*));
	for(int i=0; i<row; i++)
		array[i] = (int*)malloc(col*sizeof(int));
}
void CArray_2D::Input_ar2D()
//функція введення елементів масиву
{
	cout<<endl<< "Enter numbers of array:" <<endl;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{    
			cout <<"array["<< i <<"]["<< j << "] = ";
			cin >> array[i][j];
		}
	} 
}
void CArray_2D::Create_array_odnovimir(int cols)
//створення нового одновимірного масиву
{
    size = cols;
	array_odnovimir = (int*)malloc(size*sizeof(int));
}
void CArray_2D::Seredne_arefmet()
{
int p = 0;
int sredne = 0;
   for(int y = 0; y < col; y++)
    {
        for(int x = 0; x < row; x++)
        {
            if(array[x][y] > 0)
            {
                p++;
                sredne = array[x][y] + sredne;   
            }
        }
        int j = (sredne/p);
        array_odnovimir[y] = j;
        p = 0;
        sredne = 0;
    } 
}
void CArray_2D::Print_array()
//виведення одновимірного масиву
{
cout << endl << "Новий одновмірний масив:" << endl;
	for(int i=0; i < col; i++)
	{
		cout<<endl<<"Array["<<i<<"] = "<<array_odnovimir[i]<<endl;
	}
}