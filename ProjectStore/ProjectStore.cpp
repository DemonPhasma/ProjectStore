#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>

#if defined(max)
#undef max
#endif 

// Учетные записи
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "1", "1" };
//-----------------------------

int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];



//-----------------------------
// Функции
void Start();
bool Login();
void ShopUserMenu();
void ShopFaritMenu();
void CreateStaticStorage();
void ReffilStorage();
void WriteOffFromStorage();
void ChahgePrice();
void ChangeStaff();
void AddEmployee();


template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size);

template<typename ArrType>
void printArr(ArrType dynamicArr, int size);

int main()
{
	Start();
	delete[]loginArr;
	delete[]passwordArr;
	delete[]idArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]nameArr;

	return 0;
}

void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	CreateStaticStorage();
	std::cout << "\n\n\t\t\tМагазин собачьей еды HOTDOG!!!\n\n\n";
	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin == true)
		{
			std::string choose{};

			do
			{
				std::cout << "Использовать готовый склад или создать новый?\n";
				std::cout << "1 - Готовый склад\n2 - Создать новый \n\nВвод: ";
				std::getline(std::cin, choose, '\n');

			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{
				// создание динамического склада
			}
			ShopFaritMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}

}

void PrintStorage()
{
	std::cout << "ID\tНазвание\t\t\tЦена\tКол-во\n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << nameArr[i] << "\t\t\t"
			<< priceArr[i] << "\t" << countArr[i] << "\n";
	}
}

bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "Введите лохин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пахоль: ";
		std::getline(std::cin, pass, '\n');

		for (int i = 0; i < userCount; i++)
		{
			if (login == loginArr[0] && pass == passwordArr[0])
			{
				std::cout << "Добро " << loginArr[0] << '\n';
				isAdmin = true;
				return true;
			}
			else if (login == loginArr[i] && pass == passwordArr[i])
			{
				std::cout << "Добро " << loginArr[i] << '\n';
				isAdmin = false;
				return true;
			}
		}
		system("cls");
		std::cout << "вы лох! хихиих хахааха хухуух\n\n";
	}

}

void ShopUserMenu()
{

	std::string choose{};

	while (true)
	{
		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать склад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Отчет о прибыли\n\n";
			std::cout << "0. Закрыть смену\n";

			std::cout << "Вводи блин: ";
			std::getline(std::cin, choose, '\n');
			// добавуление акции
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); // 48-56 

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			PrintStorage();
		}
		else if (choose == "3")
		{
			ReffilStorage();
		}
		else if (choose == "4")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cerr << "ошибОЧКА";
		}

	}
}

void ShopFaritMenu()
{
	std::string choose{};

	while (true)
	{
		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать склад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Изменить цену\n";
			std::cout << "6. Изменить склад\n";
			std::cout << "7. изменить сотрудника\n";
			std::cout << "8. Отчет о прибыли\n\n";
			std::cout << "0. Закрыть смену\n";

			std::cout << "Вводи блин: ";
			std::getline(std::cin, choose, '\n');
			// добавуление акции
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); // 48-56 

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			PrintStorage();
		}
		else if (choose == "3")
		{
			ReffilStorage();
		}
		else if (choose == "4")
		{
			WriteOffFromStorage();
		}
		else if (choose == "5")
		{
			ChahgePrice();
		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{
			ChangeStaff();
		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

			break;
		}
		else
		{
			std::cerr << "ошибОЧКА";
		}
	}

}

void CreateStaticStorage()
{
	const int staticSize = 10;
	int idStaticArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string nameStaticArr[staticSize]
	{
		"Дети соседей   ",
		"Хот-Дог        ",
		"Карбонара      ",
		"Суп из индейки ",
		"Салат с грибами",
		"Сосед с дрелью ",
		"Солянка        ",
		"Собачье пиво   ",
		"Яблоко         ",
		"Рагу           "
	};
	int countStaticArr[staticSize]{ 14,16,10,9,20,19,11,18,15,19 };
	double priceStaticArr[staticSize]{ 1227.0, 1200.0, 1400.0, 1300.0, 900.0, 1250.0, 1350.0, 1400.0, 1200.0, 1400.0 };

	SetArr(idStaticArr, idArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(countStaticArr, countArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);

}
void ReffilStorage()
{
	std::string idStr;

	do
	{
		std::cout << "Пополнение склада\nВведите id товара:";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}



	} while (idStr.size() > 1 || std::stoi(idStr) < 1 || std::stoi(idStr) > size);


	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\n";
	int add{};
	do
	{
		std::cout << "Введите кол-во товара для пополнения:";
		std::cin >> add;
	} while (add < 0 || add > MAXINT - countArr[id - 1]);

	countArr[id - 1] += add;
	std::cout << "Товар" << nameArr[id - 1] << "Успешно пополнен\n\n";
	system("pause");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max());
}

void WriteOffFromStorage()
{
	std::string idStr;

	do
	{
		std::cout << "Списание со склада\nВведите id товара:";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}



	} while (idStr.size() > 1 || std::stoi(idStr) < 1 || std::stoi(idStr) > size);


	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\n";
	int del{};
	do
	{
		std::cout << "Введите кол-во товара для списания:";
		std::cin >> del;
	} while (del < 0 || del > MAXINT - countArr[id - 1]);

	countArr[id - 1] -= del;
	std::cout << "Товар" << nameArr[id - 1] << "Успешно списан\n\n";
	system("pause");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max());
}

void ChahgePrice()
{
	std::string idStr;

	do
	{
		std::cout << "Изменение цены\nВведите id товара:";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}



	} while (idStr.size() > 1 || std::stoi(idStr) < 1 || std::stoi(idStr) > size);


	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "Текущая цена" << priceArr[id - 1] << "\n\n";
	double newPrice{};
	do
	{
		std::cout << "Введите новую цену:";
		std::cin >> newPrice;
	} while (newPrice < 0 || newPrice > MAXINT);

	priceArr[id - 1] = newPrice;
	std::cout << "Товар" << nameArr[id - 1] << "Принял новую цену\n\n";
	system("pause");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max());
}

void ChangeStaff()
{
	std::string choose;
	std::cout << "Изменение персонала магазина\n\n";
	do
	{
		std::cout << "1 - Добаавить нового сотрудника\n2 - Изменить логин и пароль\n3 - Удалить старого сотрудника\n\nВвод:";
		std::getline(std::cin, choose, '\n');
	} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);
	
	if (choose == "1")
	{
		AddEmployee();
	}
	else if (choose == "2")
	{

	}
	else if (choose == "3")
	{

	}
	else if (choose == "0")
	{

	}
	else
	{
		std::cerr << "\nChangeStaffError\n\n";
	}

}

void AddEmployee()
{
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPassword = new std::string[userCount];
	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPassword[i] = passwordArr[i];
	}

	delete[]loginArr;
	delete[]passwordArr;
	userCount++;
	std::string* loginArr = new std::string[userCount];
	std::string* passwordArr = new std::string[userCount];
	for (int i = 0; i < userCount - 1; i++)
	{
		loginArr[i] = tempLogin[i];
		passwordArr[i] = tempPassword[i];

	}

	std::string newLogin, newPass;
	std::cout << "Введите логин нового сотрудника:";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "Введите пароль нового сотрудника:";
	std::getline(std::cin, newLogin, '\n');

	loginArr[userCount - 1] = newLogin;
	passwordArr[userCount - 1] = newPass;
	delete[]tempLogin;
	delete[]tempPassword;
	//test
	for (int i = 0; i < userCount; i++)
	{
		std::cout << loginArr[i] << " " << passwordArr[i] << "\n";
	}
}





template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

template<typename ArrType>
void printArr(ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";
}