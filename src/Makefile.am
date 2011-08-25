nobase_pkglib_LTLIBRARIES = \
  module/harps/clarinet.la \
  module/harps/electric_piano.la \
  module/harps/guiter.la \
  module/harps/dguiter.la \
  module/harps/brass.la \
  module/harps/strings.la

module_harps_clarinet_la_SOURCES = module/harps/clarinet.cpp
module_harps_electric_piano_la_SOURCES = module/harps/electric_piano.cpp
module_harps_guiter_la_SOURCES = module/harps/guiter.cpp
module_harps_dguiter_la_SOURCES = module/harps/dguiter.cpp
module_harps_brass_la_SOURCES = module/harps/brass.cpp
module_harps_strings_la_SOURCES = module/harps/strings.cpp

INCLUDES= $(all_includes)

AM_CPPFLAGS= @HARPS_CFLAGS@
AM_CFLAGS= @HARPS_CFLAGS@
AM_LDFLAGS = \
  @HARPS_LIBS@ -module
