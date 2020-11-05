
// SqliteDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SqliteDemo.h"
#include "SqliteDemoDlg.h"
#include "afxdialogex.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSqliteDemoDlg 对话框



CSqliteDemoDlg::CSqliteDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SQLITEDEMO_DIALOG, pParent)
	, m_pDataBase(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSqliteDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSqliteDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_NEW, &CSqliteDemoDlg::OnBnClickedBtnNew)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CSqliteDemoDlg::OnBnClickedBtnOpen)
	ON_BN_CLICKED(IDC_BTN_CREATE, &CSqliteDemoDlg::OnBnClickedBtnCreate)
	ON_BN_CLICKED(IDC_BTN_ADD, &CSqliteDemoDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_CLOSE, &CSqliteDemoDlg::OnBnClickedClose)
END_MESSAGE_MAP()


// CSqliteDemoDlg 消息处理程序

BOOL CSqliteDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSqliteDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSqliteDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSqliteDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSqliteDemoDlg::OnBnClickedBtnNew()
{
	char* file = "./SqliteDemo.db";
	if (PathFileExists(file))
	{
		AfxMessageBox(_T("创建数据库(SqliteDemo.db)已存在!"));
	}


	if (sqlite3_open(file, &m_pDataBase) != SQLITE_OK)
	{
		AfxMessageBox(_T("创建数据库(SqliteDemo.db)失败!"));
		sqlite3_close(m_pDataBase);
	}
}


void CSqliteDemoDlg::OnBnClickedBtnOpen()
{
	if (sqlite3_open("./SqliteDemo.db", &m_pDataBase) != SQLITE_OK)
	{
		AfxMessageBox(_T("打开数据库失败，请检查数据库是否已经损坏!"));
		sqlite3_close(m_pDataBase);
	}
}


void CSqliteDemoDlg::OnBnClickedBtnCreate()
{
	char* err = NULL;
	char* sql = "CREATE TABLE user(ID int, Name varchar(20), Age int)";
	if (sqlite3_exec(m_pDataBase, sql, NULL, NULL, &err) != SQLITE_OK)
	{
		AfxMessageBox(_T("创建表(user)失败，") + CString(err));
		//sqlite3_close(m_pDataBase);
	}
	else
	{
		AfxMessageBox(_T("创建表(user)成功。"));
	}
}


void CSqliteDemoDlg::OnBnClickedBtnAdd()
{
	char* err = NULL;
	char* sql = "insert into user values(1,'abc',10)";
	if (sqlite3_exec(m_pDataBase, sql, NULL, NULL, &err) != SQLITE_OK)
	{
		AfxMessageBox(_T("添加数据失败，") + CString(err));
		sqlite3_close(m_pDataBase);
	}
	else
	{
		AfxMessageBox(_T("添加数据成功。"));
	}
}


void CSqliteDemoDlg::OnBnClickedClose()
{
	// TODO: 在此添加控件通知处理程序代码
	sqlite3_close(m_pDataBase);
}
