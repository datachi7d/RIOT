RIOT=1
include $(PKG_BUILDDIR)/core/src/client/Makefile.client
include $(PKG_BUILDDIR)/core/src/common/Makefile.common
include $(PKG_BUILDDIR)/core/src/erbium/Makefile.erbium

%.o:
	$(CC) $(CFLAGS) $(INCLUDES) -DRIOT -DLWM2M_CLIENT -c -o $@ $(@:o=c)

AwaLWM2M.a: $(addprefix $(PKG_BUILDDIR)/core/src/common/,$(common_src:c=o)) $(addprefix $(PKG_BUILDDIR)/core/src/client/,$(client_src:c=o)) $(addprefix $(PKG_BUILDDIR)/core/src/erbium/,$(erbium_src:c=o))
	$(AR) cr  $(BINDIR)/AwaLWM2M.a $^

all: AwaLWM2M.a
