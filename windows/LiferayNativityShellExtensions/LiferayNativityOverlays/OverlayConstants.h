/**
 * Copyright (c) 2000-2013 Liferay, Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 */

/*
* OVERLAY_ID:
*    1 = Syncing
*    2 = Uptodate
*    3 = Error
*/

/* SYNCING OVERLAY */
//#define	OVERLAY_ID					1
//#define OVERLAY_GUID				L"{0DD5B4B0-25AF-4e09-A46B-9F274F3D7013}"
//#define OVERLAY_NAME				L"1StackSyncSyncingOverlay"

/* UPTODATE OVERLAY */
//#define	OVERLAY_ID					2
//#define OVERLAY_GUID				L"{0DD5B4B1-25AF-4e09-A46B-9F274F3D7013}"
//#define OVERLAY_NAME				L"2StackSyncUptodateOverlay"

/* ERROR OVERLAY */
#define	OVERLAY_ID					3
#define OVERLAY_GUID				L"{0DD5B4B2-25AF-4e09-A46B-9F274F3D7013}"
#define OVERLAY_NAME				L"3StackSyncErrorOverlay"


#define REGISTRY_OVERLAY_KEY		L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers"
#define REGISTRY_CLSID				L"CLSID"
#define REGISTRY_IN_PROCESS		L"InprocServer32"
#define REGISTRY_THREADING		L"ThreadingModel"
#define REGISTRY_APARTMENT		L"Apartment"
#define REGISTRY_VERSION		L"Version"
#define REGISTRY_VERSION_NUMBER		L"1.0"

//Registry values for running
#define REGISTRY_ENABLE_OVERLAY		L"EnableOverlay"

#define GET_FILE_OVERLAY_ID		L"getFileIconId"

#define PORT				32586
