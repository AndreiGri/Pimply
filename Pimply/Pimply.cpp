#include <iostream>

bool bubble_counting(bool(*p)[12])                                               // Метод ищет любое значение true и если оно 
{                                                                                // есть возвращает его иначе возвращает false
	bool b = false;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (p[i][j])
			{
				b = true;
				break;
			}
		}
	}
	return b;
}

void pop_the_bubbles(int x1, int y1, int x2, int y2, bool(*p)[12])               // Метод меняет в диапазоне указанных значений
{                                                                                // true на false
	if (x1 > x2)                                                                 // Если x первой координаты больше второй то
	{                                                                            // меняем их местами, тоже делаем с игриками
		std::swap(x1, x2);
	}

	if (y1 > y2)
	{
		std::swap(y1, y2);
	}

	for (int i = x1 - 1; i < x2; i++)
	{
		for (int j = y1 - 1; j < y2; j++)
		{
			if (p[i][j])
			{
				p[i][j] = false;
			}
		}
	}
}

int input_validation(std::string text)                                          // Метод проверяет корректность ввода значений
{
	while (true)
	{
		int n;
		std::cout << text;
		std::cout << ' ';
		std::cin >> n;
		if (std::cin.fail() || std::cin.peek() != '\n' || n < 1 || n > 12)      // если предыдущее извлечение оказалось неудачным,
		{
			std::cerr << " Incorrectly entered data!\n Try again!" << std::endl;
			std::cin.clear();                                                   // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // и удаляем значения предыдущего ввода из входного буфера
		}
		else
		{
			return n;
		}
	}
}

void do_pimply(bool(*p)[12])                                                    // Заполняем массив истинными значениями
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			p[i][j] = true;
		}
	}
}

void do_pimp(std::string(*p)[12], bool(*pi)[12])                                // Метод заполняет массив значениями 'o' если
{                                                                               // в буленновском массиве на этом же месте
	for (int i = 0; i < 12; i++)                                                // стоит true иначе записываем false
	{
		for (int j = 0; j < 12; j++)
		{
			if (pi[i][j] == true)
			{
				p[i][j] = " O  ";
			}
			else
			{
				if (p[i][j] == " O  " && pi[i][j] == false)
				{
					p[i][j] = "Pop!";
				}
				else
				{
					p[i][j] = " X  ";
				}
			}
		}
	}
}

void show_pimp(std::string(*p)[12])                                             // Выводим в консоль пупырку
{
	int level = 1;
	std::cout << std::endl;         
	for (int i = 0; i < 12; i++)
	{
		std::cout << std::string(level * 4, ' ');                               // С четверным отступом от края консоли
		for (int j = 0; j < 12; j++)
		{
			std::cout << ' ' << p[i][j];
		}
		std::cout << std::string(level * 2, '\n');                             // и делаем двойной отступ до следующей строки
	}
	std::cout << std::endl;                                  
}

int main()
{
	system("color 70");

    bool pimply[12][12];
	std::string pimp[12][12];
	do_pimply(pimply);
	do_pimp(pimp, pimply);
	show_pimp(pimp);
	bool n = true;
	while (n)                                                                  // Цикл продолжается пока есть хотябы один пузырёк
	{
		int x1 = input_validation(" Enter the X coordinate of the first point in the region: ");
		int y1 = input_validation(" Enter the Y coordinate of the first point in the region: ");
		int x2 = input_validation(" Enter the X coordinate of the second point in the region: ");
		int y2 = input_validation(" Enter the Y coordinate of the second point in the region: ");
		pop_the_bubbles(x1, y1, x2, y2, pimply);
		do_pimp(pimp, pimply);
		show_pimp(pimp);
		n = bubble_counting(pimply);
		if (n == false)
		{
			do_pimp(pimp, pimply);
			show_pimp(pimp);
		}
	}
	std::cout << " Game over!" << std::endl;

	system("pause>nul");
	return 0;
}