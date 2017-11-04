
// OOPxe4Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OOPxe4.h"
#include "OOPxe4Dlg.h"
#include "afxdialogex.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COOPxe4Dlg �Ի���



COOPxe4Dlg::COOPxe4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COOPxe4Dlg::IDD, pParent)
	, m_ID(_T(""))
	, m_Name(_T(""))
	, m_Sub2(0)
	, m_Sub1(0)
	, m_Sub3(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//this->num = 0;
}

void COOPxe4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_GRADE, m_Grade);
	DDX_Text(pDX, IDC_ID, m_ID);
	DDX_Control(pDX, IDC_LIST_LOG, m_Log);
	DDX_Control(pDX, IDC_LIST3, m_Inquiry);
	DDX_Text(pDX, IDC_NAME, m_Name);
	//  DDX_Control(pDX, IDC_SUBECT2, m_Sub2);
	DDX_Text(pDX, IDC_SUBECT2, m_Sub2);
	DDX_Text(pDX, IDC_SUBJECT1, m_Sub1);
	DDX_Text(pDX, IDC_SUBJECT3, m_Sub3);
	DDX_Control(pDX, IDC_TREE1, m_TreeCon);
}

BEGIN_MESSAGE_MAP(COOPxe4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &COOPxe4Dlg::OnBnClickedAdd)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, &COOPxe4Dlg::OnNMDblclkTree1)
	ON_BN_CLICKED(IDC_RESET, &COOPxe4Dlg::OnBnClickedReset)
	ON_BN_CLICKED(IDC_CLEAR, &COOPxe4Dlg::OnBnClickedClear)
END_MESSAGE_MAP()


// COOPxe4Dlg ��Ϣ�������

BOOL COOPxe4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/////////////////////////////////////////
	//�������οؼ�ͼ���б���ʼ��0��ͼ��
	this->m_ImageTreeList.Create(16, 16, ILC_COLOR24 | ILC_MASK, 0, 1);
	//��ͼ���б����ͼ��IDI_ICON8����Ϊ0��ͼ���꼶��
	this->m_ImageTreeList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	//��ͼ���б����ͼ��IDI_ICON9����Ϊ1��ͼ��һ�꼶��
	this->m_ImageTreeList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	//��ͼ���б����ͼ��IDI_ICON10����Ϊ2��ͼ�񣨶��꼶��
	this->m_ImageTreeList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	//��ͼ���б����ͼ��IDI_ICON10����Ϊ3��ͼ�����꼶��
	this->m_ImageTreeList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	//��ͼ���б����ͼ��IDI_ICON10����Ϊ4��ͼ��ѧ����
	this->m_ImageTreeList.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	//������Ŀ¼��ͼ���б����
	this->m_TreeCon.SetImageList(&this->m_ImageTreeList, TVSIL_NORMAL);
	HTREEITEM root, root1, root2, root3;
	this->m_TreeCon.ModifyStyle(0, TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
	root = this->m_TreeCon.InsertItem(_T("�꼶"), 0, 0, TVI_ROOT, TVI_LAST);
	this->m_TreeCon.SetItemData(root, (DWORD)1000);

	root1 = this->m_TreeCon.InsertItem(_T("һ�꼶"), 1, 1, root, TVI_LAST);
	this->m_TreeCon.SetItemData(root1, (DWORD)1001);
	root2 = this->m_TreeCon.InsertItem(_T("���꼶"), 2, 2, root, TVI_LAST);
	this->m_TreeCon.SetItemData(root2, (DWORD)1002);
	root3 = this->m_TreeCon.InsertItem(_T("���꼶"), 3, 3, root, TVI_LAST);
	this->m_TreeCon.SetItemData(root3, (DWORD)1003);
	//�б�ؼ����ӻ�
	m_Inquiry.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_ONECLICKACTIVATE);
	m_Inquiry.InsertColumn(0, _T("����"), LVCFMT_LEFT, 60);
	m_Inquiry.InsertColumn(1, _T("ѧ��"), LVCFMT_LEFT, 70);
	m_Inquiry.InsertColumn(2, _T("�꼶"), LVCFMT_LEFT, 70);
	m_Inquiry.InsertColumn(3, _T("Sub1"), LVCFMT_LEFT, 60);
	m_Inquiry.InsertColumn(4, _T("Sub2"), LVCFMT_LEFT, 60);
	m_Inquiry.InsertColumn(5, _T("Sub3"), LVCFMT_LEFT, 60);

	////////////////////////////////////////
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void COOPxe4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void COOPxe4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR COOPxe4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HTREEITEM COOPxe4Dlg::FindItem(CTreeCtrl& treeCtrl, HTREEITEM  item, CString strtext, BOOL findChild)
{
	HTREEITEM  hfind = NULL;
	//������ֱ�ӷ���NULL
	if (item == NULL)
		return NULL;
	//��������
	while (item != NULL)
	{
		//��ǰ�ڵ㼴������ҽڵ�
		if (treeCtrl.GetItemText(item) == strtext)
			return   item;
		//findChild==TRUE���ҵ�ǰ�ڵ���ӽڵ�
		if (treeCtrl.ItemHasChildren(item) && findChild == TRUE)
		{
			item = treeCtrl.GetChildItem(item);
			//�ݹ���ò����ӽڵ��½ڵ�
			hfind = FindItem(treeCtrl, item, strtext, TRUE);
			if (hfind)
			{
				return  hfind;
			}
			else
			{
				//�ӽڵ���δ��������ڵ㣬���������ֵܽڵ�
				item = treeCtrl.GetNextSiblingItem(treeCtrl.GetParentItem(item));
			}
		}
		else
		{
			//�����ӽڵ㣬���������ֵܽڵ�
			item = treeCtrl.GetNextSiblingItem(item);
		}
	}
	return hfind;
}
//��̬������ʼ��
int COOPxe4Dlg::num = 0;
void COOPxe4Dlg::OnBnClickedAdd()
{
	////////////////�ж��û������Ƿ����///////////////////////
	if (!this->Judge())
	{
		return;
	}
	////////////////��ӽڵ㿪ʼ//////////////////////////////
	UpdateData();
	//��¼��Ϣ¼�뿪ʼ
	this->students[this->num].name = this->m_Name;
	this->students[this->num].ID = this->m_ID;
	CString strGrade;//�õ������Ա���ڵ��꼶
	this->m_Grade.GetWindowTextW((LPTSTR)(LPCTSTR)strGrade, 6);
	this->students[this->num].grade = strGrade;
	this->students[this->num].sub1 = this->m_Sub1;
	this->students[this->num].sub2 = this->m_Sub2;
	this->students[this->num].sub3 = this->m_Sub3;
	//��¼��Ϣ¼�����

	HTREEITEM root;//�������οؼ����ڵ�
	root = this->m_TreeCon.GetRootItem();	
	HTREEITEM node;//��ӽڵ�
	node = this->FindItem(m_TreeCon, root, strGrade, TRUE);	
	HTREEITEM newNode = this->m_TreeCon.InsertItem(this->m_Name, 4, 4, node, TVI_LAST);
	this->m_TreeCon.SetItemData(newNode, (DWORD)this->num);
	this->num++; //���οؼ���¼��������
	this->m_TreeCon.Expand(root, TVE_EXPAND);
	this->m_TreeCon.Expand(node, TVE_EXPAND);

	//��־���� Add
	time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
	tm* t = localtime(&tt);
	CString strTime;
	strTime.Format(_T("%02d : %02d"), t->tm_hour, t->tm_min);
	CString strLog;
	strLog = strTime + (CString)(" : DATE  ADD");
	int count = this->m_Log.GetCount();
	this->m_Log.InsertString(count, strLog);
	UpdateData(false);
	////////////////��ӽڵ����/////////////////////////////
}


void COOPxe4Dlg::OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// ���Ĳ�����OnDClickTree�����������굥����Ϣ��Ӧ����   
	//��ȡ��ǰ�������Ϣ�������
	CPoint pt = GetCurrentMessage()->pt;
	
	//��������Ļ���꣬ת�������οؼ��Ŀͻ�������
	this->m_TreeCon.ScreenToClient(&pt);
	
	UINT uFlags = 0;
	HTREEITEM hItem = this->m_TreeCon.HitTest(pt, &uFlags);//Ȼ�����������
	//HitTestһ����ָ�����λ�������ĸ������,�Ӷ��õ����λ�õ������
	if ((hItem != NULL) && (TVHT_ONITEM & uFlags))//��������λ�����ڽڵ�λ����
	{
		this->m_TreeCon.SelectItem(hItem);
		//��ȡ��ʼ�������õ����ݣ�ע���������Ϊʲô��ʼҪÿ���ڵ����ò�ͬ�����ݵ�ԭ��
		//��Ȼ�����������ݽڵ�Ƚ��٣���Ҳ����ͨ����ȡ�ڵ�����֣����������õ�"root��parent1��parent2������������"��
		//Ȼ��ͨ���ַ����Ƚ����жϵ�����ĸ��ڵ� 
		int nDat = this->m_TreeCon.GetItemData(hItem);   //Ȼ����ݲ�ͬ�Ľڵ㣬����ɲ�ͬ�Ķ������� 
		if (nDat > 100)
		{
			AfxMessageBox(_T("��ѡ����Ա�ڵ����˫����"));
			return ;
		}

		int nCount = m_Inquiry.GetItemCount();
		m_Inquiry.InsertItem(nCount, this->students[nDat].name);
		m_Inquiry.SetItemText(nCount, 1, this->students[nDat].ID);
		m_Inquiry.SetItemText(nCount, 2, this->students[nDat].grade);
		CString strT;
		strT.Format(_T("%.1f"), this->students[nDat].sub1);
		m_Inquiry.SetItemText(nCount, 3, strT);
		strT.Format(_T("%.1f"), this->students[nDat].sub2);
		m_Inquiry.SetItemText(nCount, 4, strT);
		strT.Format(_T("%.1f"), this->students[nDat].sub3);
		m_Inquiry.SetItemText(nCount, 5, strT);

		//��־���� Double Click
		time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
		tm* t = localtime(&tt);
		CString strTime;
		strTime.Format(_T("%02d : %02d"), t->tm_hour, t->tm_min);
		CString strLog;
		strLog = strTime + (CString)(" : DATE  DOUBLE CLICK");
		int count = this->m_Log.GetCount();
		this->m_Log.InsertString(count, strLog);
	}	
	*pResult = 0;
}


void COOPxe4Dlg::OnBnClickedReset()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	this->m_Name = " "; //Ϊʲô�ӿո��أ�
	this->m_ID = " ";
	this->m_Grade.ResetContent();
	this->m_Grade.AddString(_T("һ�꼶"));
	this->m_Grade.AddString(_T("���꼶"));
	this->m_Grade.AddString(_T("���꼶"));
	this->m_Sub1 = 0;
	this->m_Sub2 = 0;
	this->m_Sub3 = 0;
	//��־���� Reset
	time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
	tm* t = localtime(&tt);
	CString strTime;
	strTime.Format(_T("%02d : %02d"), t->tm_hour, t->tm_min);
	CString strLog;
	strLog = strTime + (CString)(" : DATE  RESET");
	int count = this->m_Log.GetCount();
	this->m_Log.InsertString(count, strLog);
	UpdateData(false);

}

void COOPxe4Dlg::OnBnClickedClear()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->m_Log.ResetContent();
}

bool COOPxe4Dlg::JudgeName()
{
	UpdateData();
	this->m_Name.TrimLeft(_T("0123456789"));
	if (m_Name.IsEmpty())
	{//��ʱ����������ַ���ȫ������  		
		return false;
	}
	else
	{
		return true;
	}
}

bool COOPxe4Dlg::JudgeID()
{
	UpdateData();
	CString strID = m_ID;
	strID.TrimLeft(_T("0123456789"));
	if (strID.IsEmpty())
	{//ѧ��������
		return true;
	}
	else
	{
		return false;
	}
}

bool COOPxe4Dlg::JudgeGrade()
{
	UpdateData();
	CString strGrade;//�õ������Ա���ڵ��꼶
	this->m_Grade.GetWindowTextW((LPTSTR)(LPCTSTR)strGrade, 6);
	if (strGrade == _T("һ�꼶") || strGrade == _T("���꼶") || strGrade == _T("���꼶"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool COOPxe4Dlg::JudgeSub(double sub)
{
	UpdateData();
	if (sub > 0 && sub <= 100)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool COOPxe4Dlg::Judge()
{
	if (!this->JudgeName())
	{
		AfxMessageBox(_T("���������ʽ����"));
		return false;
	}
	if (!this->JudgeID())
	{
		AfxMessageBox(_T("ID�����ʽ����"));
		return false;
	}
	if (!this->JudgeGrade())
	{
		AfxMessageBox(_T("��ѡ���꼶��"));
		return false;
	}
	if (!this->JudgeSub(this->m_Sub1))
	{
		AfxMessageBox(_T("Sub1Ӧ����0-100��"));
		return false;
	}
	if (!this->JudgeSub(this->m_Sub2))
	{
		AfxMessageBox(_T("Sub2Ӧ����0-100��"));
		return false;
	}
	if (!this->JudgeSub(this->m_Sub3))
	{
		AfxMessageBox(_T("Sub3Ӧ����0-100��"));
		return false;
	}

	return true;
}