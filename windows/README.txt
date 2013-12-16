StackSync overlays
==================

Prerequisites:
--------------

* Microsoft Visual Studio 2010
* Microsoft Windows SDK 7.1


Compiling:
----------

In order to compile Windows overlays we need to follow the next steps:

    1) Open the project with Visual Studio 2010.
    2) Open the "NativityOverlay.rc" file in "LiferayNativityOverlays/Resource Files" folder and 
       edit the following constant depending on the target overlay.
       
        /* SYNCING OVERLAY */
        IDI_ICON1 ICON "syncing.ico"

        /* UPTODATE OVERLAY */
        IDI_ICON1 ICON "uptodate.ico"

        /* ERROR OVERLAY */
        IDI_ICON1 ICON "error.ico"
       
    3) Open the "OverlayConstants.h" file in "LiferayNativityOverlays/Header Files" folder and
       edit the following constants depending on the target overlay.
       
        /* SYNCING OVERLAY */
        #define	OVERLAY_ID					1
        #define OVERLAY_GUID				L"{0DD5B4B0-25AF-4e09-A46B-9F274F3D7013}"
        #define OVERLAY_NAME				L"1StackSyncSyncingOverlay"

        /* UPTODATE OVERLAY */
        #define	OVERLAY_ID					2
        #define OVERLAY_GUID				L"{0DD5B4B1-25AF-4e09-A46B-9F274F3D7013}"
        #define OVERLAY_NAME				L"2StackSyncUptodateOverlay"

        /* ERROR OVERLAY */
        #define	OVERLAY_ID					3
        #define OVERLAY_GUID				L"{0DD5B4B2-25AF-4e09-A46B-9F274F3D7013}"
        #define OVERLAY_NAME				L"3StackSyncErrorOverlay"
        
    4) Compile the project in 32 and 64 bits and rename the output DLL to the following names 
       depending on the target platform and overlay:
    
        StackSyncSyncingOverlay_x86.dll 
        StackSyncSyncingOverlay_x64.dll
        StackSyncUptodateOverlay_x86.dll 
        StackSyncUptodateOverlay_x64.dll
        StackSyncErrorOverlay_x86.dll 
        StackSyncErrorOverlay_x64.dll
        

Testing:
--------

In order for the overlay icons to work, StackSync must set the following registry keys:

"HKEY_CURRENT_USER\Software\StackSync\EnableOverlay" to "1"
"HKEY_CURRENT_USER\Software\StackSync\FilterFolder" to the current syncing folder (e.g. "C:\Users\john\stacksync_folder")

