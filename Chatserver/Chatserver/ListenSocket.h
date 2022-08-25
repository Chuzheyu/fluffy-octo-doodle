#pragma once
#include "afxsock.h"
class CChatserverDlg;
class CListenSocket :public CSocket
{
private:
	CChatserverDlg * m_dlg;
public:
	CListenSocket(CChatserverDlg * m_pdlg);
	~CListenSocket();
	virtual void OnAccept(int nErrorCode);
};

