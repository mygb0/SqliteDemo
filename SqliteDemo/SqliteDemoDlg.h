
// SqliteDemoDlg.h : ͷ�ļ�
//

#pragma once

#include "sqlite/sqlite3.h"

// CSqliteDemoDlg �Ի���
class CSqliteDemoDlg : public CDialogEx
{
// ����
public:
	CSqliteDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SQLITEDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnNew();
private:
	sqlite3 *m_pDataBase;
public:
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnCreate();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedClose();
};
