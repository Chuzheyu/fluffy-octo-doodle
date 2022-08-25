#include "stdafx.h"
#include "ClientSocket.h"
#include<list>
extern std::list<CClientSocket*> m_listSocket;

CClientSocket::CClientSocket(CChatserverDlg* dlg) : m_dlg(dlg)
{
}


CClientSocket::~CClientSocket()
{
}

void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	TCHAR meg[1024] = { 0 };
	Receive(meg, sizeof(meg));

	CString str;
	UINT port;
	GetPeerName(str, port);
	CString portstr;
	portstr.Format(L"%d", port);
	if (_tcscmp(meg, _T("FWAEGVSTBNDTYMYFUYSHTRGSE")) == 0) {
		for (auto it = m_listSocket.begin(); it != m_listSocket.end(); ++it)
		{
			CClientSocket *client = *it;
			if (client->ipStr == str && client->portStr == portstr) {
				m_listSocket.remove(client);
				client->m_dlg->RemoveItem(ipStr, portStr);
				delete client;
				break;
			}
		}
	}

	bool flag = false;
	for (auto it = m_listSocket.begin(); it != m_listSocket.end(); ++it)
	{
		CClientSocket *client = *it;
		if (client->ipStr == str && client->portStr == portstr) {
			flag = true;
			break;
		}
	}
	if (!flag) {
		return;
	}

	if (wcslen(meg) > 24) {
		TCHAR seps[] = _T("?");
		TCHAR* token = _tcstok((LPTSTR)(LPCTSTR)meg, seps);
		CString ipStr;
		CString portStr;
		if (token != nullptr) {
			if (_tcscmp(token, _T("ASDVZVTSRBT")) == 0) {
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
						DeleteItem(ipStr, portStr);
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

	CString allmsg;
	allmsg.Format(L"%s:%d>>%s\r\n", str, port, meg);
	

	std::list<CClientSocket*>::iterator it;
	for (it = m_listSocket.begin(); it != m_listSocket.end(); ++it)
	{
		CClientSocket *client = *it;
		client->Send(allmsg, allmsg.GetLength() * 2);
	}
	CSocket::OnReceive(nErrorCode);
}


void CClientSocket::DeleteItem(CString ipStr, CString portStr) {
	for (auto it = m_listSocket.begin(); it != m_listSocket.end(); ++it)
	{
		CClientSocket *client = *it;
		if (client->ipStr == ipStr && client->portStr == portStr) {
			CString endConnect = _T("DWEAGVTDBXBDTRNBYDN");
			client->Send(endConnect, endConnect.GetLength() * 2);
			m_listSocket.remove(client);
			delete client;
			m_dlg->RemoveItem(ipStr, portStr);
			break;
		}
	}
}