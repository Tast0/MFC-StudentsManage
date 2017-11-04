
// OOPxe4Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Student.h"


// COOPxe4Dlg 对话框
class COOPxe4Dlg : public CDialogEx
{
// 构造
public:
	COOPxe4Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_OOPXE4_DIALOG };

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
	CComboBox m_Grade;
	CString m_ID;
	CListBox m_Log;
	CListCtrl m_Inquiry;
	CString m_Name;
	double m_Sub2;
	double m_Sub1;
	double m_Sub3;
	CTreeCtrl m_TreeCon;
	CStudent students[100];  //存储学生信息
	static int num;     //树形控件索引记录
	CImageList m_ImageTreeList;//定义树形控件图像列表

public:
	//用于在CTreeCtrl指定节点中添加子节点   
	HTREEITEM FindItem(CTreeCtrl& treeCtrl, HTREEITEM  item, CString strtext, BOOL findChild);
	afx_msg void OnBnClickedAdd();
	afx_msg void OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedReset();
	afx_msg void OnBnClickedClear();
	bool JudgeName();
	bool JudgeID();
	bool JudgeGrade();
	bool JudgeSub(double sub);
	bool Judge();
};

