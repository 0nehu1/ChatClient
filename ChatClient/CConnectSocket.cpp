#include "pch.h"
#include "CConnectSocket.h"
#include "ChatClientDlg.h"


void CConnectSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	ShutDown();
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("ERROR: Disconnected from server!"));
	::PostQuitMessage(0);
}


void CConnectSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	TCHAR szBuffer[1024];
	ZeroMemory(szBuffer, sizeof(szBuffer));

	if (Receive(szBuffer, sizeof(szBuffer)) > 0)
	{
		CChatClientDlg* pMain = (CChatClientDlg*)AfxGetMainWnd();
		pMain->m_List.AddString(szBuffer);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);
	}

	CSocket::OnReceive(nErrorCode);
}
