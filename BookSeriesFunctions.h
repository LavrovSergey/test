#pragma once
#include "Node.h"
#include "Hero.h"
#include "BinarySearchTree.h"
#include "HeroFunctions.h"
#include <iostream>
#include <fstream>
using namespace std;
/*! @param T -data type
* @param U -object.*/
/*! Function class for working with books.*/
template <class T, class U>
class BookSeriesFunctions
{
public:
	int id = 1;
	BinarySearchTree<T, U> bst;
	HeroFunctions<T, Hero> hf;
	void CreateTree(Node<Hero>* r) {
		void CreateTreePrivate(Node<Hero> * r);
	}
private:
	void CreateTreePrivate(Node<Hero>* node) {
		if (node != NULL)
		{
			BookSeries* bs = new BookSeries(node->data->GetBooks(), id);
				id++;
			bst.AddLeafDate(bs, bst.GetRoot);
			if (node->left != NULL)
			{
				CreateTreePrivate(node->left);
			}
			if (node->right != NULL)
			{
				CreateTreePrivate(node->right);
			}
		}
		else(cout << "Empty" << endl);
	}
};