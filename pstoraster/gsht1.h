/* Copyright (C) 1994, 1997 Aladdin Enterprises.  All rights reserved.
  
  This file is part of GNU Ghostscript.
  
  GNU Ghostscript is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility
  to anyone for the consequences of using it or for whether it serves any
  particular purpose or works at all, unless he says so in writing.  Refer
  to the GNU General Public License for full details.
  
  Everyone is granted permission to copy, modify and redistribute GNU
  Ghostscript, but only under the conditions described in the GNU General
  Public License.  A copy of this license is supposed to have been given
  to you along with GNU Ghostscript so you can know your rights and
  responsibilities.  It should be in a file named COPYING.  Among other
  things, the copyright notice and this notice must be preserved on all
  copies.
  
  Aladdin Enterprises supports the work of the GNU Project, but is not
  affiliated with the Free Software Foundation or the GNU Project.  GNU
  Ghostscript, as distributed by Aladdin Enterprises, does not require any
  GNU software to build or run it.
*/

/*$Id: gsht1.h,v 1.2 2000/03/08 23:14:42 mike Exp $ */
/* Extended public interface to halftones */

#ifndef gsht1_INCLUDED
#  define gsht1_INCLUDED

#include "gsht.h"

/* Procedural interface */
int gs_setcolorscreen(P2(gs_state *, gs_colorscreen_halftone *));
int gs_currentcolorscreen(P2(gs_state *, gs_colorscreen_halftone *));

/*
 * We include sethalftone here, even though it is a Level 2 feature,
 * because it turns out to be convenient to define setcolorscreen
 * using sethalftone.
 */
#ifndef gs_halftone_DEFINED
#  define gs_halftone_DEFINED
typedef struct gs_halftone_s gs_halftone;

#endif
/*
 * gs_halftone structures may have complex substructures.  We provide two
 * procedures for setting them.  gs_halftone assumes that the gs_halftone
 * structure and all its substructures was allocated with the same allocator
 * as the gs_state; gs_halftone_allocated looks in the structure itself (the
 * rc.memory member) to find the allocator that was used.  Both procedures
 * copy the top-level structure (using the appropriate allocator), but take
 * ownership of the substructures.
 */
int gs_sethalftone(P2(gs_state *, gs_halftone *));
int gs_sethalftone_allocated(P2(gs_state *, gs_halftone *));
int gs_currenthalftone(P2(gs_state *, gs_halftone *));

#endif /* gsht1_INCLUDED */
