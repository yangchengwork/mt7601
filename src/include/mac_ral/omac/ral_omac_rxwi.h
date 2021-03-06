/*
 *************************************************************************
 * Ralink Tech Inc.
 * 5F., No.36, Taiyuan St., Jhubei City,
 * Hsinchu County 302,
 * Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2010, Ralink Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation; either version 2 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program; if not, write to the                         *
 * Free Software Foundation, Inc.,                                       *
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                       *
 *************************************************************************/


#ifndef __RAL_OMAC_RXWI_H__
#define __RAL_OMAC_RXWI_H__

#include "rtmp_type.h"

/*
	RXWI wireless information format, in PBF. invisible in driver.
*/
#ifdef RT_BIG_ENDIAN
typedef	struct GNU_PACKED _RXWI_OMAC{
	/* Word 0 */
	UINT32		tid:4;
	UINT32		MPDUtotalByteCnt:12;
	UINT32		UDF:3;
	UINT32		bss_idx:3;
	UINT32		key_idx:2;
	UINT32		wcid:8;
	
	/* Word 1 */
	UINT32		phy_mode:2;              /* 1: this RX frame is unicast to me */
	UINT32		iTxBF:1; /* iTxBF enable */
	UINT32		Sounding:1; /* Sounding enable */
	UINT32		eTxBF:1; /* eTxBF enable */
	UINT32		stbc:2;
	UINT32		sgi:1;
	UINT32		bw:1;
	UINT32		mcs:7;
	UINT32		SEQUENCE:12;
	UINT32		FRAG:4;
	
	/* Word 2 */
	UINT32		rsv1:8;
	UINT32		RSSI2:8;
	UINT32		RSSI1:8;
	UINT32		RSSI0:8;
	
	/* Word 3 */
	UINT32		FOFFSET:8;
	UINT32		SNR2:8;
	UINT32		SNR1:8;
	UINT32		SNR0:8;
	
	UINT32		rsv3;

#if defined(RT5592) || defined(MT7601)
	/* Word 5 */
	/* For Exper Antenna */
	UINT32		rsv4:24;
	UINT32		EANT_ID:8;
#endif /* RT5592 */
}	RXWI_OMAC, *PRXWI_OMAC;
#else
typedef	struct GNU_PACKED _RXWI_OMAC{
	/* Word	0 */
	UINT32		wcid:8;
	UINT32		key_idx:2;
	UINT32		bss_idx:3;
	UINT32		UDF:3;
	UINT32		MPDUtotalByteCnt:12;
	UINT32		tid:4;

	/* Word	1 */
	UINT32		FRAG:4;
	UINT32		SEQUENCE:12;
	UINT32		mcs:7;
	UINT32		bw:1;
	UINT32		sgi:1;
	UINT32		stbc:2;
	UINT32		eTxBF:1; /* eTxBF enable */
	UINT32		Sounding:1; /* Sounding enable */
	UINT32		iTxBF:1; /* iTxBF enable */
	UINT32		phy_mode:2;              /* 1: this RX frame is unicast to me */

	/*Word2 */
	UINT32		RSSI0:8;
	UINT32		RSSI1:8;
	UINT32		RSSI2:8;
	UINT32		rsv1:8;

	/*Word3 */
	UINT32		SNR0:8;
	UINT32		SNR1:8;
	UINT32		SNR2:8;
	UINT32		FOFFSET:8;

	UINT32		rsv3;

#if defined(RT5592) || defined(MT7601)
	/* Word 5 */
	/* For Exper Antenna */
	UINT32      EANT_ID:8;
	UINT32      rsv4:24;
#endif /* RT5592 */
}	RXWI_OMAC, *PRXWI_OMAC;
#endif


#define RxWIMPDUByteCnt	RXWI_O.MPDUtotalByteCnt
#define RxWIWirelessCliID	RXWI_O.wcid
#define RxWIKeyIndex		RXWI_O.key_idx
#define RxWIMCS				RXWI_O.mcs
#define RxWIBW				RXWI_O.bw
#define RxWISGI				RXWI_O.sgi
#define RxWIBSSID			RXWI_O.bss_idx
#define RxWIPhyMode		RXWI_O.phy_mode
#define RxWISTBC			RXWI_O.stbc
#define RxWITID				RXWI_O.tid
#define RxWIRSSI0			RXWI_O.RSSI0
#define RxWIRSSI1			RXWI_O.RSSI1
#define RxWIRSSI2			RXWI_O.RSSI2
#define RxWISNR0			RXWI_O.SNR0
#define RxWISNR1			RXWI_O.SNR1
#define RxWISNR2			RXWI_O.SNR2
#define RxWIFOFFSET			RXWI_O.FOFFSET



#endif /* __RAL_OMAC_RXWI_H__ */

