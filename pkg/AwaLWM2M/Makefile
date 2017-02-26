PKG_NAME=AwaLWM2M
PKG_URL=git@github.com:datachi7d/AwaLWM2M.git
PKG_VERSION=7a679818df0972ac0bdff537a05cf38a33b8b50c
PKG_LICENSE=BSD-3-Clause

.PHONY: all


AWA_LIBS="$(PKG_BUILDDIR)/riotbuild/core/src/client/libawa_static.a" \
"$(PKG_BUILDDIR)/riotbuild/core/src/common/liblwm2mcommon.a" \
"$(PKG_BUILDDIR)/riotbuild/core/src/erbium/liberbiumstatic.a"

all: cmake-prepare
	#"$(MAKE)" -C $(PKG_BUILDDIR) CMAKE_OPTIONS="-DCMAKE_BUILD_TYPE=Release"
	"$(MAKE)" -C $(PKG_BUILDDIR)/riotbuild awa_static
	mkdir -p $(BINDIR)/$(PKG_NAME); cd $(BINDIR)/$(PKG_NAME); for var in $(AWA_LIBS); do ar -x $$var; done; ar -r -c -s $(BINDIR)/$(PKG_NAME).a *.o

cmake-prepare: git-download
	mkdir -p "$(PKG_BUILDDIR)/riotbuild"
	(cd "$(PKG_BUILDDIR)/riotbuild" && cmake ../ -DCMAKE_BUILD_TYPE=Release)

include $(RIOTBASE)/pkg/pkg.mk
