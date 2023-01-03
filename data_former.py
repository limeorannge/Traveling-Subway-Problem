import json
passing_lines = ["에버라인", "서해선", "김포도시철도", "의정부경전철"]

with open("ahfinished.json", "r", encoding='utf-8') as f:
    json_data = json.load(f)

a = json_data.keys()
id = dict()
idr = dict()
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
print(len(lines))
edges = []
for i in a:
    for j in json_data[i]:
        try:
            edges.append((id[i], id[j[0]], j[2] if j[2]!='transfer' else 0))
        except:
            pass
for i in edges:
    print(*i)