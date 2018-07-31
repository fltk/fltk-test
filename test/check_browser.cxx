//
// "$Id$"
//
// Fl_Check_Browser test program for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2018 by Bill Spitzak and others.
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

#include <FL/Fl.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Choice.H>
// #include <FL/Fl_Simple_Terminal.H>
#include <FL/fl_ask.H>

Fl_Check_Browser *browser;
Fl_Button	*top,
		*bottom,
		*middle,
		*visible,
		*swap,
		*sorta,
		*sortd;
Fl_Choice       *wtype;
Fl_Int_Input	*field;
// Fl_Simple_Terminal *tty = 0;

typedef struct {
  const char *name;
  Fl_When wvalue;
} WhenItem;

// FL_WHEN chooser..
WhenItem when_items[] = {
  { "FL_WHEN_NEVER",             FL_WHEN_NEVER },
  { "FL_WHEN_CHANGED",           FL_WHEN_CHANGED },
  { "FL_WHEN_NOT_CHANGED",       FL_WHEN_NOT_CHANGED },
  { "FL_WHEN_RELEASE",           FL_WHEN_RELEASE },
  { "FL_WHEN_RELEASE_ALWAYS",    FL_WHEN_RELEASE_ALWAYS },
  { "FL_WHEN_ENTER_KEY",         FL_WHEN_ENTER_KEY },
  { "FL_WHEN_ENTER_KEY_ALWAYS",  FL_WHEN_ENTER_KEY_ALWAYS },
  { "FL_WHEN_ENTER_KEY_CHANGED", FL_WHEN_ENTER_KEY_CHANGED },
  { "FL_WHEN_ENTER_KEY + FL_WHEN_RELEASE_ALWAYS",
				 Fl_When(int(FL_WHEN_ENTER_KEY_CHANGED)+int(FL_WHEN_RELEASE_ALWAYS)) }
  // TODO: Perhaps other FL_WHEN_* combos are relevant
};

void browser_cb(Fl_Widget* o, void*) {
  printf("callback, selection = \033[31m%d\033[0m, event_clicks = \033[32m%d\033[0m\n",
	 ((Fl_Check_Browser*)o)->value(), Fl::event_clicks());
}

void show_cb(Fl_Widget *o, void *) {
  // FIXME: make line x visible (see browser.cxx)
  printf("callback show_cb() not implemented\n");
  return;
#if 0
  int line = atoi(field->value());
  if (!line) {
    fl_alert("Please enter a number in the text field\n"
             "before clicking on the buttons.");
    return;
  }
#endif
} // show_cb()

void swap_cb(Fl_Widget *, void *) {
  int a = -1, b = -1;
  for (int t = 1; t <= browser->nitems(); t++ ) { // find two selected items
    if ( browser->checked(t) ) {
      if ( a < 0 )
	{ a = t; }
      else
	{ b = t; break; }
    }
  }
  if (b>0) {					// found 2 items
    printf("swapping item # (%d, %d)\n", a, b);
    browser->item_swap(a, b);			// swap them
    browser->redraw();
  } else {
    printf("please select (at least) two items\n");
  }
} // swap_cb()

void sort_cb(Fl_Widget *, void *up) {
  if ((int)(fl_intptr_t)up) {
    printf("Sorting browser lines ascending\n");
    browser->sort(FL_SORT_ASCENDING);
  } else {
    printf("Sorting browser lines descending\n");
    browser->sort(FL_SORT_DESCENDING);
  }
  browser->redraw();
}

void wtype_cb(Fl_Widget *, void *) {
  if ( wtype->value() < 0 ) return;
  browser->when( when_items[wtype->value()].wvalue );	// when value based on array
}

int main(int argc, char **argv) {
  int i;
  if (!Fl::args(argc,argv,i)) Fl::fatal(Fl::help);
  Fl_Double_Window window(640, 400, "Fl_Check_Browser");
  browser = new Fl_Check_Browser(0, 0, window.w(), window.h()-170, 0);
  browser->callback(browser_cb);
  // load browser with test data
  browser->add("abcd");
  browser->add("test 8");
  browser->add("xyzw");
  browser->add("new item");
  browser->add("test 21");
  browser->add("what is this?");
  browser->add("test 2");
  browser->add("weird item");
  browser->add("test 1");
  browser->position(0);
  browser->set_checked(4);
  browser->set_checked(7);

  int y = browser->h();
  field = new Fl_Int_Input(55, y, window.w()-55, 25, "Line #:");
  field->callback(show_cb);

  y += 25;
  top = new Fl_Button(0, y, 80, 25, "Top");
  top->callback(show_cb);

  bottom = new Fl_Button(80, y, 80, 25, "Bottom");
  bottom->callback(show_cb);

  middle = new Fl_Button(160, y, 80, 25, "Middle");
  middle->callback(show_cb);

  swap = new Fl_Button(240, y, 80, 25, "Swap");
  swap->callback(swap_cb);
  swap->tooltip("Swaps two selected lines");

  sorta = new Fl_Button(320, y, 80, 25, "ASC");
  sorta->callback(sort_cb, (void *)1);
  sorta->tooltip("Sorts browser lines ascending");

  sortd = new Fl_Button(400, y, 80, 25, "DESC");
  sortd->callback(sort_cb, (void *)0);
  sortd->tooltip("Sorts browser lines descending");

  wtype = new Fl_Choice(480, y, 160, 25);
  wtype->textsize(8);
  // Append items from when_items[] array
  {
    int len = sizeof(when_items) / sizeof(WhenItem);
    for ( int i=0; i<len; i++ )
      wtype->add(when_items[i].name);
  }
  wtype->callback(wtype_cb);
  wtype->value(4);             // FL_WHEN_RELEASE_ALWAYS is Fl_Browser's default

  window.resizable(browser);
  window.show(argc,argv);
  return Fl::run();
}

//
// End of "$Id$".
//
