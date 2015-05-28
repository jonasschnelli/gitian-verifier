GITIAN_VERIFIER_CONFIG_INCLUDES=-I$(builddir)/config
GITIAN_VERIFIER_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BOOST_CPPFLAGS)

bin_PROGRAMS = gitian-verifier

gitian_verifier_SOURCES = gitian-verifier.cpp util.cpp util.h tinyformat.h
gitian_verifier_CPPFLAGS = $(GITIAN_VERIFIER_INCLUDES) $(QT_INCLUDES) $(QT_DBUS_INCLUDES)
gitian_verifier_CFLAGS = ${CURL_CFLAGS}
gitian_verifier_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS) $(QT_LDFLAGS)


gitian_verifier_LDADD = $(BOOST_LIBS) ${CURL_LIBS} $(QT_LIBS) $(QT_DBUS_LIBS)
