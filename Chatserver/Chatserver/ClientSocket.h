#pragma once
#include "afxsock.h"
#include "ChatserverDlg.h"
class CClientSocket :
	public CSocket
{
public:
	CClientSocket(CChatserverDlg* dlg);
	~CClientSocket();
	CString ipStr;
	CString portStr;
	CChatserverDlg* m_dlg;
	virtual void OnReceive(int nErrorCode);
	void DeleteItem(CString ipStr, CString portStr);
};

