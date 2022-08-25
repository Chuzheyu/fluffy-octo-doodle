#include "stdafx.h"
#include "ClientSocket.h"
#include "ChatClientDlg.h"

CClientSocket::CClientSocket(CChatClientDlg *p):m_pDlg(p)
{
}


CClientSocket::~CClientSocket()
{
	CString endText = _T("FWAEGVSTBNDTYMYFUYSHTRGSE");
	Send(endText, endText.GetLength() * 2);
}


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	TCHAR msg[1024] = {0};
	Receive(msg, 1024 * 2);

	if (_tcscmp(msg, _T("DWEAGVTDBXBDTRNBYDN")) == 0) {
		AfxMessageBox(_T("您已被断开连接"));
		m_pDlg->Recover();
		return;
	}
	if (_tcscmp(msg, _T("DWEAGVTDBXBDTRNBYASFEDFV")) == 0) {
		AfxMessageBox(_T("您已被升级为管理员"));
		m_pDlg->Identity = true;
		return;
	}
	if (wcslen(msg) > 24) {
		TCHAR seps[] = _T("?");
		TCHAR* token = _tcstok((LPTSTR)(LPCTSTR)msg, seps);
		CString ipStr;
		CString portStr;
		if (token != nullptr) {
			if (_tcscmp(token, _T("CVASVERVBTR")) == 0) {
				m_pDlg->m_list.DeleteAllItems();
				token = _tcstok(NULL, seps);
				bool flag = false;
				for (int i = 0; i < wcslen(token); ++i) {
					if (!flag && token[i] == TCHAR(';')) {
						flag = true;
					}
					else if (!flag) {
						ipStr += token[i];
					}
					else if (flag && token[i] == TCHAR('|')) {
						m_pDlg->m_list.InsertItem(0, ipStr);
						m_pDlg->m_list.SetItemText(0, 1, portStr);
						ipStr = _T("");
						portStr = _T("");
						flag = false;
					}
					else {
						portStr += token[i];
					}
				}
				return;
			}
		}
	}
	//显示
	int length=m_pDlg->m_showText.GetWindowTextLength();
	m_pDlg->m_showText.SetSel(length, -1);
	m_pDlg->m_showText.ReplaceSel(msg);
	CSocket::OnReceive(nErrorCode);
}


