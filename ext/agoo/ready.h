// Copyright (c) 2018, Peter Ohler, All rights reserved.

#ifndef AGOO_READY_H
#define AGOO_READY_H

#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

#include "err.h"

typedef enum {
    AGOO_READY_IN	= 'i',
    AGOO_READY_OUT	= 'o',
    AGOO_READY_BOTH	= 'b',
} agooReadyIO;

typedef struct _agooReady	*agooReady;

extern agooReady	agoo_ready_create(agooErr err, size_t size, bool use_poll);
extern int		agoo_ready_add(agooErr		err,
				       agooReady	ready,
				       int		fd,
				       agooReadyIO	(*io)(void *ctx),
				       ssize_t		(*r)(agooErr err, void *ctx, uint8_t *buf, size_t blen),
				       ssize_t		(*w)(agooErr err, void *ctx, uint8_t *buf, size_t blen),
				       void		(*e)(int fd, void *ctx, agooErrCode err_code),
				       void		*ctx);
extern void		agoo_ready_remove(agooReady ready, int fd);
extern int		agoo_ready_go(agooErr err, agooReady ready);

#endif // AGOO_READY_H
