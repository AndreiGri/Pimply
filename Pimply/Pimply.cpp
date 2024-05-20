#include <iostream>

void do_pimply(bool(*p)[12])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			p[i][j] = true;
		}
	}
}

void do_pimp(char(*p)[12])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			p[i][j] = 'o';
		}
	}
}

void show_pimp(char(*p)[12])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			std::cout << ' ' << p[i][j];
		}
		std::cout << std::endl;
	}
}

int main()
{
    bool pimply[12][12];
	do_pimply(pimply);
	char pimp[12][12];
	do_pimp(pimp);
	show_pimp(pimp);

}