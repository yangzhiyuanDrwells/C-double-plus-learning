#include <iostream>
#include <assert.h>
using namespace std;

template<typename Type>
class BSTree;

template<typename Type>
class BSTNode
{
	friend class BSTree<Type>;
public:
	BSTNode(Type d = Type(), BSTNode<Type>* left = nullptr, BSTNode<Type>* right = nullptr)
		: data(d), LeftChild(left), RightChild(right)
	{

	}
private:
	Type data;
	BSTNode<Type>* LeftChild;
	BSTNode<Type>* RightChild;
};

#if 1
template<typename Type>
class BSTree
{
public:
	BSTree() : root(nullptr)
	{}
	BSTree(Type ar[], int n) : root(nullptr)
	{
		for (int i = 0; i < n; ++i)
		{
			Insert(ar[i]);
		}
	}
	~BSTree()
	{
		Clear();
	}
public:
	bool Insert(const Type &key);
	bool Remove(const Type &key);
	void Order()const;
	BSTNode<Type>* Find(const Type &key);
	Type Max()const;
	Type Min()const;
	void Clear();  //�黹�ڶ��Ͽ��ٵ�����������
protected:
	//���������������ĵݹ鷽��
#if 0
	bool Insert(BSTNode<Type>* &root, const Type& key)
	{
		if (root == nullptr)
		{
			root = new BSTNode<Type>(key);  //
			return true;
		}
		else if (key < root->data)
			return Insert(root->LeftChild, key);
		else if (key > root->data)
			return Insert(root->RightChild, key);
		else
			return false;
	}
#endif
	//���������������ķǵݹ鷽��
#if 1
	bool Insert(BSTNode<Type>*& root, const Type& key)
	{
		BSTNode<Type>* p = root;
		BSTNode<Type>* pr = nullptr;
		//�ҵ�Ҫ�����λ��
		while (p != nullptr)
		{
			pr = p;
			if (key < p->data)
				p = p->LeftChild;
			else if (key > p->data)
				p = p->RightChild;
			else
				return false;
		}
		p = new BSTNode<Type>(key);
		if (pr == nullptr) 
		{
			root = p;
			return true;
		}
		//���ӽ��
		if (key < pr->data)
			pr->LeftChild = p;
		else
			pr->RightChild = p;
		return true;
	}
#endif
	bool Remove(BSTNode<Type>*& root, const Type& key)
	{
		if (root == nullptr)
			return nullptr;
		else if(root->LeftChild == nullptr && root->RightChild == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if (root->LeftChild != nullptr && root->RightChild == nullptr
			|| root->LeftChild == nullptr && root->RightChild != nullptr )
		{
			BSTNode<Type>* p = root;
			root = (root->LeftChild != nullptr) ? root->LeftChild : root->RightChild;
			delete p;
		}
		else
		{
			BSTNode<Type>* p = root->LeftChild;
			//�ҵ������������ؼ�ֵ�Ľ��
			while (p->RightChild != nullptr)
				p = p->RightChild;
			//��������ֵ�滻�����������ؼ�ֵ����ֵ
			root->data = p->data;
			//ɾ�������������ؼ�ֵ�Ľ��
			Remove(root->LeftChild, p->data);
		}
	}
	void Order(BSTNode<Type>* root)const
	{
		if (root != nullptr)
		{
			Order(root->LeftChild);
			cout << root->data << " ";
			Order(root->RightChild);
		}
	}
	BSTNode<Type>* Find(BSTNode<Type>* root, const Type& key)
	{
		if (root == nullptr)
			return nullptr;
		else if (key == root->data)
			return root;
		else if (key < root->data)
			return Find(root->LeftChild, key);
		else
			return Find(root->RightChild, key);
	}
	Type Max(BSTNode<Type>* root)const
	{
		assert(root != nullptr);
		while (root->RightChild != nullptr)
			root = root->RightChild;
		return root->data;
	}
	Type Min(BSTNode<Type>* root)const
	{
		assert(root != nullptr);
		while (root->LeftChild != nullptr)
			root = root->LeftChild;
		return root->data;
	}
	void Clear(BSTNode<Type>* root)
	{
		if (root != nullptr)
		{
			Clear(root->LeftChild);
			Clear(root->RightChild);
			delete root;
			root = nullptr;
		}
	}
private:
	BSTNode<Type>* root;
};

template<typename Type>
bool BSTree<Type>::Insert(const Type& key)
{
	return Insert(root, key);
}
template<typename Type>
bool BSTree<Type>::Remove(const Type& key)
{
	return Remove(root, key);
}
template<typename Type>
void BSTree<Type>::Order()const
{
	Order(root);
}
template<typename Type>
BSTNode<Type>* BSTree<Type>::Find(const Type& key)
{
	return Find(root, key);
}
template<typename Type>
Type BSTree<Type>::Max()const
{
	return Max(root);
}
template<typename Type>
Type BSTree<Type>::Min()const
{
	return Min(root);
}
template<typename Type>
void BSTree<Type>::Clear()
{
	Clear(root);
}


int main()
{
	BSTree<int> bst;
	int ar[] = { 5,3,4,1,7,8,2,6,0,9 };
	int n = sizeof(ar) / sizeof(int);
	
	//���뷽��
	for (int i = 0; i < n; ++i)
	{
		bst.Insert(ar[i]);
	}

	//�����˹��췽��֮������ڹ����ͬʱ����
	BSTree<int> bst1(ar, n);


	//�������
	bst.Order();

	//����
	BSTNode<int>* res = bst.Find(3);
	if (res != nullptr)
		printf("�ҵ���3,��ַΪ%p\n", res);
	else
		printf("û���ҵ�3\n");

	cout << "���ֵ" << bst.Max() << endl;
	cout << "��Сֵ" << bst.Min() << endl;
	return 0;

}
#endif



