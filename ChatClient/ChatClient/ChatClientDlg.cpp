
// ChatClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChatClientDlg 对话框



CChatClientDlg::CChatClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHATCLIENT_DIALOG, pParent)
	, m_uPort(6666)
	, m_text(_T(""))
	, Identity(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pClientSocket = nullptr;
}

CChatClientDlg::~CChatClientDlg() {
	delete m_pClientSocket;
}

void CChatClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ip);
	DDX_Text(pDX, IDC_EDIT3, m_uPort);
	DDX_Text(pDX, IDC_EDIT2, m_text);
	DDX_Control(pDX, IDC_EDIT1, m_showText);
	DDX_Control(pDX, IDC_LIST_MEMBER, m_list);
}

BEGIN_MESSAGE_MAP(CChatClientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUT_CONNECT, &CChatClientDlg::OnBnClickedButConnect)
	ON_BN_CLICKED(IDC_BUT_SEND, &CChatClientDlg::OnBnClickedButSend)
	ON_BN_CLICKED(IDC_BUT_CLOSE, &CChatClientDlg::OnBnClickedButClose)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CChatClientDlg::OnBnClickedButtonDelete)
END_MESSAGE_MAP()


// CChatClientDlg 消息处理程序

BOOL CChatClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	GetDlgItem(IDC_BUT_CONNECT)->EnableWindow(true);
	m_ip.SetWindowTextW(L"127.0.0.1");
	UpdateData(false);

	m_list.InsertColumn(0, _T("IP地址"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, _T("端口地址"), LVCFMT_LEFT, 60);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChatClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CChatClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChatClientDlg::OnBnClickedButConnect()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str;
	m_ip.GetWindowText(str);
	if (str.IsEmpty() || str == L"0.0.0.0")
	{
		MessageBox(L"请输入有效IP地址!", L"TIPS!", MB_OK | MB_ICONERROR);
		return;
	}
	m_pClientSocket = new CClientSocket(this);
	if (FALSE == m_pClientSocket->Create())
	{
		CString str;
		str.Format(L"创建网络套接字失败!,错误码:%d", GetLastError());
		MessageBox(str, L"温馨提示", MB_OK | MB_ICONERROR);
		delete m_pClientSocket;
		m_pClientSocket = nullptr;
		return;
	}
	//连接套接字
	
	if (FALSE == m_pClientSocket->Connect(str, m_uPort))
	{
		MessageBox(L"连接失败！");
		delete m_pClientSocket;
		m_pClientSocket = nullptr;
		return;
	}
	GetDlgItem(IDC_BUT_CONNECT)->EnableWindow(false);

}


void CChatClientDlg::OnBnClickedButSend()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_pClientSocket == nullptr)
	{
		MessageBox(L"请先连接服务器!");
		return;
	}
	if (m_text.IsEmpty())
	{
		MessageBox(L"发送不能为空!");
		return;
	}
	if (m_text.GetLength()>1024)
	{
		MessageBox(L"发送信息太多，请少一点！");
		return;
	}

	if (0 > m_pClientSocket->Send(m_text, m_text.GetLength() * 2))
	{
		MessageBox(L"发送失败！");
		return;
	}
	m_text.Empty();
	UpdateData(false);

}


void CChatClientDlg::OnBnClickedButClose()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}

void CChatClientDlg::Recover() {
	GetDlgItem(IDC_BUT_CONNECT)->EnableWindow(true);
}

void CChatClientDlg::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Identity) {
		AfxMessageBox(_T("您不是管理员，没有权力踢人"));
	}
	else {
		POSITION pos = m_list.GetFirstSelectedItemPosition();
		if (pos)
		{
			int nItem = m_list.GetNextSelectedItem(pos);
			CString ipString = m_list.GetItemText(nItem, 0);
			CString portString = m_list.GetItemText(nItem, 1);
			CString endText = _T("ASDVZVTSRBT?");
			endText += (ipString + _T(";") + portString + _T("|"));
			m_pClientSocket->Send(endText, endText.GetLength() * 2);
		}
	}
}
