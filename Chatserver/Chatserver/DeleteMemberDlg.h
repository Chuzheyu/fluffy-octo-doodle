#pragma once
#include "ClientSocket.h"
#include "ChatserverDlg.h"
#include <list>

// DeleteMemberDlg �Ի���

class DeleteMemberDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteMemberDlg)

public:
	DeleteMemberDlg(CString ipString, CString portString, int num, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DeleteMemberDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum {
		IDD = IDD_DIALOG_DELETE
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
	CString m_ipString;
	CString m_portString;
	int num;
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonChange();
};
