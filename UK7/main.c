#pragma warning(disable : 4996) // отключение ошибки c4996
// Могу поздравить лишь с тем, что вот эта вот хреновина работает исключительно с
// положительными числами
// Тут есть дохрена условностей и особенностей
// Так что удачи
#include <stdio.h>

int main(void)
{
	unsigned long int N; // dlinnyoe chislo N
	int i; // переменная для подсчёта байтов
	int k; // переменная для подсчёта битов
	int n; // переменная для ограничения области бита
	int counter; // счётчик единиц
	unsigned long int mask; // с ней мы обнулим ненужные байты
	
	printf("Enter N\nN = ");
	scanf("%d", &N);

	mask = 0;
	i = 0; 
	k = 31; // сдвигать будем направо и рассматривать поочерёдно биты слева на право 

	while (i != 4) // в лонг инт 4 байта
	{
		for (n = 0, counter = 0; n != 8; ++n, --k) // в каждом байте 8 бит
		{
			if (N >> k & 01) // сдвигаем N на k разрядов вправо и сравниваем последний бит с единицей
				             // если встречается единица увеличиваем счётчик
				             // & - логическое умножение
			{
				++counter;
			}
		}
		if (counter >= 4) // условие задачи обнулить все байты, что содержат в себе менее 4-х единиц
		{
			mask = mask << 8 | 0xff; // сдвигаем маску на 8 влево
			                         // заполняем освободившийся байт единицами
			                         // | - логическое сложение
		}
		else
		{
			mask = mask << 8; // сдвигаем маску на 8 влево и ниичем не заполняем
		}
		++i;
	}

	N = N & mask; // обнуляем ненужные байты

	printf("Result: %lu", N); // lu - long unsigned по-другому нормально не выводится значение

	return 0;
}
