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
	LinkedList() :head(nullptr) {}//���캯����ʼ��ͷ�ڵ�Ϊ��
	//���뺯��
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
	//ɾ������1
	//  // ɾ��ֵΪ target �Ľڵ�
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
	//�޸�oldval��ֵΪnewval
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



		//����ֵΪtarget �Ľ���Ƿ����
		bool query(int target) {
			if (!head) return false; // ���������
			Listnode* temp = head;
			while (temp)
			{
				if (temp->val == target)
				{
					cout << "�ɹ���ѯ��" << target << endl;
					return true;
				}
				temp = temp->next;
			}
			cout << "δ��ѯ��" << endl;
			return false;
		}
		//��ӡ����������ֵ
		void shownval()
		{
			Listnode* temp = head;
			if (!head)
			{
				cout << "��Ǹ������Ϊ�գ��޷���ӡ" << endl;
				return;
			}
			while (temp)
			{
				cout << temp->val << " ";
				temp = temp->next;
			}
		}
		// �����������ͷ������ڴ�
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
	cout << "����������Ϊ ��" << " ";
	list.shownval();
	cout << endl;

	list.query(3);
	list.modifition(2, 6);
	cout << "�޸ĺ������Ϊ ��" << " ";
	list.shownval();
	cout << endl;


	list.remove(6);
	cout << "ɾ���������Ϊ ��" << " ";
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
		////ɾ������2
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
						cout << "�ɹ���ѯ��" << target;
						return true;
					}
					head = head->next;
					curr = curr->next;
				}
			}

		}*/