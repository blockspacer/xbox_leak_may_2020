#if !defined(AFX_ADSRENVELOPE_H__01CAA562_CC67_11D0_876A_00AA00C08146__INCLUDED_)
#define AFX_ADSRENVELOPE_H__01CAA562_CC67_11D0_876A_00AA00C08146__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CADSREnvelope wrapper class

class CADSREnvelope : public CWnd
{
protected:
	DECLARE_DYNCREATE(CADSREnvelope)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x71ae3626, 0xa9bd, 0x11d0, { 0xbc, 0xba, 0x0, 0xaa, 0x0, 0xc0, 0x81, 0x46 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	long GetReleaseTime();
	void SetReleaseTime(long);
	long GetDelayTime();
	void SetDelayTime(long);
	long GetAttackTime();
	void SetAttackTime(long);
	long GetHoldTime();
	void SetHoldTime(long);
	long GetDecayTime();
	void SetDecayTime(long);
	long GetSustainLevel();
	void SetSustainLevel(long);
	void SetDLS1(BOOL bDLS1);

// Operations
public:
	void AboutBox();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADSRENVELOPE_H__01CAA562_CC67_11D0_876A_00AA00C08146__INCLUDED_)