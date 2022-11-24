/*Задание 8. Биолаборатория 2.0* (дополнительное задание)
Что нужно сделать
Благодаря вашей помощи компания «Терран Биотех» вышла на финишную прямую в борьбе со всемирной эпидемией коринебактерий. 
Однако прошлая симуляция была недостаточно точной, да и новая версия антибиотика работает по-другому.

В чашку Петри добавляется W капель воды, D капель чистого антибиотика и подселяется N коринебактерий. 
Известно, что каждую минуту количество бактерий изменяется прямо пропорционально концентрации антибиотика в растворе по формуле Nnew = 2 × Nold − Nold × D / W, 
где Nold — количество коринебактерий минуту назад, Nnew — их новое количество, а D / W — концентрация действующего антибиотика. 
При этом каждую минуту 20% от всего количества антибиотика разлагается и больше не действует.

Напишите программу, которая получает на вход значения W, D и Nold и симулирует процесс в течение 20 минут, 
для каждой минуты выводя на экран текущую концентрацию антибиотика и количество живых коринебактерий в чашке Петри. 
Обеспечьте контроль ввода.

Что оценивается
Количество измеряется в целых числах.
Ничто не уходит в отрицательные значения.
Цикл не бесконечный.*/

#include <iostream>
#include <Windows.h>

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Задаём % разложения антибиотика
	int percentDeactivateAntibiotic = 20;

	std::cout << "Введите количество бактерий: ";
	int numberBacteria;
	std::cin >> numberBacteria;
	while (numberBacteria < 0) {
		std::cout << "Количество бактерий должно быть больше 0. Введите снова: ";
		std::cin >> numberBacteria;
	}

	std::cout << "Введите количество антибиотика: ";
	int antibioticDrops;
	std::cin >> antibioticDrops;
	while (antibioticDrops < 0) {
		std::cout << "Количество антибиотика должно быть больше 0. Введите снова: ";
		std::cin >> antibioticDrops;
	}

	std::cout << "Введите количество воды: ";
	int waterDrops;
	std::cin >> waterDrops;
	while (waterDrops < 0) {
		std::cout << "Количество воды должно быть больше 0. Введите снова: ";
		std::cin >> waterDrops;
	}

	// Вычисляем количество деактивировнных капель антибиотика в минуту
	int dropDeactivateAntibiotic = (antibioticDrops * percentDeactivateAntibiotic) / 100;
	
	for (int i = 1; i <= 20; i++) {
		numberBacteria = (numberBacteria * 2) - (numberBacteria * (antibioticDrops / waterDrops));
		if (numberBacteria < 0) numberBacteria = 0;
		std::cout << "После " << i << " часа бактерий осталось " << numberBacteria << std::endl;
		antibioticDrops -= dropDeactivateAntibiotic;
		std::cout << antibioticDrops << std::endl;
	}

	std::cout << "Все бактерии погибли!" << numberBacteria;

}