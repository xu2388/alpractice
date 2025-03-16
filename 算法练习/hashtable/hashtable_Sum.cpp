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

	//插入操作,使用哈希函数映射
	void insert(int key)
	{
		int index = simpleHash(key, tableSize);
		table[index] = key;
	}
	
	//哈希表呈现
	void printhash()
	{
		for (int i = 0; i < tableSize; i++)
		{
			std::cout << "Index" << i << ":" << table[i] << std::endl;
		}
	}
	//哈希表的插入
	
};
int main(void)
{










	system("pause");
	return 0;
}