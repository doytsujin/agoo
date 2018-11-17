// Copyright (c) 2018, Peter Ohler, All rights reserved.

#include "ready.h"

typedef struct _handler {
    void	*ctx;
    agooReadyIO	(*io)(void *ctx);
    ssize_t	(*r)(agooErr err, void *ctx, uint8_t *buf, size_t blen);
    ssize_t	(*w)(agooErr err, void *ctx, uint8_t *buf, size_t blen);
    void	(*e)(int fd, void *ctx, agooErrCode err_code);
} *Handler;

struct _agooReady {
#if HAVE_SYS_EPOLL_H

#elif HAVE_SYS_EVENTS_H

#else
    
#endif
    // TBD different content for each type
    void	*tmp;
};
