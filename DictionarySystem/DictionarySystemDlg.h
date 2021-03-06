
// DictionarySystemDlg.h: 头文件
//

#pragma once


// CDictionarySystemDlg 对话框
class CDictionarySystemDlg : public CDialogEx
{
// 构造
public:
	CDictionarySystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DICTIONARYSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditChi();
	afx_msg void OnBnClickedSearchChi();
	CString search_chi;
	afx_msg void OnEnChangeEditEng();
	CString search_eng;
};
