/*
 * Copyright 2018 Red Hat Inc., Durham, North Carolina.
 * All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors:
 *      "Jan Černý" <jcerny@redhat.com>
 */

#pragma once
#ifndef OPENSCAP_SCH_QUEUE_H
#define OPENSCAP_SCH_QUEUE_H

#include "util.h"
#include "oscap_queue.h"
#include "seap-descriptor.h"

typedef struct {
	pthread_t probe_thread_id;
	pthread_t parent_thread_id;
	struct oscap_queue *to_probe_queue;
	struct oscap_queue *from_probe_queue;
	pthread_cond_t to_probe_cond;
	pthread_mutex_t to_probe_mutex;
	pthread_cond_t from_probe_cond;
	pthread_mutex_t from_probe_mutex;
	int to_probe_cnt;
	int from_probe_cnt;
} sch_queuedata_t;

int sch_queue_connect (SEAP_desc_t *desc, const char *uri, uint32_t flags);
int sch_queue_openfd (SEAP_desc_t *desc, int fd, uint32_t flags);
int sch_queue_openfd2 (SEAP_desc_t *desc, int ifd, int ofd, uint32_t flags);
ssize_t sch_queue_recv (SEAP_desc_t *desc, void *buf, size_t len, uint32_t flags);
ssize_t sch_queue_send (SEAP_desc_t *desc, void *buf, size_t len, uint32_t flags);
ssize_t sch_queue_sendsexp (SEAP_desc_t *desc, SEXP_t *sexp, uint32_t flags);
int sch_queue_close (SEAP_desc_t *desc, uint32_t flags);
int sch_queue_select (SEAP_desc_t *desc, int ev, uint16_t timeout, uint32_t flags);


#endif /* OPENSCAP_SCH_QUEUE_H */
