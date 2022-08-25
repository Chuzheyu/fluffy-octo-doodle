#pragma once
#include "afxsock.h"

class CChatClientDlg;
class CClientSocket :public CSocket
{
public:
	CClientSocket(CChatClientDlg *p);
	~CClientSocket();
	virtual void OnReceive(int nErrorCode);
private:
	CChatClientDlg * m_pDlg;
public:
//	virtual void OnClose(int nErrorCode);
};

