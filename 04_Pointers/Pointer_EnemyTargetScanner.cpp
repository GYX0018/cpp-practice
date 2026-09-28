/*
 Coding Challenge：Enemy Target Scanner
 你有一组敌人的 HP：
 int enemyHP[]{ 100, 75, 0, 40, 120 };

 你要写一个简易的 Enemy Target Scanner，程序能够：
- 用 pointer 遍历数组
- 找到第一个还活着的敌人
- 返回它的 address
- 通过 pointer 修改 HP
- 正确处理 nullptr
- 使用 pointer to const
- 使用 const pointer
- 用 pass by address 修改数据

最终你会用到你列出的全部知识：
address
pointer
dereference
&
*
nullptr
pointer to const
const pointer
pass by address
array-pointer relationship
*/

#include <iostream>	

const int* findStrongestEnemy(const int* array, int size);

void takeDamage(int* hpPtr, int damage)
{
	if (!hpPtr)
	{
		std::cout << "Invalid Input\n";
		return;
	}
	
	
	*hpPtr -= damage;

	if (*hpPtr <= 0)
	{
		*hpPtr = 0;
	}

		
}

void printHP(const int* hpPtr)
{
	if (!hpPtr)
	{
		std::cout << "Invalid Input\n";
		return;
	}
	else
	{
		//*hpPtr = 50;
		std::cout << *hpPtr << '\n';
	}
}

// 数组在大多数表达式中会 decay 成指向第一个元素的 pointer。
//注意这里的size，指的是地址的位置往后急啊多少个数；和本身的值没有关系
int* findEnemy(int* array, int size)
{
	if (!array || size <= 0)
	{
		return nullptr;
	}
	
	int* end = array + size;

	for (array;array < end;array++)
	{
		if (*array > 0)
		{
			return array;
		}
	}
	return nullptr;
}

int main()
{
	int enemyHP{ 100 };

	int* enemyHpPtr{ &enemyHP };

	std::cout << enemyHP <<'\n';
	std::cout << &enemyHP << '\n';
	std::cout << enemyHpPtr << '\n';
	std::cout << *enemyHpPtr << '\n';

	*enemyHpPtr = 60;

	std::cout << enemyHP << '\n';

	//int* target{ nullptr };

	/*if (!target)
	{
		std::cout << "No target\n";
	}
	else
	{
		target = &enemyHP;
		std::cout << *target << '\n';
	}
	*/

	int hp{ 100 };

	takeDamage(&hp, 30);
	std::cout << hp << '\n';

	takeDamage(&hp, 200);
	std::cout << hp << '\n';

	takeDamage(nullptr, 30);
	std::cout << hp << '\n';

	printHP(&hp);

	int enemyA{ 100 };
	int enemyB{ 200 };

	int* const enemyAptr{ &enemyA };

	*enemyAptr = 50;
	//enemyAptr = &enemyB;

	int enemyHParray[]{ 100, 75, 0, 40, 120 };

	int arrayNumber =  sizeof(enemyHParray) / sizeof(enemyHParray[0]);
	
	//int* arrayPtr{ &enemyHParray[0] };

	for (int* arrayPtr = &enemyHParray[0] ; arrayPtr < enemyHParray + arrayNumber;arrayPtr++)
	{
		std::cout << *arrayPtr << '\n';
	}

	/*
	for (int i = 0; i < arrayNumber; i++)
	{
		std::cout << *(arrayPtr + i) << '\n';
	}
	*/

	
	int* target{ findEnemy(enemyHParray,arrayNumber) };

	if (target)
	{
		std::cout << "Enemy Found: " << *target << '\n';
		*target = 10;
	}
	else
	{
		std::cout << "No Enemy Found!\n";
	}

	std::cout << enemyHParray[0] << '\n';

	const int* strongest{findStrongestEnemy(enemyHParray, arrayNumber)};

	if (strongest)
	{
		std::cout << *strongest << '\n';
	}

	


	return 0;
}

const int* findStrongestEnemy(const int* array, int size)
{
	if (!array || size <= 0)
	{
		return nullptr;
	}

	const int* end = array + size;
	const int* strongest = array;

	for (; array < end; array++)
	{
		if (*array > *strongest)
		{
			strongest = array;
			
		}
	}
	return strongest;
}