import tkinter
from tkinter import messagebox
from tkinter import END
#메세지 import
import sys
import os
import hashlib
import hmac
import base64
import requests
import time
import json
import keys
#TTS import
import wave
import keys_TTS

import os.path


window = tkinter.Tk()
window.title("wheelchair project")
window.attributes('-fullscreen', True)


# map 에 대한 toplevel 생성함수
def createNewWindow1():
    newWindow = tkinter.Toplevel(window)
    labelExample = tkinter.Label(newWindow, text="map")
    labelExample.pack()
    newWindow.attributes('-fullscreen', True)
    def send_message2():
        for i in cl:
            smssend(cl[i], "강원도 횡성군 안흥면")
    location = tkinter.Button(newWindow, text = "위치전송", command=send_message2)
    location.place(relx = 0.45, rely = 0.45, relwidth = 0.1, relheight = 0.1)
    exit_button = tkinter.Button(newWindow, text="exit", command=newWindow.destroy)
    exit_button.place(relx=0.45, rely=0.95, relwidth=0.1, relheight=0.05)


"""
종료버튼 있는 전체화면 창
    width = window.winfo_screenwidth()
    height = window.winfo_screenheight()
    newWindow.geometry("%dx%d" % (width, height))
"""

a = 0
# work 에 대한 toplevel 생성함수
def createNewWindow2():
    newWindow = tkinter.Toplevel(window)
    labelExample = tkinter.Label(newWindow, text="TTS")
    labelExample.pack()
    newWindow.attributes('-fullscreen', True)
    entry3 = tkinter.Entry(newWindow)
    entry3.bind("<Return>", make_TTS)
    entry3.place(relx=0.2, rely=0.2, relwidth=0.6, relheight=0.6)
    global a
    a = entry3.get()
    speakbutton = tkinter.Button(newWindow, text="재생")
    speakbutton.place(relx = 0.8, rely = 0.5, relwidth = 0.1, relheight = 0.1)
    exit_button = tkinter.Button(newWindow, text="exit", command=newWindow.destroy)
    exit_button.place(relx=0.45, rely=0.95, relwidth=0.1, relheight=0.05)


# info 에 대한 toplevel 생성함수
def createNewWindow3():
    newWindow = tkinter.Toplevel(window)
    labelExample = tkinter.Label(newWindow, text="info")
    labelExample.pack()
    newWindow.attributes('-fullscreen', True)
    exit_button = tkinter.Button(newWindow, text="exit", command=newWindow.destroy)
    exit_button.place(relx=0.45, rely=0.95, relwidth=0.1, relheight=0.05)


# 버튼생성
b1 = tkinter.Button(window, text="map", command=createNewWindow1)
b2 = tkinter.Button(window, text="TTS", command=createNewWindow2)
b3 = tkinter.Button(window, text="info", command=createNewWindow3)
# 버튼 위치
b1.place(relwidth=0.5, relheight=0.25, relx=0.05, rely=0.05)
b2.place(relwidth=0.5, relheight=0.25, relx=0.05, rely=0.37)
b3.place(relwidth=0.5, relheight=0.25, relx=0.05, rely=0.7)
# sms 프레임 생성
label_frame4 = tkinter.LabelFrame(window, text="sms", relief="solid", bd=2)
label_frame4.place(relwidth=0.3, relheight=0.9, relx=0.6, rely=0.05)

# 어떤 체크버 눌렸는지 확인하고 cl리스트(전화번호딕셔너리)에 집어넣기
cl = {}


def send_to():
    global cl
    str = ''
    if CheckVariety_1.get() == 1:
        str = str + 'mom clicked, '
        if 'mom' in cl:
            pass
        else:
            cl['mom'] = '01073631937'
    else:
        if 'mom' in cl:
            del cl['mom']
        else:
            pass
    if CheckVariety_2.get() == 1:
        str = str + 'dad clicked, '
        if 'dad' in cl:
            pass
        else:
            cl['dad'] = '01057727898'
    else:
        if 'dad' in cl:
            del cl['dad']
        else:
            pass
    if CheckVariety_3.get() == 1:
        str = str + 'friend1 clicked, '
        if 'friend1' in cl:
            pass
        else:
            cl['friend1'] = '01088435370'
    else:
        if 'friend1' in cl:
            del cl['friend1']
        else:
            pass
    if str == '':
        str = "nothing was checked"
    messagebox.showinfo("Button Clicked", str)
    print(cl)


# 체크버튼 숫자 get
CheckVariety_1 = tkinter.IntVar()
CheckVariety_2 = tkinter.IntVar()
CheckVariety_3 = tkinter.IntVar()
# 체크버튼 생성함수
checkbutton1 = tkinter.Checkbutton(window, text="mom", variable=CheckVariety_1, cursor = "plus", background = "gray")
checkbutton2 = tkinter.Checkbutton(window, text="dad", variable=CheckVariety_2, cursor = "plus", background = "gray")
checkbutton3 = tkinter.Checkbutton(window, text="friend1", variable=CheckVariety_3, cursor = "plus", background = "gray")
checkbutton1.place(relx=0.61, rely=0.07, relwidth=0.1, relheight = 0.05)
checkbutton2.place(relx=0.61, rely=0.13, relwidth=0.1, relheight = 0.05)
checkbutton3.place(relx=0.61, rely=0.19, relwidth=0.1, relheight = 0.05)

# 어떤 체크박스를 클맀했는지 확인
action = tkinter.Button(window, text="선택", command=send_to)
action.place(relx=0.61, rely=0.25, relwidth=0.1, relheight = 0.07)


# 전체 체크버튼 취소함수
def deselectall():
    checkbutton1.deselect()
    checkbutton2.deselect()
    checkbutton3.deselect()


buttondeselectall = tkinter.Button(window, text="전체취소", overrelief="solid", command=deselectall)
buttondeselectall.place(relx=0.61, rely=0.33, relwidth=0.1, relheight = 0.07)

# 리스트 박스 생성(txt 에 아무것도 없으면 기본, 있으면 그걸로 실행)
if os.path.isfile('listbox.txt') == True:
    with open("listbox.txt") as f:
        mylist = f.read().splitlines()
        if mylist == []:
            messages = ['지금가요', '학교에요', '집이에요', '바빠요']
        else:
           messages = mylist
else:
    messages = ['지금가요', '학교에요', '집이에요', '바빠요']

listbox = tkinter.Listbox(window, selectmode='single', height=0)
for i in range(len(messages)):
    listbox.insert(i, messages[i])
listbox.place(relx=0.745, rely=0.23, relwidth=0.1)


# 리스트 박스 데이터 추가
def add(event):
    global messages
    if len(messages) <= 10:
        messages.append(entry.get())
        listbox.insert(len(messages), entry.get())
        entry.delete(0, 'end')
        print(messages)
    else:
        messagebox.showwarning("경고", "한도를 초과하였습니다")


# 리스트 박스 데이터 삭제
def delete():
    global messages
    if len(messages) > 0:
        selection = listbox.curselection()
        if len(selection) == 0:
            return
        value = listbox.get(selection[0])
        ind = messages.index(value)
        del messages[ind]
        listbox.delete(selection[0])
        print(messages)
    else:
        messagebox.showwarning("경고", "한도를 초과하였습니다")


# 삭제버튼
buttonDel = tkinter.Button(window, text="선택항목 삭제", overrelief="solid", command=delete)
buttonDel.place(relx=0.745, rely=0.07, relwidth=0.1, relheight=0.07)

# 리스트 박스 추가용 entry 생성
entry = tkinter.Entry(window)
entry.bind("<Return>", add)
entry.place(relx=0.745, rely=0.15, relwidth=0.1, relheight=0.07)


# 리스트 박스 저장 함수, 버튼

def save():
    with open('listbox.txt', 'w') as f:
        f.write('\n'.join(listbox.get(0, END)))
        f.close()
    messagebox.showinfo("알림", "저징되었습니다")


buttonsave = tkinter.Button(window, text="save", overrelief="solid", command=save)
buttonsave.place(relx=0.85, rely=0.07, relwidth=0.045, relheight=0.15)


# 메세지 send entry

def set_text():
    entry2.delete(0, END)
    for i in listbox.curselection():
        entry2.insert(0, messages[i])


entry2 = tkinter.Entry(window)
entry2.place(relx=0.62, rely=0.75, relwidth=0.26, relheight=0.1)

buttontext = tkinter.Button(window, text="입력", command=set_text)
buttontext.place(relx=0.62, rely=0.86, relwidth=0.1, relheight = 0.07)


# sms 함수
# SMS API using Naver Opencloud
# Hyunmin Lee
# 21.10.26 v0.0.1


# https://api.ncloud-docs.com/docs/ko/ai-application-service-sens-smsv2#api-header

def make_signature(uri):  # POST
    timestamp = str(int(float(time.time()) * 1000))
    secret_key = bytes(keys.secret_key, 'UTF-8')
    access_key = keys.access_key
    message = "POST " + uri + "\n" + timestamp + "\n" + access_key
    message = bytes(message, 'UTF-8')
    signingKey = base64.b64encode(hmac.new(secret_key, msg=message, digestmod=hashlib.sha256).digest()).decode()
    return signingKey


def smssend(message_to, message_content):  # POST
    url = "https://sens.apigw.ntruss.com"
    uri = "/sms/v2/services/" + keys.service_ID + "/messages"
    send_url = url + uri
    timestamp = str(int(time.time() * 1000))
    headers = {'Content-Type': 'application/json; charset=utf-8',
               'x-ncp-apigw-timestamp': timestamp,
               'x-ncp-iam-access-key': keys.access_key,
               'x-ncp-apigw-signature-v2': make_signature(uri)
               }
    body = {
        "type": 'sms',
        "from": keys.mynumber,
        "content": "연락 바랍니다",
        "messages": [
            {
                "to": message_to,
                "content": message_content
            }
        ]
    }
    body = json.dumps(body)
    response_send = requests.post(send_url, headers=headers, data=body)
    print(response_send.text)


def send_message():
    for i in cl:
        smssend(cl[i], entry2.get())


sendbutton = tkinter.Button(window, text="보내기", command=send_message)
sendbutton.place(relx=0.78, rely=0.86, relwidth=0.1, relheight = 0.07)

#TTS api

# TTS api using Kakao API
# Hyunmin Lee
# 21.10.26 v0.0.1

def make_TTS(event):
    url="https://kakaoi-newtone-openapi.kakao.com/v1/synthesize"
    key=keys_TTS.REST_API_key
    headers={
            'Content-Type':'application/xml',
            'Authorization':'KakaoAK '+key
            }
    global a
    data="<speak>"+"a"+"</speak>"
    data=data.encode('utf-8').decode('latin1')
    res=requests.post(url,headers=headers,data=data)
    f=open('temp.wav', 'wb')
    f.write(res.content)
    f.close()
"""
from playsound import playsound
def speak():
    if os.path.isfile('temp.wav') == True:
        playsound("temp.wav")
    else:
        messagebox.showwarning("경고", "먼저 텍스트를 입력해주세요")
"""

window.configure(bg='#FFFAFA')
window.mainloop()
