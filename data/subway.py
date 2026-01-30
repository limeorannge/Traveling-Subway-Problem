import json
import re

import pandas as pd

filename = '서울교통공사 노선별 지하철역 정보.xlsx'
df = pd.read_excel(filename, engine='openpyxl')

stationName = df['전철역명']
stationCode = df['수정된 외부코드']
for i in stationCode.index:
    stationCode[i] = str(stationCode[i])
stationLineName = df['호선']

lines = {}

branch1 = []
branch5 = []
branchKe = []
branchKc = []

def Branching(i):
    if i >= len(stationCode) - 1:
        return False

    pattern1 = re.compile('P1[5-7].*|P14[2-9]')
    pattern5 = re.compile('P5.*')
    patternKe = re.compile('P3.*')
    patternKc = re.compile('P1[23].*|P140')
    if pattern1.match(stationCode[i]):
        branch1.append([stationName[i], stationCode[i]])
        return True
    elif pattern5.match(stationCode[i]):
        branch5.append([stationName[i], stationCode[i]])
        return True
    elif patternKe.match(stationCode[i]):
        branchKe.append([stationName[i], stationCode[i]])
        return True
    elif patternKc.match(stationCode[i]):
        branchKc.append([stationName[i], stationCode[i]])
        return True
    else:
        return False




for i in df.index:
    if stationLineName[i] not in list(lines.keys()):
        lines[stationLineName[i]] = []

    if Branching(i):
        continue

    # if hasCycle():
        
    lines[stationLineName[i]].append([stationName[i], stationCode[i]])

k = 41

index = lines[stationLineName[k]].index([stationName[k], stationCode[k]])
branch1.insert(0, lines[stationLineName[k]][index])
lines[stationLineName[k]][index] = branch1

k = 283

index = lines[stationLineName[k]].index([stationName[k], stationCode[k]])
branch5.insert(0, lines[stationLineName[k]][index])
lines[stationLineName[k]][index] = branch5

k = 492

index = lines[stationLineName[k]].index([stationName[k], stationCode[k]])
branchKe.insert(0, lines[stationLineName[k]][index])
lines[stationLineName[k]][index] = branchKe

k = 521

index = lines[stationLineName[k]].index([stationName[k], stationCode[k]])
branchKc.insert(0, lines[stationLineName[k]][index])
lines[stationLineName[k]][index] = branchKc


with open("lines.json", 'w') as f:
    json.dump(lines, f, indent='\t', ensure_ascii = False)

