#
# Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
# Use is subject to license terms.
#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License, Version 1.0 only
# (the "License").  You may not use this file except in compliance
# with the License.
#
# You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
# or http://www.opensolaris.org/os/licensing.
# See the License for the specific language governing permissions
# and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file at usr/src/OPENSOLARIS.LICENSE.
# If applicable, add the following below this CDDL HEADER, with the
# fields enclosed by brackets "[]" replaced with your own identifying
# information: Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#
# ident	"%Z%%M%	%I%	%E% SMI"
#
# mkkey.awk
#
# XCurses Library
#
# Copyright 1990, 1995 by Mortice Kern Systems Inc.  All rights reserved.
#
# USAGE:
# 	awk -f mkkey.awk caps >keyindex.c
#
#  rcsid = $Header: /rd/src/libc/xcurses/rcs/mkkey.awk 1.1 1995/05/11 14:39:17 ant Exp $
#	

BEGIN {
print "/*"
print " * keyindex.c"
print " *"
print " * XCurses Library"
print " *"
print " * **** THIS FILE IS MACHINE GENERATED."
print " * **** DO NOT EDIT THIS FILE."
print " *"
print " * Copyright 1990, 1995 by Mortice Kern Systems Inc.  All rights reserved."
print " *"
print " */"
print ""
print "#if M_RCSID"
print "#ifndef lint"
printf "static char rcsID[] = \"$Header%s\";\n", "$"
print "#endif"
print "#endif"
print ""
print "#include <private.h>"
print ""
print "/*"
print " * This table is used to map a KEY_ constant to an"
print " * index for cur_term->_str[] for use by keyname()."
print " */"
print "short __m_keyindex[][2]= {"
	strcount = 0;
}

$4 == "str" {
	if ($1 ~ /^key_f[0-9][0-9]*/)
		printf("\t{ %d, KEY_F(%d) },\n", strcount, substr($1, 6, 2));
	else if ($1 ~ /^key_/)
		printf "\t{ %d, %s },\n", strcount, toupper($1);
	++strcount;
}

END {
	print "\t{ -1, -1 }"
	print "};"
}
