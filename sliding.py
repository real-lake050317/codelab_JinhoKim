from queue import PriorityQueue
import copy

board = [ #보드의 시작상태
    [1, 2, 3],
    [0, 7, 5],
    [4, 6, 8]
]

board_solved = [ #보드의 목표상태
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0],
]

count = 0   #노드 번호
initial = copy.deepcopy(board)  #초기 보드
board_previous = copy.deepcopy(board)  #이동 전 보드 초기화

def is_solvable():  #풀이 가능성 확인 함수
    inversions = 0
    for i in range(1,9):
        x1, y1 = find(board, i)
        for j in range(i+1, 9):
            x2, y2 = find(board, j)
            if x2 - x1 == 0 and y2 - y1 < 0:
                inversions += 1
            elif x2 - x1 < 0:
                inversions += 1
    if inversions % 2 == 0: #백트래킹 값 홀수이면 풀이불가능
        return True
    else:
        return False


def backtrack(n1):   #백트래킹을 통해 전 노드에서 어떻게 움직여서 왔는지 확인 (상하좌우)
    current = n1
    g_score = 0
    solved = False
    if current == board_solved:
        for x in current:
            print(x)
        print("\n")
    while current != came_from["previous_node0"]:
        if current == board_solved:
            solved = True
        for i in range(0,len(nodes.keys())):      #이전 노드와 상관관계 계산
            if nodes["node%s" %i] == current:     #이전 노드를 찾을때까지 백트래킹 실행
                current = came_from["previous_node%s" %i]
                g_score += 1
                if solved:       #현재 보드가 최종 보드와 동일하면 풀이 중지
                    for x in current:
                        print(x)
                    print("\n")
                    if current == initial:  #처음 상태와 보드가 동일해지면 백트래킹 중지
                        print(str(g_score) + " moves \n")
                if current == came_from["previous_node0"]:
                    return g_score   #백트래킹 횟수를 g점수로 저장 (A* 알고리즘)

                break


def distance():  #맨해튼 거리 계산 시행
    man = 0
    for i in range(1,9):
        x1, y1 = find(board, i)
        x2, y2 = find(board_solved, i)
        distance = abs(x2 - x1) + abs(y2 - y1)
        man += distance
    return man

def RLrestrict():   #타겟팅된 노드에서 빈 공간이 멀리 있으면 해당 무브먼트 회피 - 오른쪽, 왼쪽 회피함수 
    global allow_r
    global allow_l
    allow_r = True
    allow_l = True
    for i in range(0,3):
        if board[i][0] == 0:
            allow_l = False
        elif board[i][2] == 0:
            allow_r = False


def UDrestrict():  #타겟팅된 노드에서 빈 공간이 멀리 있으면 해당 무브먼트 회피 - 오른쪽, 왼쪽 회피함수
    global allow_u
    global allow_d
    allow_u = True
    allow_d = True
    for i in range(0,3):
        if board[0][i] == 0:
            allow_u = False
        if board[2][i] == 0 :
            allow_d = False


def find(board, num):   #보드에서 숫자의 위치 반환
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == num:
                return (i, j)  # row, col


def right():   #왼쪽 숫자를 빈공간에 넣음 위치 변경
    i, j = find(board, 0)
    board[i][j], board[i][j + 1] = board[i][j + 1], board[i][j]
    return board

def up():   #아래 숫자를 빈공간에 넣음 위치 변경
    i, j = find(board, 0)
    board[i][j], board[i-1][j] = board[i-1][j], board[i][j]
    return board

def left():   #오른쪽 숫자를 빈공간에 넣음 위치 변경
    i, j = find(board, 0)
    board[i][j], board[i][j - 1] = board[i][j - 1], board[i][j]
    return board

def down():   #위 숫자를 빈공간에 넣음 위치 변경
    i, j = find(board, 0)
    board[i][j], board[i + 1][j] = board[i + 1][j], board[i][j]
    return board

class Node:   #노드 스트럭트 제작, 위치와 f점수 선언
    def __init__(self, position, f_score):
        self.position = position
        self.f_score = f_score  #클래스 활용해서 한 변수에 여러개의 데이터 관리


def in_closed(n1):   #이전 노드가 큐에 없음을 확인
    if len(closed_set) == 1:     #최적화 과정 코드
        return False
    if n1 == closed_set["start"]:
        return True
    if n1 in closed_set.values():
        return True
    return False

# 함수 설정 종료, 메인 함수 작성

n1 = Node(board, distance())  #n1을 노드 스트럭트 구조체에 삽입
open_set = PriorityQueue()  #우선순위 큐 생성
nodes = {}    #전체 노드를 딕셔너리화
closed_set = {}  #탐색된 노드를 딕셔너리화
came_from = {}   #노드 출처를 표기
closed_set["start"] = copy.deepcopy(board)   #갱신된 보드는 탐색된 노드의 집합

if is_solvable():
    print("Finding solution... \n")
    while board != board_solved:    #보드가 풀이될때까지 반복
        RLrestrict()
        UDrestrict()
        if allow_r:      #오른쪽으로 움직일 수 있으면 움직임
            n1.position = right()    #오른쪽으로 움직이기, n1상태로 갱신 후 저장
            if in_closed(n1.position): #노드가 이전에 탐색 되었었는지 확인
                left()    #탐색 되었었으면, 탐색하지 않음
            if not in_closed(n1.position):     #탐색되지 않았았으면,
                nodes["node%s" % count] = n1.position  #전체 노드 딕셔너리에 삽입
                came_from["previous_node%s" % count] = copy.deepcopy(left())   #이전 노드를 딕셔너리에 삽입
                n1.position = copy.deepcopy(right())  #이전 이동으로 인해 전체적으로 왼쪽으로 움직였으므로 전체를 오른쪽으로 움직임
                h_score = distance()  #탐색된 노드의 h점수를 계산함
                n1.f_score = h_score + backtrack(n1.position)   #f점수 계산
                open_set.put((n1.f_score, h_score, count, n1.position))  #값들은 우선순위 큐에 삽입
                board = copy.deepcopy(board_previous)  #보드를 이동 1회 전으로 되돌림
                count += 1  
        if allow_l:   #allow_r과 동일, 왼쪽으로 움직이는 코드
            n1.position = left()
            if in_closed(n1.position):
                right()
            if not in_closed(n1.position):
                nodes["node%s" % count] = n1.position
                came_from["previous_node%s" % count] = copy.deepcopy(right())
                n1.position = copy.deepcopy(left())
                h_score = distance()
                n1.f_score = h_score + backtrack(n1.position)
                open_set.put((n1.f_score, h_score, count, n1.position))
                board = copy.deepcopy(board_previous)
                count += 1
        if allow_u: #allow_r과 동일, 위쪽으로 움직이는 코드
            n1.position = up()
            if in_closed(n1.position):
                down()
            if not in_closed(n1.position):
                nodes["node%s" % count] = n1.position
                came_from["previous_node%s" % count] = copy.deepcopy(down())
                n1.position = copy.deepcopy(up())
                h_score = distance()
                n1.f_score = h_score + backtrack(n1.position)
                open_set.put((n1.f_score, h_score, count, n1.position))
                board = copy.deepcopy(board_previous)
                count += 1
        if allow_d: #allow_r과 동일, 아래쪽으로 움직이는 코드
            n1.position = down()
            if in_closed(n1.position):
                up()
            if not in_closed(n1.position):
                nodes["node%s" % count] = n1.position
                came_from["previous_node%s" % count] = copy.deepcopy(up())
                n1.position = copy.deepcopy(down())
                h_score = distance()
                n1.f_score = h_score + backtrack(n1.position)
                open_set.put((n1.f_score, h_score, count, n1.position))
                board = copy.deepcopy(board_previous)
                count += 1

        next_item = open_set.get()[3]
        board = copy.deepcopy(next_item)
        if board == board_solved:
            print("SOLVED")
            break
        closed_set["node%s" %count] = copy.deepcopy(next_item)  #탐색된 노드를 폐기
        board_previous = copy.deepcopy(board)  #이전 보드에 저장된 노드

else:
    print("BOARD NOT SOLVABLE")

print(str(len(closed_set)) + " nodes explored")
print(str(len(nodes)) + " nodes total")