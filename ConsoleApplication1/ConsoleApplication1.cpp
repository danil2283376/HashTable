// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vld.h>
#include <cstdlib>

using namespace std;

// хэш функции для борьбы с коллизиями
int HashFunction1(int key, int size_table)
{
	return key % size_table;
}

int HashFunction2(int key, int size_table)
{
	return 1 + (key % (size_table - 2));
}

// индекс в хэш таблице
int IndexInHash(int key, int size_table, int i)
{
	return (HashFunction1(key, size_table) + (i * HashFunction2(key, size_table))) % size_table;
}

// заполненность массива
float CapacityArray(int size, int quantityElem)
{
	if (quantityElem == 0)
		return 0;

	// нахожу коэффецент
	float coefficient = (float)size / (float)quantityElem;
	// нахожу заполненный объем массива
	float capacity = 100.0f / coefficient;

	return capacity;
}

template<class T>
class HashTable 
{
private:

	struct Node
	{
	public:
		// узнаю удален ли элемент
		bool is_deleted = true;
		// пустая ячейка или нет
		bool free_cell = true;

		// ключ
		int key;
		// элемент
		T elem;
	};

	Node* arr;
	int base_size = 16;
	// процент заполненности массива

	// меняю размер
	void Resize()
	{
		// значение старого массива
		int old_size = base_size;
		// увеличиваю в 2
		base_size *= 2;

		// передаю указатель на старый массив
		Node* old_array = arr;
		// новый массив в 2 раза больше
		arr = new Node[base_size];

		for (int i = 0; i < old_size; i++)
		{
			////Add(// элемент массива);
			// если элемент не удален
			if (old_array[i].is_deleted == false)
			{
				int key = old_array[i].key;
				T item = old_array[i].elem;

				InputInHashTable(key, item);
			}
		}

		delete[] old_array;
	}

	void InputInHashTable(int key, T item) 
	{
		// свободна ли ячейка
		bool free_cell1 = false;

		int i = 0;
		// делаю пока не наткнусь на свободную ячейку
		while (free_cell1 == false)
		{
			int indexInHash = IndexInHash(key, base_size, i);

			cout << "Index in Hash: " << indexInHash << endl;

			if (arr[indexInHash].free_cell)
			{
				arr[indexInHash].elem = item;
				arr[indexInHash].key = key;
				// ячейка занята
				arr[indexInHash].free_cell = false;
				// элемент не удален
				arr[indexInHash].is_deleted = false;
				free_cell1 = true;
			}
			else
			{
				cout << "I = " << i;
				i++;
			}
		}
	}

public:
	int quantityElem = 0;

	float capacity_for_change = 60.0f;

	// базовый конструктор
	HashTable()
	{
		arr = new Node[base_size];
	}

	// 7 + (0 * 5)

	void Add(int key, T item)
	{
		// пора увеличивать размер
		cout << "array %: " << CapacityArray(base_size, quantityElem) << endl;

		if (CapacityArray(base_size, quantityElem) >= capacity_for_change)
		{
			cout << "Increase array!" << endl;
			Resize();
		}
		// ввод элементов в хэштаблицу
		InputInHashTable(key, item);

		// элемент добавлен
		quantityElem++;
	}

	bool ExistElem(int key) 
	{
		// предсказываю что элемента сразу нет
		bool exist = false;
		// индекс
		int i = 0;
		// если элемента нет то ищем его
		while (exist == false)
		{
			// формула
			int indexElem = IndexInHash(key, base_size, i);

			// ищем элемент по формуле
			if ((arr[indexElem].key == key) && (arr[indexElem].free_cell == false)) 
			{
				// элемент найден
				exist = true;
			}

			// если прошел по всем элементам и не нашел элемента по формуле
			// выходим и значит элемента нет
			if (i == base_size) 
			{
				break;
			}

			i++;
		}
		return exist;
	}

	void DeleteElem(int key) 
	{
		bool is_deleted = false;

		int i = 0;
		while (is_deleted == false)
		{
			int indexElem = IndexInHash(key, base_size, i);

			if ((arr[indexElem].key == key) && (arr[indexElem].is_deleted == false))
			{
				arr[indexElem].is_deleted = true;
				is_deleted = true;
			}

			if (i == base_size) 
			{
				cout << "Element is not find!" << endl;
			}
		}
	}

	void OutputHashTable() 
	{
		for (int i = 0; i < base_size; i++) 
		{
			cout << arr[i].elem << endl;
		}
	}

	~HashTable()
	{
		delete[] arr;
	}
};

int main()
{
	HashTable<int>* hash = new HashTable<int>();
	hash->Add(123, 41);
	hash->Add(145, 337);
	hash->Add(1123, 228);
	hash->Add(12345, 2412);
	hash->Add(1, 53213);
	hash->Add(4511, 532);
	hash->OutputHashTable();
	/*for (int i = 0; i < 20; i++) 
	{
		hash->Add(rand(), i + 1);
	}*/



	cout << endl << endl;
	cout << "Exist: " << hash->ExistElem(228);
	delete hash;
	cin.get();
}