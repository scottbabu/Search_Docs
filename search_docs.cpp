#include <windows.h>
// #include <iostream>
#include <cstdlib>
#include <cstdio>
// #include <sqlite3.h>
// #include "sqlite3.h"
// #include <string>

#define IDC_MAIN_BUTTON	101
#define IDC_SEARCH_BUTTON	1000
#define IDC_ADD_BUTTON	1001
#define IDC_UPDATE_BUTTON 1002
#define IDC_DELETE_BUTTON 1003
#define IDC_CLEAR_BUTTON 1004
#define IDC_TITLE_EDIT	1011
#define IDC_PAGE_BUTTON	1012
#define IDC_DESC_BUTTON	1013
#define IDC_CONTENTS_BUTTON	1014
#define IDC_DOCS_LIST	1015
// #define IDC_MAIN_BUTTON	101
// #define IDC_MAIN_BUTTON	101


LRESULT CALLBACK WndProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
// void CreateLabels(HWND);

// HWND hwndSta1;
// HWND hwndSta2;
// HWND hwndSWidth;
// HWND hwndSHeight;
HWND hWndDocList;
HWND hDocListGroup;
HWND hSearchGroup;
HWND hSearchText;
HWND hSearchBtn;
HWND hWndButton;
HWND hDocInfoGroup;
HWND hDocInfoTitle;
HWND hDocInfoTitleLbl;
HWND hDocInfoPage;
HWND hDocInfoPageLbl;
HWND hDocInfoDesc;
HWND hDocInfoDescLbl;
HWND hDocInfoContents;
HWND hDocInfoContentsLbl;
HWND hDocInfoAddBtn;
HWND hDocInfoUpdateBtn;
HWND hDocInfoDeleteBtn;
HWND hDocInfoClearBtn;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  MSG Msg;
  HWND hWnd;


  //Settings All Window Class Variables
  WNDCLASSEX WndClsEx;
  WndClsEx.cbSize = sizeof(WNDCLASSEX);
  WndClsEx.style = CS_HREDRAW | CS_VREDRAW;
  WndClsEx.lpfnWndProc = WndProcedure;
  WndClsEx.cbClsExtra = 0;
  WndClsEx.cbWndExtra = 0;
  WndClsEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  WndClsEx.hInstance = hInstance;
  WndClsEx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
  WndClsEx.hCursor = LoadCursor(NULL, IDC_ARROW);
  // WndClsEx.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
  WndClsEx.hbrBackground=(HBRUSH)COLOR_WINDOW;
  // WndClsEx.hbrBackground = (HBRUSH) GetStockObject(DEFAULT_PALETTE);
  // WndClsEx.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
  
  WndClsEx.lpszMenuName = NULL;
  WndClsEx.lpszClassName = "My Window";


  //Register Window Class
  RegisterClassEx(&WndClsEx);


  //Create Window
  hWnd = CreateWindowEx(NULL, "My Window", "Search Documents", WS_OVERLAPPEDWINDOW, 200, 200, 640, 480, NULL, NULL, hInstance, NULL);

  // open db
  // sqlite3 * db;
  // char * zErrMsg = 0;
  // int rc;
  // rc = sqlite3_open("file:Search_Docs.db", &db);
  // if (rc)
  //   {
  //     // fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
  //     // exit(0);
  //   }
  // else
  //   {
  //     // fprintf(stderr, "Opened database successfully\n");
  //   }
  // sqlite3_close(db);
  
  // // add to left list
  // int pos_index;
  // pos_index = SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"one");
  // SendMessage(hwndList, LB_SETITEMDATA, pos_index, (LPARAM) 11); 
  // SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"two");
  // SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"Three");
  // SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"Four");
  // SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"Five");
  // SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"Six");
  // SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"Seven");



  //Show Window
  ShowWindow(hWnd, SW_SHOWNORMAL);


  while(GetMessage(&Msg, NULL, 0, 0))
    {
      TranslateMessage(&Msg);
      DispatchMessage(&Msg);
    }


  return 0;
}



LRESULT CALLBACK WndProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  char buffer[50] = "";
  // RECT rect;
  // wchar_t buf[10];
  
  
  switch(Msg)
    {
    case WM_INITDIALOG:
      {

      }
      break;
    case WM_CREATE:
      HFONT hCustomfont;

      // CreateLabels(hWnd);

      // setup font
      hCustomfont = CreateFont(16,0,0,0,FW_BOLD,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, TEXT("Times New Roman"));

      // setup group for list
      hDocListGroup = CreateWindowEx(NULL, "BUTTON", "Documents", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
             10,            /* X Position */
             10,            /* Y Position */
             250,           /* X Width */
             385,           /* Y Height */
             hWnd, NULL, GetModuleHandle(NULL), NULL);
      SendMessage(hDocListGroup, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));

      //Create Listbox's
      hWndDocList = CreateWindowEx(WS_EX_CLIENTEDGE, "LISTBOX", NULL, WS_BORDER | WS_VSCROLL | WS_CHILD | WS_VISIBLE | LBS_NOTIFY, 15, 30, 240, 360, hWnd,  (HMENU)IDC_DOCS_LIST, GetModuleHandle(NULL), NULL);
      SendMessage(hWndDocList, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));
      
      // -----------------------------------------------------------------------
      // create search box
      hSearchGroup = CreateWindowEx(NULL, "BUTTON", "Search Documents", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
             10,            /* X Position */
             400,            /* Y Position */
             250,           /* X Width */
             50,           /* Y Height */
             hWnd, NULL, GetModuleHandle(NULL), NULL);
      SendMessage(hSearchGroup, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));

      //create search text box
      hSearchText = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_VISIBLE | WS_CHILD, 15, 420, 165, 24, hWnd, NULL, GetModuleHandle(NULL), NULL);
      SendMessage(hSearchText, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));

      //Create Button
      hSearchBtn = CreateWindowEx(NULL, "BUTTON", "Search", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 185, 420, 65, 24, hWnd, (HMENU)IDC_SEARCH_BUTTON, GetModuleHandle(NULL), NULL);
      // hWndButton = CreateWindowEx(NULL, "BUTTON", "Search", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_DISABLED, 185, 285, 65, 24, hWnd, (HMENU)IDC_MAIN_BUTTON, GetModuleHandle(NULL), NULL);
      SendMessage(hSearchBtn, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));

      // -----------------------------------------------------------------------
      // create edit fields -  group
      hDocInfoGroup = CreateWindowEx(NULL, "BUTTON", "Document Information", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
             270,            /* X Position */
             10,            /* Y Position */
             350,           /* X Width */
             440,           /* Y Height */
             hWnd, NULL, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoGroup, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));

      // create title
      hDocInfoTitle = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "Document Title", WS_TABSTOP | WS_VISIBLE | WS_CHILD, 400, 30, 205, 24, hWnd, (HMENU)IDC_TITLE_EDIT, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoTitle, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));
      hDocInfoTitleLbl = CreateWindowEx(NULL, "STATIC", "Document Title:",  WS_VISIBLE | WS_CHILD, 277, 32, 115, 20, hWnd, NULL, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoTitleLbl, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));

      // create page
      hDocInfoPage = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "Page Number", WS_TABSTOP | WS_VISIBLE | WS_CHILD, 400, 60, 205, 24, hWnd, (HMENU)IDC_PAGE_BUTTON, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoPage, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));
      hDocInfoPageLbl = CreateWindowEx(NULL, "STATIC", "Page Number:", WS_TABSTOP | WS_VISIBLE | WS_CHILD, 277, 62, 115, 20, hWnd, NULL, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoPageLbl, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));

      // create description
      hDocInfoDesc = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "Description", WS_TABSTOP | WS_VISIBLE | WS_CHILD, 400, 90, 205, 24, hWnd, (HMENU)IDC_DESC_BUTTON, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoDesc, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));
      hDocInfoDescLbl = CreateWindowEx(NULL, "STATIC", "Description:", WS_VISIBLE | WS_CHILD, 277, 92, 115, 20, hWnd, NULL, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoDescLbl, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));

      // create contents
      hDocInfoContents = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "Contents", WS_TABSTOP | WS_VISIBLE | WS_CHILD|ES_MULTILINE|ES_AUTOVSCROLL|ES_AUTOHSCROLL, 277, 150, 330, 260, hWnd, (HMENU)IDC_CONTENTS_BUTTON, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoContents, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));
      hDocInfoContentsLbl = CreateWindowEx(NULL, "STATIC", "Contents:", WS_VISIBLE | WS_CHILD, 277, 122, 115, 20, hWnd, NULL, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoContentsLbl, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));

      // create buttons

      // add
      hDocInfoAddBtn = CreateWindowEx(NULL, "BUTTON", "Add", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON| WS_DISABLED, 280, 420, 65, 24, hWnd, (HMENU)IDC_ADD_BUTTON, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoAddBtn, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));
      // update
      hDocInfoUpdateBtn = CreateWindowEx(NULL, "BUTTON", "Update", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON| WS_DISABLED, 365, 420, 65, 24, hWnd, (HMENU)IDC_UPDATE_BUTTON, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoUpdateBtn, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));
      // delete
      hDocInfoDeleteBtn = CreateWindowEx(NULL, "BUTTON", "Delete", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON| WS_DISABLED, 460, 420, 65, 24, hWnd, (HMENU)IDC_DELETE_BUTTON, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoDeleteBtn, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));
      // clear
      hDocInfoClearBtn = CreateWindowEx(NULL, "BUTTON", "Clear", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 545, 420, 65, 24, hWnd, (HMENU)IDC_CLEAR_BUTTON, GetModuleHandle(NULL), NULL);
      SendMessage(hDocInfoClearBtn, WM_SETFONT, (WPARAM)hCustomfont, MAKELPARAM(FALSE, 0));
      // -----------------------------------------------------------------------
      // add to left list
      int pos_index;
      pos_index = SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"one");
      SendMessage(hWndDocList, LB_SETITEMDATA, pos_index, (LPARAM) "Item data 1");
	
      pos_index = SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"two");
      SendMessage(hWndDocList, LB_SETITEMDATA, pos_index, (LPARAM) "Item data 2");
	
      pos_index = SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"Three");
      SendMessage(hWndDocList, LB_SETITEMDATA, pos_index, (LPARAM) "Item data 3");
	
      pos_index = SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"Four");
      SendMessage(hWndDocList, LB_SETITEMDATA, pos_index, (LPARAM) "Item data 4");
	
      pos_index = SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"Five");
      SendMessage(hWndDocList, LB_SETITEMDATA, pos_index, (LPARAM) "Item data 5");
	
      pos_index = SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"Six");
      SendMessage(hWndDocList, LB_SETITEMDATA, pos_index, (LPARAM) "Item data 6");
	
      pos_index = SendMessage(hWndDocList, LB_ADDSTRING, NULL, (LPARAM)"Seven");
      SendMessage(hWndDocList, LB_SETITEMDATA, pos_index, (LPARAM) "Item data 7");
	
      
      break;
    case WM_COMMAND:
      switch(HIWORD(wParam))
	{
	case LBN_SELCHANGE:
	  {
	    //EnableWindow( GetDlgItem( hWnd, (HMENU)IDC_BUTTON_MAIN ), TRUE );
	    EnableWindow(hWndButton, true);
	    // get the index of the item selected
	    break;
	  }
	case LBN_DBLCLK:
	  {
	    int index = 0;
	    HWND hwndList = GetDlgItem(hWnd, IDC_DOCS_LIST); 
	    // Get selected index.
	    int lbItem = (int)SendMessage(hwndList, LB_GETCURSEL, 0, (LPARAM)&index); 
	    // Get item data.
	    char* data = (char *)SendMessage(hwndList, LB_GETITEMDATA, (WPARAM)index, 0);
	    
	    SendMessage(hDocInfoTitle, WM_SETTEXT, 0, (LPARAM)data);
	  }
	  break;
	}
      switch(LOWORD(wParam))
	{
	case IDC_MAIN_BUTTON:
	  {
	    //length = SendMessage(hWndDocList, LB_GETTEXTLEN, NULL, NULL);
	    SendMessage(hWndDocList, LB_GETTEXT, NULL, (LPARAM)buffer);
	    // SendMessage(hWndListR, LB_ADDSTRING, NULL, (LPARAM)buffer);
	    SendMessage(hWndDocList, LB_DELETESTRING, NULL, NULL);
	    EnableWindow(hWndButton, false);
	    break;
	  }
	case IDC_SEARCH_BUTTON:
	  {
	  }
	  break;
	case IDC_ADD_BUTTON:
	  {
	  }
	  break;
	case IDC_UPDATE_BUTTON:
	  {
	  }
	  break;
	case IDC_DELETE_BUTTON:
	  {
	  }
	  break;
	case  IDC_CLEAR_BUTTON:
	  {
	    SendMessage(hDocInfoTitle,WM_SETTEXT,NULL,(LPARAM)""); 
	    SendMessage(hDocInfoPage,WM_SETTEXT,NULL,(LPARAM)""); 
	    SendMessage(hDocInfoDesc,WM_SETTEXT,NULL,(LPARAM)""); 
	    SendMessage(hDocInfoContents,WM_SETTEXT,NULL,(LPARAM)""); 
	  }
	  break;
	}
      break;
      //    case WM_MOVE:
      // GetWindowRect(hWnd, &rect);

      // _itow(rect.left, buf, 10);
      // // SetWindowTextW(hwndSta1, buf);

      // _itow(rect.top, buf, 10);
      // SetWindowTextW(hwndSta2, buf);

      // break;
    case WM_GETMINMAXINFO:
      {
	LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
	lpMMI->ptMinTrackSize.x = 640;
	lpMMI->ptMinTrackSize.y = 480;
      }
      break; 
    case WM_SIZE:
      {
    	RECT rc;
    	GetClientRect(hWnd,&rc);
    	// check size
    	// if(rc.right >= 400)
    	//   {
	// move the search box
	// keep the width
	SetWindowPos(hSearchGroup, NULL, 10, rc.bottom - 50, 250, 50, SWP_NOZORDER);
	SetWindowPos(hSearchText, NULL, 15, rc.bottom - 30, 165, 24, SWP_NOZORDER);
	SetWindowPos(hSearchBtn, NULL, 185, rc.bottom - 30, 65, 24, SWP_NOZORDER);

	// move the docs list
	// make it longer
	SetWindowPos(hDocListGroup, NULL, 10, 10, 250, rc.bottom - 70, SWP_NOZORDER);
	SetWindowPos(hWndDocList, NULL, 15, 30, 240, rc.bottom - 95, SWP_NOZORDER);

	// move the doc info
	// keep left location
	// only make contents bigger
	SetWindowPos(hDocInfoGroup, NULL, 270, 10, rc.right - 280, rc.bottom - 10, SWP_NOZORDER);
	SetWindowPos(hDocInfoAddBtn, NULL, 280, rc.bottom - 35, 65, 24, SWP_NOZORDER);
	SetWindowPos(hDocInfoUpdateBtn, NULL, 365, rc.bottom - 35, 65, 24, SWP_NOZORDER);
	SetWindowPos(hDocInfoDeleteBtn, NULL, 450, rc.bottom - 35, 65, 24, SWP_NOZORDER);
	SetWindowPos(hDocInfoClearBtn, NULL, rc.right - 90, rc.bottom - 35, 65, 24, SWP_NOZORDER);
	SetWindowPos(hDocInfoContents, NULL, 277, 145, rc.right - 300, rc.bottom - 200, SWP_NOZORDER);
	SetWindowPos(hDocInfoPage, NULL, 400, 60, rc.right - 420, 24, SWP_NOZORDER);
	SetWindowPos(hDocInfoDesc, NULL, 400, 90, rc.right - 420, 24, SWP_NOZORDER);
	SetWindowPos(hDocInfoTitle, NULL, 400, 30, rc.right - 420, 24, SWP_NOZORDER);
	
	// SetWindowPos(hSearchGroup, NULL, 10, rc.bottom - 80, rc.right-50,rc.bottom-50, SWP_NOZORDER);
      }
      break;
    case WM_DESTROY:
      PostQuitMessage(WM_QUIT);
      break;
    }

  return DefWindowProc(hWnd, Msg, wParam, lParam);
}

// void CreateLabels(HWND hwnd) {

//   CreateWindowW(L"static", L"x: ", WS_CHILD | WS_VISIBLE, 210, 150, 25, 25, hwnd, (HMENU) 1, NULL, NULL);
//   hwndSta1 = CreateWindowW(L"static", L"150", WS_CHILD | WS_VISIBLE, 240, 150, 55, 25,  hwnd, (HMENU) 2, NULL, NULL);

//   CreateWindowW(L"static", L"y: ", WS_CHILD | WS_VISIBLE, 210, 190, 25, 25, hwnd, (HMENU) 3, NULL, NULL);
//   hwndSta2 = CreateWindowW(L"static", L"150", WS_CHILD | WS_VISIBLE, 240, 190, 55, 25,  hwnd, (HMENU) 4, NULL, NULL);

//   CreateWindowW(L"static", L"Height: ", WS_CHILD | WS_VISIBLE, 210, 230, 45, 25, hwnd, (HMENU) 3, NULL, NULL);
//   hwndSHeight = CreateWindowW(L"static", L"150", WS_CHILD | WS_VISIBLE, 260, 230, 55, 25,  hwnd, (HMENU) 4, NULL, NULL);

//   CreateWindowW(L"static", L"Width: ", WS_CHILD | WS_VISIBLE, 210, 270, 45, 25, hwnd, (HMENU) 3, NULL, NULL);
//   hwndSWidth = CreateWindowW(L"static", L"150", WS_CHILD | WS_VISIBLE, 260, 270, 55, 25,  hwnd, (HMENU) 4, NULL, NULL);

// }
