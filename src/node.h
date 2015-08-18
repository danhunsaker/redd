// -*- mode: c; tab-width: 4; indent-tabs-mode: 1; st-rulers: [70] -*-
// vim: ts=8 sw=8 ft=c noet
/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2013 Pagoda Box, Inc.  All rights reserved.
 */

#ifndef VTEPD_NODE_H
#define VTEPD_NODE_H

#include <netinet/in.h>
#include <msgpack.h>

typedef struct vtep_node_s {
	char 				*hostname;
	struct sockaddr_in	send_addr;
} vtep_node_t;

void		*dup_node(void *ptr);
void		free_node(void *ptr);
int			match_node(void *ptr, void *key);

void		pack_node(msgpack_packer *packer, vtep_node_t *node);
void		pack_nodes(msgpack_packer *packer);
vtep_node_t	*unpack_node(msgpack_object object);
void		unpack_nodes(msgpack_object object);
int			validate_node(vtep_node_t *node);

void		save_nodes();
void		load_nodes();

void		add_vtep_node(vtep_node_t *node);
void		remove_vtep_node(vtep_node_t *key);

#endif
