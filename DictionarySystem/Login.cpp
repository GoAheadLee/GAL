// Login.cpp: 实现文件
//

#include "stdafx.h"
#include "DictionarySystem.h"
#include "Login.h"
#include "afxdialogex.h"
#include <iostream>
#include "Enroll.h"
#include "UserBaseInit.h"
#include "Administrators.h"


// Login 对话框

IMPLEMENT_DYNAMIC(Login, CDialogEx)

Login::Login(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN, pParent)
	, username(_T(""))
	, password(_T(""))
{

}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, username);
	DDV_MaxChars(pDX, username, 10);
	DDX_Text(pDX, IDC_PASSWORD, password);
	DDV_MaxChars(pDX, password, 10);
}


BEGIN_MESSAGE_MAP(Login, CDialogEx)
	ON_EN_CHANGE(IDC_USERNAME, &Login::OnEnChangeUsername)
	ON_BN_CLICKED(IDB_B_LOGIN, &Login::OnBnClickedBLogin)
	ON_BN_CLICKED(IDB_B_ENROLL, &Login::OnBnClickedBEnroll)
	ON_EN_CHANGE(IDC_PASSWORD, &Login::OnEnChangePassword)
END_MESSAGE_MAP()


// Login 消息处理程序


void Login::OnEnChangeUsername()                                  //用户名输入框
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Login::OnEnChangePassword()                                 //密码输入框
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void Login::OnBnClickedBLogin()                              //确认按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UserBaseInit ubi;
	/*登陆判定*/
	UpdateData(true);

	/*CString judge_username;																				
	CString judge_password;
	CStdioFile file;
	file.Open(_T("UserBase.txt"), CFile::modeRead);
	while(file.ReadString(judge_username)&&file.ReadString(judge_password)){
		if (judge_username == username && judge_password == password) {
			isClose = true;
			CDialog::OnOK();//点即登陆就可以进入主框架
			return;
		}
	} */
	if (username == "0"&&password == "0") {
		Administrators ads;
		ads.DoModal();
		return;
	}
	if (ubi.Check(username, password)) {
		isClose = true;
		CDialog::OnOK();
	}
	else {
		MessageBox(_T("账号或密码错误！"), _T("错误"));  //账号或密码错误
	}
}


void Login::OnBnClickedBEnroll()                         //注册按钮
{
	// TODO: 在此添加控件通知处理程序代码
	Enroll eroll;
	eroll.DoModal();
}
