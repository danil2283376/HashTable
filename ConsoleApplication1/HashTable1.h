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
//	// ������� ������������� �������
//	float Capacity()
//	{
//		// ������ ����������
//		float coefficient = (float)base_size / (float)quantityElem;
//		// ������ ���������� ����� �������
//		float capacity = 100.0f / coefficient;
//
//		return capacity;
//	}
//
//	void Resize()
//	{
//		// �������� ������� �������
//		int old_size = base_size;
//		// ���������� � 2
//		base_size *= 2;
//
//		// ������� ��������� �� ������ ������
//		T* old_array = arr;
//		// ����� ������ � 2 ���� ������
//		arr = new int[base_size];
//
//		for (int i = 0; old_size; i++)
//		{
//			//Add(// ������� �������);
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
//	// ���������� ���� ����� int
//	void Add(T key, T item)
//	{
//		// ���� ����������� ������
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
//		// ����� ������ �� �������
//		bool is_deleted = false;
//
//		// �������
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

