// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2021 SiFive, Inc
 */

#include <common.h>
#include <cache.h>
#include <cpu_func.h>
#include <dm.h>

void enable_caches(void)
{
	struct udevice *dev;
	int ret;

	/* Enable ways of ccache */
	ret = uclass_get_device_by_driver(UCLASS_CACHE,
					  DM_DRIVER_GET(sifive_ccache),
					  &dev);
	if (ret) {
		log_debug("Cannot enable cache ways");
	} else {
		ret = cache_enable(dev);
		if (ret)
			log_debug("ccache enable failed");
	}
}

//Patch StarFive
void flush_dcache_range(unsigned long start, unsigned long end)
{
	struct udevice *dev;
	int ret;

	/* Enable ways of ccache */
	ret = uclass_get_device_by_driver(UCLASS_CACHE,
					  DM_DRIVER_GET(sifive_ccache),
					  &dev);
	if (ret) {
		log_debug("Cannot flush dcache in %p - %p",
			  (void *)start, (void *)end);
	} else {
		ret = flush_range(dev, start, end);
		if (ret)
			log_debug("ccache flush failed in %p - %p",
				  (void *)start, (void *)end);
	}
}
