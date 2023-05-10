DISABLE_MODULE += auto_init_at86rf2xx

USEMODULE += od

APPLICATION = hello-jammer
BOARD ?= native
USEMODULE += shell
USEMODULE += shell_commands
USEMODULE += ps
USEMODULE += ztimer_sec

# define the driver to be used for selected boards
ifneq (,$(filter samr21-xpro,$(BOARD)))
  DRIVER := at86rf233
endif
ifneq (,$(filter iotlab-m3,$(BOARD)))
  DRIVER := at86rf231
endif
ifneq (,$(filter mulle,$(BOARD)))
  DRIVER := at86rf212b
endif

# use the at86rf231 as fallback device
DRIVER ?= at86rf231

# include the selected driver
USEMODULE += $(DRIVER)

RIOTBASE ?= $(CURDIR)/RIOT
include $(RIOTBASE)/Makefile.include
include $(RIOTBASE)/tests/Makefile.tests_common