# Traveling-Subway-Problem

K-Project of Insoo Chung (Seoul Nat'l Univ. Class of 2026', Department of Computer Science & Engineering)

Finds the **Euler Path** which tries to pass all lanes in Seoul Metro,
except for few minor ones (의정부경전철, 김포골드라인, 에버라인, 서해선)

## data_former.py
Forms the proper adjency list using ahFinished.json (by Eunsik Choi)

## solver.cpp
Solved the Euler Path problem using bitmask method.
Have time complexity of $O(N2^M)$, $N$ means the number of possible stations and $M$ means the number of lanes.

## Final result
Path with shortest time was the one with starting point "Incheon City Hall" station. It requires 120 minutes to cycle around whole metro system.
Full path is:
> 인천시청역 인천2호선 --> 인천시청역 인천1호선 --> 계양역 공항철도 --> 서울역 4호선 --> 성신여대입구역 우이신설선 --> 보문역 6호선 --> 공덕역 5호선 --> 여의도역 9호선 --> 샛강역 신림선 --> 대방역 1호선 --> 청량리역 경의중 앙선 --> 상봉역 경춘선 --> 상봉역 7호선 --> 건대입구역 2호선 --> 교대역 3호선 --> 양재역 신분당선 --> 판교역 경강선 --> 이매역 수인분당선 --> 모란역 8호선
