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

#ifndef __OASS_ALG_H__
#define __OASS_ALG_H__

#include <oss_common.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct oss_btree_node_s {
	oss_element data;
	struct oss_btree_node_s *left;
	struct oss_btree_node_s *right;
} oss_btree_node_t;

typedef struct oss_btree {
	oss_btree_node_t *root;
	oss_uint32 count;
} oss_btree;

typedef oss_btree_node_t *oss_btree_node_ptr;

typedef oss_btree *oss_btree_ptr;

#ifdef __cplusplus
}
#endif

#endif /* __OASS_ALG_H__ */
