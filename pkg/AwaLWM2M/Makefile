PKG_NAME=AwaLWM2M
PKG_URL=git@github.com:datachi7d/AwaLWM2M.git
PKG_VERSION=riot_testing
PKG_LICENSE=BSD-3-Clause

.PHONY: all

all: git-download 
	$(MAKE) -C $(RIOTBASE)/pkg/AwaLWM2M/src PKG_BUILDDIR=$(PKG_BUILDDIR) BINDIR=$(BINDIR)


include $(RIOTBASE)/pkg/pkg.mk


	

