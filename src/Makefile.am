NULL =

AM_CPPFLAGS =							\
	$(GLIB_CFLAGS)					\
	$(GTK_CFLAGS)				\
	$(GOOCANVAS_CFLAGS)					\
	$(NULL)

bin_PROGRAMS = screenshot-editor

screenshot_editor_SOURCES = screenshot-editor.c

screenshot_editor_LDFLAGS = -export-dynamic

screenshot_editor_LDADD =		\
	$(GLIB_LIBS)			\
	$(GTK_LIBS)		\
	$(GOOCANVAS_LIBS)		\
	$(NULL)
