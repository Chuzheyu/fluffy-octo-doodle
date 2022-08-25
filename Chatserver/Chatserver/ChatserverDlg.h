
// ChatserverDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "ListenSocket.h"
#include "resource.h"
#include "ClientSocket.h"
#include "DeleteMemberDlg.h"
#include <list>
// CChatserverDlg 对话框
class CChatserverDlg : public CDialogEx
{
// 构造
public:
	CChatserverDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CChatserverDlg();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
