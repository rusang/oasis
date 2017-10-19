/*
 * Copyright (c) 2017-2018 Roy Liao <royliao1026@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

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
