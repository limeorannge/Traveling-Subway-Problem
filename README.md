# Traveling-Subway-Problem

K-Project of Insoo Chung (Seoul Nat'l Univ. Class of 2026', Department of Computer Science & Engineering)

Finds the **Euler Path** which tries to pass all lanes in Seoul Metro,
except for few minor ones (의정부경전철, 김포골드라인, 에버라인, 서해선)

## data_former.py
Forms the proper adjency list using ahFinished.json (by Eunsik Choi)

## solver.cpp
Solved the Euler Path problem using bitmask method.
Have time complexity of $O(N2^M)$, $N$ means the number of possible stations and $M$ means the number of lanes.

