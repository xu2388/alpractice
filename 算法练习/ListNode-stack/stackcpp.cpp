#include<iostream>
#include<stdexcept>

class LinkedlistStack
{
private:
	struct Node
	{
		int date;
		Node* next;
		Node(const int val):date(val),next(nullptr) {}//成员初始化列表的效率更高
	};
	Node* topNode;
public:
	LinkedlistStack():topNode(nullptr) {}
	/*~LinkedlistStack()
	{
		clear();
	}*/
	//判断栈为空(这个思想确实值得学习，你都看bool函数多少遍了还没记住）
	bool empty()const
	{
		return topNode == nullptr;
	}

	//入栈操作
	void push(const int& val)
	{
		Node* newNode = new Node(val);
		newNode->date = val;
		newNode->next = topNode;
		topNode = newNode;
		//topNode->next = newNode->next;
	}
	//出栈操作
    int  pop()
	{
		if (empty())
		{
			throw std::underflow_error("Stack empty");
		}

		int save = topNode->date;
		//创建临时的节点temp指向栈顶节点，当替罪羊
		Node* temp = topNode;
		//把栈顶节点移开
		topNode = topNode->next;
		//释放内存
		delete temp;
		return save;
	}



	//获取栈顶元素
	int gettop() const
	{
		if (empty())
		{
			throw std::underflow_error("Stack empty!");
		}
		return topNode->date;
	}
	

	//清空栈操作
	void clear()
	{
		while (!empty())
		{
			pop();
		}
	}

	//获取栈的大小
	int query_size() const
	{
		int count = 0;
		//Node* temp = topNode;
		if (empty())
		{
			return count;
		}
		Node* temp = topNode;
		//如果栈为空，不进去while循环直接返回count = 0;
		//直接初始化就行了
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
	std::cout << "栈顶元素为 ： " << stack.gettop() << std::endl;

	std::cout << "栈的大小为 ： " << stack.query_size() << std::endl;
	
	stack.pop();
	std::cout << "栈顶元素为 ： " << stack.gettop() << std::endl;

	std::cout << "栈的大小为 ： " << stack.query_size() << std::endl;


	system("pause");
	return 0;

}