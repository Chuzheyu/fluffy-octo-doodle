#pragma once
#include "ClientSocket.h"
#include "ChatserverDlg.h"
#include <list>

// DeleteMemberDlg 对话框

class DeleteMemberDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteMemberDlg)

public:
	DeleteMemberDlg(CString ipString, CString portString, int num, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DeleteMemberDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum {
		IDD = IDD_DIALOG_DELETE
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
	CString m_ipString;
	CString m_portString;
	int num;
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonChange();
};
