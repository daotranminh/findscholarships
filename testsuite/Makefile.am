# global preprocessor flags
AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir) \
	$(BM_CPPFLAGS) \
	$(BOOST_CPPFLAGS) \
	$(LOG4CXX_CFLAGS) \
	@LIBCURL_CPPFLAGS@

# global linker flags
AM_LDFLAGS = \
	$(BOOST_SYSTEM_LDFLAGS) \
	$(BOOST_THREAD_LDFLAGS) \
	$(BOOST_DATE_TIME_LDFLAGS) \
	$(BOOST_SERIALIZATION_LDFLAGS) \
	$(BOOST_UNIT_TEST_FRAMEWORK_LDFLAGS)

# global libs
LIBS = \
	$(BOOST_THREAD_LIBS) \
	$(BOOST_GRAPH_LIBS) \
	$(BOOST_SERIALIZATION_LIBS) \
	$(BOOST_UNIT_TEST_FRAMEWORK_LIBS) \
	$(BOOST_SYSTEM_LIBS) \
	$(BOOST_DATE_TIME_LIBS)

TESTS = \
	testBoostDateTime \
	testConfiguration \
	testDatabase \
	testDateConverter

TESTS_ENVIRONMENT = \
	EXAMPLESDIR=$(top_srcdir)/examples \
	BOOST_TEST_REPORT_LEVEL=detailed \
	BOOST_TEST_LOG_LEVEL=all

check_PROGRAMS = \
	testBoostDateTime \
	testConfiguration \
	testDatabase \
	testDateConverter


testBoostDateTime_SOURCES = testBoostDateTime.cpp


testConfiguration_SOURCES = testConfiguration.cpp
testConfiguration_LDADD = \
	$(top_builddir)/src/utilities/libutilities.la


testDateConverter_SOURCES = testDateConverter.cpp
testDateConverter_LDADD = \
	$(top_builddir)/src/utilities/libutilities.la


testDatabase_SOURCES = testDatabase.cpp
testDatabase_LDADD = \
	$(top_builddir)/src/utilities/libutilities.la \
	$(top_builddir)/src/html/libhtmlcxx.la \
	$(top_builddir)/src/htmlgen/libhtmlgen.la
