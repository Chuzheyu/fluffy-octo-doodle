
// ChatserverDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "ListenSocket.h"
#include "resource.h"
#include "ClientSocket.h"
#include "DeleteMemberDlg.h"
#include <list>
// CChatserverDlg �Ի���
class CChatserverDlg : public CDialogEx
{
// ����
public:
	CChatserverDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CChatserverDlg();
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATSERVER_DIALOG };
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

private:
	CListCtrl m_list;
public:
	CListenSocket *m_pListenSocket;
	int m_portNum;
	void OnAccept();
	void RemoveItem(int num);
	void RemoveItem(CString ipStr, CString portStr);
	void Refresh();
	afx_msg void OnBnClickedButStart();
	afx_msg void OnBnClickedButStop();
	afx_msg void OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonSetport();
};
