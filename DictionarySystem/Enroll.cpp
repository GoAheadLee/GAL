// Enroll.cpp: 实现文件
//

#include "stdafx.h"
#include "DictionarySystem.h"
#include "Enroll.h"
#include "afxdialogex.h"
#include "UserBaseInit.h"

// Enroll 对话框

IMPLEMENT_DYNAMIC(Enroll, CDialogEx)

Enroll::Enroll(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ENROLL, pParent)
	, enroll_username(_T(""))
	, enroll_password(_T(""))
{

}

Enroll::~Enroll()
{

}

void Enroll::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, enroll_username);
	DDX_Text(pDX, IDC_PASSWORD, enroll_password);
	DDV_MaxChars(pDX, enroll_password, 10);
}


BEGIN_MESSAGE_MAP(Enroll, CDialogEx)
	ON_BN_CLICKED(IDB_BUTTON_LOGIN, &Enroll::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// Enroll 消息处理程序


void Enroll::OnBnClickedButtonLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	UserBaseInit ubi;
	UpdateData(true);
	if (ubi.Check(enroll_username, enroll_password)) {
		MessageBox(_T("用户名已存在！"));
		return;
	}
	ubi.username = enroll_username;
	ubi.password = enroll_password;
	ubi.Input();
	MessageBox(_T("注册成功！"));
}
