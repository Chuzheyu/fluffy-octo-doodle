// DeleteMemberDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Chatserver.h"
#include "DeleteMemberDlg.h"
#include "afxdialogex.h"


// DeleteMemberDlg �Ի���

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


// DeleteMemberDlg ��Ϣ�������

BOOL DeleteMemberDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	UpdateData(false);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

extern std::list<CClientSocket*> m_listSocket;
void DeleteMemberDlg::OnBnClickedButtonDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
