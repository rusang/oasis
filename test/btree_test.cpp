#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include "btree_test.hpp"
using namespace std;

typedef int Position;

typedef struct BTreeNodeFile {
	Element e; //节点值
	Position p; //节点在完全二叉树中的位置
} BTreeNodeFile;

typedef map<int, BTreeNodePtr> NodeMap;

const char fileName[] = "btree.dat";

FILE *filePtr;

void writeNode(const BTreeNodePtr btn, Position p)
{
	if (!btn)
		return;

	BTreeNodeFile node;
	node.e = btn->e;
	node.p = p;
	//写入当前节点
	fwrite(&node, sizeof(node), 1, filePtr);
	//写入左子树
	writeNode(btn->left, 2 * p);
	//写入右子树
	writeNode(btn->right, 2 * p + 1);
}

void writeBTree(const BTreePtr bt)
{
	filePtr = fopen(fileName, "w");
	fwrite(&bt->count, sizeof(bt->count), (size_t) 1, filePtr); //写入节点个数
	writeNode(bt->root, 1); //写入节点
	fclose(filePtr);
}

BTreePtr readBTree()
{
	BTreePtr bt = new BTree;
	NodeMap mapNode;
	BTreeNodeFile btnf;
	BTreeNode *btn;
	filePtr = fopen(fileName, "r");
	fread(&(bt->count), sizeof(bt->count), 1, filePtr); //读入结点个数

	while (fread(&btnf, sizeof(btnf), (size_t) 1, filePtr) > 0) {
		btn = new BTreeNode;
		btn->e = btnf.e;
		mapNode.insert(NodeMap::value_type(btnf.p, btn));
	}

	NodeMap::iterator iter;
	NodeMap::iterator iter_t;

	for (iter = mapNode.begin(); iter != mapNode.end(); iter++) {
		iter_t = mapNode.find(2 * iter->first);

		if (iter_t != mapNode.end())   //找到左儿子
			iter->second->left = iter_t->second;
		else 	//未找到左儿子
			iter->second->left = NULL;

		iter_t = mapNode.find(2 * iter->first + 1);

		if (iter_t != mapNode.end())   //找到右儿子
			iter->second->right = iter_t->second;
		else 	//未找到右儿子
			iter->second->right = NULL;
	}

	iter_t = mapNode.find(1); //找root节点

	if (iter_t != mapNode.end())
		bt->root = iter_t->second;

	fclose(filePtr);
	return bt;
}

BTreePtr buildBTree()
{
	BTreePtr bt = new BTree;
	BTreeNodePtr btn = new BTreeNode[9];

	for (int i = 0; i < 9; i++) {
		memset(&btn[i], 0, sizeof(BTreeNode));
		btn[i].e = i;
	}

	btn[0].left = &btn[1];
	btn[1].left = &btn[3];
	btn[2].left = &btn[4];
	btn[5].left = &btn[7];
	btn[0].right = &btn[2];
	btn[2].right = &btn[5];
	btn[4].right = &btn[6];
	btn[5].right = &btn[8];
	bt->root = &btn[0];
	bt->count = 9;
	return bt;
}

void printSubBTree(BTreeNodePtr btn, int lvl)
{
	int i;

	if (!btn)
		return;

	for (i = 0; i < lvl; i++)
		printf("  ");

	printf("%d\n", btn->e + 1);
	printSubBTree(btn->left, lvl + 1);
	printSubBTree(btn->right, lvl + 1);
}

void printBTree(BTreePtr bt)
{
	printSubBTree(bt->root, 0);
}

int main()
{
	BTreePtr bt = buildBTree();
	printBTree(bt);
	writeBTree(bt);
	bt = readBTree();
	printBTree(bt);
	return 0;
}
