#include <iostream>
#include <windows.h>


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int choice = 0;

	while (true)
	{
		std::cout << "Выберите задание(1-3): ";
		std::cin >> choice;

		if (choice == 1) //Задание 1
		{
			int number = 0;
			std::cout << "Введите любое шестизначное число: ";
			std::cin >> number;
			if (number >= 100000 && number <=999999)
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
	
	
	return 0;
}