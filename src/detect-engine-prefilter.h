/* Copyright (C) 2016 Open Information Security Foundation
 *
 * You can copy, redistribute or modify this Program under the terms of
 * the GNU General Public License version 2 as published by the Free
 * Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

/**
 * \file
 *
 * \author Victor Julien <victor@inliniac.net>
 */

#ifndef __DETECT_ENGINE_PREFILTER_H__
#define __DETECT_ENGINE_PREFILTER_H__

void Prefilter(DetectEngineThreadCtx *, const SigGroupHead *, Packet *p,
        const uint8_t flags, int has_state);

int PrefilterAppendEngine(SigGroupHead *sgh,
        void (*Prefilter)(DetectEngineThreadCtx *det_ctx, Packet *p, const void *pectx),
        void *pectx, void (*FreeFunc)(void *pectx));
int PrefilterAppendTxEngine(SigGroupHead *sgh,
        void (*PrefilterTx)(DetectEngineThreadCtx *det_ctx, const void *pectx,
            Packet *p, Flow *f, void *tx,
            const uint64_t idx, const uint8_t flags),
        const AppProto alproto, const int tx_min_progress,
        void *pectx, void (*FreeFunc)(void *pectx));

void PrefilterFreeEngines(PrefilterEngine *list);

#endif