#include<iostream>
#include<fstream>
using namespace std;
void output_array(int **p, int c_size, int r_size)
{
	for (int i = 0; i < r_size; i++)
	{
		for (int j = 0; j < c_size; j++)
		{
			cout << p[i][j];
			cout << " ";
		}
		cout << endl;
	}
}
void initialize_array(int **&p, int c_size, int r_size)
{
	cout << "enter your matrix data:\n ";
	for (int i = 0; i < r_size; i++)
	{
		for (int j = 0; j < c_size; j++)
		{
			cin >> p[i][j];
			cout << " ";
		}
		cout << endl;
	}
}
void console_data(int **&p, int &c_size, int &r_size)
{
start:
	cout << "enter row size: ";
	cin >> r_size;
	if (r_size < 1)
	{
		cout << "enter greater than 1: ";
		goto start;
	}
jump:
	cout << "enter column size: ";
	cin >> c_size;
	if (c_size < 1)
	{
		cout << "enter greater than 1: ";
		goto jump;
	}
	p = new int *[r_size];
	for (int i = 0; i < 3; i++)
	{
		p[i] = new int[c_size];
	}
	initialize_array(p, c_size, r_size);
	//output_array(p, c_size, r_size);
	//system("pause");
}
void file_data(int **&p, int &c_size, int &r_size)
{
	char ch[20], ch1[20];
	//int *p1 = new int[20];
txt:
	cout << "enter name of file(or whole path if it's not in the same location as matrix manipulation) : ";
	cin >> ch;
	ifstream fin;
	fin.open(ch);
	if (!fin)
	{
		cout << "enter right name of file : ";
		goto txt;

	}
	while (1)
	{
		fin.getline(ch1, 20);
		r_size++;
		//file:
		if (!fin.eof())
		{
			continue;
			//goto file;
		}
		else
			break;
	}
	for (int i = 0; ch[i] != '\0'; i++)
	{
		if (ch1[i] == ' ')
		{
			c_size++;
		}
	}
	c_size++;
	fin.close();
	p = new int *[r_size];
	for (int i = 0; i < r_size; i++)
	{
		p[i] = new int[c_size];
	}
	cout << r_size << " " << c_size;
	fin.open(ch);
	while (!fin.eof())
	{
		for (int i = 0; i < r_size; i++)
		{
			for (int j = 0; j < c_size; j++)
			{
				fin >> p[i][j];
			}
		}
	}
	fin.close();
	output_array(p, c_size, r_size);
}
void sumofmatrix(int **p, int r_size, int c_size)
{
	int sum = 0;
	for (int i = 0; i < r_size; i++)
	{
		for (int j = 0; j < c_size; j++)
		{
			sum += p[i][j];
		}
	}
	cout << endl << "Sum of Your matrix is = " << sum << endl;
}
void productofmatrix(int **p, int r_size, int c_size)
{
	int product = 1;
	for (int i = 0; i < r_size; i++)
	{
		for (int j = 0; j < c_size; j++)
		{
			product *= p[i][j];
		}
	}
	cout << endl << "product of Your matrix is = " << product << endl;
}
void row_wise_avg(int **p, int r_size, int c_size)
{
	int *sum;
	int *avg = new int[r_size];
	sum = new int[r_size];
	for (int i = 0; i<r_size; i++)
	{
		sum[i] = 0;
	}
	for (int i = 0; i < r_size; i++)
	{
		for (int j = 0; j < c_size; j++)
		{
			sum[i] += p[i][j];
		}
	}
	for (int i = 0; i < r_size; i++)
	{
		avg[i] = sum[i] / c_size;
	}
	for (int i = 0; i < r_size; i++)
	{
		cout << "Average of row " << i + 1 << " is : " << avg[i] << endl;
	}
	delete[]sum;
	delete[]avg;
}
void column_wise_avg(int **p, int r_size, int c_size)
{
	int *sum = new int[c_size];
	for (int i = 0; i<r_size; i++)
	{
		sum[i] = 0;
	}
	int *avg = new int[c_size];
	for (int i = 0; i < c_size; i++)
	{
		for (int j = 0; j < r_size; j++)
		{
			sum[i] += p[j][i];
		}
	}
	for (int i = 0; i < c_size; i++)
	{
		avg[i] = sum[i] / r_size;
	}
	for (int i = 0; i < c_size; i++)
	{
		cout << "Average of column " << i + 1 << " is : " << avg[i] << endl;
	}
	delete[]sum;
	delete[]avg;
}
void averageOfMatrix(int **p, int r_size, int c_size)
{
	int sum = 0;
	for (int i = 0; i < r_size; i++)
	{
		for (int j = 0; j < c_size; j++)
		{
			sum += p[i][j];
		}
	}
	int avg = sum / (r_size*c_size);
	cout << "The average of your matrix is : " << avg;
}
void row_wise_sort(int **p, int r_size, int c_size)
{
	// loop for rows of matrix
	for (int i = 0; i < r_size; i++)
	{
		// loop for column of matrix
		for (int j = 0; j < c_size; j++)
		{
			// loop for comparison and swapping
			for (int k = 0; k < c_size - j - 1; k++)
			{
				if (p[i][k] > p[i][k + 1])
				{
					// swapping of elements
					swap(p[i][k], p[i][k + 1]);
				}
			}
		}
	}
	output_array(p, c_size, r_size);
}
void column_wise_sort(int **p, int r_size, int c_size)
{
	for (int i = 0; i < c_size; i++)
	{
		for (int j = 0; j < r_size; j++)
		{
			for (int k = 0; k < r_size - j - 1; k++)
			{
				if (p[k][i]>p[k + 1][i])
				{
					swap(p[k][i], p[k + 1][i]);
				}
			}
		}
	}
	output_array(p, c_size, r_size);
}
void SumOfMatrices(int **p, int r_size, int c_size, int **p2)
{
	int **sum = new int*[r_size];
	for (int i = 0; i < r_size; i++)
	{
		sum[i] = new int[c_size];
	}
	for (int i = 0; i < r_size; i++)
	{
		for (int j = 0; j < c_size; j++)
		{
			sum[i][j] = p[i][j] + p2[i][j];
		}
	}
	output_array(sum, c_size, r_size);
	for (int i = 0; i < r_size; i++)
	{
		delete[]sum[i];
	}
	delete[]sum;
	sum = 0;
}
void DiffOfMatrices(int **p, int r_size, int c_size, int **p2)
{
	int **diff = new int*[r_size];
	for (int i = 0; i < r_size; i++)
	{
		diff[i] = new int[c_size];
	}
	cout << "If U wanna subtract 1st matrix with second write 1 else write 2 : ";
	int num;
	cin >> num;
	if (num == 1)
	{
		for (int i = 0; i < r_size; i++)
		{
			for (int j = 0; j < c_size; j++)
			{
				diff[i][j] = p[i][j] - p2[i][j];
			}
		}
	}
	if (num == 2)
	{
		for (int i = 0; i < r_size; i++)
		{
			for (int j = 0; j < c_size; j++)
			{
				diff[i][j] = p2[i][j] - p[i][j];
			}
		}
	}
	output_array(diff, c_size, r_size);
	for (int i = 0; i < r_size; i++)
	{
		delete[]diff[i];
	}
	delete[]diff;
	diff = 0;
}
void TranposeOfMatrix(int **&p, int r_size, int c_size)
{
	int **temp = new int*[c_size];
	for (int i = 0; i < r_size; i++)
	{
		temp[i] = new int[r_size];
	}
	for (int i = 0; i < r_size; i++)
	{
		for (int j = 0; j < c_size; j++)
		{
			temp[j][i] = p[i][j];
		}
	}
	//As rows are changed with columns
	output_array(temp, r_size, c_size);
	for (int i = 0; i < r_size; i++)
	{
		delete[]p[i];
	}
	delete[]p;
	p = 0;
}
int main()
{
start:
	int **p = 0;
	int r_size = 0, c_size = 0, num1;
	cout << "       ***MATRIX MANIPULATION***     " << endl;
	cout << "How do u want to enter your matrix: \n enter 1 for console input \n enter 2 for file input \n";
	cin >> num1;
	if (num1 == 1)
	{
		console_data(p, c_size, r_size);
	}
	else if (num1 == 2)
	{
		file_data(p, c_size, r_size);
	}
	cout << "What do you want to do with the matrix:" << endl;
	cout << "press key of the number you want to use" << endl;
	cout << " 1.Sum of Matrix (sum of all values)" << endl;
	cout << " 2.Product of Matrix (product of all values)" << endl;
	cout << " 3.Row wise average" << endl;
	cout << " 4.column wise average" << endl;
	cout << " 5.Average of whole matrix" << endl;
	cout << " 6.Row wise sorting" << endl;
	cout << " 7.column wise sorting " << endl;
	cout << " 8.Sum of two matrices " << endl;
	cout << " 9.Diff of two matrices " << endl;
	cout << " 10.Transpose of a matrix" << endl;
	int num;
	cin >> num;
	if (num == 1)
	{
		sumofmatrix(p, r_size, c_size);
	}
	else if (num == 2)
	{
		productofmatrix(p, r_size, c_size);
	}
	else if (num == 3)
	{
		row_wise_avg(p, r_size, c_size);
	}
	else if (num == 4)
	{
		column_wise_avg(p, r_size, c_size);
	}
	else if (num == 5)
	{
		averageOfMatrix(p, r_size, c_size);
	}
	else if (num == 6)
	{
		row_wise_sort(p, r_size, c_size);
	}
	else if (num == 7)
	{
		column_wise_sort(p, r_size, c_size);
	}
	else if (num == 8 || num == 9)
	{
	again:
		int **p1 = 0;
		int r_size1 = 0, opt;
		int c_size1 = 0;
		cout << "Enter Another matrix : \n";
		cout << "How do u want to enter your matrix: \n enter 1 for console input \n enter 2 for file input \n";
		cin >> opt;
		if (opt == 1)
		{
			console_data(p1, c_size1, r_size1);
		}
		else if (opt == 2)
		{
			file_data(p1, c_size1, r_size1);
		}

		if (r_size != r_size1&&c_size != c_size1)
		{
			cout << "enter matrix again  :(" << endl;
			goto again;
		}
		else
		{
			if (num == 8)
			{
				SumOfMatrices(p, r_size, c_size, p1);
			}
			else if (num == 9)
			{
				DiffOfMatrices(p, r_size, c_size, p1);
			}
		}
		for (int i = 0; i < r_size; i++)
		{
			delete[]p1[i];
		}
		delete[]p1;
		p1 = 0;

	}
	else if (num == 10)
	{
		TranposeOfMatrix(p, r_size, c_size);
	}
	//deleting previously used array
	for (int i = 0; i < r_size; i++)
	{
		delete[]p[i];
	}
	delete[]p;
	int PA;
	cout << "Press 1 to play again \n";
	cout << "Press 2 to Quit \n";
	cin >> PA;
	if (PA == 1)
	{
		goto start;
	}
	else
	{
		return 0;
	}



}
