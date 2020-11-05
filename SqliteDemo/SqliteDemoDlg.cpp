
// SqliteDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SqliteDemo.h"
#include "SqliteDemoDlg.h"
#include "afxdialogex.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CSqliteDemoDlg �Ի���



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


// CSqliteDemoDlg ��Ϣ�������

BOOL CSqliteDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSqliteDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSqliteDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSqliteDemoDlg::OnBnClickedBtnNew()
{
	char* file = "./SqliteDemo.db";
	if (PathFileExists(file))
	{
		AfxMessageBox(_T("�������ݿ�(SqliteDemo.db)�Ѵ���!"));
	}


	if (sqlite3_open(file, &m_pDataBase) != SQLITE_OK)
	{
		AfxMessageBox(_T("�������ݿ�(SqliteDemo.db)ʧ��!"));
		sqlite3_close(m_pDataBase);
	}
}


void CSqliteDemoDlg::OnBnClickedBtnOpen()
{
	if (sqlite3_open("./SqliteDemo.db", &m_pDataBase) != SQLITE_OK)
	{
		AfxMessageBox(_T("�����ݿ�ʧ�ܣ��������ݿ��Ƿ��Ѿ���!"));
		sqlite3_close(m_pDataBase);
	}
}


void CSqliteDemoDlg::OnBnClickedBtnCreate()
{
	char* err = NULL;
	char* sql = "CREATE TABLE user(ID int, Name varchar(20), Age int)";
	if (sqlite3_exec(m_pDataBase, sql, NULL, NULL, &err) != SQLITE_OK)
	{
		AfxMessageBox(_T("������(user)ʧ�ܣ�") + CString(err));
		//sqlite3_close(m_pDataBase);
	}
	else
	{
		AfxMessageBox(_T("������(user)�ɹ���"));
	}
}


void CSqliteDemoDlg::OnBnClickedBtnAdd()
{
	char* err = NULL;
	char* sql = "insert into user values(1,'abc',10)";
	if (sqlite3_exec(m_pDataBase, sql, NULL, NULL, &err) != SQLITE_OK)
	{
		AfxMessageBox(_T("�������ʧ�ܣ�") + CString(err));
		sqlite3_close(m_pDataBase);
	}
	else
	{
		AfxMessageBox(_T("������ݳɹ���"));
	}
}


void CSqliteDemoDlg::OnBnClickedClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	sqlite3_close(m_pDataBase);
}
