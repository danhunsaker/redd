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

#ifndef VTEPD_IP_H
#define VTEPD_IP_H

#include <msgpack.h>

typedef struct vtep_ip_s {
	char 				*ip_address;
} vtep_ip_t;

void		*dup_ip(void *ptr);
void		free_ip(void *ptr);
int			match_ip(void *ptr, void *key);

void		pack_ip(msgpack_packer *packer, vtep_ip_t *ip);
void		pack_ips(msgpack_packer *packer);
vtep_ip_t	*unpack_ip(msgpack_object object);
int			validate_ip(vtep_ip_t *ip);

void		save_ips();
void		load_ips();

int			add_vtep_ip(vtep_ip_t *ip);
int			remove_vtep_ip(vtep_ip_t *key);

#endif
