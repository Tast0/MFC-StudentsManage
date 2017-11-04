
// OOPxe4Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "OOPxe4.h"
#include "OOPxe4Dlg.h"
#include "afxdialogex.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	

// 实现
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


// COOPxe4Dlg 对话框



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


// COOPxe4Dlg 消息处理程序

BOOL COOPxe4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/////////////////////////////////////////
	//建立树形控件图像列表，初始有0个图像
	this->m_ImageTreeList.Create(16, 16, ILC_COLOR24 | ILC_MASK, 0, 1);
	//向图像列表添加图标IDI_ICON8，作为0号图像（年级）
	this->m_ImageTreeList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	//向图像列表添加图标IDI_ICON9，作为1号图像（一年级）
	this->m_ImageTreeList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	//向图像列表添加图标IDI_ICON10，作为2号图像（二年级）
	this->m_ImageTreeList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	//向图像列表添加图标IDI_ICON10，作为3号图像（三年级）
	this->m_ImageTreeList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	//向图像列表添加图标IDI_ICON10，作为4号图像（学生）
	this->m_ImageTreeList.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	//将树形目录和图像列表关联
	this->m_TreeCon.SetImageList(&this->m_ImageTreeList, TVSIL_NORMAL);
	HTREEITEM root, root1, root2, root3;
	this->m_TreeCon.ModifyStyle(0, TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
	root = this->m_TreeCon.InsertItem(_T("年级"), 0, 0, TVI_ROOT, TVI_LAST);
	this->m_TreeCon.SetItemData(root, (DWORD)1000);

	root1 = this->m_TreeCon.InsertItem(_T("一年级"), 1, 1, root, TVI_LAST);
	this->m_TreeCon.SetItemData(root1, (DWORD)1001);
	root2 = this->m_TreeCon.InsertItem(_T("二年级"), 2, 2, root, TVI_LAST);
	this->m_TreeCon.SetItemData(root2, (DWORD)1002);
	root3 = this->m_TreeCon.InsertItem(_T("三年级"), 3, 3, root, TVI_LAST);
	this->m_TreeCon.SetItemData(root3, (DWORD)1003);
	//列表控件可视化
	m_Inquiry.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_ONECLICKACTIVATE);
	m_Inquiry.InsertColumn(0, _T("姓名"), LVCFMT_LEFT, 60);
	m_Inquiry.InsertColumn(1, _T("学号"), LVCFMT_LEFT, 70);
	m_Inquiry.InsertColumn(2, _T("年级"), LVCFMT_LEFT, 70);
	m_Inquiry.InsertColumn(3, _T("Sub1"), LVCFMT_LEFT, 60);
	m_Inquiry.InsertColumn(4, _T("Sub2"), LVCFMT_LEFT, 60);
	m_Inquiry.InsertColumn(5, _T("Sub3"), LVCFMT_LEFT, 60);

	////////////////////////////////////////
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void COOPxe4Dlg::OnPaint()
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
HCURSOR COOPxe4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HTREEITEM COOPxe4Dlg::FindItem(CTreeCtrl& treeCtrl, HTREEITEM  item, CString strtext, BOOL findChild)
{
	HTREEITEM  hfind = NULL;
	//空树，直接返回NULL
	if (item == NULL)
		return NULL;
	//遍历查找
	while (item != NULL)
	{
		//当前节点即所需查找节点
		if (treeCtrl.GetItemText(item) == strtext)
			return   item;
		//findChild==TRUE查找当前节点的子节点
		if (treeCtrl.ItemHasChildren(item) && findChild == TRUE)
		{
			item = treeCtrl.GetChildItem(item);
			//递归调用查找子节点下节点
			hfind = FindItem(treeCtrl, item, strtext, TRUE);
			if (hfind)
			{
				return  hfind;
			}
			else
			{
				//子节点中未发现所需节点，继续查找兄弟节点
				item = treeCtrl.GetNextSiblingItem(treeCtrl.GetParentItem(item));
			}
		}
		else
		{
			//若无子节点，继续查找兄弟节点
			item = treeCtrl.GetNextSiblingItem(item);
		}
	}
	return hfind;
}
//静态变量初始化
int COOPxe4Dlg::num = 0;
void COOPxe4Dlg::OnBnClickedAdd()
{
	////////////////判断用户输入是否合理///////////////////////
	if (!this->Judge())
	{
		return;
	}
	////////////////添加节点开始//////////////////////////////
	UpdateData();
	//记录信息录入开始
	this->students[this->num].name = this->m_Name;
	this->students[this->num].ID = this->m_ID;
	CString strGrade;//得到添加人员所在的年级
	this->m_Grade.GetWindowTextW((LPTSTR)(LPCTSTR)strGrade, 6);
	this->students[this->num].grade = strGrade;
	this->students[this->num].sub1 = this->m_Sub1;
	this->students[this->num].sub2 = this->m_Sub2;
	this->students[this->num].sub3 = this->m_Sub3;
	//记录信息录入结束

	HTREEITEM root;//查找树形控件根节点
	root = this->m_TreeCon.GetRootItem();	
	HTREEITEM node;//添加节点
	node = this->FindItem(m_TreeCon, root, strGrade, TRUE);	
	HTREEITEM newNode = this->m_TreeCon.InsertItem(this->m_Name, 4, 4, node, TVI_LAST);
	this->m_TreeCon.SetItemData(newNode, (DWORD)this->num);
	this->num++; //树形控件记录索引增加
	this->m_TreeCon.Expand(root, TVE_EXPAND);
	this->m_TreeCon.Expand(node, TVE_EXPAND);

	//日志增加 Add
	time_t tt = time(NULL);//这句返回的只是一个时间cuo
	tm* t = localtime(&tt);
	CString strTime;
	strTime.Format(_T("%02d : %02d"), t->tm_hour, t->tm_min);
	CString strLog;
	strLog = strTime + (CString)(" : DATE  ADD");
	int count = this->m_Log.GetCount();
	this->m_Log.InsertString(count, strLog);
	UpdateData(false);
	////////////////添加节点结束/////////////////////////////
}


void COOPxe4Dlg::OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 第四步：在OnDClickTree函数中添加鼠标单击消息响应代码   
	//获取当前鼠标点击消息的坐标点
	CPoint pt = GetCurrentMessage()->pt;
	
	//将鼠标的屏幕坐标，转换成树形控件的客户区坐标
	this->m_TreeCon.ScreenToClient(&pt);
	
	UINT uFlags = 0;
	HTREEITEM hItem = this->m_TreeCon.HitTest(pt, &uFlags);//然后做点击测试
	//HitTest一般是指鼠标点击位置上是哪个树结点,从而得到鼠标位置的树结点
	if ((hItem != NULL) && (TVHT_ONITEM & uFlags))//如果点击的位置是在节点位置上
	{
		this->m_TreeCon.SelectItem(hItem);
		//获取开始我们设置的数据，注意这就是我为什么开始要每个节点设置不同的数据的原因。
		//当然，如果你的数据节点比较少，你也可以通过获取节点的文字，如上面设置的"root，parent1，parent2······"，
		//然后通过字符串比较来判断点击了哪个节点 
		int nDat = this->m_TreeCon.GetItemData(hItem);   //然后根据不同的节点，你完成不同的动作即可 
		if (nDat > 100)
		{
			AfxMessageBox(_T("请选择人员节点进行双击！"));
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

		//日志增加 Double Click
		time_t tt = time(NULL);//这句返回的只是一个时间cuo
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
	// TODO:  在此添加控件通知处理程序代码
	UpdateData();
	this->m_Name = " "; //为什么加空格呢？
	this->m_ID = " ";
	this->m_Grade.ResetContent();
	this->m_Grade.AddString(_T("一年级"));
	this->m_Grade.AddString(_T("二年级"));
	this->m_Grade.AddString(_T("三年级"));
	this->m_Sub1 = 0;
	this->m_Sub2 = 0;
	this->m_Sub3 = 0;
	//日志增加 Reset
	time_t tt = time(NULL);//这句返回的只是一个时间cuo
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
	// TODO:  在此添加控件通知处理程序代码
	this->m_Log.ResetContent();
}

bool COOPxe4Dlg::JudgeName()
{
	UpdateData();
	this->m_Name.TrimLeft(_T("0123456789"));
	if (m_Name.IsEmpty())
	{//此时姓名里面的字符串全是数字  		
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
	{//学号是数字
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
	CString strGrade;//得到添加人员所在的年级
	this->m_Grade.GetWindowTextW((LPTSTR)(LPCTSTR)strGrade, 6);
	if (strGrade == _T("一年级") || strGrade == _T("二年级") || strGrade == _T("三年级"))
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
		AfxMessageBox(_T("名字输入格式有误！"));
		return false;
	}
	if (!this->JudgeID())
	{
		AfxMessageBox(_T("ID输入格式有误！"));
		return false;
	}
	if (!this->JudgeGrade())
	{
		AfxMessageBox(_T("请选择年级！"));
		return false;
	}
	if (!this->JudgeSub(this->m_Sub1))
	{
		AfxMessageBox(_T("Sub1应该在0-100！"));
		return false;
	}
	if (!this->JudgeSub(this->m_Sub2))
	{
		AfxMessageBox(_T("Sub2应该在0-100！"));
		return false;
	}
	if (!this->JudgeSub(this->m_Sub3))
	{
		AfxMessageBox(_T("Sub3应该在0-100！"));
		return false;
	}

	return true;
}