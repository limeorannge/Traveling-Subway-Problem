import json
passing_lines = ["에버라인", "서해선", "김포도시철도", "의정부경전철"]

with open("ahfinished.json", "r", encoding='utf-8') as f:
    json_data = json.load(f)

a = json_data.keys()
id = dict() # corresponds to each station
idr = dict() # reverse of id
cnt = 0
for i in a:
    if i.split()[1] not in passing_lines:
        id[i] = cnt
        idr[cnt] = i
        cnt+=1
lines = set()
for i in a:
    if i.split()[1] not in passing_lines:
        lines.add(i.split()[1])
lid = dict() # corresponds to each lane
lidr = dict() # reverse of lid
cnt = 0
for i in lines:
    if i not in passing_lines:
        lid[i] = cnt
        lidr[cnt] = i
        cnt+=1
station_data = [] # contains data of stations in tuple list form
for i in a:
    if i.split()[1] not in passing_lines:
        station_data.append((id[i], lid[i.split()[1]]))
print(len(station_data))
for i in station_data:
    print(*i)        

edges = [] # contains data of the path between each stations in tuple list form
for i in a:
    for j in json_data[i]:
        try:
            edges.append((id[i], id[j[0]], j[2] if j[2]!='transfer' else 0))
        except:
            pass
print(len(edges))
for i in edges:
    print(*i)