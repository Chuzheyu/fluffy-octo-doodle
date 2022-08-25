
// ChatClientDlg.h : 头文件
//

#pragma once
#include "ClientSocket.h"
#include "afxcmn.h"
#include "afxwin.h"

// CChatClientDlg 对话框
class CChatClientDlg : public CDialogEx
{
// 构造
public:
	CChatClientDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CChatClientDlg();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATCLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CClientSocket *m_pClientSocket;
	CIPAddressCtrl m_ip;
	bool Identity;
private:
	UINT m_uPort;
public:
	afx_msg void OnBnClickedButClose();
	afx_msg void OnBnClickedButConnect();
	afx_msg void OnBnClickedButSend();

	void Recover();
	CString m_text;
	CEdit m_showText;
	CListCtrl m_list;
	afx_msg void OnBnClickedButtonDelete();
};
