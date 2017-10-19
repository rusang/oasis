#ifndef __OASS_ALG_H__
#define __OASS_ALG_H__

#include <oss_common.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct oss_btree_node {
	oss_element data;
	oss_btree_node *left;
	oss_btree_node *right;
} oss_btree_node;

typedef struct oss_btree {
	oss_btree_node *root;
	oss_uint32 count;
} oss_btree;

typedef oss_btree_node *oss_btree_node_ptr;

typedef oss_btree *oss_btree_ptr;

#ifdef __cplusplus
}
#endif

#endif /* __OASS_ALG_H__ */
