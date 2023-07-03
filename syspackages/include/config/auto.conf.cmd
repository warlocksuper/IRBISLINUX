deps_config := \
	packages/Kconfig \
	Kconfig \

include/config/auto.conf: $(deps_config)


$(deps_config): ;
