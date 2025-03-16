#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
struct Listnode
{
	int val;
	Listnode* next;
	Listnode(int x) : val(x), next(nullptr) {}
};

class LinkedList
{
private:
	Listnode* head;
public:
	LinkedList() :head(nullptr) {}//构造函数初始化头节点为空
	//插入函数
	void insert(int val)
	{
		Listnode* newnode = new Listnode(val);
		if (!head)
		{
			head = newnode;
			return;
		}
		Listnode* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
	//删除函数1
	//  // 删除值为 target 的节点
	void remove(int target) {
		if (!head) return;
		if (head->val == target) {
			Listnode* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Listnode* prev = head;
		Listnode* curr = head->next;
		while (curr) {
			if (curr->val == target) {
				prev->next = curr->next;
				delete curr;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	//修改oldval的值为newval
		void modifition(int OldVal,int NewVal)
		{
			if (!head)
			{
				return;
			}
		
			Listnode* temp = head;

			while (temp)
			{
				if (temp->val == OldVal)
				{
					temp->val = NewVal;
				}
				temp = temp->next;
			}
		}



		//查找值为target 的结点是否存在
		bool query(int target) {
			if (!head) return false; // 处理空链表
			Listnode* temp = head;
			while (temp)
			{
				if (temp->val == target)
				{
					cout << "成功查询到" << target << endl;
					return true;
				}
				temp = temp->next;
			}
			cout << "未查询到" << endl;
			return false;
		}
		//打印链表结点所有值
		void shownval()
		{
			Listnode* temp = head;
			if (!head)
			{
				cout << "抱歉，链表为空，无法打印" << endl;
				return;
			}
			while (temp)
			{
				cout << temp->val << " ";
				temp = temp->next;
			}
		}
		// 析构函数，释放链表内存
		~LinkedList() 
		{
			
			while (head) 
			{
				Listnode* temp = head;
				head = head->next;
				delete temp;
			}
		}


};


int main(void)
{

	LinkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	cout << "插入后的链表为 ：" << " ";
	list.shownval();
	cout << endl;

	list.query(3);
	list.modifition(2, 6);
	cout << "修改后的链表为 ：" << " ";
	list.shownval();
	cout << endl;


	list.remove(6);
	cout << "删除后的链表为 ：" << " ";
	list.shownval();
	cout << endl;

	system("pause");
	return 0;

}

//void removeal(int target)
		//{
		//	if (!head)
		//	{
		//		return;
		//	}
		//	if(head->val == target)
		//	{
		//		Listnode* temp = head;
		//		head = head->next;
		//		delete temp;
		//		return;
		//	}
		//}
		////删除函数2
		//void removal2(int target)
		//{
		//	Listnode* prev = head;
		//	Listnode* curr = prev->next;
		//	while (curr)
		//	{
		//		if (curr->val == target)
		//		{
		//			prev->next = curr->next;
		//			delete curr;
		//		}
		//		prev = curr;
		//		curr = curr->next;
		//	}
		//}\\







		/*bool query(int target)
		{
			Listnode* temp = head;
			Listnode* curr = head->next;
			if (!head)
			{
				return false;
			}
			if (head)
			{
				while (curr)
				{
					if (temp->val = target)
					{
						cout << "成功查询到" << target;
						return true;
					}
					head = head->next;
					curr = curr->next;
				}
			}

		}*/