﻿
// GrayScaleAlpha1Doc.h: CGrayScaleAlpha1Doc 클래스의 인터페이스
//


#pragma once


class CGrayScaleAlpha1Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CGrayScaleAlpha1Doc() noexcept;
	DECLARE_DYNCREATE(CGrayScaleAlpha1Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CGrayScaleAlpha1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// 입력 영상 배열
	unsigned char** m_inImage = NULL;
	// 출력 영상 배열
	unsigned char** m_outImage = NULL;

	// 입력 이미지 크기 (행/열)
	int m_inH = 0;
	int m_inW = 0;
	// 출력 이미지 크기 (행/열)
	int m_outH = 0;
	int m_outW = 0;

	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	unsigned char** malloc2D(int h, int w);
	void free2D(unsigned char** memory, int h);
	virtual void OnCloseDocument();
	void OnEqualImage();
	void OnNegaImage();
};
