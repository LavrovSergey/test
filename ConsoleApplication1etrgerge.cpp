#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<map>
#include <conio.h>
#include "windows.h"
using namespace std;
template<class T, class U> class BinarySearchTree;
template< class T, class U>
class Node {
	friend class BinarySearchTree<T, Node<T, U>>;
public:
	Node<T, U>* left=NULL;
	Node<T, U>* right = NULL;
	U* data;
	/*std::vector<T> v;
	int id = 0;
	bool way;*/
};
template<class T>
class Part1 {
public:
	T data;
	std::vector<T> v;
	int id = 0;
	bool way;
};
template<class T, class U>
class BinarySearchTree
{
public:
	int d = 1;
	Node<T, U>* root;
	/*! Constructer. Root = 0.*/
	BinarySearchTree()
	{
		root = NULL;
	}
	/*! Find the smallest value of the tree to rebuild after deletion.*/
	U* Find_smallest()
	{
		return Find_smallestPrivate(root);
	}

	/*!Creating a Part1.*/
	void creat_leaf(T e, bool way1) {
		U* cur = new U;
		cur->data=e;
		cur->way = way1;
		cur->id = d++;
		AddLeaf(cur, root);
	};
	/*! Adding a Part1.*/
	void AddLeaf(U* cur, Node<T, U>* node) {
		if (root == NULL)
		{
			root = new Node<T, U>;
			root->data = cur;
		}
		else if (cur->data <= node->data->data)
		{
			if (node->left != NULL)
			{
				AddLeaf(cur, node->left);
			}
			else
			{
				node->left =new Node<T, U>;
				node->left->data = cur;
				cur->way = 0;
			}
		}
		else if (cur->data > node->data->data)
		{
			if (node->right != NULL)
			{
				AddLeaf(cur, node->right);
			}
			else
			{
				node->right = new Node<T, U>;
				node->right->data = cur;
				cur->way = 1;
			}
		}
	}
	/*! Ствоюємо вузол для вектора.*/
	//void creat_leaf_v(std::vector<T> vv, bool way1) {
	//	U* cur = new U;
	//	cur->v = vv;
	//	cur->way = way1;
	//	cur->left = NULL;
	//	cur->right = NULL;
	//	cur->id = d++;
	//	AddLeaf_v(cur, root);
	//};
	/*! Deleting the Part1.*/
//	void RemoveNode(U* p, U* parent, int a)
//	{
//		if (root != NULL)
//		{
//			if (root == p)
//			{
//				RemoveRoot(a);
//			}
//			else
//			{
//				if (p->data <= parent->data && parent->left != NULL)
//				{
//					parent->left == p ?
//						RemoveMatch(parent, parent->left, true, a) :
//						RemoveNode(p, parent->left, a);
//				}
//				else if (p->data > parent->data && parent->right != NULL)
//				{
//					parent->right == p ?
//						RemoveMatch(parent, parent->right, false, a) :
//						RemoveNode(p, parent->right, a);
//				}
//			}
//		}
//	}
//	/*! Видалення вузла вектора.*/
//	void RemoveNode_vect(U* p, U* parent, int a)
//	{
//		if (root != NULL)
//		{
//			if (root == p)
//			{
//				RemoveRoot(a);
//			}
//			else
//			{
//				if (p->v[0] <= parent->data && parent->left != NULL)
//				{
//					parent->left == p ?
//						RemoveMatch_vect(parent, parent->left, true, a) :
//						RemoveNode_vect(p, parent->left, a);
//				}
//				else if (p->v[0] > parent->data && parent->right != NULL)
//				{
//					parent->right == p ?
//						RemoveMatch_vect(parent, parent->right, false, a) :
//						RemoveNode_vect(p, parent->right, a);
//				}
//			}
//		}
//	}
//private:
//
//	void AddLeaf_v(U* cur, U* node) {
//		if (root == NULL)
//		{
//			root = cur;
//		}
//		else if (cur->v[0] <= node->v[0])
//		{
//			if (node->left != NULL)
//			{
//				AddLeaf_v(cur, node->left);
//			}
//			else
//			{
//				node->left = cur;
//				cur->way = 0;
//			}
//		}
//		else if (cur->v[0] > node->v[0])
//		{
//			if (node->right != NULL)
//			{
//				AddLeaf_v(cur, node->right);
//			}
//			else
//			{
//				node->right = cur;
//				cur->way = 1;
//			}
//		}
//	}
//	U* Find_smallestPrivate(U* node)
//	{
//		if (node->left != NULL)
//		{
//			return Find_smallestPrivate(node->left);
//		}
//		else { return node; };
//	}
//	/*! Deleting the root.*/
//	void RemoveRoot(int a) {
//		U* delPtr = root;
//		if (root->left == NULL && root->right == NULL)
//		{
//			root = NULL;
//
//		}
//		else if (root->left == NULL && root->right != NULL)
//		{
//			root = root->right;
//			delPtr->right = NULL;
//
//		}
//		else if (root->left != NULL && root->right == NULL)
//		{
//			root = root->left;
//			delPtr->left = NULL;
//
//		}
//		else
//		{
//			U* p = Find_smallest();
//			RemoveNode(p, root, a);
//			root->data = p->data;
//		}
//	}
//	/*! Delete the node that was found before.*/
//	void RemoveMatch(U* parent, U* match, bool left, int a) {
//
//		if (match->left == NULL && match->right == NULL)
//		{
//			left == true ? parent->left = NULL : parent->right = NULL;
//		}
//		else if (match->left == NULL && match->right != NULL && a == 1)
//		{
//			left == true ? parent->left = match->right : parent->right = match->right;
//			match->right = NULL;
//		}
//		else if (match->left != NULL && match->right == NULL && a == 1)
//		{
//			left == true ? parent->left = match->left : parent->right = match->left;
//			match->left = NULL;
//		}
//		else if (a == 2)
//		{
//			if (parent->left == match) { parent->left = NULL; }
//			else(parent->right = NULL);
//		}
//		else
//		{
//			U* p = Find_smallestPrivate(match->right);
//			RemoveNode(p, match, a);
//			match->data = p->data;
//		}
//	}
//	void RemoveRoot_vect(int a) {
//		U* delPtr = root;
//		if (root->left == NULL && root->right == NULL)
//		{
//			root = NULL;
//
//		}
//		else if (root->left == NULL && root->right != NULL)
//		{
//			root = root->right;
//			delPtr->right = NULL;
//
//		}
//		else if (root->left != NULL && root->right == NULL)
//		{
//			root = root->left;
//			delPtr->left = NULL;
//
//		}
//		else
//		{
//			U* p = Find_smallest();
//			RemoveNode_vect(p, root);
//			root->v.resize(p->v.size());
//			for (int i = 0; i < root->v.size(); i++) {
//				root->v[i] = p->v[i];
//			}
//		}
//	}
//	void RemoveMatch_vect(U* parent, U* match, bool left, int a) {
//
//		if (match->left == NULL && match->right == NULL)
//		{
//			left == true ? parent->left = NULL : parent->right = NULL;
//		}
//		else if (match->left == NULL && match->right != NULL && a == 1)
//		{
//			left == true ? parent->left = match->right : parent->right = match->right;
//			match->right = NULL;
//		}
//		else if (match->left != NULL && match->right == NULL && a == 1)
//		{
//			left == true ? parent->left = match->left : parent->right = match->left;
//			match->left = NULL;
//		}
//		else if (a == 2) {
//			if (parent->left == match) { parent->left = NULL; }
//			else(parent->right = NULL);
//		}
//		else
//		{
//			U* p = Find_smallestPrivate(match->right);
//			RemoveNode(p, match, a);
//			match->v.resize(p->v.size());
//			for (int i = 0; i < root->v.size(); i++) {
//				match->v[i] = p->v[i];
//			}
//		}
//	}
};

template <class T, class U>
class Functions : public BinarySearchTree<T, U>, Node<T, U>
{
public:
	friend class Node<T, U>;
	/*! Search by the way.*/
	//void FindByTheWay(int a) {
	//	bool count = false, i = 0;
	//	int n;
	//	cout << "Введите длину маршрута" << endl;
	//	cin >> n;
	//	bool* mas = new bool[n];
	//	cout << "Заполните маршрут" << endl;
	//	for (int j = 0; j < n; j++) {
	//		cin >> mas[j];
	//	}
	//	if (a == 1) {
	//		if (FindByTheWayPrivate1(mas, BinarySearchTree<T, U>::root, count, i, n) == 0)
	//		{
	//			cout << "Такого нема";
	//		}
	//	}
	//	
	//	delete[]mas;
	//	system("pause");
	//}
	///*! All ways to delete.*/
	//void Delete(int a, int b)
	//{
	//	if (b == 1) {
	//		T inf;
	//		cout << "Введите, что хотите удалить" << endl;
	//		cin >> inf;
	//		if (a == 1)
	//		{
	//			U* ptr = FindPrivate1(inf, BinarySearchTree<T, U>::root);
	//			if (ptr == NULL) { cout << "Такого нема" << endl; }
	//			else  (BinarySearchTree<T, U>::RemoveNode(ptr, BinarySearchTree<T, U>::root, 1));
	//		}
	//		
	//	}
	//	else if (b == 2) {
	//		PrintPreOrder(a);
	//		int id;
	//		cout << "Введите id" << endl;
	//		cin >> id;
	//		if (a == 1)
	//		{
	//			U* ptr = FindPrivateId1(id, BinarySearchTree<T, U>::root);
	//			if (ptr == NULL) { cout << "Такого нема" << endl; }
	//			else  (BinarySearchTree<T, U>::RemoveNode(ptr, BinarySearchTree<T, U>::root, 1));
	//		}
	//		
	//	}
	//	else if (b == 3)
	//	{
	//		PrintPreOrder(a);
	//		int id;
	//		cout << "Введите id отца" << endl;
	//		cin >> id;
	//		if (a == 1)
	//		{
	//			U* ptr = FindPrivateId1(id, BinarySearchTree<T, U>::root);
	//			if (ptr == NULL) { cout << "Такого нема" << endl; }
	//			else  (BinarySearchTree<T, U>::RemoveNode(ptr, BinarySearchTree<T, U>::root, 2));
	//		}
	//		
	//	}
	//}
	/*! Adding a node.*/
	void AddLeaf(int a) {
		T inf;
		cout << "Введите информацию" << endl;
		cin >> inf;
		if (a == 1) { BinarySearchTree<T, U>::creat_leaf(inf, 0); }
	}
	/*! Search by the information.*/
	//void Find(int a) {
	//	T inf;
	//	cout << "Введите, что хотите найти" << endl;
	//	cin >> inf;
	//	if (a == 1)
	//	{
	//		Node* ptr = FindPrivate1(inf, BinarySearchTree<T, U>::root);
	//		if (ptr == NULL) { cout << "Такого нема" << endl; }
	//		else(cout << ptr->data.id << ". " << ptr->data << endl);
	//		system("pause");
	//	}
	//}
	/*! Print.*/
	void PrintInOrder(int a) {
		if (a == 1) { PrintInOrderPrivate1(BinarySearchTree<T, U>::root); }
		system("pause");
	}
	///*! Print.*/
	///*! Print.*/
	//void PrintPostOrder(int a) {
	//	if (a == 1) { PrintPostOrderPrivate1(BinarySearchTree<T, U>::root); }
	//	system("pause");
	//}
	///*! Print.*/
	///*! Print.*/
	//void PrintPreOrder(int a) {
	//	if (a == 1) { PrintPreOrderPrivate1(BinarySearchTree<T, U>::root); }
	//	system("pause");
	//}
	///*! Print.*/

private:
	/*bool FindByTheWayPrivate1(bool* mas, U* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate1(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate1(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}*/
	void PrintInOrderPrivate1(Node<T,U>* node)
	{
		if (BinarySearchTree<T, U>::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1(node->left);
			}
			cout << node->data->id << ". ";
			cout << node->data->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	/*void PrintPreOrderPrivate1(U* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate1(U* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate1(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	Node* FindPrivate1(T e, U* node)
	{
		if (node != NULL)
		{
			if (node->data == e)
			{
				return node;
			}
			else
			{
				if (e <= node->data)
				{
					FindPrivate1(e, node->left);
				}
				else if (e > node->data)
				{
					FindPrivate1(e, node->right);
				}
			}
		}
		else { return node; }
	}
	U* FindPrivateId1(int id, U* node) {
		if (node == NULL) return node;
		if (id == node->id) {
			return node;
		}
		U* tmp1 = FindPrivateId1(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->id) { return tmp1; }
		}
		U* tmp2 = FindPrivateId1(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->id) { return tmp2; }
		}
	}*/
};

int menu_console() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 19) % 19;
		if (key == 0) cout << "-> Записать" << endl;
		else  cout << "   Записать" << endl;
		if (key == 1) cout << "-> Вывести InOrder" << endl;
		else  cout << "   Вывести InOrder" << endl;
		if (key == 2) cout << "-> Вывести PreOrder" << endl;
		else  cout << "   Вывести PreOrder" << endl;
		if (key == 3) cout << "-> Вывести PostOrder" << endl;
		else  cout << "   Вывести PostOrder " << endl;
		if (key == 4) cout << "-> Найти по пути" << endl;
		else  cout << "   Найти по пути" << endl;
		if (key == 5) cout << "-> Найти" << endl;
		else  cout << "   Найти" << endl;
		if (key == 6) cout << "-> Удалить по значению" << endl;
		else  cout << "   Удалить по значению" << endl;
		if (key == 7) cout << "-> Удалить по id" << endl;
		else  cout << "   Удалить по id" << endl;
		if (key == 8) cout << "-> Удалить по отцу" << endl;
		else  cout << "   Удалить по отцу" << endl;
		if (key == 9) cout << "-> Записать vector" << endl;
		else  cout << "   Записать vector" << endl;
		if (key == 10) cout << "-> Вывести InOrder vector" << endl;
		else  cout << "   Вывести InOrder vector" << endl;
		if (key == 11) cout << "-> Вывести PreOrder vector" << endl;
		else  cout << "   Вывести PreOrder vector" << endl;
		if (key == 12) cout << "-> Вывести PostOrder vector" << endl;
		else  cout << "   Вывести PostOrder vector" << endl;
		if (key == 13) cout << "-> Найти по пути vector " << endl;
		else  cout << "   Найти по пути vector" << endl;
		if (key == 14) cout << "-> Найти vector" << endl;
		else  cout << "   Найти vector" << endl;
		if (key == 15) cout << "-> Удалить vector по значению" << endl;
		else  cout << "   Удалить vector по значению" << endl;
		if (key == 16) cout << "-> Удалить vector по id" << endl;
		else  cout << "   Удалить int vector id" << endl;
		if (key == 17) cout << "-> Удалить vector по отцу" << endl;
		else  cout << "   Удалить vector по отцу" << endl;
		if (key == 18) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int menu1(bool isRunning, int a)
{
	Functions<int, Part1<int>> i;/*
	Functions<int, Node<int, Part1<int>>> i_v;*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_console();

		switch (answer)
		{
		case 0: i.AddLeaf(a); break;
		case 1: i.PrintInOrder(a); break;
	/*	case 2: i.PrintPreOrder(a); break;
		case 3: i.PrintPostOrder(a); break;
		case 4: i.FindByTheWay(a); break;
		case 5: i.Find(a); break;
		case 6: i.PrintInOrder(a); i.Delete(a, 1);  break;
		case 7: i.PrintInOrder(a); i.Delete(a, 2);  break;
		case 8: i.PrintInOrder(a); i.Delete(a, 3);  break;
		case 9: ; break;
		case 10: ; break;
		case 11: ; break;
		case 12:; break;
		case 13: i_v.FindByTheWay(a); break;
		case 14: ; break;
		case 15: ; break;
		case 16:; break;*/
		case 17: ; break;
		case 18: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}
	}
	return 0;
}
int menu_inf(int a) {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> INT" << endl;
		else  cout << "   INT" << endl;
		if (key == 1) cout << "-> DOUBLE" << endl;
		else  cout << "   DOUBLE" << endl;
		if (key == 2) cout << "-> STRING" << endl;
		else  cout << "   STRING" << endl;
		if (key == 3) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int main(bool isRunning, int a)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_inf(a);
		switch (answer)
		{
		case 0: menu1(true, 1); break;
		case 4: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}
