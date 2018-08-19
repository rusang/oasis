VERSION = 0.1

# Generating file version.h if current version has changed
VERSION_FILE := inc/version.h
SOFTWARE_VERSION:=$(shell git describe 2>/dev/null || echo '$(VERSION)')
VERSION_H := $(shell cat $(VERSION_FILE) 2>/dev/null)
ifneq ($(lastword $(VERSION_H)),"$(SOFTWARE_VERSION)")
$(info $(shell echo   '       GEN  '$(VERSION_FILE)))
$(shell echo '#define SOFTWARE_VERSION "$(SOFTWARE_VERSION)"' > $(VERSION_FILE))
endif

CC           = gcc
LD           = gcc
AR           = ar
OBJDUMP      = objdump

SOURCES      = src
INCLUDE      = inc

# find all c files
CFILES       = $(shell find $(SOURCES) -type f -iname '*.c')
COBJS        = $(foreach cfile, $(basename $(CFILES)), $(cfile).o)
OBJS         = $(COBJS)

EXE          = src/test

CFLAGS       = -Wall -Werror -g -Os -I$(INCLUDE)

DEPS_CFLAGS  = -MMD -MP -MF .deps/$*.d

ALL_CFLAGS   = $(CFLAGS) $(DEPS_CFLAGS)

all: $(EXE)

debug:
	$(Q)echo "$(CFILES)"
	$(Q)echo "$(OBJS)"
	# $(QUIET_DUMP)$(OBJDUMP) -D $(EXE) > $(EXE).dis

$(EXE): $(OBJS)

%: %.o
	$(QUIET_LINK)$(LD) $(CFLAGS) $^ -o $@

%.o: %.c
	$(Q)mkdir -p .deps/$(*D)
	$(QUIET_CC)$(CC) $(ALL_CFLAGS) -c -o $@ $<

-include $(OBJS:%.o=.deps/%.d)

clean:
	$(Q)$(RM) -r .deps
	$(Q)$(RM) $(OBJS) $(EXE) $(EXE).dis

distclean: clean

.PHONY: all debug clean distclean

# quiet and pretty print
V			= @
Q			= $(V:1=)
QUIET_CC		= $(Q:@=@echo    '        CC  '$@;)
QUIET_LINK		= $(Q:@=@echo    '      LINK  '$@;)
QUIET_GEN		= $(Q:@=@echo    '       GEN  '$@;)
QUIET_ASCIIDOC		= $(Q:@=@echo    '  ASCIIDOC  '$@;)
QUIET_XMLTO		= $(Q:@=@echo    '     XMLTO  '$@;)
QUIET_DB2PDF		= $(Q:@=@echo    '    DB2PDF  '$@;)
QUIET_DUMP		= $(Q:@=@echo    '      DUMP  '$<;)
# tools/install.sh will print 'file -> $install_dir/file'
QUIET_INSTALL		= $(Q:@=@printf  '   INSTALL  ';)
QUIET_INSTALL_EACH	= $(Q:@=printf   '   INSTALL  ';)
QUIET_UNINSTALL		= $(Q:@=@printf  ' UNINSTALL  ';)
QUIET_UNINSTALL_EACH	= $(Q:@=printf   ' UNINSTALL  ';)
QUIET_TEST		= $(Q:@=@echo    '      TEST  '$@;)
QUIET_SUMMARY		= $(Q:@=@printf  '   SUMMARY  ';)
QUIET_LCOV		= $(Q:@=@echo    '      LCOV  '$@;)
QUIET_GENHTML		= $(Q:@=@echo    '   GENHTML  '$@;)

