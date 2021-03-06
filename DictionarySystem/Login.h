#pragma once


// Login 对话框

class Login : public CDialogEx
{
	DECLARE_DYNAMIC(Login)

public:
	Login(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Login();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeUsername();
	afx_msg void OnBnClickedBLogin();
	afx_msg void OnBnClickedBEnroll();
	afx_msg void OnEnChangePassword();
	CString username;
	CString password;
	bool isClose = false;
};
