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
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */



#include "Handle.h"
#include "HBA.h"
#include "HBAPort.h"
#include "Exceptions.h"
#include "sun_fc.h"
#include "Trace.h"
#ifdef	__cplusplus
extern "C" {
#endif

/**
 * @depricated	    Use SendCTPassThruV2 instead.
 */
HBA_STATUS Sun_fcSendCTPassThru(HBA_HANDLE handle,
	    void *requestBuffer, HBA_UINT32 requestSize,
	    void *responseBuffer, HBA_UINT32 responseSize) {
	Trace log("Sun_fcSendCTPassThru");

	try {
	    Handle *myHandle = Handle::findHandle(handle);
	    HBA *hba = myHandle->getHBA();
	    HBAPort *port = hba->getPortByIndex(0);
	    uint64_t tmp = htonll(port->getPortWWN());
	    HBA_WWN wwn;
	    memcpy(wwn.wwn, &tmp, sizeof (wwn));
	    return (Sun_fcSendCTPassThruV2(handle,
		wwn, requestBuffer, requestSize,
		responseBuffer, &responseSize));
	} catch (HBAException &e) {
	    return (e.getErrorCode());
	} catch (...) {
	    log.internalError(
		"Uncaught exception");
	    return (HBA_STATUS_ERROR);
	}
}
#ifdef	__cplusplus
}
#endif
