//
// "Oxy theme" drawing routines for the Fast Light Tool Kit (FLTK).
//
// Copyright 2011 by Dmitrij K. e-mail: kdiman at live dot ru
//
// This library is free software. Distribution and use rights are outlined in
// the file "COPYING" which should have been included with this file.  If this
// file is missing or damaged, see the license at:
//
//     http://www.fltk.org/COPYING.php
//
// Please report all bugs and problems on the following page:
//
//     http://www.fltk.org/str.php
//

#ifndef fl_oxy_h
#define fl_oxy_h

#include <FL/Fl.H>

// to draw arrow, a - direction the arrow, ac - active widget?, c - color the arrow, hc - lighting the arrrow
extern FL_EXPORT void oxy_arrow(Fl_Rect bb, Fl_Arrow_Type t, Fl_Orientation o,
	       bool ac, Fl_Color c, Fl_Color hc = FL_BLACK);

#endif
