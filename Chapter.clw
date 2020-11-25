; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlg_ShowPicStatic
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Chapter.h"
LastPage=0

ClassCount=7
Class1=CChapterApp
Class2=CChapterDoc
Class3=CChapterView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDD_Dlg_ShowPicStatic
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX
Class6=CDlg_ShowPicDynamic
Class7=CDlg_ShowPicStatic
Resource4=IDD_Dlg_ShowPicDynamic

[CLS:CChapterApp]
Type=0
HeaderFile=Chapter.h
ImplementationFile=Chapter.cpp
Filter=N

[CLS:CChapterDoc]
Type=0
HeaderFile=ChapterDoc.h
ImplementationFile=ChapterDoc.cpp
Filter=N

[CLS:CChapterView]
Type=0
HeaderFile=ChapterView.h
ImplementationFile=ChapterView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CChapterView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_M_ShowPicDynamic




[CLS:CAboutDlg]
Type=0
HeaderFile=Chapter.cpp
ImplementationFile=Chapter.cpp
Filter=D
LastObject=CAboutDlg

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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_M_ShowPicStatic
Command18=ID_M_ShowPicDynamic
CommandCount=18

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

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_Dlg_ShowPicStatic]
Type=1
Class=CDlg_ShowPicStatic
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342181902

[DLG:IDD_Dlg_ShowPicDynamic]
Type=1
Class=CDlg_ShowPicDynamic
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDlg_ShowPicDynamic]
Type=0
HeaderFile=Dlg_ShowPicDynamic.h
ImplementationFile=Dlg_ShowPicDynamic.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlg_ShowPicDynamic
VirtualFilter=dWC

[CLS:CDlg_ShowPicStatic]
Type=0
HeaderFile=Dlg_ShowPicStatic.h
ImplementationFile=Dlg_ShowPicStatic.cpp
BaseClass=CDialog
Filter=D

