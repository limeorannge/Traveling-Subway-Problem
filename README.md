# Traveling-Subway-Problem

This repository computes a route that attempts to visit every *lane* (metro line) in the Seoul Metro graph.
It uses a small Python pre-processor to convert the original JSON map (`data/MapData.json`) into a compact numeric format (`data/data.txt`) and a C++ BFS-based solver (`src/solver.cpp`) that searches for a route covering all lines.

## Quick overview
- `src/data_former.py`: reads `../data/MapData.json`, filters out `passing_lines`, assigns numeric station and line ids, writes `../data/data.txt`, and can pretty-print solver output from `src/result.txt`.
- `src/solver.cpp`: reads `../data/data.txt` (via `freopen("../data/data.txt","r",stdin)`), performs BFS over (station, visited-lines-bitmask) and prints the best route found.

### Getting started (recommended)
1. From the repository root, run the Makefile targets (recommended):

```bash
make generate-data   # creates/overwrites data/data.txt from data/MapData.json
make build           # compiles src/solver.cpp -> src/solver
make run             # runs solver and writes src/result.txt
make pretty          # uses src/data_former.py to pretty-print result.txt to stdout
```

## Notes & conventions
- Working directory matters: many files use relative paths (`../data/...` or `result.txt`) — run the commands from `src/` when running scripts manually, or use the `Makefile` targets from the repo root.
- `src/data_former.py` has a `passing_lines` list which excludes minor lines from the processed input. Edit that list to change which lines are ignored.
- Transfer edges in the JSON are encoded as the string `"transfer"` and are converted by the pre-processor to cost `0` in `data/data.txt`.
- The C++ solver assumes `n <= 258` and `LINES = 19` (it uses a bitmask `1<<19`). If you add or remove lines in `MapData.json`, update the solver constants accordingly.

Reproducing the repo's reported result
- The `README.md` previously contained a final result example. To reproduce the same output: generate the data, build, run, then pretty-print as shown above. The solver prints progress messages as it simulates different starting points.

## Final result
Path with shortest time was the one with starting point "Geomam" station. It requires 195 minutes to travel around whole metro system.
Full path is:
> 검암역 인천2호선, 인천시청역 인천1호선, 부평구청역 7호선, 보라매역 신림선, 샛강역 9호선, 신논현역 신분당선, 판교역 경강선, 이매역 수인분당선, 수서역 3호선, 가락시장역 8호선, 잠실역 2호선, 왕십리역 경의중앙선, 청량리역 경춘선, 청량리역 1호선, 신설동역 우이신설선, 보문역 6호선, 청구역 5호선, 동대문역사문화공원역 4호선, 서울역 공항철도, 검암역 인천2호선
