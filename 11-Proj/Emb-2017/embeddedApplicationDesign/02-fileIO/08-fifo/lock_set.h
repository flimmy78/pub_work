#ifndef __LOCK_SET_H__
#define __LOCK_SET_H__

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "lock_set.h"

int lock_set(int fd, int type);

#endif
