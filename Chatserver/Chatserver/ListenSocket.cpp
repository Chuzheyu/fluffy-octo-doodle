#include "stdafx.h"
#include "ListenSocket.h"
#include  "ChatserverDlg.h"
CListenSocket::CListenSocket(CChatserverDlg * m_pdlg):m_dlg(m_pdlg)
{
}


CListenSocket::~CListenSocket()
{
}


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_dlg->OnAccept();
	CSocket::OnAccept(nErrorCode);
}
