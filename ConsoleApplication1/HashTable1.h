//#pragma once
//
//#ifndef HashTable_H
//
//template<class T>
//class HashTable1
//{
//private:
//	T* arr;
//
//	// процент заполненности массива
//	float Capacity()
//	{
//		// нахожу коэффецент
//		float coefficient = (float)base_size / (float)quantityElem;
//		// нахожу заполненый объем массива
//		float capacity = 100.0f / coefficient;
//
//		return capacity;
//	}
//
//	void Resize()
//	{
//		// значение старого массива
//		int old_size = base_size;
//		// увеличиваю в 2
//		base_size *= 2;
//
//		// передаю указатель на старый массив
//		T* old_array = arr;
//		// новый массив в 2 раза больше
//		arr = new int[base_size];
//
//		for (int i = 0; old_size; i++)
//		{
//			//Add(// элемент массива);
//		}
//	}
//
//public:
//	int base_size = 8;
//	int quantityElem = 0;
//
//	float capacity_for_change = 0.75f;
//
//	HashTable()
//	{
//		arr = new T[base_size];
//	}
//
//	// представлю пока через int
//	void Add(T key, T item)
//	{
//		// пора увеличивать размер
//		if (Capacity() >= capacity_for_change)
//		{
//			Resize();
//		}
//
//
//	}
//
//	struct Node
//	{
//		// узнаю удален ли элемент
//		bool is_deleted = false;
//
//		// элемент
//		T elem;
//	};
//
//
//
//	~HashTable()
//	{
//		delete[] arr;
//	}
//};
//#endif // !

