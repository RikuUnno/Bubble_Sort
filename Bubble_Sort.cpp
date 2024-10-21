#include <iostream>
#include <random>

using namespace std;

void ShowArray(int num, int *ptr)
{
	for (int i = 0; i < num; i++)
	{
		cout << ptr[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arrayNum;
	int tmp;

	cout << "配列の長さを入力してください" << endl;

	cin >> arrayNum;

	int* ptr = new int[arrayNum];

	for (int i = 0; i < arrayNum; i++)
	{
		ptr[i] = rand() % 99 + 1;
	}

#ifdef _DEBUG

	ShowArray(arrayNum, ptr);
	cout << "初期値" << endl;

#endif // _DEBUG

	for (int i = 0; i < arrayNum; i++)
	{

		//昇順
		for (int j = arrayNum - 1; j > i; j--) 
		{
			if (ptr[j] < ptr[j - 1])
			{
				tmp = ptr[j];
				ptr[j] = ptr[j - 1];
				ptr[j - 1] = tmp;
			}
		}

		////降順
		//for (int j = 0; j < arrayNum - 1;j++ )
		//{
		//	if (ptr[j] < ptr[j + 1])
		//	{
		//		tmp = ptr[j];
		//		ptr[j] = ptr[j + 1];
		//		ptr[j + 1] = tmp;
		//	}
		//}
		ShowArray(arrayNum, ptr);
		cout << i + 1 << "回目の変更結果" << endl;
	}

	delete[] ptr;
}
