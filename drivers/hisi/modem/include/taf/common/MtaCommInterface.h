/*
* Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
* foss@huawei.com
*
* If distributed as part of the Linux kernel, the following license terms
* apply:
*
* * This program is free software; you can redistribute it and/or modify
* * it under the terms of the GNU General Public License version 2 and
* * only version 2 as published by the Free Software Foundation.
* *
* * This program is distributed in the hope that it will be useful,
* * but WITHOUT ANY WARRANTY; without even the implied warranty of
* * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* * GNU General Public License for more details.
* *
* * You should have received a copy of the GNU General Public License
* * along with this program; if not, write to the Free Software
* * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
*
* Otherwise, the following license terms apply:
*
* * Redistribution and use in source and binary forms, with or without
* * modification, are permitted provided that the following conditions
* * are met:
* * 1) Redistributions of source code must retain the above copyright
* *    notice, this list of conditions and the following disclaimer.
* * 2) Redistributions in binary form must reproduce the above copyright
* *    notice, this list of conditions and the following disclaimer in the
* *    documentation and/or other materials provided with the distribution.
* * 3) Neither the name of Huawei nor the names of its contributors may
* *    be used to endorse or promote products derived from this software
* *    without specific prior written permission.
*
* * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifndef __MTACOMMINTERFACE_H__
#define __MTACOMMINTERFACE_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "vos.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 宏定义 
*****************************************************************************/
/*network monitor GSM临区 上报最大个数 */
#define NETMON_MAX_GSM_NCELL_NUM                (6)

/*network monitor UTRAN 临区 上报最大个数 */
#define NETMON_MAX_UTRAN_NCELL_NUM              (16)

/*network monitor LTE 临区 上报最大个数 */
#define NETMON_MAX_LTE_NCELL_NUM                (16)

#define MTA_LRRC_MSG_TYPE_BASE                  (0x1000)            /* MTA模块与LTE接入层消息基数 */
#define MTA_COMM_MSG_TYPE_BASE                  (0x2000)            /* MTA模块和其他模块公共消息基数 */

/*****************************************************************************
  3 枚举定义
*****************************************************************************/

enum MTA_RRC_GSM_BAND_ENUM
{
    MTA_RRC_GSM_BAND_850  = 0x00,
    MTA_RRC_GSM_BAND_900,
    MTA_RRC_GSM_BAND_1800,
    MTA_RRC_GSM_BAND_1900,

    MTA_RRC_GSM_BAND_BUTT
};
typedef VOS_UINT16 MTA_RRC_GSM_BAND_ENUM_UINT16;


enum MTA_NETMON_CELL_TYPE_ENUM
{
    MTA_NETMON_SCELL_TYPE               = 0,
    MTA_NETMON_NCELL_TYPE               = 1,
    MTA_NETMON_CELL_TYPE_BUTT
};

typedef VOS_UINT32 MTA_NETMON_CELL_TYPE_ENUM_UINT32;


enum MTA_NETMON_UTRAN_TYPE_ENUM
{
    MTA_NETMON_UTRAN_FDD_TYPE           = 0,
    MTA_NETMON_UTRAN_TDD_TYPE           = 1,
    MTA_NETMON_UTRAN_TYPE_BUTT
};
typedef VOS_UINT32 MTA_NETMON_UTRAN_TYPE_ENUM_UINT32;


enum MTA_NETMON_RESULT_ENUM
{
    MTA_NETMON_RESULT_NO_ERR            = 0,
    MTA_NETMON_RESULT_ERR               = 1,
    MTA_NETMON_RESULT_BUTT
};
typedef VOS_UINT32 MTA_NETMON_RESULT_ENUM_UINT32;

/*****************************************************************************
 枚举名    : MTA_NETMON_CELL_QRY_MODULE_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : 当前向接入层查询小区的模块枚举值
*****************************************************************************/
enum MTA_NETMON_CELL_QRY_MODULE_ENUM
{
    MTA_NETMON_CELL_QRY_MODULE_AT    = 0x00,    /* AT模块向接入层查询小区信息，AT^MONSC/AT^MONNC触发 */
    MTA_NETMON_CELL_QRY_MODULE_MTC   = 0x01,    /* MTC模块向接入层查询小区信息 */
    MTA_NETMON_CELL_QRY_MODULE_BUTT
};
typedef VOS_UINT32 MTA_NETMON_CELL_QRY_MODULE_ENUM_UINT32;

/*****************************************************************************
 枚举名    : MTA_NV_REFRESH_REASON_ENUM
 协议表格  :
 ASN.1描述 :
 枚举说明  : NV REFRESH的原因
*****************************************************************************/
enum MTA_NV_REFRESH_REASON_ENUM
{
    MTA_NV_REFRESH_REASON_USIM_DEPENDENT                    = 0x00,             /* 随卡匹配 */
    MTA_NV_REFRESH_REASON_BUTT
};
typedef VOS_UINT8 MTA_NV_REFRESH_REASON_ENUM_UINT8;

/*****************************************************************************
  4 全局变量声明
*****************************************************************************/

/*****************************************************************************
  5 消息头定义
*****************************************************************************/

/*****************************************************************************
  6 消息定义
*****************************************************************************/
enum MTA_COMM_MSG_TYPE_ENUM
{
    ID_MTA_NV_REFRESH_IND               = MTA_COMM_MSG_TYPE_BASE + 0x01,        /* _H2ASN_MsgChoice MTA_NV_REFRESH_IND_STRU */

    ID_MTA_NV_REFRESH_RSP               = MTA_COMM_MSG_TYPE_BASE + 0x02,        /* _H2ASN_MsgChoice MTA_NV_REFRESH_RSP_STRU */

    ID_MTA_COMM_MSG_TYPE_BUTT

};
typedef VOS_UINT32 MTA_COMM_MSG_TYPE_ENUM_UINT32;



/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/

/* ========以下是接入层与MTA之间的消息结构体======== */

/**************************network monitor查询临区信息结构体部分**********************************************************/

/* MTA发给接入层的消息，通用，不区分2G/3G/服务小区/邻区 */

typedef struct
{
    VOS_MSG_HEADER                                     /* 消息头*/              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;     /*消息名称*/             /*_H2ASN_Skip*/
    MTA_NETMON_CELL_TYPE_ENUM_UINT32    enCelltype;    /*0:查询服务小区，1:查询临区*/
    VOS_UINT32                          ulQryModule;   /* 当前查询的模块信息 */
}MTA_RRC_NETMON_CELL_QRY_REQ_STRU;

/*GSM 临区结构*/

typedef struct
{
    VOS_UINT32                          bitOpBsic     : 1;
    VOS_UINT32                          bitOpCellID   : 1;
    VOS_UINT32                          bitOpLAC      : 1;
    VOS_UINT32                          bitOpSpare    : 29;
    VOS_UINT32                          ulCellID;       /*小区ID*/
    VOS_UINT16                          usLAC;          /*位置区码*/
    VOS_UINT16                          usAfrcn;        /*频点*/
    VOS_INT16                           sRSSI;          /* 频点的RSSI */
    MTA_RRC_GSM_BAND_ENUM_UINT16        enBand;         /* band 0-3 */
    VOS_UINT8                           ucBsic;         /*小区基站码*/
    VOS_UINT8                           aucReserved[3];
}MTA_NETMON_GSM_NCELL_INFO_STRU;


/*LTE 临区结构,暂时定义的数据结构，根据需要进行调整*/

typedef struct
{
    VOS_UINT32                          ulPID;            /*物理小区ID*/
    VOS_UINT32                          ulArfcn;          /*频点*/
    VOS_INT16                           sRSRP;            /* RSRP参考信号接收功率*/
    VOS_INT16                           sRSRQ;            /* RSRQ参考信号接收质量*/
    VOS_INT16                           sRSSI;            /* Receiving signal strength in dbm */
    VOS_UINT8                           aucReserved[2];
}MTA_NETMON_LTE_NCELL_INFO_STRU;


/*WCDMA 临区结构*/

typedef struct
{
    VOS_UINT16                          usArfcn;          /*频点*/
    VOS_UINT16                          usPSC;            /*主扰码*/
    VOS_INT16                           sECN0;            /*ECN0*/
    VOS_INT16                           sRSCP;            /*RSCP*/
}MTA_NETMON_UTRAN_NCELL_INFO_FDD_STRU;


/*TD_SCDMA 临区结构,暂时定义结构，根据需要继续调整*/

typedef struct
{
    VOS_UINT16                          usArfcn;          /*频点*/
    VOS_UINT16                          usSC;             /*扰码*/
    VOS_UINT16                          usSyncID;         /*下行导频码*/
    VOS_INT16                           sRSCP;            /*RSCP*/
}MTA_NETMON_UTRAN_NCELL_INFO_TDD_STRU;


/*临区数据结构*/

typedef struct
{
    VOS_UINT8                                ucGsmNCellCnt;      /*GSM 临区个数*/
    VOS_UINT8                                ucUtranNCellCnt;    /*WCDMA 临区个数*/
    VOS_UINT8                                ucLteNCellCnt;      /*LTE 临区个数*/
    VOS_UINT8                                ucReserved;
    MTA_NETMON_GSM_NCELL_INFO_STRU           astGsmNCellInfo[NETMON_MAX_GSM_NCELL_NUM];          /*GSM 临区数据结构*/
    MTA_NETMON_UTRAN_TYPE_ENUM_UINT32        enCellMeasTypeChoice;     /* NETMON频率信息类型:FDD,TDD */
    union
    {
        MTA_NETMON_UTRAN_NCELL_INFO_FDD_STRU astFddNCellInfo[NETMON_MAX_UTRAN_NCELL_NUM];         /* FDD临区数据结构 */
        MTA_NETMON_UTRAN_NCELL_INFO_TDD_STRU astTddNCellInfo[NETMON_MAX_UTRAN_NCELL_NUM];         /*  TDD临区数据结构 */
    }u;
    MTA_NETMON_LTE_NCELL_INFO_STRU           astLteNCellInfo[NETMON_MAX_LTE_NCELL_NUM];      /*LTE 临区数据结构*/
}RRC_MTA_NETMON_NCELL_INFO_STRU;


/*********************network monitor查询GSM 小区信息部分************************************************/

typedef struct
{
    VOS_MSG_HEADER                                     /* 消息头 */             /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;     /* 消息名称 */           /*_H2ASN_Skip*/
}MTA_GRR_NETMON_TA_QRY_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER                                          /* 消息头 */        /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;          /* 消息名称 */      /*_H2ASN_Skip*/
    MTA_NETMON_RESULT_ENUM_UINT32       enResult;           /* 返回结果 */
    VOS_UINT16                          usTa;               /* 返回的TA值 */
    VOS_UINT8                           aucReserved[2];     /* 四字节对齐的保留位 */
}GRR_MTA_NETMON_TA_QRY_CNF_STRU;


typedef struct
{
    VOS_UINT32                          ulMcc;              /* 移动国家码 */
    VOS_UINT32                          ulMnc;              /* 移动网络码 */
    VOS_UINT32                          ulCellID;           /* 小区ID */
    VOS_UINT16                          usLac;              /* 位置区码 */
    VOS_UINT16                          usArfcn;            /* 绝对频点号 */
    VOS_INT16                           sRssi;              /* Receiving signal strength in dbm */
    MTA_RRC_GSM_BAND_ENUM_UINT16        enBand;             /* GSM频段(0-3) */
    VOS_UINT8                           ucBsic;             /* 小区基站码 */
    VOS_UINT8                           ucRxQuality;        /* IDLE态下或者PS数传态下无效,专用态下填充信道质量值，范围[0,7] ,无效值99*/
    VOS_UINT8                           aucReserved[2];     /* 四字节对齐的保留位 */
}GRR_MTA_NETMON_SCELL_INFO_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;      /* 消息名称 */          /*_H2ASN_Skip*/
    MTA_NETMON_RESULT_ENUM_UINT32       enResult;
    MTA_NETMON_CELL_TYPE_ENUM_UINT32    enCelltype;     /* 0:查询服务小区，1:查询邻区 */
    VOS_UINT32                          ulQryModule;    /* 当前查询的模块信息 */
    union
    {
        GRR_MTA_NETMON_SCELL_INFO_STRU  stSCellinfo;    /* GSM下的服务小区信息 */
        RRC_MTA_NETMON_NCELL_INFO_STRU  stNCellinfo;    /* GSM下的邻区信息 */
    }u;
}GRR_MTA_NETMON_CELL_QRY_CNF_STRU;

/******************************network monitor查询UTRAN 小区信息部分****************************************************/


/*FDD 服务小区信息结构*/

typedef struct
{
    VOS_UINT32                          bitOpDRX      : 1;
    VOS_UINT32                          bitOpURA      : 1;
    VOS_UINT32                          bitOpSpare    : 30;
    VOS_UINT32                          ulDrx;          /* Discontinuous reception cycle length */
    VOS_INT16                           sECN0;          /*ECN0*/
    VOS_INT16                           sRSSI;          /* Receiving signal strength in dbm */
    VOS_INT16                           sRSCP;          /*Received Signal Code Power in dBm，接收信号码功率*/
    VOS_UINT16                          usPSC;          /*主扰码*/
    VOS_UINT16                          usURA;          /* UTRAN Registration Area Identity */
    VOS_UINT8                           aucReserved[2];

} MTA_NETMON_UTRAN_SCELL_INFO_FDD_STRU;


/*TDD 服务小区信息结构预留，待确认后填充*/

typedef struct
{
    VOS_UINT32                          ulDrx;              /* Discontinuous reception cycle length */
    VOS_UINT16                          usSC;               /*扰码*/
    VOS_UINT16                          usSyncID;           /*下行导频码*/
    VOS_UINT16                          usRac;              /*RAC*/
    VOS_INT16                           sRSCP;              /*RSCP*/
} MTA_NETMON_UTRAN_SCELL_INFO_TDD_STRU;



 /*UTRAN 服务小区结构*/
 
typedef struct
{
    VOS_UINT32                                  bitOpCellID  : 1;
    VOS_UINT32                                  bitOpLAC     : 1;
    VOS_UINT32                                  bitOpSpare   : 30;
    VOS_UINT32                                  ulMcc;                  /*移动国家码*/
    VOS_UINT32                                  ulMnc;                  /*移动网络码*/
    VOS_UINT32                                  ulCellID;               /*小区ID*/
    VOS_UINT16                                  usArfcn;                /*频点*/
    VOS_UINT16                                  usLAC;                  /*位置区码*/
    MTA_NETMON_UTRAN_TYPE_ENUM_UINT32           enCellMeasTypeChoice;   /* NETMON频率信息类型:FDD,TDD */
    union
    {
        MTA_NETMON_UTRAN_SCELL_INFO_FDD_STRU    stCellMeasResultsFDD;    /* FDD */
        MTA_NETMON_UTRAN_SCELL_INFO_TDD_STRU    stCellMeasResultsTDD;    /*  TDD */
    }u;
}RRC_MTA_NETMON_UTRAN_SCELL_INFO_STRU;



typedef struct
{
    VOS_MSG_HEADER                                              /* 消息头*/     /*_H2ASN_Skip*/
    VOS_UINT32                                ulMsgName;        /*消息名称*/    /*_H2ASN_Skip*/
    MTA_NETMON_RESULT_ENUM_UINT32             enResult;
    MTA_NETMON_CELL_TYPE_ENUM_UINT32          enCelltype;       /*0:查询服务小区，1:查询临区*/
    VOS_UINT32                                ulQryModule;      /* 当前查询的模块信息 */
    union
    {
        RRC_MTA_NETMON_UTRAN_SCELL_INFO_STRU  stSCellinfo;      /* UTRAN下的服务小区信息 */
        RRC_MTA_NETMON_NCELL_INFO_STRU        stNCellinfo;      /* UTRAN下的邻区信息 */
    }u;
}RRC_MTA_NETMON_CELL_INFO_QRY_CNF_STRU;

/*LTE 服务小区结构*/

typedef struct
{
    VOS_UINT32                                  ulMcc;                  /*移动国家码*/
    VOS_UINT32                                  ulMnc;                  /*移动网络码*/
    VOS_UINT32                                  ulCellID;               /*小区ID*/
    VOS_UINT32                                  ulPID;                  /*物理小区ID*/
    VOS_UINT32                                  ulArfcn;                /*频点*/
    VOS_UINT16                                  usTAC;
    VOS_INT16                                   sRSRP;
    VOS_INT16                                   sRSRQ;
    VOS_INT16                                   sRSSI;
} MTA_NETMON_EUTRAN_SCELL_INFO_STRU;


typedef struct
{
    VOS_MSG_HEADER                                  /* 消息头 */                /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;   /* 消息名称 */             /*_H2ASN_Skip*/
    MTA_NETMON_CELL_TYPE_ENUM_UINT32    enCelltype;  /* 0：查询服务小区，1：查询临区 */
    VOS_UINT32                          ulQryModule; /* 当前查询的模块信息 */
}MTA_LRRC_NETMON_CELL_QRY_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER                                              /* 消息头*/     /*_H2ASN_Skip*/
    VOS_UINT32                                ulMsgName;        /*消息名称*/    /*_H2ASN_Skip*/
    MTA_NETMON_RESULT_ENUM_UINT32             enResult;
    MTA_NETMON_CELL_TYPE_ENUM_UINT32          enCelltype;       /*0:查询服务小区，1:查询临区*/
    VOS_UINT32                                ulQryModule;      /* 当前查询的模块信息 */
    union
    {
        MTA_NETMON_EUTRAN_SCELL_INFO_STRU     stSCellinfo;      /* LTE下的服务小区信息 */
        RRC_MTA_NETMON_NCELL_INFO_STRU        stNCellinfo;      /* LTE下的邻区信息 */
    }u;
}LRRC_MTA_NETMON_CELL_INFO_QRY_CNF_STRU;



typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                                              ulMsgName;          /*_H2ASN_Skip*/
    MTA_NV_REFRESH_REASON_ENUM_UINT8                        enReason;           /* NV REFRESH原因 */
    VOS_UINT8                                               aucRsv[3];
}MTA_NV_REFRESH_IND_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                                              ulMsgName;          /*_H2ASN_Skip*/
    VOS_UINT32                                              ulRslt;             /* VOS_OK:成功，其他:失败 */
}MTA_NV_REFRESH_RSP_STRU;

/*****************************************************************************
  10 函数声明
*****************************************************************************/
VOS_UINT32 NAS_RegNvRefreshIndMsg(
    MODEM_ID_ENUM_UINT16                enModemId,
    VOS_UINT32                          ulRegPid
);

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of MtaCommInterface.h */
