/* $NetBSD: exi.h,v 1.2 2024/02/10 11:00:15 jmcneill Exp $ */

/*-
 * Copyright (c) 2024 Jared McNeill <jmcneill@invisible.ca>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _WII_DEV_EXI_H_
#define _WII_DEV_EXI_H_

typedef enum {
	EXI_FREQ_1MHZ = 0,
	EXI_FREQ_2MHZ = 1,
	EXI_FREQ_4MHZ = 2,
	EXI_FREQ_8MHZ = 3,
	EXI_FREQ_16MHZ = 4,
	EXI_FREQ_32MHZ = 5,
} exi_freq_t;

struct exi_attach_args {
	uint32_t	eaa_id;
	uint8_t		eaa_chan;
	uint8_t		eaa_device;
};

void exi_select(uint8_t, uint8_t, exi_freq_t);
void exi_unselect(uint8_t);
void exi_send_imm(uint8_t, uint8_t, const void *, size_t);
void exi_recv_imm(uint8_t, uint8_t, void *, size_t);
void exi_recv_dma(uint8_t, uint8_t, void *, size_t);

#endif /* _WII_DEV_EXI_H_ */