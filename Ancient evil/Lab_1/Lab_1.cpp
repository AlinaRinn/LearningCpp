#include <iostream>
#include <fstream>
#include <string.h> 
#include <cmath> 
#include <stdlib.h>

using namespace std;

//����� �������� ������� � ������ ������� � ���������� ����������

//���������� �� ����� � ����� ���� ��
void Filling_File(float** TwoArray, float OneArray[] , const int N)
{
    ifstream file;
    bool Doda = true;

	//�������� �� �������� 
    while (Doda)
	{
        Doda = false;
		file.open("input.txt");
		if (!file.is_open())
		{
            cout << "������ �������� �����\n";
            Doda = true;
		}
	}

	//���������� 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= N; j++)
			file >> TwoArray[i][j];
	}
	for (int i = 0; i < N; i++)
		file >> OneArray[i];


	file.close();
}
void Print_File(float OneArray[], const int N, string str = " ")
{
	ofstream file;
	file.open("output.txt", ios::app);

	if (str != " ")
		file << str << endl;

	for (int i = 0; i < N; i++)
		file << OneArray[i]<< "\t";
	file << endl;

	file.close();
}
//�����������
void Cpy(float** Array_1, float** Array_2,const int N)
{
	for (int i = 0; i <= N; i++)
		for (int j = 0; j < N; j++)
			Array_2[i][j] = Array_1[i][j];
}
void Cpy(float Array_1[], float Array_2[], const int N)
{
	for (int j = 0; j < N; j++)
		Array_2[j] = Array_1[j];
}
//������� �������
void Clear()
{
	char us = 1;
	while (us != '1')
	{
		cout << "������� 1, ����� ����������" << endl;
		cin >> us;
	}
	system("cls");
}
//����� � ���c���
void Results(float** Array, const int N, string str = " ")
{
	if (str != " ")
		cout << str << endl;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			cout.width(15);
			cout << Array[i][j];
			if (j == N - 1)
				cout << '|';

		}
		cout << endl;
	}
	cout << endl;
}
void Results(float Appr[], const int N, string str = " ")
{
	if (str != " ")
		cout << str << endl;


	for (int i = 0; i < N; i++)
	{
		cout.width(15);
		cout << Appr[i];
	}
	cout << endl;
}

string to_string(int n)
{
    char buf[40];
    sprintf(buf,"%d",n);
    return buf;
}
//������
void Gordan_Gaus(const int N = 4)
{
	//���������� ����������
	float* Appr_ST= new float[N];
	float* rew = new float[N];
	float** Array = new float* [N];
	for (int i = 0; i < N; i++)
		Array[i] = new float[N + 1];

	//���������� � ����� � �������
	Filling_File(Array, Appr_ST, N);
	Results(Array, N, "����������� �������:");


	//������ ����������� ��� �������
	for (int i = 0; i < N; i++)
	{
		for (int stol = N; stol >= 0; stol--)
			Array[i][stol] /= Array[i][i];
		for (int str = i + 1; str < N; str++)
			for (int stol = N; stol >= 0; stol--)
				Array[str][stol] -= Array[i][stol] * Array[str][i];
	}
	Results(Array, N, "������������� ������� � ������ �������-������:");


	//������ ������� ������������ ����
	for (int i = N-1; i > 0; i--)
	{
		for (int str = i - 1; str >= 0; str--)
			for (int stol = N; stol >= i; stol--)
				Array[str][stol] = Array[str][stol] - Array[str][i] * Array[i][stol];
	}
	Results(Array, N, "�������� ������� ������ �������-������:");

	
	//����� ������� � ���� � �������� ����������
	for (int i = 0; i < N; i++)
		rew[i] = Array[i][N];
	Print_File(rew, N, "������� ������� �������-������");

	
	for (int i = 0; i < N; i++)
		delete[] Array[i];
	delete[] Array, rew, Appr_ST;
}
void Gauss_Zeidel(const float E, const int N = 4)
{
	//����������� ����������
	float max; int iter = 0;
	float* New_ap = new float[N];
	float* Old_ap = new float[N];
	float* error = new float[N];
	float** Array = new float* [N];
	for (int i = 0; i < N; i++)
		Array[i] = new float[N + 1];

	//���������� � ����� � �������
	Filling_File(Array, New_ap, N);
	if (E >= 0.1)
		Results(Array, N, "����������� �������:");
	

	//��������� �������
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
			if (abs(Array[j][i]) > abs(Array[i][i]))
				for (int k = 0; k <= N; k++)
					swap(Array[j][k], Array[i][k]);
	}

	
	//����� � �������
	if (E >= 0.1)
	{ 
		Results(Array, N, "��������������� �������");
		Results(New_ap, N, "��������� �����������:");
	}
	cout << "������� ���������� ��� E = " << E << endl;

	
	do 
	{
		Cpy(New_ap, Old_ap, N);
		iter++;

		//���������� ����������
		for (int i = 0; i < N; i++) 
		{
			New_ap[i] = Array[i][N];
			for (int j = 0; j < (N); j++)
			{
				if (i == j)
					continue;
				New_ap[i] -= (Array[i][j] * New_ap[j]);
			}
			New_ap[i] /= Array[i][i];
		}


		//����� ������������ �����������
		for (int i = 0; i < N; i++) 
		{
			error[i] = fabs((New_ap[i] - Old_ap[i]) / New_ap[i]);
			if (i == 0)
				max = error[i];
			else
				max = ((error[i - 1] < error[i]) ? error[i] : max);
		}


		Results(New_ap, N);
	} while (max > E);
	

	//����� ������� � ���� � �������� ����������
	Results(New_ap, N);
	cout << "���������� �������� " << iter << endl;
	Print_File(New_ap, N, "������� ������� �������-������, ��� E = " + to_string(E));

	for (int i = 0; i < N; i++)
		delete[] Array[i];
	delete[] Array, Old_ap, New_ap, error;
}

int main()
{
	setlocale(LC_ALL, "Russian");


	const int EPS = 4;
	const float E[] { 0.1, 0.02 , 0.005, 0.001 };


	Gordan_Gaus();
	Clear();


	for (int i = 0; i < EPS; i++)
	{
		Gauss_Zeidel(E[i]);
	}


	return 0;
}
