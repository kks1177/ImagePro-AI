# 영상(정지,웹캠, 유튜브) 처리 툴
# ===================================
# 기능
# - 좌측화면은  원본 출력(720x까지)
# - 중간화면은 처리 출력(1초에1번)
# - 우측화면은 정보 출력(객체인식이미지까지)
# 사진, 동영상, 웹캠, 유튜브까지 가능하게끔.
# ===================================
# -*-coding:utf-8-*-
import sys
import math
from tkinter import *
from tkinter.colorchooser import *
from tkinter.simpledialog import *
from tkinter.filedialog import *
import cv2
import numpy as np
import os
import random
import threading
import pafy#, youtube_dl


# # ============ 함수 =================
# # # -------------- 공통함수 -------------------
def mainThread():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global canvas_hist, paper_hist, canvas_hist
    global sx, sy, ex, ey, boxLine, status
    # # # 메뉴창 선언
    mainMenu = Menu(window)  # 메뉴 창
    window.config(menu=mainMenu)  # 세부설정(메뉴 창)
    # # # # 메뉴창_파일
    fileMenu = Menu(mainMenu)
    mainMenu.add_cascade(label="파일", menu=fileMenu)
    fileMenu.add_command(label="열기", command=openImage)
    fileMenu.add_command(label="저장", command=saveImage)
    fileMenu.add_separator()
    fileMenu.add_command(label="종료", command=None)
    #### 메뉴창_화소점처리
    pxpointMenu = Menu(mainMenu)
    mainMenu.add_cascade(label="화소점필터", menu=pxpointMenu)
    pxpointMenu.add_command(label="동일", command=equalImage)
    pxpointMenu.add_command(label="반전", command=reverseImage)
    pxpointMenu.add_command(label="127흑백", command=bw127Image)
    pxpointMenu.add_command(label="평균흑백", command=bwAvgImage)
    pxpointMenu.add_command(label="더하기밝기", command=lightPlusImage)
    pxpointMenu.add_command(label="감마", command=gammaImage)
    pxpointMenu.add_command(label="파라볼라(cap)", command=paraCapImage)
    pxpointMenu.add_command(label="파라볼라(cup)", command=paraCupImage)
    #### 메뉴창_기하학처리
    ghhMenu = Menu(mainMenu)
    mainMenu.add_cascade(label="기하학처리", menu=ghhMenu)
    ghhMenu.add_command(label="이동이미지", command=moveImage)
    ghhMenu.add_command(label="상하미러링", command=mirrorUpImage)
    ghhMenu.add_command(label="좌우미러링", command=mirrorLRImage)
    ghhMenu.add_command(label="확대", command=zoomInImage)
    ghhMenu.add_command(label="축소", command=zoomOutImage)
    ghhMenu.add_command(label="양선형확대", command=zoomYSInImage)
    ghhMenu.add_command(label="중앙회전", command=roateImage)
    #### 메뉴창_화소영역처리
    pxAreaMenu = Menu(mainMenu)
    mainMenu.add_cascade(label="화소영역필터", menu=pxAreaMenu)
    pxAreaMenu.add_command(label="엠보싱", command=embosImage)
    pxAreaMenu.add_command(label="평균블러", command=blurAvgImage)
    pxAreaMenu.add_command(label="가우스블러(3x3)", command=gausBlrImage)
    pxAreaMenu.add_command(label="고주파패스필터", command=hpfImage)
    pxAreaMenu.add_command(label="고주파필터", command=lpfImage)
    #### 메뉴창_화소영역처리(엣지처리)
    pxAreaEdgeMenu = Menu(mainMenu)
    mainMenu.add_cascade(label="엣지필터", menu=pxAreaEdgeMenu)
    pxAreaEdgeMenu.add_command(label="유사연산", command=calcUsaImage)
    pxAreaEdgeMenu.add_command(label="차연산", command=calcMnsImage)
    pxAreaEdgeMenu.add_separator()
    pxAreaEdgeMenu.add_command(label="로버츠", command=robertsImage)
    pxAreaEdgeMenu.add_command(label="프리윗", command=prwImage)
    pxAreaEdgeMenu.add_command(label="소벨", command=sblImage)
    pxAreaEdgeMenu.add_separator()
    pxAreaEdgeMenu.add_command(label="라플라", command=laplaImage)
    pxAreaEdgeMenu.add_command(label="LoG", command=logFilterImage)
    pxAreaEdgeMenu.add_command(label="DoG", command=dogFilterImage)
    #### 메뉴창_히스토그램처리
    histogramMenu = Menu(mainMenu)
    mainMenu.add_cascade(label="히스토그램", menu=histogramMenu)
    histogramMenu.add_command(label="스트레칭", command=histStrchImage)
    histogramMenu.add_command(label="평활화", command=histEqualImage)

    #### 메뉴창_OpenCV용 메뉴
    openCVMenu = Menu(mainMenu)
    mainMenu.add_cascade(label="OpenCV", menu=openCVMenu)
    openCVMenu.add_command(label="회색", command=grayImage_cv)
    openCVMenu.add_command(label="엠보스", command=embossImage_cv)
    openCVMenu.add_command(label="카툰", command=cartoonImage_cv)
    openCVMenu.add_command(label="오렌지_블루검출", command=hsvOrangeBlueImage_cv)
    openCVMenu.add_command(label="블러", command=blurImage_cv)
    openCVMenu.add_command(label="확대", command=zoomInImage_cv)
    openCVMenu.add_command(label="축소", command=zoomOutImage_cv)
    openCVMenu.add_command(label="사이즈변경", command=reSizeImage_cv)
    #### 메뉴창_clf인식용 메뉴
    clfMenu = Menu(mainMenu)
    mainMenu.add_cascade(label="clf인식", menu=clfMenu)
    clfMenu.add_command(label="얼굴인식", command=faceDetect_cv)
    clfMenu.add_command(label="눈인식", command=eyeDetect_cv)
    clfMenu.add_command(label="입인식", command=mouthDetect_cv)
    #### 메뉴창_영역선택용 메뉴
    selectClickMenu = Menu(mainMenu)
    mainMenu.add_cascade(label="영역선택", menu=selectClickMenu)
    selectClickMenu.add_command(label="반전", command=mouseClick_reverseImage)

    #### 메뉴창_동영상
    UCCMenu = Menu(mainMenu)
    mainMenu.add_cascade(label="동영상", menu=UCCMenu)
    UCCMenu.add_command(label="웹캠", command=displayUCCThreading)
    UCCMenu.add_command(label="웹캠_객체인식(Haar)", command=haarDisplayUCCThreading)
    UCCMenu.add_command(label="웹캠_객체인식(SSD)", command=ssdDisplayUCCThreading)
    UCCMenu.add_command(label="유튜브", command=yotubeDisplayThreading)
    UCCMenu.add_command(label="유튜브_평활화", command=yotubeEqaulDisplayThreading)
    UCCMenu.add_command(label="유튜브_평활화_SSD", command=yotubeEqaulSSDDisplayThreading)

    # # # 화면 선언
    # # # # 캔버스 (Output Image)
    canvas = Canvas(window, height=m_outH + 255, width=m_outW + 255, bg='black')  # 캔버스 위젯
    paper = PhotoImage(width=500, height=500)  # paper 초기화
    canvas.create_image((500 / 2, 500 / 2), image=paper,
                        state='normal')  # 캔버스 중앙에 paper 그리기
    # # # # 캔버스 (Histogram)
    canvas_hist = Canvas(window, height=255, width=255, bg='black')
    paper_hist = PhotoImage(width=255, height=255)  # paper 초기화
    canvas_hist.create_image((255 / 2, 255 / 2), image=paper,
                             state='normal')  # 캔버스 중앙에 paper 그리기
    ##### pack
    canvas_hist.grid(row=0, column=2, sticky="s")
    canvas.grid(row=0, column=1, sticky="n")

    ##### pack

    window.mainloop()


def malloc3D(h, w, init=0):
    # init =0 <- 디폴트 파라미터 선언
    global RGB
    # 지역변수
    memory = [[[init for _ in range(w)] for _ in range(h)]
              for _ in range(RGB)]  # RGB 3차원 리스트 선언
    return memory


def malloc3D_double(h, w, init=0.0):  # *** 수정바람
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    # 지역변수
    memory = [[[init for _ in range(w)] for _ in range(h)]
              for _ in range(RGB)]  # 리스트 함축
    return memory


def openImage():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine, status
    # 파일 선택하고 크기 계산
    ## 파일 이름으로 파일 찾기
    filename = askopenfilename(parent=window,
                               filetypes=(("컬러 파일", "*.jpg *.png *.bmp *tiff *.tif"), ("모든파일", "*.*")))
    ## CV용 개체생성
    cvInPhoto = cv2.imread(filename)

    ## 영상 크기 알아내기
    # m_inH = cvInPhoto.shape[0]
    # m_inW = cvInPhoto.shape[1]
    m_inH, m_inW = cvInPhoto.shape[:2]  # [0:2]0~1까지
    # 메모리 할당
    m_InputImage = malloc3D(m_inH, m_inW)
    # 파일 --> 메모리
    ## OpenCV 는 BGR 순으로 출력
    for i in range(m_inH):
        for k in range(m_inW):
            m_InputImage[RR][i][k] = cvInPhoto.item(i, k, BB)
            m_InputImage[GG][i][k] = cvInPhoto.item(i, k, GG)
            m_InputImage[BB][i][k] = cvInPhoto.item(i, k, RR)
    print(m_InputImage[RR][100][100], m_InputImage[GG]
    [100][100], m_InputImage[BB][100][100])
    equalImage()


##### 이미지 저장
def saveImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    # 빈 OpenCV 개체 생성
    saveCvPhoto = np.zeros((m_outH, m_outW, 3), np.uint8)  # 넘파이배열 사용
    # 출력리스트 --> 넘파이 배열
    ## BGR 순서
    for i in range(m_outH):
        for k in range(m_outW):
            tp = tuple(
                ([m_OutputImage[BB][i][k], m_OutputImage[GG][i][k], m_OutputImage[RR][i][k]]))  # tuple(): 튜플로 만들어주는 함수
            saveCvPhoto[i, k] = tp

    saveFp = asksaveasfile(parent=window, mode='wb', defaultextension='.',
                           filetypes=(("컬러 파일", "*.jpg *.png *.bmp *tiff *.tif"), ("모든파일", "*.*")))
    cv2.imwrite(saveFp.name, saveCvPhoto)
    print("Save")


# OUTPUT 디스플레이
def displayImage():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global m_reH, m_reW
    global m_histImage
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    # 캔버스
    ## 캔버스 초기화(이전것 없애기)
    if canvas != None:
        canvas.destroy()
    # 히스토그램 출력
    histogramImage()
    ## 사이즈 일정하게 ( 640 x 360 크기 안으로 )
    tempOutputImage = None
    reH = m_outH
    reW = m_outW
    maxSize = 640 * 360
    reScale = 1
    ## 빠른출력(C++식, 더블버퍼, 빠름 )
    rgbString = ""
    ### Output사이즈가 크면 (줄이기)
    if maxSize <= reH * reW:
        print("축소")
        reScale = int(math.sqrt((reH * reW) / maxSize))
        if int(reScale) <= 0:
            reScale = 1
        reH = int(reH / reScale)
        reW = int(reW / reScale)
        tempOutputImage = malloc3D(reH, reW)
        for rgb in range(RGB):
            for i in range(reH):
                for k in range(reW):
                    m = m_OutputImage[rgb][int(i * reScale)][int(k * reScale)]
                    tempOutputImage[rgb][i][k] = m

    ### 사이즈가 작으면 (양선형 보간으로 키우기)
    elif maxSize > reH * reW:
        print("양선형확대")
        reScale = int(math.sqrt(maxSize / (reH * reW)))
        if int(reScale) <= 0:
            reScale = 1
        reH = int(m_outH * reScale)
        reW = int(m_outW * reScale)
        tempImage = malloc3D(m_outH, m_outW)
        tempOutputImage = malloc3D(reH, reW)
        for rgb in range(RGB):
            for i in range(m_outH):
                for k in range(m_outW):
                    tempImage[rgb][i][k] = m_OutputImage[rgb][i][k]

        r_H, r_W, s_H, s_W = [0.0] * 4
        i_W, i_H, v = [0] * 3
        for rgb in range(RGB):
            for i in range(reH):
                for k in range(reW):
                    r_H = i / reScale
                    r_W = k / reScale

                    i_H = int(math.floor(r_H))  # 내림.celi = 올림
                    i_W = int(math.floor(r_W))

                    s_H = r_H - i_H
                    s_W = r_W - i_W

                    if (i_H < 0 or i_H >= (m_outH - 1) or i_W < 0 or i_W >= (m_outW - 1)):
                        tempOutputImage[rgb][i][k] = 255
                    else:
                        C1 = tempImage[rgb][i_H][i_W]  # A
                        C2 = tempImage[rgb][i_H][i_W + 1]  # B
                        C3 = tempImage[rgb][i_H + 1][i_W + 1]  # C
                        C4 = tempImage[rgb][i_H + 1][i_W]  # D
                        v = int(C1 * (1 - s_H) * (1 - s_W) + C2 * s_W *
                                (1 - s_H) + C3 * s_W * s_H + C4 * (1 - s_W) * s_H)
                        tempOutputImage[rgb][i][k] = v
    print("scale :", reScale)
    print(reH, "x", reW)
    for i in range(reH):
        tmpStr = ""  # 한 라인
        for k in range(reW):
            r = tempOutputImage[RR][i][k]
            g = tempOutputImage[GG][i][k]
            b = tempOutputImage[BB][i][k]
            # 'rgb ' 로 넣기 (마지막 띄어쓰기로 구분처리(구분처리 안하면 못읽음))
            tmpStr += "#%02x%02x%02x " % (r, g, b)
        # '{rgb} ' 로 넣기 (마지막 띄어쓰기로 구분처리(구분처리 안하면 못읽음))
        rgbString += "{" + tmpStr + "} "

    ## 윈도우 화면 크기 딱 맞추기
    ### oepnCV는 geometry 가 반대이다.
    window.geometry(str(reW + 265) + "x" + str(reH + 20))
    canvas = Canvas(window, height=reH, width=reW)  # 캔버스 위젯
    paper = PhotoImage(height=reH, width=reW)  # paper 초기화
    canvas.create_image((reW / 2, reH / 2), image=paper,
                        state='normal')  # 캔버스 중앙에 paper 그리기
    paper.put(rgbString)
    # canvas 출력
    canvas_hist.grid(row=0, column=2, sticky="s")
    canvas.grid(row=0, column=1, sticky="n")

    # 상태창 설정
    status.configure(text=str(m_inW) + "x" + str(m_inH) + '    ' + filename)


# HISTOGRAM 디스플레이
def displayHistogram():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global canvas_hist, paper_hist, canvas_hist
    global m_histImage
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    # 캔버스
    ## 캔버스 초기화(이전것 없애기)
    if canvas_hist != None:
        canvas_hist.destroy()
    ## 윈도우 화면 크기 딱 맞추기
    ### oepnCV는 geometry 가 반대이다.
    canvas_hist = Canvas(window, height=256, width=256)  # 캔버스 위젯
    paper_hist = PhotoImage(height=256, width=256)  # paper 초기화
    canvas_hist.create_image((256 / 2, 256 / 2), image=paper_hist,
                             state='normal')  # 캔버스 중앙에 paper 그리기
    ## 빠른출력(C++식, 더블버퍼, 빠름)
    rgbString = ""
    for i in range(256):
        tmpStr = ""  # 한 라인
        for k in range(256):
            r = m_histImage[RR][i][k]
            g = m_histImage[GG][i][k]
            b = m_histImage[BB][i][k]
            # 'rgb ' 로 넣기 (마지막 띄어쓰기로 구분처리(구분처리 안하면 못읽음))
            tmpStr += "#%02x%02x%02x " % (r, g, b)
        # '{rgb} ' 로 넣기 (마지막 띄어쓰기로 구분처리(구분처리 안하면 못읽음))
        rgbString += "{" + tmpStr + "} "
    paper_hist.put(rgbString)
    # canvas pack
    canvas_hist.grid(row=0, column=1)
    # 상태창 설정


#### 히스토그램 출력 (BGR)
def histogramImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global canvas_hist, paper_hist, canvas_hist
    global m_histImage
    if not m_OutputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[히스토그램출력]")
    # 히스토그램 크기
    outH = 256
    outW = 256

    # 출력 메모리 할당
    m_histImage = malloc3D(outH, outW)
    # 히스토그램 데이터 초기화
    reSize = outH * outW

    LOW = 0
    HIGH = 255
    histR = [0 for _ in range(256)]
    histG = [0 for _ in range(256)]
    histB = [0 for _ in range(256)]
    valueR, valueG, valueB = [0] * 3
    print(valueR, valueG, valueB)
    # 빈도수 조사
    for i in range(m_outH):
        for k in range(m_outW):
            valueR = m_OutputImage[RR][i][k]
            valueG = m_OutputImage[GG][i][k]
            valueB = m_OutputImage[BB][i][k]
            histR[valueR] += 1
            histG[valueG] += 1
            histB[valueB] += 1
    # 정규화
    minR, minG, minB = [0] * 3
    maxR, maxG, maxB = [0] * 3
    difR, difG, difB = [0] * 3
    print(minR, minG, minB)
    print(maxR, maxG, maxB)
    print(difR, difG, difB)
    for i in range(256):
        if (histR[i] <= minR):
            minR = histR[i]
        if (histR[i] >= maxR):
            maxR = histR[i]
        if (histG[i] <= minG):
            minG = histG[i]
        if (histG[i] >= maxG):
            maxG = histG[i]
        if (histB[i] <= minB):
            minB = histB[i]
        if (histB[i] >= maxB):
            maxB = histB[i]
    difR = maxR - minR
    difG = maxG - minG
    difB = maxB - minB
    print(difR, difG, difB)
    scaleHistR = [255 for _ in range(256)]
    scaleHistG = [255 for _ in range(256)]
    scaleHistB = [255 for _ in range(256)]
    # 정규화 된 히스토그램
    for i in range(256):
        scaleHistR[i] = int((histR[i] - minR) * HIGH / difR)
        scaleHistG[i] = int((histG[i] - minG) * HIGH / difG)
        scaleHistB[i] = int((histB[i] - minB) * HIGH / difB)
    # 정규화된 히스토그램 출력
    OutImageR = [255 for _ in range(reSize)]
    OutImageG = [255 for _ in range(reSize)]
    OutImageB = [255 for _ in range(reSize)]
    for i in range(outH):
        for k in range(scaleHistR[i]):
            OutImageR[outW * (outH - k - 1) + i] = 0
        for k in range(scaleHistG[i]):
            OutImageG[outW * (outH - k - 1) + i] = 0
        for k in range(scaleHistB[i]):
            OutImageB[outW * (outH - k - 1) + i] = 0
    histNum = 0
    # BGR로 출력
    for i in range(outH):
        for k in range(outW):
            m_histImage[RR][i][k] = OutImageB[histNum]
            m_histImage[GG][i][k] = OutImageG[histNum]
            m_histImage[BB][i][k] = OutImageR[histNum]
            histNum += 1
    displayHistogram()


# # # -------------- 영상처리함수 -------------
# # # ~~~~C++ 기반 알고리즘~~~~
# # # # 동일 이미지
def equalImage():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine, status
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    # (중요!) 출력 영상 크기 결정 --> 알고리즘에 따름
    m_outH = m_inH
    m_outW = m_inW
    # 출력 메모리 할당
    m_OutputImage = malloc3D(m_outH, m_outW)
    ## 진짜 영상처리 알고리즘
    for rgb in range(RGB):
        for h in range(m_inH):
            for w in range(m_inW):
                m_OutputImage[rgb][h][w] = m_InputImage[rgb][h][w]
    displayImage()


#### 반전 이미지
def reverseImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    # (중요!) 출력 영상 크기 결정 --> 알고리즘에 따름
    m_outH = m_inH
    m_outW = m_inW
    # 출력 메모리 할당
    m_OutputImage = malloc3D(m_outH, m_outW)
    ## 진짜 영상처리 알고리즘
    for rgb in range(RGB):
        for h in range(m_inH):
            for w in range(m_inW):
                m_OutputImage[rgb][h][w] = 255 - m_InputImage[rgb][h][w]
    displayImage()


#### 127흑백이미지
def bw127Image():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)
    print("[127흑백이미지]")
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                if (m_InputImage[rgb][i][k] > 127):
                    m_OutputImage[RR][i][k] = 255
                    m_OutputImage[GG][i][k] = 255
                    m_OutputImage[BB][i][k] = 255
                else:
                    m_OutputImage[RR][i][k] = 0
                    m_OutputImage[GG][i][k] = 0
                    m_OutputImage[BB][i][k] = 0
    displayImage()


#### 평균흑백이미지
def bwAvgImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)
    print("[평균흑백이미지]")
    avg = 0
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                avg += m_InputImage[RR][i][k]
                avg += m_InputImage[GG][i][k]
                avg += m_InputImage[BB][i][k]
    # 평균구하기
    avg /= m_inH * m_inW * rgb * 3
    print(m_inH * m_inW * 3)
    print(avg)
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                if (m_InputImage[rgb][i][k] > avg):
                    m_OutputImage[RR][i][k] = 255
                    m_OutputImage[GG][i][k] = 255
                    m_OutputImage[BB][i][k] = 255
                else:
                    m_OutputImage[RR][i][k] = 0
                    m_OutputImage[GG][i][k] = 0
                    m_OutputImage[BB][i][k] = 0
    displayImage()


#### 더하기밝기이미지
def lightPlusImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)
    print("[더하기밝기이미지]")
    number = askfloat("입력창", "원하는 밝기강도를 입력")
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                if (m_InputImage[rgb][i][k] + 100) > 255:
                    m_OutputImage[rgb][i][k] = 255
                else:
                    m_OutputImage[rgb][i][k] = m_InputImage[rgb][i][k] + 100
    displayImage()


#### 감마이미지
def gammaImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)
    print("[감마이미지]")
    gamma = askfloat("입력창", "0.3~1.6에서 입력하세요")
    if gamma > 1.6:
        gamma = 1.6
    elif gamma < 0:
        gamma = 0
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                m = m_InputImage[rgb][i][k]
                m_OutputImage[rgb][i][k] = int(
                    255.0 * math.pow(m / 255.0, gamma))
    displayImage()


#### Cap파라이미지
def paraCapImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)
    print("[Cap파라이미지]")
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                valueR = 255.0 - 255.0 * \
                         math.pow((m_InputImage[RR][i][k] /
                                   128.0 - 1.0), 2)  # 밝은 곳 입체형 (CAP)
                if (valueR > 255.0):
                    valueR = 255.0
                elif (valueR < 0.0):
                    valueR = 0.0
                valueG = 255.0 - 255.0 * \
                         math.pow((m_InputImage[GG][i][k] / 128.0 - 1.0), 2)
                if (valueG > 255.0):
                    valueG = 255.0
                elif (valueG < 0.0):
                    valueG = 0.0
                valueB = 255.0 - 255.0 * \
                         math.pow((m_InputImage[BB][i][k] / 128.0 - 1.0), 2)
                if (valueB > 255.0):
                    valueB = 255.0
                elif (valueB < 0.0):
                    valueB = 0.0
                m_OutputImage[RR][i][k] = int(valueR)
                m_OutputImage[GG][i][k] = int(valueG)
                m_OutputImage[BB][i][k] = int(valueB)
    print(255.0 - 255.0 *
          math.pow((m_InputImage[rgb][100][100] / 128.0 - 1.0), 2))
    displayImage()


#### Cup파라이미지
def paraCupImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)
    print("[Cup파라이미지]")
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                # 밝은 곳 입체형 (CAP)
                valueR = 255.0 * \
                         math.pow((m_InputImage[RR][i][k] / 128.0 - 1.0), 2)
                if (valueR > 255.0):
                    valueR = 255.0
                elif (valueR < 0.0):
                    valueR = 0.0
                valueG = 255.0 * \
                         math.pow((m_InputImage[GG][i][k] / 128.0 - 1.0), 2)
                if (valueG > 255.0):
                    valueG = 255.0
                elif (valueG < 0.0):
                    valueG = 0.0
                valueB = 255.0 * \
                         math.pow((m_InputImage[BB][i][k] / 128.0 - 1.0), 2)
                if (valueB > 255.0):
                    valueB = 255.0
                elif (valueB < 0.0):
                    valueB = 0.0
                m_OutputImage[RR][i][k] = int(valueR)
                m_OutputImage[GG][i][k] = int(valueG)
                m_OutputImage[BB][i][k] = int(valueB)
    print(255.0 - 255.0 *
          math.pow((m_InputImage[rgb][100][100] / 128.0 - 1.0), 2))
    displayImage()


#### 확대이미지
def zoomInImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    scale = askinteger("입력창", "원하는 배율을 입력하세요", )
    if scale < 0:
        scale = 0
    m_outH = m_inH * scale
    m_outW = m_inW * scale
    m_OutputImage = malloc3D(m_outH, m_outW)
    print("[확대이미지]")
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                m = m_InputImage[rgb][int(i / scale)][int(k / scale)]
                m_OutputImage[rgb][i][k] = m
    displayImage()


#### 축소이미지
def zoomOutImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    scale = askinteger("입력창", "원하는 배율을 입력하세요")
    if scale <= 0:
        scale = 1
    m_outH = int(m_inH / scale)
    m_outW = int(m_inW / scale)
    m_OutputImage = malloc3D(m_outH, m_outW)
    print("[축소이미지]")
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                m = m_InputImage[rgb][int(i * scale)][int(k * scale)]
                m_OutputImage[rgb][i][k] = m
    displayImage()


#### 양선형확대이미지
def zoomYSInImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[양선형확대이미지]")
    scale = askinteger("입력창", "원하는 배율을 입력하세요")
    if scale <= 0:
        scale = 1
    m_outH = int(m_inH * scale)
    m_outW = int(m_inW * scale)
    tempImage = malloc3D(m_inH, m_inW)
    m_OutputImage = malloc3D(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tempImage[rgb][i][k] = m_InputImage[rgb][i][k]

    r_H, r_W, s_H, s_W = [0.0] * 4
    i_W, i_H, v = [0] * 3
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                r_H = i / scale
                r_W = k / scale

                i_H = int(math.floor(r_H))  # 내림.celi = 올림
                i_W = int(math.floor(r_W))

                s_H = r_H - i_H
                s_W = r_W - i_W

                if (i_H < 0 or i_H >= (m_inH - 1) or i_W < 0 or i_W >= (m_inW - 1)):
                    m_OutputImage[rgb][i][k] = 255
                else:
                    C1 = tempImage[rgb][i_H][i_W]  # A
                    C2 = tempImage[rgb][i_H][i_W + 1]  # B
                    C3 = tempImage[rgb][i_H + 1][i_W + 1]  # C
                    C4 = tempImage[rgb][i_H + 1][i_W]  # D
                    v = int(C1 * (1 - s_H) * (1 - s_W) + C2 * s_W *
                            (1 - s_H) + C3 * s_W * s_H + C4 * (1 - s_W) * s_H)
                    m_OutputImage[rgb][i][k] = v

    displayImage()


#### 회전이미지  TODO: 회전방향고치기 _반시계로 돌아간다..
def roateImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    angle = askinteger("입력창", "원하는 각도를 입력하세요")

    tmp_radian = angle % 90 * 3.141592 / 180.0
    tmp_radian90 = (90 - angle % 90) * 3.141592 / 180.0
    # 출력 영상의 높이와 폭을 결정 --> 알고리즘에 따름
    m_outH = (int)(m_inH * math.cos(tmp_radian90) +
                   m_inW * math.cos(tmp_radian))
    m_outW = (int)(m_inW * math.cos(tmp_radian) +
                   m_inW * math.cos(tmp_radian90))
    # 출력 영상 메모리 할당
    radian = angle * 3.141592 / 180.0
    m_OutputImage = malloc3D(m_outH, m_outW)
    # 임시 입력 영상 ---> 출력과 크기가 같게 하고, 입력 영상을 중앙에 두기.
    tmpInput = malloc3D(m_outH, m_outW)
    dx = int((m_outH - m_inH) / 2)
    dy = int((m_outW - m_inW) / 2)
    # 임시 입력 영상 ---> 출력과 크기가 같게 하고, 입력 영상을 중앙에 두기.
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + dx][k + dy] = m_InputImage[rgb][i][k]
    # 중앙 위치 구하기
    cx = int(m_outH / 2)
    cy = int(m_outW / 2)
    print("[회전(30도)이미지]")
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                oldI = int((math.cos(radian) * (i - cx) +
                            math.sin(radian) * (k - cy)) + cx)
                oldK = int((-math.sin(radian) * (i - cx) +
                            math.cos(radian) * (k - cy)) + cy)
                if (((0 <= oldI) and (oldI < m_outH)) and ((0 <= oldK) and (oldK < m_outW))):
                    m_OutputImage[rgb][i][k] = tmpInput[rgb][oldI][oldK]
    displayImage()


#### 이동이미지
def moveImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    input = askinteger("입력창", "원하는 움직임을 입력하세요")
    if input < 0:
        input = 0
    m_outH = m_inH + input
    m_outW = m_inW + input
    m_OutputImage = malloc3D(m_outH, m_outW)
    print("[이동이미지]")
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                m_OutputImage[rgb][i + input][k +
                                              input] = m_InputImage[rgb][i][k]
    displayImage()


#### 상하미러링
def mirrorUpImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)
    print("[상하미러링]")
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                m_OutputImage[rgb][i][k] = m_InputImage[rgb][m_inH - i - 1][k]
    displayImage()


#### 좌우미러링
def mirrorLRImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)
    print("[좌우미러링]")
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                m_OutputImage[rgb][i][k] = m_InputImage[rgb][i][m_inW - k - 1]
    displayImage()


#### 엠보싱이미지
def embosImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[엠보싱이미지]")
    # 마스크
    mask = [[-1.0, 0.0, 0.0],
            [0.0, 0.0, 0.0],
            [0.0, 0.0, 1.0]]
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 2, m_inW + 2)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 1][k + 1] = m_InputImage[rgb][i][k]
    # 마스크 회선 연산
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(3):
                    for n in range(3):
                        S += tmpInput[rgb][i + m][k + n] * mask[m][n]
                tmpOutput[rgb][i][k] = S
    # 다듬기
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                tmpOutput[rgb][i][k] += 127.0
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v = tmpOutput[rgb][i][k]
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### 평균블러이미지 ***TODO: 이상하게 나온다. 다시하기
def blurAvgImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[평균블러이미지]")
    # 마스크 ( 입력값에 맞게 블러를 만들어준다 )
    scale = askinteger("입력창", "원하는 블러강도 입력하세요")
    if scale < 0:
        scale = 0
    if scale % 2 == 0:
        scale += 1
    mask = [[0 for _ in range(scale)] for _ in range(scale)]
    for i in range(scale):
        for k in range(scale):
            mask[i][k] = float(1.0 / scale * scale)
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(
        m_inH + int(scale / 2) * 2, m_inW + int(scale / 2) * 2)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + int(scale / 2)][k +
                                                  int(scale / 2)] = m_InputImage[rgb][i][k]
    # 마스크 회선 연산
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(scale):
                    for n in range(scale):
                        S += tmpInput[rgb][i + m][k + n] * mask[m][n]
                tmpOutput[rgb][i][k] = S
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v = tmpOutput[rgb][i][k]
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### 가우스블러(3x3)처리
def gausBlrImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[가우스블러처리]")
    # 마스크
    mask = [[1.0 / 16.0, 1.0 / 8.0, 1.0 / 16.0],
            [1.0 / 8.0, 1.0 / 4.0, 1.0 / 8.0],
            [1.0 / 16.0, 1.0 / 8.0, 1.0 / 16.0]]
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 2, m_inW + 2)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 1][k + 1] = m_InputImage[rgb][i][k]
    # 마스크 회선 연산
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(3):
                    for n in range(3):
                        S += tmpInput[rgb][i + m][k + n] * mask[m][n]
                tmpOutput[rgb][i][k] = S
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v = tmpOutput[rgb][i][k]
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### 고주파패스필터처리
def hpfImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[고주파패스필터처리]")
    # 마스크
    mask = [[0., -1., 0],
            [-1., 5., -1.],
            [0, -1., 0.]]
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 2, m_inW + 2)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 1][k + 1] = m_InputImage[rgb][i][k]
    # 마스크 회선 연산
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(3):
                    for n in range(3):
                        S += tmpInput[rgb][i + m][k + n] * mask[m][n]
                tmpOutput[rgb][i][k] = S
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v = tmpOutput[rgb][i][k]
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()
#### 고주파필터처리
def lpfImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[고주파필터처리]")
    # 마스크
    mask = [[-1. / 9., 1 / 9., -1. / 9.],
            [-1. / 9., 8. / 9., -1. / 8.],
            [-1. / 9., 1 / 9., -1. / 9.]]
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 2, m_inW + 2)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 1][k + 1] = m_InputImage[rgb][i][k]
    # 마스크 회선 연산
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(3):
                    for n in range(3):
                        S += tmpInput[rgb][i + m][k + n] * mask[m][n]
                tmpOutput[rgb][i][k] = S
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v = tmpOutput[rgb][i][k]
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### 유사연산자처리
def calcUsaImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[유사연산자처리]")

    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 2, m_inW + 2)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 1][k + 1] = m_InputImage[rgb][i][k]

    ## 유사연산 알고리즘
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                max = 0.0
                for m in range(3):
                    for n in range(3):
                        if abs(tmpInput[rgb][i + 1][k + 1] - tmpInput[rgb][i + m][k + n] >= max):
                            # 블록의 가운대값 - 블록의 주변 픽셀값의 절대값 중에서
                            # 최대값을 찾는다.
                            max = abs(
                                tmpInput[rgb][i + 1][k + 1] - tmpInput[rgb][i + m][k + n])
                tmpOutput[rgb][i][k] = max

    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v = tmpOutput[rgb][i][k]
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### 차연산자
def calcMnsImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[고주파필터처리]")
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 2, m_inW + 2)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 1][k + 1] = m_InputImage[rgb][i][k]
    mask = [0 for _ in range(4)]
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                max = 0.0
                mask[0] = abs(tmpInput[rgb][i][k] -
                              tmpInput[rgb][i + 2][k + 2])
                mask[1] = abs(tmpInput[rgb][i][k + 1] -
                              tmpInput[rgb][i + 2][k + 1])
                mask[2] = abs(tmpInput[rgb][i][k + 2] -
                              tmpInput[rgb][i + 2][k])
                mask[3] = abs(tmpInput[rgb][i + 1][k] -
                              tmpInput[rgb][i + 1][k + 2])
                for m in range(4):
                    if (mask[m] >= max):
                        max = mask[m]
                tmpOutput[rgb][i][k] = max
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v = tmpOutput[rgb][i][k]
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### 로버츠엣지처리
def robertsImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[로버츠엣지처리]")
    # 마스크
    maskV = [[-1, 0, 0],
             [0, 1, 0],
             [0, 0, 0]]
    maskH = [[0, 0, -1],
             [0, 1, 0],
             [0, 0, 0]]
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 2, m_inW + 2)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    tmpOutput2 = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 1][k + 1] = m_InputImage[rgb][i][k]
    # 마스크 회선 연산
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(3):
                    for n in range(3):
                        S += tmpInput[rgb][i + m][k + n] * maskH[m][n]
                tmpOutput[rgb][i][k] = S
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(3):
                    for n in range(3):
                        S += tmpInput[rgb][i + m][k + n] * maskV[m][n]
                tmpOutput2[rgb][i][k] = S
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v1 = tmpOutput[rgb][i][k]
                v2 = tmpOutput2[rgb][i][k]
                v = v1 + v2
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### 프리윗엣지처리
def prwImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return

    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[로버츠엣지처리]")
    # 마스크
    maskV = [[-1, 0, 1],
             [-1, 0, 1],
             [-1, 0, 1]]
    maskH = [[1, 1, 1],
             [0, 0, 0],
             [-1, -1, -1]]
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 2, m_inW + 2)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    tmpOutput2 = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 1][k + 1] = m_InputImage[rgb][i][k]
    # 마스크 회선 연산
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(3):
                    for n in range(3):
                        S += tmpInput[rgb][i + m][k + n] * maskH[m][n]
                tmpOutput[rgb][i][k] = S
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(3):
                    for n in range(3):
                        S += tmpInput[rgb][i + m][k + n] * maskV[m][n]
                tmpOutput2[rgb][i][k] = S
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v1 = tmpOutput[rgb][i][k]
                v2 = tmpOutput2[rgb][i][k]
                v = v1 + v2
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### 소벨엣지처리
def sblImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[소벨엣지처리]")
    # 마스크
    maskV = [[1, 2, 1],
             [0, 0, 0],
             [-1, -2, -1]]
    maskH = [[-1, 0, 1],
             [-2, 0, 2],
             [-1, 0, 1]]
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 2, m_inW + 2)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    tmpOutput2 = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 1][k + 1] = m_InputImage[rgb][i][k]
    # 마스크 회선 연산
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(3):
                    for n in range(3):
                        S += tmpInput[rgb][i + m][k + n] * maskH[m][n]
                tmpOutput[rgb][i][k] = S
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(3):
                    for n in range(3):
                        S += tmpInput[rgb][i + m][k + n] * maskV[m][n]
                tmpOutput2[rgb][i][k] = S
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v1 = tmpOutput[rgb][i][k]
                v2 = tmpOutput2[rgb][i][k]
                v = v1 + v2
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### 라플라필터처리
def laplaImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[라플라필터처리]")
    # 마스크
    mask = [[-1, -1, -1],
            [-1, 8, -1],
            [-1, -1, -1]]
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 2, m_inW + 2)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 1][k + 1] = m_InputImage[rgb][i][k]
    # 마스크 회선 연산
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(3):
                    for n in range(3):
                        S += tmpInput[rgb][i + m][k + n] * mask[m][n]
                tmpOutput[rgb][i][k] = S
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v = tmpOutput[rgb][i][k]
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### LoG필터처리
def logFilterImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[LoG필터처리]")
    # 마스크
    mask = [[0, 0, -1, 0, 0],
            [0, -1, -2, -1, 0],
            [-1, -2, 16, -2, -1],
            [0, -1, -2, -1, 0],
            [0, 0, -1, 0, 0]]
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 4, m_inW + 4)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 2][k + 2] = m_InputImage[rgb][i][k]
    # 마스크 회선 연산
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(5):
                    for n in range(5):
                        S += tmpInput[rgb][i + m][k + n] * mask[m][n]
                tmpOutput[rgb][i][k] = S
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v = tmpOutput[rgb][i][k]
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### DoG필터처리
def dogFilterImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    m_outH = m_inH
    m_outW = m_inW
    m_OutputImage = malloc3D(m_outH, m_outW)

    print("[DoG필터처리]")
    # 마스크
    mask = [
        [0, 0, 0, -1, -1, -1, 0, 0, 0],
        [0, -2, -3, -3, -3, -3, -3, -2, 0],
        [0, -3, -2, -1, -1, -1, -2, -3, 0],
        [0, -3, -1, 9, 9, 9, -1, -3, 0],
        [-1, -3, -1, 9, 19, 9, -1, -3, -1],
        [0, -3, -1, 9, 9, 9, -1, -3, 0],
        [0, -3, -2, -1, -1, -1, -2, -3, 0],
        [0, -2, -3, -3, -3, -3, -3, -2, 0],
        [0, 0, 0, -1, -1, -1, 0, 0, 0]]
    # 임시 입/출력 메모리 준비
    tmpInput = malloc3D_double(m_inH + 8, m_inW + 8)
    tmpOutput = malloc3D_double(m_outH, m_outW)
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                tmpInput[rgb][i + 4][k + 4] = m_InputImage[rgb][i][k]
    # 마스크 회선 연산
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                S = 0.0
                for m in range(9):
                    for n in range(9):
                        S += tmpInput[rgb][i + m][k + n] * mask[m][n]
                tmpOutput[rgb][i][k] = S
    ## 오버플로 확인절차 및 출력
    for rgb in range(RGB):
        for i in range(m_outH):
            for k in range(m_outW):
                v = tmpOutput[rgb][i][k]
                if (v > 255.0):
                    v = 255.0
                if (v < 0.0):
                    v = 0.0
                m_OutputImage[rgb][i][k] = int(v)
    displayImage()


#### 스트레칭이미지
def histStrchImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("스트레칭이미지")
    LOW = 0
    HIGH = 255
    minR, minG, minB = [HIGH] * 3
    maxR, maxG, maxB = [LOW] * 3
    m_outH = m_inH
    m_outW = m_inW
    # 출력 메모리 할당
    m_OutputImage = malloc3D(m_outH, m_outW)
    ## 최소 값 찾기
    for i in range(m_inH):
        for k in range(m_inW):
            if (m_InputImage[RR][i][k] <= minR):
                minR = m_InputImage[RR][i][k]
            if (m_InputImage[GG][i][k] <= minG):
                minG = m_InputImage[GG][i][k]
            if (m_InputImage[BB][i][k] <= minB):
                minB = m_InputImage[RR][i][k]
    ## 최대 값 찾기
    for i in range(m_inH):
        for k in range(m_inW):
            if (m_InputImage[RR][i][k] >= maxR):
                maxR = m_InputImage[RR][i][k]
            if (m_InputImage[GG][i][k] >= maxG):
                maxG = m_InputImage[GG][i][k]
            if (m_InputImage[BB][i][k] >= maxB):
                maxB = m_InputImage[RR][i][k]
    print(maxR, maxG, maxB, minR, minG, minB)
    ## 진짜 영상처리 알고리즘
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                m_OutputImage[RR][i][k] = int(
                    (m_InputImage[RR][i][k] - minR) * HIGH / (maxR - minR))
                if (m_OutputImage[RR][i][k] > 255):
                    m_OutputImage[RR][i][k] = 255
                elif (m_OutputImage[RR][i][k] < 0):
                    m_OutputImage[RR][i][k] = 0
                m_OutputImage[GG][i][k] = int(
                    (m_InputImage[GG][i][k] - minG) * HIGH / (maxG - minG))
                if (m_OutputImage[GG][i][k] > 255):
                    m_OutputImage[GG][i][k] = 255
                elif (m_OutputImage[GG][i][k] < 0):
                    m_OutputImage[GG][i][k] = 0
                m_OutputImage[BB][i][k] = int(
                    (m_InputImage[BB][i][k] - minB) * HIGH / (maxB - minB))
                if (m_OutputImage[BB][i][k] > 255):
                    m_OutputImage[BB][i][k] = 255
                elif (m_OutputImage[BB][i][k] < 0):
                    m_OutputImage[BB][i][k] = 0
    displayImage()


#### 평활화이미지
def histEqualImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[평활화이미지]")
    # (중요!) 출력 영상 크기 결정 --> 알고리즘에 따름
    m_outH = m_inH
    m_outW = m_inW
    # 출력 메모리 할당
    m_OutputImage = malloc3D(m_outH, m_outW)
    ## 진짜 영상처리 알고리즘
    sumR, sumG, sumB = [0.0] * 3
    m_HISTR = [0 for _ in range(256)]
    m_HISTG = [0 for _ in range(256)]
    m_HISTB = [0 for _ in range(256)]
    m_Sum_of_HISTR = [0 for _ in range(256)]
    m_Sum_of_HISTG = [0 for _ in range(256)]
    m_Sum_of_HISTB = [0 for _ in range(256)]
    size = m_inH * m_inW
    LOW = 0
    HIGH = 255

    # 빈도수 조사
    for i in range(m_inH):
        for k in range(m_inW):
            value = m_InputImage[RR][i][k]
            m_HISTR[value] += 1
            value = m_InputImage[GG][i][k]
            m_HISTG[value] += 1
            value = m_InputImage[BB][i][k]
            m_HISTB[value] += 1
    ## 누적 히스토그램 생성
    for i in range(256):
        sumR += m_HISTR[i]
        sumG += m_HISTG[i]
        sumB += m_HISTB[i]
        m_Sum_of_HISTR[i] = sumR
        m_Sum_of_HISTG[i] = sumG
        m_Sum_of_HISTB[i] = sumB
    ### 평활화 된 영상으로 출력
    for i in range(m_outH):
        for k in range(m_outW):
            TempR = m_InputImage[RR][i][k]
            TempG = m_InputImage[RR][i][k]
            TempB = m_InputImage[RR][i][k]
            m_OutputImage[RR][i][k] = int(m_Sum_of_HISTR[TempR] * HIGH / size)
            m_OutputImage[GG][i][k] = int(m_Sum_of_HISTG[TempG] * HIGH / size)
            m_OutputImage[BB][i][k] = int(m_Sum_of_HISTB[TempB] * HIGH / size)
    displayImage()


### ~~~ OpenCV 기반 알고리즘 ~~~~
#### 결과를 화면출력으로 보내기
def cv2OutImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    # 크기 알아내기
    m_outH, m_outW = cvOutPhoto.shape[:2]  # [0:2]0~1까지
    # 메모리 할당
    m_OutputImage = malloc3D(m_outH, m_outW)
    # 3차원 스케일
    # if not m_OutputImage[RR]:
    if cvOutPhoto.ndim > 2:  # ndim : 넘파이 차원수 확인
        for i in range(m_outH):
            for k in range(m_outW):
                m_OutputImage[RR][i][k] = cvOutPhoto.item(i, k, BB)
                m_OutputImage[GG][i][k] = cvOutPhoto.item(i, k, GG)
                m_OutputImage[BB][i][k] = cvOutPhoto.item(i, k, RR)
    # 단일 스케일
    # elif m_OutputImage[RR]:
    else:
        for i in range(m_outH):
            for k in range(m_outW):
                m_OutputImage[RR][i][k] = cvOutPhoto.item(i, k)
                m_OutputImage[GG][i][k] = cvOutPhoto.item(i, k)
                m_OutputImage[BB][i][k] = cvOutPhoto.item(i, k)
#### 회색처리_OpenCV
def grayImage_cv():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[회색처리_OpenCV]")
    ## OpenCV용 알고리즘 ##
    cvOutPhoto = cv2.cvtColor(cvInPhoto, cv2.COLOR_RGB2GRAY)
    ## 화면출력
    cv2OutImage()
    displayImage()
#### 엠보싱처리_OpenCV
def embossImage_cv():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[엠보싱처리_OpenCV]")
    ## OpenCV용 알고리즘 ##
    mask = np.zeros((3, 3), np.float32)
    mask[0][0] = -1.0
    mask[2][2] = 1.0
    cvOutPhoto = cv2.filter2D(cvInPhoto, -1, mask)
    cvOutPhoto += 127  # 넘파이배열은 이렇게 간단하게 전부 계산처리 가능
    ## 화면출력
    cv2OutImage()
    displayImage()
#### 카툰이미지처리_OpenCV
def cartoonImage_cv():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[카툰이미지처리_OpenCV]")
    ## OpenCV용 알고리즘 ##
    cvOutPhoto = cv2.cvtColor(cvInPhoto, cv2.COLOR_RGB2GRAY)
    cvtOutPhoto = cv2.medianBlur(cvOutPhoto, 7)
    edges = cv2.Laplacian(cvOutPhoto, cv2.CV_8U, ksize=5)
    ret, mask = cv2.threshold(edges, 100, 255, cv2.THRESH_BINARY_INV)
    cvOutPhoto = cv2.cvtColor(mask, cv2.COLOR_GRAY2RGB)
    ## 화면출력
    cv2OutImage()
    displayImage()
#### 공간색감검출 (HSV)_OpenCV
def hsvOrangeBlueImage_cv():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[공간색감검출]")
    ## OpenCV용 알고리즘 ##
    src = cv2.imread(filename)
    hsv = cv2.cvtColor(src, cv2.COLOR_BGR2HSV)
    h, s, v = cv2.split(hsv)
    orange = cv2.inRange(hsv, (8, 100, 100), (20, 255, 255))
    blue = cv2.inRange(hsv, (110, 100, 100), (130, 255, 255))
    mix_color = cv2.addWeighted(orange, 1.0, blue, 1.0, 0.0)

    cvOutPhoto = cv2.bitwise_and(hsv, hsv, mask=mix_color)
    cvOutPhoto = cv2.cvtColor(cvOutPhoto, cv2.COLOR_HSV2BGR)
    ## 화면출력
    cv2OutImage()
    displayImage()
#### blur 필터 _OpenCV
def blurImage_cv():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[blur 필터]")
    ## OpenCV용 알고리즘 ##
    cvOutPhoto = cv2.bilateralFilter(
        cvInPhoto, 100, 33, 11, borderType=cv2.BORDER_ISOLATED)
    ## 화면출력
    cv2OutImage()
    displayImage()
#### 확대_OpenCV
def zoomInImage_cv():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[확대_OpenCV]")
    ## OpenCV용 알고리즘 ##
    scale = askinteger("입력창", "원하는 배율 입력(2의제곱으로올라감)")
    cvOutPhoto = cvInPhoto.copy()
    for _ in range(scale):
        cvOutPhoto = cv2.pyrUp(cvOutPhoto)  # 피라미드 업
    ## 화면출력
    cv2OutImage()
    displayImage()
#### 축소_OpenCV
def zoomOutImage_cv():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[축소_OpenCV]")
    ## OpenCV용 알고리즘 ##
    scale = askinteger("입력창", "원하는 배율 입력(2의제곱으로올라감)")
    cvOutPhoto = cvInPhoto.copy()
    for _ in range(scale):
        cvOutPhoto = cv2.pyrDown(cvOutPhoto)  # 피라미드 다운
    ## 화면출력
    cv2OutImage()
    displayImage()
#### 사이즈바꾸기_OpenCV
def reSizeImage_cv():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    global frameCount, capture, s_factor
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[사이즈바꾸기_OpenCV]")
    ## OpenCV용 알고리즘 ##
    scale = askinteger("입력창", "원하는 배율 입력")
    cvOutPhoto = cvInPhoto.copy()
    re_H = m_inH * scale
    re_W = m_inW * scale
    if re_H > monitor_height:
        re_H = monitor_height
    if re_W > monitor_width:
        re_W = monitor_width
    cvOutPhoto = cv2.resize(cvOutPhoto, dsize=(re_W, re_H), interpolation=cv2.INTER_NEAREST)  # 보간법을 고를 수 있다.
    ## 화면출력
    cv2OutImage()
    displayImage()


# ~~~~ 동영상 관련 ~~~~~
#### 결과를 화면출력으로 보내기
def cv2OutImage_UCC():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    # 크기 알아내기
    m_outH, m_outW = cvOutPhoto.shape[:2]  # [0:2]0~1까지
    # 메모리 할당
    m_OutputImage = malloc3D(m_outH, m_outW)
    # 3차원 스케일
    # if not m_OutputImage[RR]:
    if cvOutPhoto.ndim > 2:  # ndim : 넘파이 차원수 확인
        for i in range(m_outH):
            for k in range(m_outW):
                m_OutputImage[RR][i][k] = cvOutPhoto.item(i, k, BB)
                m_OutputImage[GG][i][k] = cvOutPhoto.item(i, k, GG)
                m_OutputImage[BB][i][k] = cvOutPhoto.item(i, k, RR)
    # 단일 스케일
    # elif m_OutputImage[RR]:
    else:
        for i in range(m_outH):
            for k in range(m_outW):
                m_OutputImage[RR][i][k] = m_InputImage[RR][i][k] = cvOutPhoto.item(i, k)
                m_OutputImage[GG][i][k] = m_InputImage[GG][i][k] = cvOutPhoto.item(i, k)
                m_OutputImage[BB][i][k] = m_InputImage[BB][i][k] = cvOutPhoto.item(i, k)
    m_inH, m_inW = m_outH, m_outW


#### 스크린샷
def snapshot(f):
    global filename
    cv2.imwrite('save' + str(random.randint(11111, 99999)) + '.png', f)


#### 유튜브 연동 함수
def youtubeDisplay():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine, status
    global url
    print("[Youtube_영상출력]")
    url = askstring("입력창", "출력할 유튜브 영상을 url을 입력하시오")
    if not url or url == "":
        return
    ytVideo = pafy.new(url)
    frameCount = 0
    best = ytVideo.getbest(preftype='mp4')  # 'webm','3gp'
    capture = cv2.VideoCapture(best.url)
    title = ytVideo.title
    s_factor = 0.8  # 화면크기 비율 ( 조절 가능 )
    while True:
        ret, frame = capture.read()
        if not ret:
            break
        ## 동영상 딥러닝(SSD) ##
        frameCount += 1
        if frameCount % 5 == 0:
            frame = cv2.resize(frame, None, fx=s_factor, fy=s_factor, interpolation=cv2.INTER_AREA)
            # frame = ssdNet(frame)
            # 화면출력
            cv2.imshow("Youtube", frame)
        key = cv2.waitKey(25)
        ## 키입력
        if key == 27:  # Esc
            cvOutPhoto = frame
            filename = title
            cv2OutImage_UCC()
            displayImage()
            break
        if key == ord('c') or key == ord('C'):
            filename = title
            snapshot(frame)
    capture.release()
    cv2.destroyAllWindows()
#### Youtube영상출력 쓰레드
def yotubeDisplayThreading():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    thread_Youtube = threading.Thread(target=youtubeDisplay(), daemon=True)
    thread_Youtube.start()
    thread_Youtube.join()

#### 유튜브 연동 함수_SSD
def youtubeSSDDisplay():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine, status
    global url
    print("[Youtube_영상출력_SSD]")
    url = askstring("입력창", "출력할 유튜브 영상을 url을 입력하시오")
    if not url or url == "":
        return
    ytVideo = pafy.new(url)
    frameCount = 0
    best = ytVideo.getbest(preftype='mp4')  # 'webm','3gp'
    capture = cv2.VideoCapture(best.url)
    title = ytVideo.title
    s_factor = 0.8  # 화면크기 비율 ( 조절 가능 )
    while True:
        ret, frame = capture.read()
        if not ret:
            break
        ## 동영상 딥러닝(SSD) ##
        frameCount += 1
        if frameCount % 5 == 0:
            frame = cv2.resize(frame, None, fx=s_factor, fy=s_factor, interpolation=cv2.INTER_AREA)
            # frame = ssdNet(frame)
            # 화면출력
            cv2.imshow("Youtube", frame)
        key = cv2.waitKey(25)
        ## 키입력
        if key == 27:  # Esc
            cvOutPhoto = frame
            filename = title
            cv2OutImage_UCC()
            displayImage()
            break
        if key == ord('c') or key == ord('C'):
            filename = title
            snapshot(frame)
    capture.release()
    cv2.destroyAllWindows()
#### Youtube영상출력 쓰레드_SSD
def yotubeDisplayThreading():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    thread_Youtube = threading.Thread(target=youtubeSSDDisplay(), daemon=True)
    thread_Youtube.start()
    thread_Youtube.join()

#### 유튜브 연동 함수_(평활화)
def youtubeEqualDisplay():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine, status
    global url
    print("[Youtube_영상출력_평활화]")
    url = askstring("입력창", "출력할 유튜브 영상을 url을 입력하시오")
    if not url or url == "":
        return
    ytVideo = pafy.new(url)
    frameCount = 0
    best = ytVideo.getbest(preftype='mp4')  # 'webm','3gp'
    capture = cv2.VideoCapture(best.url)
    title = ytVideo.title
    s_factor = 0.8  # 화면크기 비율 ( 조절 가능 )
    while True:
        ret, frame = capture.read()
        if not ret:
            break
        frameCount += 1
        if frameCount % 5 == 0:
            frame = cv2.resize(frame, None, fx=s_factor, fy=s_factor, interpolation=cv2.INTER_AREA)
            # 화면출력
            ### 평활화 ###
            #### 평활화를 위해 HSV 분리
            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            h, s, v = cv2.split(hsv)
            equalizedV = cv2.equalizeHist(v)
            hsv2 = cv2.merge([h, s, equalizedV])
            #### v값 평활화 후 합치고 BGR로 변환 (명도값 평활화)
            frame = cv2.cvtColor(hsv2, cv2.COLOR_HSV2BGR)
            cv2.imshow("Youtube_Equal", frame)
        key = cv2.waitKey(25)
        ## 키입력
        if key == 27:  # Esc
            #### 평활화를 위해 HSV 분리
            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            h, s, v = cv2.split(hsv)
            equalizedV = cv2.equalizeHist(v)
            hsv2 = cv2.merge([h, s, equalizedV])
            #### v값 평활화 후 합치고 BGR로 변환 (명도값 평활화)
            frame = cv2.cvtColor(hsv2, cv2.COLOR_HSV2BGR)
            cvOutPhoto = frame
            filename = title
            cv2OutImage_UCC()
            displayImage()
            break
        if key == ord('c') or key == ord('C'):
            filename = title
            #### 평활화를 위해 HSV 분리
            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            h, s, v = cv2.split(hsv)
            equalizedV = cv2.equalizeHist(v)
            hsv2 = cv2.merge([h, s, equalizedV])
            #### v값 평활화 후 합치고 BGR로 변환 (명도값 평활화)
            frame = cv2.cvtColor(hsv2, cv2.COLOR_HSV2BGR)
            snapshot(frame)
    capture.release()
    cv2.destroyAllWindows()
#### Youtube영상출력 쓰레드_(평활화)
def yotubeEqaulDisplayThreading():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    thread_Youtube = threading.Thread(target=youtubeEqualDisplay(), daemon=True)
    thread_Youtube.start()
    thread_Youtube.join()

#### 유튜브 연동 함수_SSD_(평활화)
def youtubeEqualSSDDisplay():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine, status
    global url
    print("[Youtube_영상출력_SSD_평활화]")
    url = askstring("입력창", "출력할 유튜브 영상을 url을 입력하시오")
    if not url or url == "":
        return
    ytVideo = pafy.new(url)
    frameCount = 0
    best = ytVideo.getbest(preftype='mp4')  # 'webm','3gp'
    capture = cv2.VideoCapture(best.url)
    title = ytVideo.title
    s_factor = 0.8  # 화면크기 비율 ( 조절 가능 )
    while True:
        ret, frame = capture.read()
        if not ret:
            break
        frameCount += 1
        if frameCount % 5 == 0:
            frame = cv2.resize(frame, None, fx=s_factor, fy=s_factor, interpolation=cv2.INTER_AREA)
            # 화면출력
            ### 평활화 ###
            #### 평활화를 위해 HSV 분리
            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            h, s, v = cv2.split(hsv)
            equalizedV = cv2.equalizeHist(v)
            hsv2 = cv2.merge([h, s, equalizedV])
            #### v값 평활화 후 합치고 BGR로 변환 (명도값 평활화)
            frame = cv2.cvtColor(hsv2, cv2.COLOR_HSV2BGR)
            cvOutPhoto = ssdNet(frame)
            frame = cvOutPhoto
            cv2.imshow("Youtube_Equal_SSD", frame)
        key = cv2.waitKey(25)
        ## 키입력
        if key == 27:  # Esc
            #### 평활화를 위해 HSV 분리
            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            h, s, v = cv2.split(hsv)
            equalizedV = cv2.equalizeHist(v)
            hsv2 = cv2.merge([h, s, equalizedV])
            #### v값 평활화 후 합치고 BGR로 변환 (명도값 평활화)
            frame = cv2.cvtColor(hsv2, cv2.COLOR_HSV2BGR)
            cvOutPhoto = frame
            filename = title
            cv2OutImage_UCC()
            displayImage()
            break
        if key == ord('c') or key == ord('C'):
            filename = title
            #### 평활화를 위해 HSV 분리
            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            h, s, v = cv2.split(hsv)
            equalizedV = cv2.equalizeHist(v)
            hsv2 = cv2.merge([h, s, equalizedV])
            #### v값 평활화 후 합치고 BGR로 변환 (명도값 평활화)
            frame = cv2.cvtColor(hsv2, cv2.COLOR_HSV2BGR)
            snapshot(frame)
    capture.release()
    cv2.destroyAllWindows()
#### Youtube영상출력 쓰레드_SSD_(평활화)
def yotubeEqaulSSDDisplayThreading():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    thread_Youtube = threading.Thread(target=youtubeEqualSSDDisplay(), daemon=True)
    thread_Youtube.start()
    thread_Youtube.join()


#### 웹캠인식
def displayUCC():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    global lock
    frameCount = 0
    capture = cv2.VideoCapture(0, cv2.CAP_DSHOW)  # captureDevice = camera ## 카메라 캡쳐를 백에드에서 시키기
    s_factor = 1  # 화면크기 비율 ( 조절 가능 )
    while True:
        ret, frame = capture.read()
        print(ret)
        if not ret:
            break
        frameCount += 1
        if frameCount % 10 == 0:
            frame = cv2.resize(frame, None, fx=s_factor, fy=s_factor, interpolation=cv2.INTER_AREA)
            cv2.imshow('WebCam', frame)

        ## 키 입력 ##
        key = cv2.waitKey(6)
        if key == 27:  # ESC 키
            filename = "WebCam"
            cvOutPhoto = frame
            cv2OutImage_UCC()
            displayImage()
            break
        if key == ord('c') or key == ord('C'):
            filename = "WebCam"
            snapshot(frame)
    capture.release()
    print("[동영상인식_SSD]")
    cv2.destroyAllWindows()
def displayUCCThreading():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    thread_UCC = threading.Thread(target=displayUCC(), daemon=True)
    thread_UCC.start()
    thread_UCC.join()

#### 웹캠인식_haar
def haarDisplayUCC():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    global lock
    frameCount = 0
    capture = cv2.VideoCapture(0, cv2.CAP_DSHOW)  # captureDevice = camera ## 카메라 캡쳐를 백에드에서 시키기
    s_factor = 1  # 화면크기 비율 ( 조절 가능 )
    while True:
        ret, frame = capture.read()
        print(ret)
        if not ret:
            break
        ## 동영상 머신러닝(haar) ##
        frameCount += 1
        if frameCount % 10 == 0:
            frame = cv2.resize(frame, None, fx=s_factor, fy=s_factor, interpolation=cv2.INTER_AREA)
            gray = cv2.cvtColor(frame, cv2.COLOR_RGB2GRAY)
            # 인공지능 불러오기 (모델, Classifire) --> Pre trained data
            face_clf = cv2.CascadeClassifier("./haar/haarcascade_frontalface_alt.xml")
            # 얼굴 찾기
            face_rects = face_clf.detectMultiScale(gray, 1.1, 5)
            cvOutPhoto = frame[:]
            for (x, y, w, h) in face_rects:
                cv2.rectangle(cvOutPhoto, (x, y), (x + w, y + h), (0, 255, 0), 3)
            frame = cvOutPhoto
            cv2.imshow('WebCam_Haar', frame)

        ## 키 입력 ##
        key = cv2.waitKey(6)
        if key == 27:  # ESC 키
            filename = "WebCam"
            cvOutPhoto = frame
            cv2OutImage_UCC()
            displayImage()
            break
        if key == ord('c') or key == ord('C'):
            filename = "WebCam"
            snapshot(frame)
    capture.release()
    print("[동영상인식_SSD]")
    cv2.destroyAllWindows()
def haarDisplayUCCThreading():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    thread_UCC = threading.Thread(target=haarDisplayUCC(), daemon=True)
    thread_UCC.start()
    thread_UCC.join()

#### 웹캠인식_ssd
def ssdDisplayUCC():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    global lock
    frameCount = 0
    capture = cv2.VideoCapture(0, cv2.CAP_DSHOW)  # captureDevice = camera ## 카메라 캡쳐를 백에드에서 시키기
    s_factor = 1  # 화면크기 비율 ( 조절 가능 )
    while True:
        ret, frame = capture.read()
        print(ret)
        if not ret:
            break
        ## 동영상 딥러닝(SSD) ##
        frameCount += 1
        if frameCount % 10 == 0:
            frame = cv2.resize(frame, None, fx=s_factor, fy=s_factor, interpolation=cv2.INTER_AREA)
            cvOutPhoto = ssdNet(frame)
            frame = cvOutPhoto
            cv2.imshow('WebCam_SSD', frame)

        ## 키 입력 ##
        key = cv2.waitKey(6)
        if key == 27:  # ESC 키
            filename = "WebCam"
            cvOutPhoto = frame
            cv2OutImage_UCC()
            displayImage()
            break
        if key == ord('c') or key == ord('C'):
            filename = "WebCam"
            snapshot(frame)
    capture.release()
    print("[동영상인식_SSD]")
    cv2.destroyAllWindows()
def ssdDisplayUCCThreading():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global cvInPhoto, cvOutPhoto
    global sx, sy, ex, ey, boxLine
    thread_UCC = threading.Thread(target=ssdDisplayUCC(), daemon=True)
    thread_UCC.start()
    thread_UCC.join()


#### ~~~~ 머신러닝 알고리즘 ~~~~
### 딥러닝 기반의 사물
#### SSD 넷을 이용한 인식
def ssdNet(image):
    CONF_VALUE = 0.5  # 컨피던스 값 조정
    CLASSES = ["background", "aeroplane", "bicycle", "bird", "boat",
               "bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
               "dog", "horse", "motorbike", "person", "pottedplant", "sheep",
               "sofa", "train", "tvmonitor"]
    COLORS = np.random.uniform(0, 255, size=(len(CLASSES), 3))
    net = cv2.dnn.readNetFromCaffe("./MibileNetSSD/MobileNetSSD_deploy.prototxt.txt",
                                   "./MibileNetSSD/MobileNetSSD_deploy.caffemodel")
    (h, w) = image.shape[:2]
    blob = cv2.dnn.blobFromImage(cv2.resize(image, (300, 300)), 0.007843, (300, 300), 127.5)
    net.setInput(blob)
    detections = net.forward()
    for i in np.arange(0, detections.shape[2]):
        confidence = detections[0, 0, i, 2]
        if confidence > CONF_VALUE:
            idx = int(detections[0, 0, i, 1])
            box = detections[0, 0, i, 3:7] * np.array([w, h, w, h])
            (startX, startY, endX, endY) = box.astype("int")
            label = "{}: {:.2f}%".format(CLASSES[idx], confidence * 100)
            cv2.rectangle(image, (startX, startY), (endX, endY),
                          (255, 255, 255), 2)
            y = startY - 15 if startY - 15 > 15 else startY + 15
            cv2.putText(image, label, (startX, y),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, COLORS[idx], 2)
    return image


#### CLF 를 이용한 인식
def faceDetect_cv():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[얼굴인식_clf__OpenCV]")
    ## OpenCV용 알고리즘 ##
    gray = cv2.cvtColor(cvInPhoto, cv2.COLOR_RGB2GRAY)
    # 인공지능 불러오기 (모델, Classifire) --> Pre trained data
    face_clf = cv2.CascadeClassifier("./haar/haarcascade_frontalface_alt.xml")
    # 얼굴 찾기
    face_rects = face_clf.detectMultiScale(gray, 1.1, 5)
    cvOutPhoto = cvInPhoto[:]
    for (x, y, w, h) in face_rects:
        cv2.rectangle(cvOutPhoto, (x, y), (x + w, y + h), (0, 255, 0), 3)
    ## 화면출력
    cv2OutImage()
    displayImage()


def eyeDetect_cv():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[눈인식_clf__OpenCV]")
    ## OpenCV용 알고리즘 ##
    gray = cv2.cvtColor(cvInPhoto, cv2.COLOR_RGB2GRAY)
    # 인공지능 불러오기 (모델, Classifire) --> Pre trained data
    face_clf = cv2.CascadeClassifier("./haar/haarcascade_eye.xml")
    # 얼굴 찾기
    face_rects = face_clf.detectMultiScale(gray, 1.1, 5)
    cvOutPhoto = cvInPhoto[:]
    for (x, y, w, h) in face_rects:
        cv2.rectangle(cvOutPhoto, (x, y), (x + w, y + h), (0, 255, 0), 3)
    ## 화면출력
    cv2OutImage()
    displayImage()


def mouthDetect_cv():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    global cvInPhoto, cvOutPhoto
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[입인식_clf__OpenCV]")
    ## OpenCV용 알고리즘 ##
    gray = cv2.cvtColor(cvInPhoto, cv2.COLOR_RGB2GRAY)
    # 인공지능 불러오기 (모델, Classifire) --> Pre trained data
    face_clf = cv2.CascadeClassifier("./haar/haarcascade_mcs_mouth.xml")
    # 얼굴 찾기
    face_rects = face_clf.detectMultiScale(gray, 1.1, 5)
    cvOutPhoto = cvInPhoto[:]
    for (x, y, w, h) in face_rects:
        cv2.rectangle(cvOutPhoto, (x, y), (x + w, y + h), (0, 255, 0), 3)
    ## 화면출력
    cv2OutImage()
    displayImage()


#### ~~~~ 마우스 관련 함수 ~~~~

#### 선택반전
def mouseClick_reverseImage():
    global window, canvas, paper, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW, RGB, RR, GG, BB
    if not m_InputImage:
        messagebox.showinfo("알림", "이미지가 입력되지 않았습니다.")
        return
    print("[선택반전]")
    # 마우스 이벤트 받을 준비 시키기
    canvas.bind("<Button-1>", leftClickMouse)
    canvas.bind("<ButtonRelease-1>", leftDropMouse_reverseImage)
    canvas.bind("<B1-Motion>", leftMoveMouse)  # 움직임대로 상자 그려짐


def leftClickMouse(event):
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global sx, sy, ex, ey
    sx = event.x
    sy = event.y


# 클릭마우스의 움직임 대로 상자 그려짐
def leftMoveMouse(event):
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global sx, sy, ex, ey, boxLine
    ex = event.x
    ey = event.y
    # 이전 박스 지우기
    if boxLine == None:
        pass
    else:
        canvas.delete(boxLine)

    boxLine = canvas.create_rectangle(sx, sy, ex, ey, fill=None)


def leftDropMouse_reverseImage(event):
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global sx, sy, ex, ey
    ex = event.x
    ey = event.y
    # 알고리즘에 맞게 드래그박스 위치 지정
    if sx > ex:
        sx, ex = ex, sx
    if sy > ey:
        sy, ey = ey, sy
    reverseImage_Click()
    canvas.unbind("<Button-1>")
    canvas.unbind("<ButtonRelease-1>")


def reverseImage_Click():
    global window, canvas, paper, filename, m_InputImage, m_OutputImage, m_inH, m_inW, m_outH, m_outW
    global sx, sy, ex, ey, boxLine
    # (중요!) 출력 영상 크기 결정 --> 알고리즘에 따름
    m_outH = m_inH
    m_outW = m_inW
    # 출력 메모리 할당
    m_OutputImage = malloc3D(m_outH, m_outW)
    ## 진짜 영상처리 알고리즘
    for rgb in range(RGB):
        for i in range(m_inH):
            for k in range(m_inW):
                if (sx <= k <= ex) and (sy <= i <= ey):
                    m_OutputImage[rgb][i][k] = 255 - m_InputImage[rgb][i][k]
                else:
                    m_OutputImage[rgb][i][k] = m_InputImage[rgb][i][k]
    displayImage()


#### Todo : 위젯설정 (영상두개)

#### ToDo : 동영상 필터설정
def uccFilter():
    hi = "hi"


# # ========== 전역변수 ================
# # # 윈도우창, (OutPut)캔버스, 이미지용 화면
window, canvas, paper = None, None, None
canvas_hist, paper_hist, canvas_hist = None, None, None
# # # # Input Canvas
inCanvas = None
# # # 파일 주소
filename = ""
m_InputImage, m_OutputImage = None, None
m_histImage = None
m_inH, m_inW, m_outH, m_outW = [0] * 4
RGB, RR, GG, BB = 3, 0, 1, 2
# # # OpenCV 변수
cvInPhoto, cvOutPhoto = None, None
# # # 마우스 관련
sx, sy, ex, ey = [-1] * 4
boxLine = None
# # # 동영상 관련
# filename = './faces.mp4'
# capture = cv2.VideoCapture(filename)
# # # 유튜브 관련
url = ""
window = Tk()
window.title("영상처리기 Ver 3.0")  # 타이틀
window.geometry(str(255 + 265) + "x" + str(255 + 40))  # 윈도우창 크기
window.resizable(width=False, height=False)  # 사이즈 조정여부
# # # 모니터 사이즈 구하기
monitor_height = window.winfo_screenheight()
monitor_width = window.winfo_screenwidth()
# # # 상태바
status = Label(window, text='이미지 정보', bd=1, relief=SUNKEN, anchor=W)  # 상태바
status.grid(row=1, column=1, sticky="s")
# # # 라디오버튼 타이틀
# radTitle = Label(window, text='[ 모드 ]', bd=1)
# radTitle.grid(row=0, column=0, sticky="n")
# # # 히스토그램 타이틀
histTitle = Label(window, text='히스토그램', bd=1, relief=SUNKEN, anchor=W)
histTitle.grid(row=1, column=2, sticky="n")
# # ============ 메인 =================
if __name__ == '__main__':
    thread_main = threading.Thread(target=mainThread(), args=())
    thread_main.daemon = True
    thread_main.start()
