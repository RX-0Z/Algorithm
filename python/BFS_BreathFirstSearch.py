from collections import deque

graph = {}

# asinus = {'아시누스':False}
# teemo = {'티모': True}
# nanus = {'나서스': False}
# ezreal = {'나서스': False}
# vayne = {'베인':False}
# jhin = {'진':False}
#graph["asinus"] = {teemo, nanus, ezreal, vayne, jhin}

# todo 각 인원 별로 자신과 연결된 node(정점) 목록을 생성
graph['아시누스'] = {'티모': True, '나서스': False, '나서스': False, '베인':False, '진':False}
graph['티모'] = []
graph['나서스'] = []
graph['베인'] = []
graph['진'] = []

def who_is_seller(person):
    print("step5 : is seller?")
    print("step5 : ", graph['아시누스'].get(person))

#누가 버섯을 파는가?
def search(name):
    search_queue = deque()
    search_queue += graph[name]
    searched = []

    print("step1 : ", graph)
    print("step2 : ", graph['아시누스'].values())
    print("setp3 : ", graph['아시누스'].get('티모'))

    while search_queue:
        person = search_queue.popleft()
        print("step4 : ", person)
        if not person in searched:
            if who_is_seller(person):
                print(person + " is a mushroom seller!")
                return True
            else:
                search_queue += graph[person]
                searched.append(person)
    return False

search('아시누스')

def bfs(graph):
    print("start bfs search...")