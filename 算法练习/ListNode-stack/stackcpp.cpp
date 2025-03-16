#include<iostream>
#include<stdexcept>

class LinkedlistStack
{
private:
	struct Node
	{
		int date;
		Node* next;
		Node(const int val):date(val),next(nullptr) {}//��Ա��ʼ���б��Ч�ʸ���
	};
	Node* topNode;
public:
	LinkedlistStack():topNode(nullptr) {}
	/*~LinkedlistStack()
	{
		clear();
	}*/
	//�ж�ջΪ��(���˼��ȷʵֵ��ѧϰ���㶼��bool�������ٱ��˻�û��ס��
	bool empty()const
	{
		return topNode == nullptr;
	}

	//��ջ����
	void push(const int& val)
	{
		Node* newNode = new Node(val);
		newNode->date = val;
		newNode->next = topNode;
		topNode = newNode;
		//topNode->next = newNode->next;
	}
	//��ջ����
    int  pop()
	{
		if (empty())
		{
			throw std::underflow_error("Stack empty");
		}

		int save = topNode->date;
		//������ʱ�Ľڵ�tempָ��ջ���ڵ㣬��������
		Node* temp = topNode;
		//��ջ���ڵ��ƿ�
		topNode = topNode->next;
		//�ͷ��ڴ�
		delete temp;
		return save;
	}



	//��ȡջ��Ԫ��
	int gettop() const
	{
		if (empty())
		{
			throw std::underflow_error("Stack empty!");
		}
		return topNode->date;
	}
	

	//���ջ����
	void clear()
	{
		while (!empty())
		{
			pop();
		}
	}

	//��ȡջ�Ĵ�С
	int query_size() const
	{
		int count = 0;
		//Node* temp = topNode;
		if (empty())
		{
			return count;
		}
		Node* temp = topNode;
		//���ջΪ�գ�����ȥwhileѭ��ֱ�ӷ���count = 0;
		//ֱ�ӳ�ʼ��������
		while (temp->next)
		{
			
			count++;
			temp = temp->next;
		}
		return count;
	}
};
int main(void)
{
	LinkedlistStack  stack;
	stack.push(1);
	stack.push(4);
	stack.push(8);
	std::cout << "ջ��Ԫ��Ϊ �� " << stack.gettop() << std::endl;

	std::cout << "ջ�Ĵ�СΪ �� " << stack.query_size() << std::endl;
	
	stack.pop();
	std::cout << "ջ��Ԫ��Ϊ �� " << stack.gettop() << std::endl;

	std::cout << "ջ�Ĵ�СΪ �� " << stack.query_size() << std::endl;


	system("pause");
	return 0;

}