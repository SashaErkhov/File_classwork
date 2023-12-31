#include <iostream>
#include <fstream>

template <typename T>
T * adder(T *input, int* len, T newl)
{
	T * tmp = new T[*len + 1];
	for (int i = 0;i != *len;++i)
	{
		tmp[i] = input[i];
	}
	tmp[*len] = newl;
	delete[] input;
	(*len)++;
	return tmp;
}

int main()
{
	std::fstream fs;
	fs.open("file.txt", std::ios_base::in);
	if (!fs.is_open())
	{
		std::cout << "can't open file" << std::endl;
		return 1;
	}
	int input;
	char midle;
	int len = 0;
	int *arrive=new int[len];

	int rlen;
	int ok = true;
	int count=0;

	while (true)
	{
		fs >> input;
		if (fs.eof()) break;
		arrive = adder(arrive, &len, input);
		++count;
		if (ok)
		{
			fs.get(midle);
			if (midle == '/n')
			{
				ok = false;
				rlen = count;
			}
		}
		
	}
	for (int i = 0;i != len;++i)
	{
		std::cout << arrive[i] << std::endl;
	}
	fs.close();
	delete[] arrive;
	std::cout << std::endl;
	system("pause");
    return 0;
}

