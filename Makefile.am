ACLOCAL_AMFLAGS = -I build-aux/m4
SUBDIRS = src

GITIAN_VERIFIER_BIN=$(top_builddir)/src/gitian-verifier$(EXEEXT)

$(GITIAN_VERIFIER_BIN): FORCE
	$(MAKE) -C src $(@F)
