// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2018, Bin Meng <bmeng.cn@gmail.com>
 */

#include <common.h>
#include <command.h>
#include <hang.h>

__weak void reset_misc(void)
{
}

int do_reset(struct cmd_tbl *cmdtp, int flag, int argc, char *const argv[])
{
	printf("resetting ...\n");

	//Patch StarFive
	reset_misc();
	printf("reset not supported yet\n");
	hang();

	return 0;
}
