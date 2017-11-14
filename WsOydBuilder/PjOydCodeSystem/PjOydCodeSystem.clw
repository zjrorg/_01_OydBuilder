; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PjOydCodeSystem.h"
LastPage=0

ClassCount=14
Class1=CPjOydCodeSystemApp
Class2=CPjOydCodeSystemDoc
Class3=CPjOydCodeSystemView
Class4=CMainFrame
Class9=CMonitorRBOTTOMView

ResourceCount=13
Resource1=IDD_MONITORRBOTTOM_FORM
Resource2=IDD_MONITORRTOP_FORM
Resource3=IDD_ABOUTBOX
Resource4=IDD_LEFTTAB2
Resource5=IDD_PJOYDCODESYSTEM_FORM
Resource6=IDD_NEWCATEGORY
Resource7=IDD_MONITORLEFT_FORM
Resource8=IDD_MONITORRIGHT_FORM
Resource9=IDD_LEFTTAB1
Class5=CAboutDlg
Class6=CMonitorLeftView
Class7=CMonitorRightView
Class8=CMonitorRTopView
Class10=CLeftTab1
Class11=CLeftTab2
Class12=CLeftTab3
Resource10=IDD_LEFTTAB3
Class13=CDialogNewCateGory
Resource11=IDR_MENU1
Resource12=IDD_NEWCODETAB
Class14=CDialogNewCodeTab
Resource13=IDR_MAINFRAME

[CLS:CPjOydCodeSystemApp]
Type=0
HeaderFile=PjOydCodeSystem.h
ImplementationFile=PjOydCodeSystem.cpp
Filter=N

[CLS:CPjOydCodeSystemDoc]
Type=0
HeaderFile=PjOydCodeSystemDoc.h
ImplementationFile=PjOydCodeSystemDoc.cpp
Filter=N

[CLS:CPjOydCodeSystemView]
Type=0
HeaderFile=PjOydCodeSystemView.h
ImplementationFile=PjOydCodeSystemView.cpp
Filter=D
LastObject=CPjOydCodeSystemView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=IDMI_SAVE




[CLS:CAboutDlg]
Type=0
HeaderFile=PjOydCodeSystem.cpp
ImplementationFile=PjOydCodeSystem.cpp
Filter=D
LastObject=IDOK

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=IDMI_NEW
Command2=ID_APP_EXIT
Command3=IDMI_NEWCODETAB
Command4=IDMI_NEWCODE
Command5=IDMI_SAVE
Command6=IDMI_MDF
Command7=IDMI_DEL
Command8=ID_MENUITEM32783
Command9=ID_MENUITEM32784
Command10=ID_APP_ABOUT
CommandCount=10

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_PJOYDCODESYSTEM_FORM]
Type=1
Class=CPjOydCodeSystemView
ControlCount=0

[DLG:IDD_MONITORLEFT_FORM]
Type=1
Class=CMonitorLeftView
ControlCount=0

[DLG:IDD_MONITORRIGHT_FORM]
Type=1
Class=CMonitorRightView
ControlCount=0

[DLG:IDD_MONITORRTOP_FORM]
Type=1
Class=CMonitorRTopView
ControlCount=4
Control1=IDC_TXTNEWENGNAME,edit,1350631552
Control2=IDC_TXTNEWCHNNAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_MONITORRBOTTOM_FORM]
Type=1
Class=CMonitorRBOTTOMView
ControlCount=0

[CLS:CMonitorLeftView]
Type=0
HeaderFile=MonitorLeftView.h
ImplementationFile=MonitorLeftView.cpp
BaseClass=CFormView
Filter=D
VirtualFilter=VWC
LastObject=CMonitorLeftView

[CLS:CMonitorRightView]
Type=0
HeaderFile=MonitorRightView.h
ImplementationFile=MonitorRightView.cpp
BaseClass=CFormView
Filter=D

[CLS:CMonitorRTopView]
Type=0
HeaderFile=MonitorRTopView.h
ImplementationFile=MonitorRTopView.cpp
BaseClass=CFormView
Filter=D
VirtualFilter=VWC
LastObject=IDC_BTNTEST

[CLS:CMonitorRBOTTOMView]
Type=0
HeaderFile=MonitorRBOTTOMView.h
ImplementationFile=MonitorRBOTTOMView.cpp
BaseClass=CFormView
Filter=D
LastObject=CMonitorRBOTTOMView
VirtualFilter=VWC

[DLG:IDD_LEFTTAB1]
Type=1
Class=CLeftTab1
ControlCount=1
Control1=IDC_TREEMAIN,SysTreeView32,1350631456

[DLG:IDD_LEFTTAB2]
Type=1
Class=CLeftTab2
ControlCount=1
Control1=IDC_RADIO1,button,1342177289

[DLG:IDD_LEFTTAB3]
Type=1
Class=CLeftTab3
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:CLeftTab1]
Type=0
HeaderFile=LeftTab1.h
ImplementationFile=LeftTab1.cpp
BaseClass=CDialog
Filter=W
LastObject=CLeftTab1
VirtualFilter=dWC

[CLS:CLeftTab2]
Type=0
HeaderFile=LeftTab2.h
ImplementationFile=LeftTab2.cpp
BaseClass=CDialog
Filter=D
LastObject=CLeftTab2

[CLS:CLeftTab3]
Type=0
HeaderFile=LeftTab3.h
ImplementationFile=LeftTab3.cpp
BaseClass=CDialog
Filter=D
LastObject=CLeftTab3

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=IDT_NEW
CommandCount=1

[DLG:IDD_NEWCATEGORY]
Type=1
Class=CDialogNewCateGory
ControlCount=4
Control1=IDC_TXTNEWCATEGORYNAME,edit,1350631552
Control2=ID_OK,button,1342242817
Control3=IDC_CANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:CDialogNewCateGory]
Type=0
HeaderFile=DialogNewCateGory.h
ImplementationFile=DialogNewCateGory.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialogNewCateGory
VirtualFilter=dWC

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUITEM32775
CommandCount=1

[DLG:IDD_NEWCODETAB]
Type=1
Class=CDialogNewCodeTab
ControlCount=7
Control1=IDC_NEWCODEENGNAME,edit,1350631552
Control2=IDC_TXTNEWCATEGORYNAME,edit,1350631552
Control3=ID_OK,button,1342242817
Control4=IDC_CANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352

[CLS:CDialogNewCodeTab]
Type=0
HeaderFile=DialogNewCodeTab.h
ImplementationFile=DialogNewCodeTab.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_NEWCODEENGNAME
VirtualFilter=dWC

