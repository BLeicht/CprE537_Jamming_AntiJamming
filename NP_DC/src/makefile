APPLICATION ?= NP_DC_NODES

BOARD ?= native

USEMODULE += shell
USEMODULE += shell_commands
USEMODULE += ps
USEMODULE += posix_sockets
USEMODULE += ztimer_msec
USEMODULE += sock_udp
USEMODULE += auto_init_gnrc_netif
USEMODULE += gnrc_ipv6_default

SERVER_PORT ?= 8888
SERVER_ADDR ?= fe80::1

RIOTBASE ?= $(CURDIR)/../../RIOT

FEATURES_REQUIRED += cpp

CFLAGS += -DSERVER_PORT=$(SERVER_PORT)
CFLAGS += -DSERVER_ADDR=\"$(SERVER_ADDR)\"
#CFLAGS += -fno-use-cxa-atexit

include $(RIOTBASE)/Makefile.include
