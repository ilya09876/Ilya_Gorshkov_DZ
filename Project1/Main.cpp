#include <iostream>
#include <windows.h>


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int choice = 0;

	while (true)
	{
		std::cout << "1.Дз за 24.09\n";
		std::cout << "2.Дз за 14.10\n";
		std::cout << "Выберите Дз: ";
		std::cin >> choice;
		if (choice == 1)
		{
			while (true)
			{
				std::cout << "Выберите задание(1-3)(0-назад): ";
				std::cin >> choice;
				if (choice == 0)
				{
					break;
				}

				else if (choice == 1) //Задание 1
				{
					int number = 0;
					std::cout << "Введите любое шестизначное число: ";
					std::cin >> number;
					if (number >= 100000 && number <= 999999)
					{
						if ((number / 100000) + ((number / 10000) % 10) + ((number / 1000) % 10) == ((number % 10) + ((number % 100) / 10) + ((number % 1000) / 100)))
						{
							std::cout << "Ваше число - счастливое\n";
						}
						else
						{
							std::cout << "Ваше число - НЕ счастливое\n";
						}
					}
					else
					{
						std::cout << "Ошибка, нужно ввести шестизначное число!\n";
					}
				}

				else if (choice == 2) //Задание 2
				{
					int number = 0;
					int arr1[4]{};
					int arr2[4]{};

					std::cout << "Введите любое четырёхзначное число: ";
					std::cin >> number;
					if (number >= 1000 && number <= 9999)
					{
						arr1[0] += number / 1000;
						arr1[1] += (number / 100) % 10;
						arr1[2] += (number / 10) % 10;
						arr1[3] += number % 10;

						arr2[0] = arr1[1];
						arr2[1] = arr1[0];
						arr2[2] = arr1[3];
						arr2[3] = arr1[2];

						for (size_t i = 0; i < 4; i++)
						{
							std::cout << arr2[i];
						}
						std::cout << "\n";
					}
					else
					{
						std::cout << "Ошибка, нужно ввести четырёхзначное число!\n";
					}
				}

				else if (choice == 3) //Задание 3
				{
					int num = 0;
					int maxnum = 0;

					for (size_t i = 0; i < 7; i++)
					{
						std::cout << "Введите " << i + 1 << "-е число: ";
						std::cin >> num;
						if (num > maxnum)
						{
							maxnum = num;
						}
					}
					std::cout << "Самое большое число: " << maxnum << "\n";
				}

				else
				{
					std::cout << "Такого задания нет!\n";
				}
			}
		}

		else if (choice == 2)
		{
			while (true)
			{
				std::cout << "Выберите задание(1-3)(0-назад): ";
				std::cin >> choice;
				if (choice == 0)
				{
					break;
				}

				else if (choice == 1) //Задание 1
				{
					const int size = 10;
					int arr[size]{};
					int MinRand = -100;
					int MaxRand = 100;
					int MinNum = MaxRand;
					int MaxNum = MinRand;

					for (size_t i = 0; i < size; i++)
					{
						arr[i] += rand() % (MaxRand - MinRand + 1) + MinRand;
					}

					for (size_t i = 0; i < size; i++)
					{
						if (arr[i] < MinNum)
						{
							MinNum = arr[i];
						}

						if (arr[i] > MaxNum)
						{
							MaxNum = arr[i];
						}
					}
					std::cout << "Максимальное число в списке: " << MaxNum << "\n";
					std::cout << "Минимальное число в списке: " << MinNum << "\n";
				}

				else if (choice == 2) //Задание 2
				{
					const int size = 10;
					int arr[size]{};
					int MinNumDiap = 0;
					int MaxNumDiap = 0;
					int NumDo = 0;
					int summ = 0;

					std::cout << "Введите диапазон(от какого числа): ";
					std::cin >> MinNumDiap;

					std::cout << "Введите диапазон(до какого числа(включительно)): ";
					std::cin >> MaxNumDiap;

					for (size_t i = 0; i < size; i++)
					{
						arr[i] += rand() % (MaxNumDiap - MinNumDiap + 1) + MinNumDiap;
					}

					std::cout << "Введите число, все числа меньше которого будут суммированы: ";
					std::cin >> NumDo;

					for (size_t i = 0; i < size; i++)
					{
						if (arr[i] < NumDo)
						{
							summ += arr[i];
						}
					}

					std::cout << "Сумма: " << summ << "\n";
				}

				else if (choice == 3) //Задание 3
				{
					const int size = 12;
					int arr[size]{};
					int MinMonthDiap = 0;
					int MaxMonthDiap = 0;
					int MinProfit = 0;
					int MaxProfit = 0;
					int MinProfitMonth = 0;
					int MaxProfitMonth = 0;

					for (size_t i = 0; i < size; i++)
					{
						std::cout << "Введите прибыль фирмы за " << i + 1 << "-й месяц: ";
						std::cin >> arr[i];
					}

					std::cout << "Введите диапазон(от какого месяца): ";
					std::cin >> MinMonthDiap;
					MinMonthDiap--;

					std::cout << "Введите диапазон(до какого месяца(включительно)): ";
					std::cin >> MaxMonthDiap;
					MaxMonthDiap--;

					MinProfit = arr[MinMonthDiap];
					MaxProfit = arr[MaxMonthDiap];

					MinProfitMonth = MinMonthDiap;
					MaxProfitMonth = MaxMonthDiap;

					for (size_t i = MinMonthDiap; i <= MaxMonthDiap; i++)
					{
						if (arr[i] < MinProfit)
						{
							MinProfit = arr[i];
							MinProfitMonth = i;
						}

						if (arr[i] > MaxProfit)
						{
							MaxProfit = arr[i];
							MaxProfitMonth = i;
						}
					}

					std::cout << "Месяц, в котором прибыль была минимальна: " << MinProfitMonth + 1 << "\n";
					std::cout << "Месяц, в котором прибыль была максимальна: " << MaxProfitMonth + 1 << "\n";
				}

				else
				{
					std::cout << "Такого задания нет!\n";
				}
			}
		}

		else
		{
			std::cout << "Такого Дз нет!\n";
		}
	}


	return 0;
}