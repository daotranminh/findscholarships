SUBDIRS = html css fetch utilities

# global preprocessor flags
AM_CPPFLAGS = \
    -I$(top_srcdir)/include \
    -I$(top_srcdir) \
    $(BOOST_CPPFLAGS) \
    -DNO_GMP \
    @LIBCURL_CPPFLAGS@


# global linker flags
AM_LDFLAGS = \
	$(BOOST_DATE_TIME_LDFLAGS) \
	$(BOOST_PROGRAM_OPTIONS_LDFLAGS) \
	$(BOOST_SYSTEM_LDFLAGS) \
	$(BOOST_THREAD_LDFLAGS) \
	$(BOOST_SERIALIZATION_LDFLAGS) \
	$(BOOST_ASIO_LDFLAGS) \
	$(BOOST_GRAPH_LDFLAGS) 

# global libs
LIBS = \
	$(BOOST_DATE_TIME_LIBS) \
	$(BOOST_PROGRAM_OPTIONS_LIBS) \
	$(BOOST_SYSTEM_LIBS) \
	$(BOOST_THREAD_LIBS) \
	$(BOOST_SERIALIZATION_LIBS) \
	$(BOOST_ASIO_LIBS) \
	$(BOOST_GRAPH_LIBS) \
	$(LOG4CXX_LIBS)

# install htmlcxx into $prefix/bin
bin_PROGRAMS = htmlcxx 

# the htmlcxx binary
htmlcxx_SOURCES = \
		htmlcxx.cc

htmlcxx_LDADD = \
	$(top_builddir)/src/html/libhtmlcxx.la \
	$(top_builddir)/src/css/libcss_parser_pp.la \
	$(top_builddir)/src/css/libcss_parser.la \
	$(top_builddir)/src/fetch/libfetch.la \
	$(top_builddir)/src/utilities/libutilities.la \
	@LIBCURL@

EXTRA_DIST = wingetopt.c COPYING

