#ifndef _BTREE_TEST_H_
#define _BTREE_TEST_H_

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int Element;

typedef struct BTreeNode {
	Element e;
	BTreeNode *left;
	BTreeNode *right;
} BTreeNode;

typedef struct BTree {
	BTreeNode *root;
	unsigned int count;
} BTree;

typedef BTreeNode *BTreeNodePtr;

typedef BTree *BTreePtr;

#ifdef __cplusplus
}
#endif

#endif /* _BTREE_TEST_H_ */
