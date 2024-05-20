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

int main()
{
    bool pimply[12][12];
	do_pimply(pimply);



}