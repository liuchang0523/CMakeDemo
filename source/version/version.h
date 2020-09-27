/*****************************************************************************
*  Orbbec DispIP 3.0
*  Copyright (C) 2018 by ORBBEC Technology., Inc.
*
*  This file is part of Orbbec DispIP.
*
*  This file belongs to ORBBEC Technology., Inc.
*  It is considered a trade secret, and is not to be divulged or used by
* parties who have NOT received written authorization from the owner.
*
*  Description:
*
****************************************************************************/
#ifndef ___VERSION_H__
#define ___VERSION_H__

#define Test_VERSION_MAJOR 1
#define Test_VERSION_MINOR 1
#define Test_VERSION_PATCH 1

#define Test_STR_EXP(__A)    #__A
#define Test_STR(__A)        Test_STR_EXP(__A)

#define Test_STRW_EXP(__A)   L#__A
#define Test_STRW(__A)       Test_STRW_EXP(__A)

#define VERSION     "Biometrics_" "200925" "_v" Test_STR(1) "." Test_STR(1) "." Test_STR(1)


#endif // ___VERSION_H__
