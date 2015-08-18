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

#ifndef VTEPD_HELPER_H
#define VTEPD_HELPER_H

#include <msgpack.h>
#include <stdint.h>
#include <uv.h>

typedef void (*save_data_function)(msgpack_packer *packer);
typedef void (*load_data_function)(msgpack_object object);


// helper functions
void	msgpack_pack_key_value(msgpack_packer *packer, char *key, 
			int key_len, char *value, int value_len);

char	*parse_ip_address(char *ip_address_string, int size);
char	*parse_host(char *host_string, int len);

int		validate_ip_address(char *ip_address);
int		validate_host(char *host);

char	*blank_ip_address();
char	*blank_host();

char	*pack_ip_address(char *ip_address);
char	*pack_host(char *host);

void	ngx_empty_into(ngx_queue_t *from,ngx_queue_t *to,int limit);

void	save_data(char *filename, save_data_function pack_function);
void	load_data(char *filename, load_data_function unpack_funciton);

#endif
