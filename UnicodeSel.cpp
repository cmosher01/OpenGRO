// UnicodeSel.cpp : implementation file
//

#include "stdafx.h"
#include "gedtree.h"
#include "UnicodeSel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUnicodeSel dialog


CUnicodeSel::CUnicodeSel(wxWindow* pParent /*=NULL*/)
	: wxDialog(CUnicodeSel::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUnicodeSel)
	m_bUnicode = FALSE;
	//}}AFX_DATA_INIT
	ReadFromRegistry();
}


void CUnicodeSel::DoDataExchange(CDataExchange* pDX)
{
	wxDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUnicodeSel)
	DDX_Radio(pDX, IDC_ASCII, m_bUnicode);
	//}}AFX_DATA_MAP
}

void CUnicodeSel::ReadFromRegistry()
{
	theApp.GetReg("Unicode","Unicode",m_bUnicode,FALSE);
}

void CUnicodeSel::WriteToRegistry()
{
	if (!theApp.m_info.m_bPermanent)
		theApp.PutReg("Unicode","Unicode",m_bUnicode);
}

BEGIN_EVENT_TABLE(CUnicodeSel, wxDialog)
	//{{AFX_MSG_MAP(CUnicodeSel)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_EVENT_TABLE()

/////////////////////////////////////////////////////////////////////////////
// CUnicodeSel message handlers

void CUnicodeSel::OnOK() 
{
	wxDialog::OnOK();
	WriteToRegistry();
}
