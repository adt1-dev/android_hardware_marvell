/*
 * Copyright 2012 The Android Open Source Project
 * Copyright (C) 2013 Freescale Semiconductor, Inc.
 * Copyright 2013 Quester Technology, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/******************************************************************************
 *
 *  Filename:      bt_vendor_mrvl.c
 *
 *  Description:   marvell vendor specific library implementation
 *
 ******************************************************************************/

#define LOG_TAG "bt_mrvl"
#include "cutils/misc.h"
#include <utils/Log.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>
#include "cutils/properties.h"
#include "bt_vendor_mrvl.h"
#ifdef MRVL_WIRELESS_DAEMON_API
#include "marvell_wireless.h"
#endif



/******************************************************************************
**  Externs
******************************************************************************/
extern int bt_vnd_mrvl_if_init(const bt_vendor_callbacks_t *p_cb,
		unsigned char *local_bdaddr);
extern int bt_vnd_mrvl_if_op(bt_vendor_opcode_t opcode, void *param);
extern void bt_vnd_mrvl_if_cleanup(void);


/******************************************************************************
**  Variables
******************************************************************************/
bt_vendor_callbacks_t *bt_vendor_cbacks = NULL;
uint8_t vnd_local_bd_addr[6]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

//bt_hci_transport_device_type bt_hci_transport_device;

/******************************************************************************
**  Local type definitions
******************************************************************************/

/*****************************************************************************
**
**   BLUETOOTH VENDOR INTERFACE LIBRARY FUNCTIONS
**
*****************************************************************************/

static int init(const bt_vendor_callbacks_t* p_cb, unsigned char *local_bdaddr)
{
	return bt_vnd_mrvl_if_init(p_cb, local_bdaddr);	
}


/** Requested operations */
static int op(bt_vendor_opcode_t opcode, void *param)
{
	return bt_vnd_mrvl_if_op(opcode, param);

}

/** Closes the interface */
static void cleanup( void )
{
	bt_vnd_mrvl_if_cleanup();
}

// Entry point of DLib
const bt_vendor_interface_t BLUETOOTH_VENDOR_LIB_INTERFACE = {
    sizeof(bt_vendor_interface_t),
    init,
    op,
    cleanup
};
