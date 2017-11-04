
// OOPxe4Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Student.h"


// COOPxe4Dlg �Ի���
class COOPxe4Dlg : public CDialogEx
{
// ����
public:
	COOPxe4Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_OOPXE4_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	CStudent students[100];  //�洢ѧ����Ϣ
	static int num;     //���οؼ�������¼
	CImageList m_ImageTreeList;//�������οؼ�ͼ���б�

public:
	//������CTreeCtrlָ���ڵ�������ӽڵ�   
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

