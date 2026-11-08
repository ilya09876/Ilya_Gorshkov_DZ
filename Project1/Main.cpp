#include <iostream>
#include <windows.h>

bool VisokosniCheck(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int DateToDays(int year, int month, int day)
{
	int daysInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int itog = 0;

	itog += (year - 1) * 365;

	for (size_t i = 1; i < year; i++)
	{
		if (VisokosniCheck(i) == true)
		{
			itog += 1;
		}
	}

	for (size_t i = 0; i < month - 1; i++)
	{
		itog += daysInMonths[i];
		if (i == 1 && VisokosniCheck(year) == true)
		{
			itog += 1;
		}
	}

	itog += day;

	return itog;
}

int RaznitsaDate(int year1, int month1, int day1, int year2, int month2, int day2)
{
	return DateToDays(year2, month2, day2) - DateToDays(year1, month1, day1);
}


double Average(double arr[], int size)
{
	double itog = 0;

	for (size_t i = 0; i < size; i++)
	{
		itog += arr[i];
	}

	itog /= size;

	return itog;
}


void Counts(double arr[], int size)
{
	int positive = 0;
	int negative = 0;
	int zero = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > 0)
		{
			positive++;
		}

		else if (arr[i] < 0)
		{
			negative++;
		}

		else
		{
			zero++;
		}
	}

	std::cout << "Количество положительных элементов: " << positive << "\n";
	std::cout << "Количество отрицательных элементов: " << negative << "\n";
	std::cout << "Количество нулевых элементов: " << zero << "\n";
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int choice = 0;

	while (true)
	{
		system("cls");
		std::cout << "1.Дз за 18.10\n";
		std::cout << "2.Дз за 20.10\n";
		std::cout << "Выберите Дз(0-выход): ";
		std::cin >> choice;

		if (choice == 0)
		{
			break;
		}

		else if (choice == 1)
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
					system("cls");
					int year1 = 0;
					int month1 = 0;
					int day1 = 0;
					int year2 = 0;
					int month2 = 0;
					int day2 = 0;

					std::cout << "Введите год первой даты: ";
					std::cin >> year1;
					std::cout << "Введите месяц первой даты: ";
					std::cin >> month1;
					std::cout << "Введите день первой даты: ";
					std::cin >> day1;
					std::cout << "Введите год второй даты: ";
					std::cin >> year2;
					std::cout << "Введите месяц второй даты: ";
					std::cin >> month2;
					std::cout << "Введите день второй даты: ";
					std::cin >> day2;

					std::cout << "Разность в днях между этими датами: " << RaznitsaDate(year1, month1, day1, year2, month2, day2) << "\n";
				}

				else if (choice == 2) //Задание 2
				{
					system("cls");
					const int size = 5;
					double arr[size]{ 2, 5, 7, 32, 8 };

					std::cout << "Среднее арифметическое: " << Average(arr, size) << "\n";
				}

				else if (choice == 3) //Задание 3
				{
					const int size = 5;
					double arr[size]{ 5, 0, 10, -2, -99 };

					Counts(arr, size);
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
				system("cls");
				int rasstoyanie[2]{};
				int weight = 0;
				int rasxodMultiplier = 1;
				int refueling = 0;

				std::cout << "1) Самолёт №1\n";
				std::cout << "Ёмкость бака - 300 литров\n";
				std::cout << "Потребление топлива в зависимости от веса груза :\n";
				std::cout << "-до 750 кг : 1 литров / км\n";
				std::cout << "-до 1500 кг : 4 литров / км\n";
				std::cout << "-до 2000 кг : 7 литров / км.\n";
				std::cout << "-более 2000 кг – самолет не поднимает\n\n";

				std::cout << "2) Самолёт №2\n";
				std::cout << "Ёмкость бака - 1000 литров\n";
				std::cout << "Потребление топлива в зависимости от веса груза :\n";
				std::cout << "-до 1000 кг : 2 литров / км\n";
				std::cout << "-до 2000 кг : 4 литров / км\n";
				std::cout << "-до 3000 кг : 6 литров / км.\n";
				std::cout << "-более 3000 кг – самолет не поднимает\n";
				std::cout << "Самолёт имеет сбрасываемый временый бак ёмкостью 100 литров\n\n";

				std::cout << "Выберите номер самолета(1-2)(0-назад): ";
				std::cin >> choice;
				if (choice == 0)
				{
					break;
				}

				if (choice == 1)
				{
					system("cls");
					int tankcapacy = 300;

					std::cout << "Введите расстояние между пунктами А и В(км): ";
					std::cin >> rasstoyanie[0];

					std::cout << "Введите расстояние между пунктами B и C(км): ";
					std::cin >> rasstoyanie[1];

					while (true)
					{
						std::cout << "Введите вес груза(кг): ";
						std::cin >> weight;

						if (weight <= 750)
						{
							rasxodMultiplier = 1;
							break;
						}

						if (weight <= 1500 && weight > 750)
						{
							rasxodMultiplier = 4;
							break;
						}

						if (weight <= 2000 && weight > 1500)
						{
							rasxodMultiplier = 7;
							break;
						}

						if (weight > 2000 || weight < 0)
						{
							std::cout << "Некорректный вес!(Вес дожен быть от 0 до 2000)\n";
							system("pause");
						}
					}


					if (rasstoyanie[0] * rasxodMultiplier > tankcapacy)
					{
						std::cout << "Самолет не сможет долететь до места назначения!\n";
						system("pause");
					}
					
					else if (rasstoyanie[1] * rasxodMultiplier > tankcapacy)
					{
						std::cout << "Самолет не сможет долететь до места назначения!\n";
						system("pause");
					}

					else
					{
						if ((rasstoyanie[1] - (tankcapacy - (rasstoyanie[0] * rasxodMultiplier))) > 0)
						{
							refueling = (rasstoyanie[1] - (tankcapacy - (rasstoyanie[0] * rasxodMultiplier)));
						}
						std::cout << "Минимальное количество топлива, необходимое для дозаправки самолету в пункте В: " << refueling << "\n";
						system("pause");
					}
				}

				else if (choice == 2)
				{
					system("cls");
					int tankcapacy = 1000;
					int extraTank = 100;

					std::cout << "Введите расстояние между пунктами А и В(км): ";
					std::cin >> rasstoyanie[0];

					std::cout << "Введите расстояние между пунктами B и C(км): ";
					std::cin >> rasstoyanie[1];

					while (true)
					{
						std::cout << "Введите вес груза(кг): ";
						std::cin >> weight;

						if (weight <= 1000)
						{
							rasxodMultiplier = 2;
							break;
						}

						if (weight <= 2000 && weight > 1000)
						{
							rasxodMultiplier = 4;
							break;
						}

						if (weight <= 3000 && weight > 2000)
						{
							rasxodMultiplier = 6;
							break;
						}

						if (weight > 3000 || weight < 0)
						{
							std::cout << "Некорректный вес!(Вес должен быть от 0 до 3000)\n";
							system("pause");
						}
					}

					int fuelNeeded[2]{};
					fuelNeeded[0] = rasstoyanie[0] * rasxodMultiplier;
					fuelNeeded[1] = rasstoyanie[1] * rasxodMultiplier;

					if (fuelNeeded[0] > (tankcapacy + extraTank))
					{
						std::cout << "Самолет не сможет долететь до места назначения!\n";
						system("pause");
					}

					else if (fuelNeeded[1] > tankcapacy)
					{
						std::cout << "Самолет не сможет долететь до места назначения!\n";
						system("pause");
					}

					else
					{
						int remainingFuel = 0;

						if (fuelNeeded[0] <= extraTank)
						{
							remainingFuel = tankcapacy;
						}
						else
						{
							remainingFuel = tankcapacy - (fuelNeeded[0] - extraTank);
						}

						if (fuelNeeded[1] > remainingFuel)
						{
							refueling = fuelNeeded[1] - remainingFuel;
						}

						std::cout << "Минимальное количество топлива, необходимое для дозаправки самолету в пункте В: " << refueling << "\n";
						system("pause");
					}
				}

				else
				{
					std::cout << "Такого самолета нет!\n";
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