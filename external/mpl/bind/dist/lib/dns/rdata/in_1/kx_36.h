/*	$NetBSD: kx_36.h,v 1.7 2024/02/21 22:52:15 christos Exp $	*/

/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * SPDX-License-Identifier: MPL-2.0
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, you can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * See the COPYRIGHT file distributed with this work for additional
 * information regarding copyright ownership.
 */

#pragma once

/*!
 *  \brief Per RFC2230 */

typedef struct dns_rdata_in_kx {
	dns_rdatacommon_t common;
	isc_mem_t *mctx;
	uint16_t preference;
	dns_name_t exchange;
} dns_rdata_in_kx_t;