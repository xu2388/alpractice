#include<iostream>
#include<vector>
int simpleHash(int key, int tableSize)
{
	return key % tableSize;
}
class SimpleHashTable
{

private :
	std::vector<int> table;
	int tableSize;
public:
	SimpleHashTable(int size) : tableSize(size)
	{
		table.resize(tableSize, -1);
	}

	//�������,ʹ�ù�ϣ����ӳ��
	void insert(int key)
	{
		int index = simpleHash(key, tableSize);
		table[index] = key;
	}
	
	//��ϣ�����
	void printhash()
	{
		for (int i = 0; i < tableSize; i++)
		{
			std::cout << "Index" << i << ":" << table[i] << std::endl;
		}
	}
	//��ϣ��Ĳ���
	
};
int main(void)
{










	system("pause");
	return 0;
}