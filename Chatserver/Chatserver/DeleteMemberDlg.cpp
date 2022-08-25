// DeleteMemberDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Chatserver.h"
#include "DeleteMemberDlg.h"
#include "afxdialogex.h"


// DeleteMemberDlg 对话框

IMPLEMENT_DYNAMIC(DeleteMemberDlg, CDialogEx)

DeleteMemberDlg::DeleteMemberDlg(CString ipString, CString portString, int num, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_DELETE, pParent),
	m_ipString(ipString),
	m_portString(portString),
	num(num)
{

}

DeleteMemberDlg::~DeleteMemberDlg()
{

}

void DeleteMemberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_IP, m_ipString);
	DDX_Text(pDX, IDC_EDIT_PORT, m_portString);
}


BEGIN_MESSAGE_MAP(DeleteMemberDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &DeleteMemberDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &DeleteMemberDlg::OnBnClickedButtonChange)
END_MESSAGE_MAP()


// DeleteMemberDlg 消息处理程序

BOOL DeleteMemberDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	UpdateData(false);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

extern std::list<CClientSocket*> m_listSocket;
void DeleteMemberDlg::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	for (auto it = m_listSocket.begin(); it != m_listSocket.end(); ++it)
	{
		CClientSocket *client = *it;
		if (client->ipStr == m_ipString && client->portStr == m_portString) {
			CString endConnect = _T("DWEAGVTDBXBDTRNBYDN");
			client->Send(endConnect, endConnect.GetLength() * 2);
			m_listSocket.remove(client);
			delete client;
			CChatserverDlg* parentDlg = (CChatserverDlg*)GetParent();
			parentDlg->RemoveItem(num);
			break;
		}
	}
	OnCancel();
	OnClose();
}


void DeleteMemberDlg::OnBnClickedButtonChange()
{
	// TODO: 在此添加控件通知处理程序代码
	for (auto it = m_listSocket.begin(); it != m_listSocket.end(); ++it)
	{
		CClientSocket *client = *it;
		if (client->ipStr == m_ipString && client->portStr == m_portString) {
			CString proID = _T("DWEAGVTDBXBDTRNBYASFEDFV");
			client->Send(proID, proID.GetLength() * 2);
			break;
		}
	}
}
