/***************************************************************************
 *   Copyright (C) 2007 Ryan Schultz, PCSX-df Team, PCSX team              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02111-1307 USA.           *
 ***************************************************************************/

#ifndef __PSXMEMORY_H__
#define __PSXMEMORY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "psxcommon.h"

#if defined(__BIGENDIAN__)
#ifdef _XBOX

#define SWAP16(x) _byteswap_ushort(x)
#define SWAP32(x) _byteswap_ulong(x)

#define SWAP16p(X) __loadwordbytereverse(0,X)
#define SWAP32p(X) __loadshortbytereverse(0,X)
#define SWAP32wp(X,Y) __storewordbytereverse(Y,0,X);

#define SWAPu32(v) SWAP32((u32)(v))
#define SWAPs32(v) SWAP32((s32)(v))

#define SWAPu16(v) SWAP16((u16)(v))
#define SWAPs16(v) SWAP16((s16)(v))

#else

#define _SWAP16(b) ((((unsigned char *)&(b))[0] & 0xff) | (((unsigned char *)&(b))[1] & 0xff) << 8)
#define _SWAP32(b) ((((unsigned char *)&(b))[0] & 0xff) | ((((unsigned char *)&(b))[1] & 0xff) << 8) | ((((unsigned char *)&(b))[2] & 0xff) << 16) | (((unsigned char *)&(b))[3] << 24))

#define SWAP16(v) ((((v) & 0xff00) >> 8) +(((v) & 0xff) << 8))
#define SWAP32(v) ((((v) & 0xff000000ul) >> 24) + (((v) & 0xff0000ul) >> 8) + (((v) & 0xff00ul)<<8) +(((v) & 0xfful) << 24))
#define SWAPu32(v) SWAP32((u32)(v))
#define SWAPs32(v) SWAP32((s32)(v))

#define SWAPu16(v) SWAP16((u16)(v))
#define SWAPs16(v) SWAP16((s16)(v))

#endif

#else

#define SWAP16(b) (b)
#define SWAP32(b) (b)

#define SWAPu16(b) (b)
#define SWAPu32(b) (b)

#endif

extern s8 *psxM;
#define psxMs8(mem)		psxM[(mem) & 0x1fffff]
#define psxMs16(mem)	(SWAP16(*(s16 *)&psxM[(mem) & 0x1fffff]))
#define psxMs32(mem)	(SWAP32(*(s32 *)&psxM[(mem) & 0x1fffff]))
#define psxMu8(mem)		(*(u8 *)&psxM[(mem) & 0x1fffff])
#define psxMu16(mem)	(SWAP16(*(u16 *)&psxM[(mem) & 0x1fffff]))
#define psxMu32(mem)	(SWAP32(*(u32 *)&psxM[(mem) & 0x1fffff]))

#define psxMs8ref(mem)	psxM[(mem) & 0x1fffff]
#define psxMs16ref(mem)	(*(s16 *)&psxM[(mem) & 0x1fffff])
#define psxMs32ref(mem)	(*(s32 *)&psxM[(mem) & 0x1fffff])
#define psxMu8ref(mem)	(*(u8 *)&psxM[(mem) & 0x1fffff])
#define psxMu16ref(mem)	(*(u16 *)&psxM[(mem) & 0x1fffff])
#define psxMu32ref(mem)	(*(u32 *)&psxM[(mem) & 0x1fffff])

extern s8 *psxP;
#define psxPs8(mem)	    psxP[(mem) & 0xffff]
#define psxPs16(mem)	(SWAP16(*(s16 *)&psxP[(mem) & 0xffff]))
#define psxPs32(mem)	(SWAP32(*(s32 *)&psxP[(mem) & 0xffff]))
#define psxPu8(mem)		(*(u8 *)&psxP[(mem) & 0xffff])
#define psxPu16(mem)	(SWAP16(*(u16 *)&psxP[(mem) & 0xffff]))
#define psxPu32(mem)	(SWAP32(*(u32 *)&psxP[(mem) & 0xffff]))

#define psxPs8ref(mem)	psxP[(mem) & 0xffff]
#define psxPs16ref(mem)	(*(s16 *)&psxP[(mem) & 0xffff])
#define psxPs32ref(mem)	(*(s32 *)&psxP[(mem) & 0xffff])
#define psxPu8ref(mem)	(*(u8 *)&psxP[(mem) & 0xffff])
#define psxPu16ref(mem)	(*(u16 *)&psxP[(mem) & 0xffff])
#define psxPu32ref(mem)	(*(u32 *)&psxP[(mem) & 0xffff])

extern s8 *psxR;
#define psxRs8(mem)		psxR[(mem) & 0x7ffff]
#define psxRs16(mem)	(SWAP16(*(s16 *)&psxR[(mem) & 0x7ffff]))
#define psxRs32(mem)	(SWAP32(*(s32 *)&psxR[(mem) & 0x7ffff]))
#define psxRu8(mem)		(*(u8* )&psxR[(mem) & 0x7ffff])
#define psxRu16(mem)	(SWAP16(*(u16 *)&psxR[(mem) & 0x7ffff]))
#define psxRu32(mem)	(SWAP32(*(u32 *)&psxR[(mem) & 0x7ffff]))

#define psxRs8ref(mem)	psxR[(mem) & 0x7ffff]
#define psxRs16ref(mem)	(*(s16*)&psxR[(mem) & 0x7ffff])
#define psxRs32ref(mem)	(*(s32*)&psxR[(mem) & 0x7ffff])
#define psxRu8ref(mem)	(*(u8 *)&psxR[(mem) & 0x7ffff])
#define psxRu16ref(mem)	(*(u16*)&psxR[(mem) & 0x7ffff])
#define psxRu32ref(mem)	(*(u32*)&psxR[(mem) & 0x7ffff])

extern s8 *psxH;
#define psxHs8(mem)		psxH[(mem) & 0xffff]
#define psxHs16(mem)	(SWAP16(*(s16 *)&psxH[(mem) & 0xffff]))
#define psxHs32(mem)	(SWAP32(*(s32 *)&psxH[(mem) & 0xffff]))
#define psxHu8(mem)		(*(u8 *)&psxH[(mem) & 0xffff])
#define psxHu16(mem)	(SWAP16(*(u16 *)&psxH[(mem) & 0xffff]))
#define psxHu32(mem)	(SWAP32(*(u32 *)&psxH[(mem) & 0xffff]))

#define psxHs8ref(mem)	psxH[(mem) & 0xffff]
#define psxHs16ref(mem)	(*(s16 *)&psxH[(mem) & 0xffff])
#define psxHs32ref(mem)	(*(s32 *)&psxH[(mem) & 0xffff])
#define psxHu8ref(mem)	(*(u8 *)&psxH[(mem) & 0xffff])
#define psxHu16ref(mem)	(*(u16 *)&psxH[(mem) & 0xffff])
#define psxHu32ref(mem)	(*(u32 *)&psxH[(mem) & 0xffff])

// NEW - Vm is broken ... need to find a way to have mirror :s
#define _USE_VM 1
#define VM_SIZE	0x20000000
#define VM_MASK (VM_SIZE - 1)


#define VM_PSX_MEM_MASK			(0x00200000 - 1)
#define PSX_MEM_MIRROR			0x00800000

//#define VM_MASK  0x101fffff
// Use with mask !
#define CHECK_ADR(adr) (adr>=0x00000000 && adr<(0x00200000)) || (adr>=0x1f000000 && adr<0x1fc80000)

extern s8 *psxVM;
#define psxVMs8(mem)	psxVM[(mem) & VM_MASK]
#define psxVMs16(mem)	(SWAP16(*(s16 *)&psxVM[(mem) & VM_MASK]))
#define psxVMs32(mem)	(SWAP32(*(s32 *)&psxVM[(mem) & VM_MASK]))
#define psxVMu8(mem)	(*(u8 *)&psxVM[(mem) & VM_MASK])
#define psxVMu16(mem)	(SWAP16(*(u16 *)&psxVM[(mem) & VM_MASK]))
#define psxVMu32(mem)	(SWAP32(*(u32 *)&psxVM[(mem) & VM_MASK]))

#define psxVMs8ref(mem)		psxVM[(mem) & VM_MASK]
#define psxVMs16ref(mem)	(*(s16 *)&psxVM[(mem) & VM_MASK])
#define psxVMs32ref(mem)	(*(s32 *)&psxVM[(mem) & VM_MASK])
#define psxVMu8ref(mem)		(*(u8 *)&psxVM[(mem) & VM_MASK])
#define psxVMu16ref(mem)	(*(u16 *)&psxVM[(mem) & VM_MASK])
#define psxVMu32ref(mem)	(*(u32 *)&psxVM[(mem) & VM_MASK])

#ifdef _USE_VM
#define PSXM(mem)		(u8*)(&psxVM[(mem) & VM_MASK])

#define PSXMs8(mem)		(*(s8 *)PSXM(mem))
#define PSXMs16(mem)	(SWAP16(*(s16 *)PSXM(mem)))
#define PSXMs32(mem)	(SWAP32(*(s32 *)PSXM(mem)))
#define PSXMu8(mem)		(*(u8 *)PSXM(mem))
#define PSXMu16(mem)	(SWAP16(*(u16 *)PSXM(mem)))
#define PSXMu32(mem)	(SWAP32(*(u32 *)PSXM(mem)))

#define PSXMu32ref(mem)	(*(u32 *)PSXM(mem))
#else
extern u8 **psxMemWLUT;
extern u8 **psxMemRLUT;

#define PSXM(mem)		(psxMemRLUT[(mem) >> 16] == 0 ? NULL : (u8*)(psxMemRLUT[(mem) >> 16] + ((mem) & 0xffff)))
#define PSXMs8(mem)		(*(s8 *)PSXM(mem))
#define PSXMs16(mem)	(SWAP16(*(s16 *)PSXM(mem)))
#define PSXMs32(mem)	(SWAP32(*(s32 *)PSXM(mem)))
#define PSXMu8(mem)		(*(u8 *)PSXM(mem))
#define PSXMu16(mem)	(SWAP16(*(u16 *)PSXM(mem)))
#define PSXMu32(mem)	(SWAP32(*(u32 *)PSXM(mem)))
#endif

#if !defined(PSXREC) && (defined(__x86_64__) || defined(__i386__) || defined(__ppc__)) && !defined(NOPSXREC)
#define PSXREC
#endif

int psxMemInit();
void psxMemReset();
void psxMemShutdown();

u8 psxMemRead8 (u32 mem);
u16 psxMemRead16(u32 mem);
u32 psxMemRead32(u32 mem);
void psxMemWrite8 (u32 mem, u8 value);
void psxMemWrite16(u32 mem, u16 value);
void psxMemWrite32(u32 mem, u32 value);
void *psxMemPointer(u32 mem);

#ifdef __cplusplus
}
#endif
#endif
