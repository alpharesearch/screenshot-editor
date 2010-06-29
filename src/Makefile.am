NULL =

AM_CPPFLAGS =							\
	-I.							\
	-I$(srcdir)						\
	-DGNOMELOCALEDIR=\""$(prefix)/$(DATADIRNAME)/locale"\"	\
	-DUIDIR=\""$(uidir)"\"					\
	$(LIBGDICT1_CFLAGS)					\
	$(LIBGDICT2_CFLAGS)				\
	$(LIBGDICT3_CFLAGS)					\
	$(NULL)

bin_PROGRAMS = screenshot-editor

screenshot_editor_SOURCES = screenshot-editor.c

screenshot_editor_LDFLAGS = -export-dynamic

screenshot_editor_LDADD =		\
	$(LIBGDICT1_LIBS)			\
	$(LIBGDICT2_LIBS)		\
	$(LIBGDICT3_LIBS)		\
	$(GTHREAD_LIBS)			\
	-lm				\
	$(NULL)
