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
 * Copyright (c) 2002-2003, Network Appliance, Inc. All rights reserved.
 */

/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*
 *
 * HEADER: dapl_mr_util.h
 *
 * PURPOSE: Utility defs & routines for memory registration functions
 *
 */

#ifndef _DAPL_MR_UTIL_H_
#define	_DAPL_MR_UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "dapl.h"
#include "dapl_hash.h"

/*
 *
 * Function Prototypes
 *
 */
extern DAT_VADDR
dapl_mr_get_address(IN DAT_REGION_DESCRIPTION desc, IN DAT_MEM_TYPE type);

extern DAT_BOOLEAN
dapl_mr_bounds_check(IN DAT_VADDR addr_a,
	IN DAT_VLEN length_a,
	IN DAT_VADDR addr_b, IN DAT_VLEN length_b);

#ifdef __cplusplus
}
#endif

#endif /* _DAPL_MR_UTIL_H_ */
