# Microsoft Developer Studio Project File - Name="PjOydCodeSystem" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=PjOydCodeSystem - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PjOydCodeSystem.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PjOydCodeSystem.mak" CFG="PjOydCodeSystem - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PjOydCodeSystem - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PjOydCodeSystem - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PjOydCodeSystem - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "PjOydCodeSystem - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "PjOydCodeSystem - Win32 Release"
# Name "PjOydCodeSystem - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Config.cpp
# End Source File
# Begin Source File

SOURCE=.\DBTSYSCategory.cpp
# End Source File
# Begin Source File

SOURCE=.\DBTSYSCodes.cpp
# End Source File
# Begin Source File

SOURCE=.\DBUtil1.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogNewCateGory.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogNewCodeTab.cpp
# End Source File
# Begin Source File

SOURCE=.\LeftTab1.cpp
# End Source File
# Begin Source File

SOURCE=.\LeftTab2.cpp
# End Source File
# Begin Source File

SOURCE=.\LeftTab3.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MonitorLeftView.cpp
# End Source File
# Begin Source File

SOURCE=.\MonitorRBOTTOMView.cpp
# End Source File
# Begin Source File

SOURCE=.\MonitorRightView.cpp
# End Source File
# Begin Source File

SOURCE=.\MonitorRTopView.cpp
# End Source File
# Begin Source File

SOURCE=.\MTSYSCategory.cpp
# End Source File
# Begin Source File

SOURCE=.\MTSYSCodes.cpp
# End Source File
# Begin Source File

SOURCE=.\MySplitter.cpp
# End Source File
# Begin Source File

SOURCE=.\PjOydCodeSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\PjOydCodeSystem.rc
# End Source File
# Begin Source File

SOURCE=.\PjOydCodeSystemDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\PjOydCodeSystemView.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Config.h
# End Source File
# Begin Source File

SOURCE=.\DBTSYSCategory.h
# End Source File
# Begin Source File

SOURCE=.\DBTSYSCodes.h
# End Source File
# Begin Source File

SOURCE=.\DBUtil1.h
# End Source File
# Begin Source File

SOURCE=.\DialogNewCateGory.h
# End Source File
# Begin Source File

SOURCE=.\DialogNewCodeTab.h
# End Source File
# Begin Source File

SOURCE=.\LeftTab1.h
# End Source File
# Begin Source File

SOURCE=.\LeftTab2.h
# End Source File
# Begin Source File

SOURCE=.\LeftTab3.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MonitorLeftView.h
# End Source File
# Begin Source File

SOURCE=.\MonitorRBOTTOMView.h
# End Source File
# Begin Source File

SOURCE=.\MonitorRightView.h
# End Source File
# Begin Source File

SOURCE=.\MonitorRTopView.h
# End Source File
# Begin Source File

SOURCE=.\MTSYSCategory.h
# End Source File
# Begin Source File

SOURCE=.\MTSYSCodes.h
# End Source File
# Begin Source File

SOURCE=.\MySplitter.h
# End Source File
# Begin Source File

SOURCE=.\PjOydCodeSystem.h
# End Source File
# Begin Source File

SOURCE=.\PjOydCodeSystemDoc.h
# End Source File
# Begin Source File

SOURCE=.\PjOydCodeSystemView.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon3.ico
# End Source File
# Begin Source File

SOURCE=.\res\PjOydCodeSystem.ico
# End Source File
# Begin Source File

SOURCE=.\res\PjOydCodeSystem.rc2
# End Source File
# Begin Source File

SOURCE=.\res\PjOydCodeSystemDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\T1.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\Notes.txt
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
