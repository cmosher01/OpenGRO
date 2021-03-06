// gedtreeViewPD.h : interface of the CGedtreeViewPD class
//
/////////////////////////////////////////////////////////////////////////////

#include "gedtreeview.h"

class CGedtreeDoc;
class CIndividual;

class CGedtreeViewPD : public CGedtreeView
{
protected: // create from serialization only
	CGedtreeViewPD();
	DECLARE_DYNCREATE(CGedtreeViewPD)

// Attributes
public:
	BOOL m_bInit;
	INT m_iIndi;
	int m_cGen;
	int m_dx, m_dy;

// Operations
public:
	void Init(int iIndi);
	wxString GetWindowTitle();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGedtreeViewPD)
	public:
	virtual void OnDraw(wxDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(wxDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(wxDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
	void PositionControls(int cx, int cy);
	void DrawGen(wxDC* pDC, wxPoint ptStart, int dx, int dy, int g, int iIndi);
	void DrawPerson(wxDC* pDC, wxPoint pt, CIndividual* pIndi);

public:
	virtual ~CGedtreeViewPD();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void Reset(UINT flagsChanged = -1);

// Generated message map functions
protected:
	//{{AFX_MSG(CGedtreeViewPD)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDblClk(UINT nFlags, wxPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_EVENT_TABLE()
};
/////////////////////////////////////////////////////////////////////////////
